# NovaGlow: Smart Candle Control System

NovaGlow is a Bluetooth-enabled microcontroller-based system designed to wirelessly control electronic candles or LED-based ambient lighting. Developed for a commercial client in the event automation and decorative electronics domain, this system provides safe, scalable, and programmable lighting control without the hazards of open flame or manual switching.

## Overview

The NovaGlow system enables wireless activation and deactivation of multiple lighting channels using standard Bluetooth serial communication. Built on Arduino-compatible hardware, it is structured for scalability and extension to include complex behaviors such as timed sequences, grouped control, and integration with mobile or IoT interfaces.

This solution is ideal for use cases such as:
- Event and stage lighting
- Smart home ambient control
- Commercial decorative setups (hotels, restaurants)
- Flame-free lighting applications in safety-sensitive environments

## System Capabilities

- Wireless Bluetooth control of individual LED or relay channels
- Supports up to 8 independent outputs (expandable)
- Instantaneous, low-latency response to control commands
- Customizable logic for group control or sequenced patterns
- Compact, low-power hardware footprint
- Fully compatible with Android terminal apps or Bluetooth clients

## Hardware Components

- **Microcontroller**: Arduino Nano / Uno / Mega or ESP32 (Bluetooth-integrated)
- **Bluetooth Module**: HC-05 (for Arduino boards) or native Bluetooth via ESP32
- **Output Drivers**:
  - Relay Modules (for AC load switching)
  - MOSFETs or ULN2803 (for DC LEDs or low-voltage outputs)
- **Lighting Elements**:
  - LED candles
  - LED strips
  - Decorative fixtures
- **Power Supply**: 5V regulated source (USB or external)
- **Optional Add-ons**:
  - Indicator LEDs
  - Manual override push buttons
  - Opto-isolators or flyback diodes (for inductive safety)

## Firmware Overview

### File: `Candel_code_123.ino`

This is the main program file that:

- Initializes selected GPIO pins for output
- Establishes serial Bluetooth communication
- Listens for integer commands via `Serial.read()`
- Maps each command to ON/OFF control logic per pin
- Executes `digitalWrite()` based on decoded instructions

### Command-to-Pin Mapping

The system maps incoming command codes to lighting actions. Example mapping:

| Command | Action           | Output Pin |
|---------|------------------|------------|
| 1       | ON Candle 1      | D2         |
| 2       | OFF Candle 1     | D2         |
| 3       | ON Candle 2      | D3         |
| 4       | OFF Candle 2     | D3         |
| 5       | ON Candle 3      | D4         |
| 6       | OFF Candle 3     | D4         |
| ...     | Extend as needed | D5–D9      |

You can easily modify or extend this logic to support more channels, group behavior, or sequenced lighting effects.

## Software Requirements

- Arduino IDE (1.8.x or later)
- No third-party libraries required
- Compatible with Arduino AVR-based boards or ESP32 using `Serial` or `BluetoothSerial`

## Setup Instructions

1. **Hardware Setup**:
   - Wire each output pin (D2 to D9) to your relay/MOSFET or LED circuit.
   - Connect your Bluetooth module (HC-05 RX/TX to Arduino TX/RX).
   - Ensure a common ground between power sources.
2. **Programming**:
   - Open `Candel_code_123.ino` in Arduino IDE.
   - Select the correct board and COM port.
   - Upload the code via USB.
3. **Bluetooth Pairing**:
   - Power on the device and pair the Bluetooth module with a smartphone or PC (default HC-05 passcode: `1234` or `0000`).
   - Use a serial Bluetooth terminal app (e.g., Serial Bluetooth Terminal on Android).
4. **Command Input**:
   - Send integers like `1`, `2`, `3`, etc., over the serial interface to toggle candle states.
   - Validate by observing relays/LEDs turning ON/OFF.

## Example Use Case

An event setup involves 6 electronic candles placed on individual tables. The operator pairs a mobile device with NovaGlow and sends numeric commands via Bluetooth terminal to control which candles are lit throughout the evening — either individually or in a sequence for aesthetic effect. No manual handling or flame-based candles are needed.

## Extensibility and Customization

NovaGlow is built to be modular and extensible. Potential enhancements include:

- Group activation commands (e.g., turn all ON/OFF)
- Fade-in/fade-out PWM transitions for LEDs
- Timed sequences (e.g., choreographed lighting)
- Remote control integration via Wi-Fi or IoT (ESP32)
- Mobile app interface for non-terminal users
- Sensor-triggered lighting automation (e.g., sound or motion)

## Applications

- Event decoration and ambience control
- Flame-free religious or ceremonial use
- Smart home automation
- Theatrical and film lighting setups
- Hospitality and commercial ambiance systems

## Acknowledgements

- Developed for a commercial event solutions provider as a safe, programmable alternative to traditional open-flame candles.


