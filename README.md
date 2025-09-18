IoT-Based Aqua Water Purifier with Automatic Level Control
Project Overview
This project implements an intelligent water purification system that automates the water filling process based on water levels in both the raw water input container (e.g., from an AC outlet) and the purified water output container. The system uses an Arduino Nano to control a pump, ensuring efficient and hands-free operation of a water purifier.

This project was developed between January and March 2023.

Problem Statement
Manually filling water purifiers can be inconvenient and lead to overflows or running the purifier dry. This system addresses these issues by providing an automated solution that monitors water levels and controls the pumping process, ensuring continuous availability of purified water without manual intervention.

Key Features
Automatic Water Pumping: A motor-driven pump automatically transfers water from an input container to the purifier.

Intelligent Level Control:

Starts pumping only when sufficient raw water is collected in the input container.

Automatically stops pumping when the input container is empty or the purified water output container is full.

Arduino Nano Based: The control logic is implemented on a cost-effective and widely available Arduino Nano microcontroller using embedded C/C++.

Real-time Monitoring (Conceptual IoT): While the core logic is local, the design is "IoT-Based" in its concept, laying the groundwork for future integration with cloud platforms for remote monitoring and control (e.g., sending alerts, viewing water levels remotely).

How It Works
The system relies on two water level sensors and a controllable pump:

Input Water Level Sensor: Placed in the raw water collection container (e.g., receiving water from an AC outlet). When water reaches a predetermined "start" level, this sensor signals the Arduino.

Output Water Level Sensor: Placed near the top of the purified water collection container. This sensor signals the Arduino when the container is full, indicating that pumping should stop.

Pump Control Logic:

The Arduino continuously reads the state of both sensors.

The pump is activated only if the input container has water AND the output container is not yet full.

The pump is deactivated if the input container becomes empty OR the output container becomes full.

Components Used
Microcontroller: Arduino Nano

Water Pump: (e.g., a small DC submersible pump)

Motor Driver/Relay Module: (Crucial for controlling the pump with Arduino)

Water Level Sensors (x2): (e.g., float switches, conductive sensors, or non-contact liquid level sensors)

One for the input raw water container.

One for the output purified water container.

Connecting Wires

Breadboard (for prototyping)

Power Supply: (e.g., 9V battery, USB power bank, or dedicated power adapter for Arduino and pump)

Optional: Status LED (for visual indication of pump operation)

Circuit Diagram / Wiring
Below is a conceptual wiring diagram. The exact connections for your water level sensors might vary based on their type (digital output, analog output, etc.). Ensure your pump is connected via a motor driver or relay.

Conceptual wiring diagram showing connections between Arduino Nano, water pump (via driver), and two water level sensors.

Pin Connections (as per code):

Water Pump (via driver): Arduino Digital Pin 2

Input Water Level Sensor: Arduino Digital Pin 3

Output Water Level Sensor: Arduino Digital Pin 4

Status LED (Optional): Arduino Digital Pin 13 (with resistor)

Common GND: Connect all component GNDs to Arduino GND.

VCC/Power: Connect sensors and driver VCC to Arduino 5V or appropriate power supply.

Code
The embedded C/C++ code for the Arduino Nano manages the entire level-based pump control logic.

You can find the source code in the src/ directory: src/aqua_purifier.ino

Getting Started (for Replication)
To set up and run this project:

Hardware Assembly: Connect the components as per the circuit diagram. Pay close attention to the motor driver/relay connections and the type/logic of your water level sensors.

Software Installation:

Download and install the Arduino IDE.

Connect your Arduino Nano to your computer via USB.

Upload Code:

Open the aqua_purifier.ino file in the Arduino IDE.

Go to Tools > Board and select Arduino Nano.

Go to Tools > Port and select the serial port corresponding to your Arduino Nano.

Click the "Upload" button (right arrow icon) in the Arduino IDE.

Testing: Place the sensors in your containers and observe the pump's behavior. Use the Serial Monitor (Tools > Serial Monitor) to view status messages.

Skills Demonstrated
This project effectively showcases skills relevant to embedded systems, IoT, and automation:

Embedded C/C++ Programming: Core development on a microcontroller.

Microcontroller Interfacing: Working directly with Arduino Nano pins for input/output.

Sensor Integration: Successfully interfacing and reading data from water level sensors.

Actuator Control: Controlling a water pump via a motor driver/relay.

Automation Logic: Implementing conditional control based on sensor inputs.

Basic Electronics & Circuit Design: Understanding component connections and power requirements.

Problem Solving: Designing a solution for automated water management.

Prototyping: Building and testing a functional hardware-software system.

Conceptual IoT: Laying the foundation for connected device applications.

License
This project is open-sourced under the MIT License.