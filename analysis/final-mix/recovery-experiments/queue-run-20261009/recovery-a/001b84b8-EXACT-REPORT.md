# Exact isolated recovery 001b84b8

Directly reading member[2] as the final helper argument after conditional initialization reproduces original reloads and branch-likely scheduling. Caching it in a branch phi variable caused unwanted result reuse. Only the initial store-to-member[4] memory barrier remains; the proposed post-helper barrier is unnecessary.

Complete compiled size and bytes equal the live declared original range (100 bytes). Source signatures and meanings remain provisional. Primary independent curation/re-probe and full acceptance remain required.

Source SHA256: b547b8e6be95052e561c2953aa4792be2f1dd086ad911f3905ca1217855fd907
Proof SHA256: a4b95908bd7041ab4740f604a137c4b11bb6394ebb8daca546b784606c587747
Original range SHA256: 999ac813c9dc2fe1c41a7c79650db63167b8140720975b197981faae2417f24a
