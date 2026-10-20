"""Read this chat's latest native context counter without exposing message text."""
import json
from pathlib import Path

rollout = Path('C:/Users/KoZa/.codex/sessions/2026/10/18/rollout-2026-10-18T05-31-45-01a14eff-2257-7390-ae57-04d4241976ca.jsonl')
latest = None
peak = 0
previous = 0
segment_start = 0
completed_growth = 0
for line in rollout.open(encoding='utf-8'):
    try:
        record = json.loads(line)
    except json.JSONDecodeError:
        continue
    payload = record.get('payload', {})
    if payload.get('type') == 'token_count' and payload.get('info'):
        info = payload['info']
        current = info['last_token_usage']['input_tokens']
        peak = max(peak, current)
        # Ignore the zero marker; the next nonzero count establishes the summary
        # baseline. Count fresh context growth across compaction, not cached reads.
        if current:
            if previous > 50000 and current < previous / 2:
                completed_growth += previous - segment_start
                segment_start = current
            previous = current
        latest = {
            'timestamp': record.get('timestamp'),
            'input_context_tokens': info['last_token_usage']['input_tokens'],
            'model_context_window': info.get('model_context_window'),
            'handoff_threshold': 400000,
        }
if latest is None:
    raise SystemExit('No native context counter found; do not invent a value')
latest['peak_input_context_tokens'] = peak
latest['accumulated_context_tokens'] = 1062788 + completed_growth + previous - segment_start
latest['handoff_due'] = latest['accumulated_context_tokens'] >= latest['handoff_threshold']
print(json.dumps(latest))


