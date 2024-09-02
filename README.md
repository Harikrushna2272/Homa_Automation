### Home Automation Project

In this home automation project, I implemented automation using both IR-based and IoT-based systems. The project involved several components:

1. **Curtain Automation**: 
   - Automated curtains using a limit switch to control the start and stop points.
   - Employed a DC motor with an L298 motor driver to manage the direction of the motor.

2. **Lighting and Fan Control**:
   - Automated lighting using a relay system.
   - Developed an advanced fan speed control system using power electronics converters to optimize power consumption. This approach helps save energy and improves power utilization.
   - Implemented three different control techniques:
     - Timer-based
     - Interrupt-based
     - Pulse Width Modulation (PWM)-based (selected for this project).

3. **Air Quality Monitoring**:
   - Integrated an MQ-8 gas sensor for measuring CO₂ levels and the Air Quality Index (AQI).
   - Used the GP2Y1010AU0F Dust Smoke Particle Sensor to measure PM2.5 (particulate matter with a diameter of 2.5 µm or smaller) and also PM10.
   - Displayed the measurements using an I2C communication protocol.

4. **Microcontrollers and IoT Integration**:
   - Utilized an Arduino Mega 2560 for processing and control.
   - Incorporated an ESP8266 module for IoT connectivity, enabling remote monitoring and control.

By combining these components, I created a comprehensive home automation system that enhances both convenience and energy efficiency.

