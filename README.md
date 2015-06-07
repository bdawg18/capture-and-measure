# Capture and Measure - Fishackathon 2015

Problem Statement 15-9: "Develop a measuring board (or another system) that could automatically measure and record fish length."

[Fishtech Website](http://fishtech.azurewebsites.net/)

## Feature Stories

- It should be cheap, simple, and open source.
- It should water/saltwater resistant. (open leads can be coated in liquid plastic, etc)
- It should log the time, date and length results to a file.

## Limitations

- Only one fish can be measured at a time.
- Measuring distance dependant on padding between sensors. (due to sensor size there will be gaps)

## Research

- Simple example of LED used to detect light. http://playground.arduino.cc/Learning/LEDSensor
- Better example of LED sensor. http://www.instructables.com/id/LED-as-lightsensor-on-the-arduino/
- Another example of LED sensor. http://www.instructables.com/id/Light-Sensing-LEDs/
- Demonstration of photocell sensor. https://learn.adafruit.com/photocells/using-a-photocell
- Another idea for measurement with only two sensors, provided target is moving but not accelerating/decelerating. http://forum.arduino.cc/index.php?topic=268039.0

## Future iterations

- Hang a camera, or kinect-like device, over the measuring device to record an image of the catch and write to log. This could be used for record keeping and to ensure the device is being used correctly (ie sensors are not intentionally blocked to record a legal catch)
- Device could be improved to measure the weight of the fish.
- Device could be GPS aware and log location data.
- Device could be connected to the internet to report back catch results in real-time.
- Device could be intelligent enough to reject catches under a specific size. (Though even if the fish is released the mortality rate is probably low)

## Required Hardware

- Arduino Uno - Open source microcontroller (the brain; approximately $20-30)
- Photocells - Ambient light sensitive resistors. (small, low-power, inexpensive, and tough; approximately $0.75/each)
- LEDs - Light emitting diodes. (use to monitor photocell switches & act as state storage)
- Resistors & bulk wire.
- Breadboard for prototyping.

![Prototype](https://raw.githubusercontent.com/fishcloud/capture-and-measure/master/images/capture-and-measure.jpg)

## Schematic

See: `schematic.pdf`

## Software

See: `capture-and-measure.ino`



