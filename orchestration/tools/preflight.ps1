# KH2FM preflight: the orchestration plan's VERIFY command.
# Run from the PowerShell tool (not through Bash):
#   powershell -NoProfile -ExecutionPolicy Bypass -File C:\Users\KoZa\Documents\AGENTS\Codex\orchestration\tools\preflight.ps1
# Prints "PREFLIGHT: PASS ..." on success. Any other ending is a failure; read the line above it.
# -SkipGate skips the checkpoint gate (only for testing this script). Note: the gate REWRITES the
# current checkpoint JSON to rebind file hashes; that is expected and is how the project has always worked.
param([switch]$SkipGate)
$ErrorActionPreference = 'Stop'
$agents = 'C:\Users\KoZa\Documents\AGENTS'
$tools = "$agents\Codex\orchestration\tools"
$fail = $null

function Check($name, $ok, $detail) {
    if ($ok) { Write-Output ("ok    {0}: {1}" -f $name, $detail) }
    else { Write-Output ("FAIL  {0}: {1}" -f $name, $detail); if ($null -eq $script:fail) { $script:fail = $name } }
}

# 1. WSL and Docker reachable (never restart Docker Desktop yourself; see decision table).
$docker = (wsl -d Ubuntu-24.04 -u root -- docker info --format '{{.ServerVersion}}' 2>&1 | Out-String).Trim()
Check 'docker' ($LASTEXITCODE -eq 0 -and $docker -match '^\d') "server $docker"

# 2. Stage original executable identity.
$stageHash = (wsl -d Ubuntu-24.04 -u root -- sha256sum /root/kh2fm-build/SLPM_666.75 2>&1 | Out-String).Trim()
Check 'stage-elf' ($stageHash -like 'd869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87*') $stageHash.Split(' ')[0]

# 3. Compiler stage ownership.
$compiler = Get-Content "$agents\Codex\analysis\final-mix\worker-coordination\compiler-status.json" -Raw | ConvertFrom-Json
Check 'compiler' ($compiler.state -eq 'idle') "state=$($compiler.state) phase=$($compiler.phase)"

# 4. Queue state (read-only view).
$queue = (python -I "$tools\orch.py" leases | Out-String) | ConvertFrom-Json
Check 'queue' ($true) ("paused={0} leases={1} submitted={2}" -f $queue.paused, @($queue.leases).Count, @($queue.submitted_awaiting_integration).Count)

# 5. Accepted state numbers.
$state = (python -I "$tools\orch.py" state | Out-String) | ConvertFrom-Json
Check 'build-record' ($state.whole_executable_byte_exact -eq $true) ("phase={0} exact={1} fallback={2}" -f $state.phase, $state.exact_matches, $state.fallback_ranges)

# 6. Current checkpoint gate (derived from compiler-status.json, never typed by hand).
if (-not $SkipGate -and $null -eq $fail) {
    Push-Location $agents
    try {
        $gate = "Public\tools\kh2-audit\verify_fm_primary_$($state.phase)_checkpoint.py"
        $out = (python $gate 2>&1 | Out-String)
        Check 'gate' ($LASTEXITCODE -eq 0 -and $out -match 'checkpoint PASS') ($out.Trim().Split("`n")[-1])
    } finally { Pop-Location }
}

if ($null -eq $fail) {
    $gateNote = 'gate run'
    if ($SkipGate) { $gateNote = 'gate SKIPPED' }
    Write-Output ("PREFLIGHT: PASS phase={0} exact={1} cpp={2} fallback={3} inputs={4} queue_paused={5} leases={6} ({7})" -f `
        $state.phase, $state.exact_matches, $state.cpp_ranges, $state.fallback_ranges, $state.staged_inputs, $queue.paused, @($queue.leases).Count, $gateNote)
    exit 0
}
Write-Output "PREFLIGHT: FAIL at $fail"
exit 1
