Welcome, Arduino enthusiasts and all! Today, we're diving into the world of temperature sensing with a fun project that not only measures water temperature but also provides a visual indicator using LEDs. By the end of this guide, you'll have an NTC thermistor based water temperature thermometer that lights up red for hot, blue for cold, and green for medium temperatures. Let's get started!

## What You'll Need:

- NTC (Negative Temperature Coefficient) thermistor
- Arduino microcontroller board (such as Arduino Uno)
- Three LEDs (Red, Blue, Green)
- Resistors (220 ohms for each LED)
- Jumper wires (make sure to have two longer ones!)
- Soldering Iron and solder
- Breadboard
- Heat shrink (and a heat source, like a hair-dryer!)

## Step 1: Circuit Setup

### Connect the LEDs:
Place the LEDs on the breadboard and connect each one to the Arduino board using jumper wires. Remember to insert a 220-ohm resistor in series with each LED to limit the current and protect them from burning out.

### Wire the NTC Thermistor: 
Connect one end of the NTC thermistor to the 5V pin on the Arduino board. Connect the other end to an analog pin (e.g., A0). To create a voltage divider circuit, connect a resistor (10k ohms) from the analog pin to the ground (GND) pin on the Arduino board. The resulting wiring should follow the image below:

![](https://github.com/NeatPatel/temperature-sensor/blob/main/images/arduino_schematic.png?raw=true)

## Step 2: Code Implementation

Now, let's write the Arduino code to read the temperature from the NTC thermistor and control the LEDs accordingly. Here's a basic example to get you started:

```c
const int thermistorPin = A0;
const int redLedPin = 2;
const int blueLedPin = 3;
const int greenLedPin = 4;

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(thermistorPin);
  float voltage = sensorValue * (5.0 / 1023.0); // Convert analog reading to voltage
  float resistance = (5.0 * 10000.0) / voltage - 10000.0; // Calculate resistance of the thermistor
  float temperature = 1.0 / (log(resistance / 10000.0) / 3950.0 + 1.0 / 298.15) - 273.15; // Calculate temperature in Celsius
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  if (temperature >= 30) {
    digitalWrite(redLedPin, HIGH); // Red for hot
    digitalWrite(blueLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
  } else if (temperature <= 15) {
    digitalWrite(redLedPin, LOW);
    digitalWrite(blueLedPin, HIGH); // Blue for cold
    digitalWrite(greenLedPin, LOW);
  } else {
    digitalWrite(redLedPin, LOW);
    digitalWrite(blueLedPin, LOW);
    digitalWrite(greenLedPin, HIGH); // Green for medium
  }
  
  delay(1000); // Delay for readability
}
```

## Step 3: Testing and Calibration

Upload the code to your Arduino board and immerse the NTC thermistor in water of different temperatures. Observe how the LEDs change color based on the temperature readings.

For more accurate readings, you may need to calibrate the sensor by adjusting the temperature thresholds in the code according to your specific NTC thermistor's characteristics. It can be a good idea to create visuals for the data, for example by making a graph to analyze the data with a line of best fit as shown below:

![](https://github.com/NeatPatel/temperature-sensor/blob/main/images/detector_graph.png?raw=true)

> This graph uses variating voltage readings to see the temperature differences, and can use its line of prediction to adjust its readings

## Step 4: Encasing using heat shrink

To protect your NTC thermistor wire from water, we will be encasing the wire in a water-resistant insulation known as heat shrink. 
- Take the two long jumper wires, and use electrical tape and solder to combine them with the ends of the NTC thermistor. 
- Take two pieces of heat shrink and put them over the NTC thermistor wires, covering them completely from water.
- Use the hair dryer to shrink the heat shrink into place, and then attach the loose ends of the jumper wires to the breadboard where the NTC thermistor should connect.
- The result device should look as follows:

![](https://github.com/NeatPatel/temperature-sensor/blob/main/images/final_detector.png?raw=true)

## Conclusion

Congratulations! You've successfully created a DIY NTC thermistor water temperature sensor that indicates temperature using LEDs. This project opens up endless possibilities for monitoring temperature in various applications, from aquariums to hot tubs. Feel free to experiment with different LED colors or add more features to suit your needs. Happy tinkering!
