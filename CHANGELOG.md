# Development History

## 2026-09-24

### Packet logging
- Added a separate `fujitsu.packet` logger tag for raw RX/TX packet dumps.
- Raw packet logging can be controlled independently from the general Fujitsu diagnostic log.

### ESPHome 2027.3 compatibility
- Removed the deprecated C++ `UARTDevice::check_uart_settings()` call from `dump_config()`.
- UART requirements are already validated in `climate.py` with `uart.final_validate_device_schema()`: 500 baud, 8 data bits, EVEN parity, 1 stop bit, RX and TX required.
- This removes the ESPHome deprecation warning without changing Fujitsu bus communication.

## Planned
- Runtime packet logging control from the Web UI.
- Support for two independent Fujitsu buses / MCP2025 interfaces.
