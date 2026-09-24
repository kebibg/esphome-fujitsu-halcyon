# Development changelog

## 2026-09-24 — Separate RX/TX packet logging

Branch: `dual-bus-dev`

Changed `components/fujitsu-halcyon/esphome-fujitsu-halcyon.cpp`:
- Added dedicated logger tag `fujitsu.packet`.
- Moved only the raw RX/TX hexadecimal packet dump in `FujitsuHalcyonController::log_buffer()` from the component's main logger tag to `fujitsu.packet`.
- Left UART communication, TZSP forwarding, initialization logic, and all other component diagnostics unchanged.

Recommended ESPHome configuration:

```yaml
logger:
  level: VERY_VERBOSE
  logs:
    fujitsu.packet: NONE

external_components:
  - source: github://kebibg/esphome-fujitsu-halcyon@dual-bus-dev
```

For temporary packet diagnostics, change `fujitsu.packet: NONE` to `fujitsu.packet: DEBUG` and rebuild.

Source commit: `5437c0944ea2d6f7c43b17b931c1f3c1ecae1c66`.

Status: source committed; ESPHome compilation and device OTA not yet tested.
Next: verify build and OTA recovery without power-cycling the Fujitsu system. Future work: runtime packet-log menu and second independent Fujitsu bus.
