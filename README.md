
            GATE SECURITY SYSTEM (AVR Project)


📌 Project Overview
------------------------------------------------------------
This project implements a robust **Gate/Door Security System**
using two AVR microcontrollers (MC1: HMI_ECU, MC2: Control_ECU).
It is designed for residential, commercial, or industrial gate
control applications where secure access is required.

The system uses:
- **MC1 (HMI_ECU):** Handles the Human-Machine Interface through
  LCD and Keypad. It manages password entry, display messages,
  and communicates with MC2.
- **MC2 (Control_ECU):** Manages actual control operations like
  motor movement, EEPROM storage, buzzer alarms, and timing.

Key communication:
- **UART:** Connects MC1 ↔ MC2 for exchanging commands, passwords,
  and system status.
- **I2C (TWI):** Connects MC2 ↔ EEPROM to store and retrieve passwords.

------------------------------------------------------------
🎯 Features
------------------------------------------------------------
- **Password Protection:**  
  User must enter a valid password to open or change gate settings.

- **EEPROM Integration:**  
  Passwords are stored in an external EEPROM, ensuring data retention
  even after power loss.

- **LCD Display:**  
  Provides clear instructions, status updates (e.g., "Door Opening",
  "Wrong Password", "Change Password").

- **Keypad Input:**  
  4x4 keypad allows entering numbers and functional keys (+, –, Enter).

- **Motor Control:**  
  Controls DC motor rotation for door open/close sequences with precise timing.

- **Buzzer Security Alarm:**  
  If the password is entered wrong 3 times, a buzzer activates for 60s.

- **Timing Control:**  
  Motor and buzzer timings are precisely handled by Timer0 with interrupts.

- **Scalable Modular Drivers:**  
  Reusable drivers (GPIO, LCD, Keypad, UART, Timer, EEPROM, PWM, TWI).

------------------------------------------------------------
🖥️ System Architecture
------------------------------------------------------------
ASCII Block Diagram:

     [ Keypad ]        [ LCD Display ]
          |                   |
       +--+--+           +----+----+
       |  MC1 |<-------->|  MC2     |
       | HMI  |   UART   | Control  |
       +--+---+          +----+-----+
          |                   |
          |              [ External EEPROM ]
          |                       |
      User Input            Store Passwords
                            |
                        [ DC Motor ] ---> Gate
                        [ Buzzer  ] ---> Alarm

Data Flow:
1. User enters password on MC1 → MC1 sends to MC2 via UART.
2. MC2 compares with EEPROM data (via I2C).
3. If correct → MC2 drives motor to open/close door.
4. If wrong → retries allowed; after 3 wrong, buzzer ON.

------------------------------------------------------------
⚙️ Hardware Requirements
------------------------------------------------------------
- **Microcontrollers:** 2x ATmega16 or ATmega32.
- **Input:** 4x4 Keypad.
- **Output:** 16x2 LCD (HD44780 compatible).
- **Actuators:** DC Motor (controlled by H-Bridge like L293D or L298N).
- **Alarm:** Buzzer connected to MC2 (logic controlled).
- **Memory:** 24C16 or compatible I2C EEPROM.
- **Power:** 5V regulated power supply (with decoupling capacitors).
- **Clock:** 8 MHz internal/external oscillator.

------------------------------------------------------------
💻 Software Requirements
------------------------------------------------------------
- **Compiler:** AVR-GCC (part of WinAVR or Atmel/Microchip Studio).
- **IDE (optional):** Atmel Studio / Microchip Studio.
- **Simulation:** Proteus (to simulate LCD, keypad, EEPROM, UART, motor).
- **Programmer:** USBasp / AVR ISP for flashing HEX files.
- **Operating System:** Windows/Linux.

------------------------------------------------------------
📂 Code Structure
------------------------------------------------------------
- **MC1 Files (HMI_ECU):**
  - Door_Security_System.c → Main application (LCD, keypad, UART communication).
  - lcd.c/h → LCD control functions.
  - keypad.c/h → Keypad scanning and mapping.

- **MC2 Files (Control_ECU):**
  - Door_Security_System2.c → Main application (EEPROM, motor, buzzer, timing).
  - external_eeprom.c/h → EEPROM read/write functions.
  - motor.c/h → DC Motor control (CW, CCW, Stop).
  - buzzer.c/h → Buzzer ON/OFF control.

- **Shared Drivers:**
  - gpio.c/h → Input/output pin and port control.
  - timer0.c/h → Timer0 configuration and callback functions.
  - pwm.c/h → PWM driver (for motor speed control, optional).
  - uart.c/h → UART send/receive functions.
  - twi.c/h → I2C protocol implementation for EEPROM.

- **Utility Files:**
  - std_types.h → Type definitions, system-wide constants, macros.
  - common_macros.h → Bit manipulation macros.

------------------------------------------------------------
🔑 Operation Flow
------------------------------------------------------------
1. **Initialization:**
   - LCD, Keypad, UART, Timer0, and EEPROM initialized.
   - User prompted to set a new password.

2. **Password Setup:**
   - User enters password twice.
   - If both match → Stored in EEPROM.
   - If mismatch → Repeat entry.

3. **Main Menu (LCD):**
   - (+) Open Door
   - (–) Change Password

4. **Open Door:**
   - User enters password → Sent to MC2.
   - If match → Motor rotates CW (open 15s), Hold 3s, CCW (close 15s).
   - If wrong → Retry up to 3 times, else buzzer ON for 60s.

5. **Change Password:**
   - User must enter old password.
   - If correct → System asks for new password setup.
   - If wrong → Retry up to 3 times, else buzzer ON.

6. **Error Handling:**
   - After 3 consecutive wrong attempts:
     - Buzzer ON for 60 seconds.
     - System reset to home state.

------------------------------------------------------------
📊 Timing Charts
------------------------------------------------------------

Door Motor Sequence:
------------------------------------------------------------
Time (sec):  0---15---18---33
Motor:     [Opening] [Hold] [Closing]

- 0–15s → Motor rotates CW (door opening).
- 15–18s → Motor stops (door held open).
- 18–33s → Motor rotates CCW (door closing).

Buzzer Alarm:
------------------------------------------------------------
Wrong Attempts: 3
Buzzer:  [ ON ================================ OFF ]
Time:     0s                                60s

- After 3 wrong attempts → buzzer ON for exactly 60s.
- Timer0 interrupts count ticks for precision (31.25 ticks ≈ 1s).

------------------------------------------------------------
⚡ Build & Run Instructions
------------------------------------------------------------
1. Compile source code using AVR-GCC:
   avr-gcc -mmcu=atmega16 -Os -o MC1.elf Door_Security_System.c lcd.c keypad.c gpio.c timer0.c uart.c
   avr-objcopy -O ihex MC1.elf MC1.hex

   avr-gcc -mmcu=atmega16 -Os -o MC2.elf Door_Security_System2.c motor.c buzzer.c external_eeprom.c gpio.c timer0.c uart.c twi.c pwm.c
   avr-objcopy -O ihex MC2.elf MC2.hex

2. Flash HEX files into MCUs:
   avrdude -c usbasp -p m16 -U flash:w:MC1.hex
   avrdude -c usbasp -p m16 -U flash:w:MC2.hex

3. Connect hardware as per header file pin configurations.

4. Test in Proteus or deploy on real hardware.

------------------------------------------------------------
🚀 Future Improvements
------------------------------------------------------------
- **Enhanced Authentication:** RFID, Fingerprint, or Face ID.
- **Remote Monitoring:** WiFi/GSM modules for SMS/APP alerts.
- **Access Logging:** Store access history in EEPROM/SD card.
- **Multi-User Support:** Allow multiple stored passwords or roles.
- **Battery Backup:** Ensure operation during power failures.
- **Tamper Detection:** Alert if hardware is physically tampered.


           END OF README - GATE SECURITY SYSTEM

