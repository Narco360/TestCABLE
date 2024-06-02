#include <Arduino.h>
#include <Wire.h>

#define I2C_TEST 13 // Uncomment this if you want to test I2C communication
//#define R7mis 11  // Uncomment if R7 bypass reception is not soldered
//#define DB9_UART0 12 // Uncomment if using DB9 UART0 port for Serial

const int acapteur = 13;    // the number of the LED pin
const int usbpo = 38; 
const int RS485 = 37;   
const int txPin = 10;       // TX LED pin
const int rxPin = 11;       // RX LED pin

// SDA on pin 8
// SCL on pin 9

void printChipInfo(Stream &output = Serial); // Function prototype
void performI2CScan(); // Function prototype
void testCableConnectivity(); // Function prototype
void testCableVoltage(); // Function prototype

void setup() {
  delay(500);

  // Initialize LED pins and set them to low
  pinMode(acapteur, OUTPUT);
  digitalWrite(acapteur, LOW);
  pinMode(txPin, OUTPUT);
  digitalWrite(txPin, LOW);
  pinMode(rxPin, OUTPUT);
  digitalWrite(rxPin, LOW);
  
  #ifdef I2C_TEST
    Wire.begin(8, 9, 100000);
    Serial.begin(115200);
    Serial.println("\nI2C Scanner V1.0");
  #endif

  #ifdef DB9_UART0 // port DB9 !! in addition to the "classic" USB
    Serial2.begin(115200, SERIAL_8N1, 44, 43);   // Ensure RX GPIO43 and TX GPIO44 pins
    Serial.begin(115200);
  #else
    Serial.begin(115200);
  #endif
  delay(500);

  printChipInfo();
}

void loop() {
  #ifdef R7mis  // emit and receive => echo
    while (Serial.available()) {
      Serial.print(char(Serial.read()));
    }
  #endif

  #ifdef DB9_UART0 // on UART0
    printChipInfo(Serial2);
  #endif

  printChipInfo(Serial);

  #ifdef I2C_TEST
    performI2CScan();
  #endif

  testCableConnectivity();
  testCableVoltage();

  delay(1000); // Delay for 1 second before the next loop iteration
}

void printChipInfo(Stream &output) {
  output.print("Chip version: ");
  output.println(ESP.getChipRevision());
  output.print("Number of cores: ");
  output.println(ESP.getChipCores());
  output.print("Flash Chip Size: ");
  output.println(ESP.getFlashChipSize());
  output.print("Flash Chip Speed: ");
  output.println(ESP.getFlashChipSpeed());
  output.println("================================");
}

void performI2CScan() {
  byte error, address;
  int nDevices = 0;
  char c = '0';

  Serial.println("Type 1 to detect I2C devices or 2 to do nothing");
  c = Serial.read();

  if (c == '1') {
    Serial.println("Scanning...");
    for (address = 1; address < 127; address++) {
      Wire.beginTransmission(address);
      error = Wire.endTransmission();
      if (error == 0) {
        Serial.print("I2C device found at address 0x");
        if (address < 16) Serial.print("0");
        Serial.print(address, HEX);
        Serial.println("  !");
        nDevices++;
      } else if (error == 4) {
        Serial.print("Unknown error at address 0x");
        if (address < 16) Serial.print("0");
        Serial.println(address, HEX);
      }
    }
    if (nDevices == 0) Serial.println("No I2C devices found\n");
    else Serial.println("Done\n");
  } else if (c == '2') {
    Serial.println("No detection requested");
  }
  delay(500);
}

void testCableConnectivity() {
  // Test connectivity by blinking LEDs on TX and RX pins
  digitalWrite(txPin, HIGH);
  delay(100);
  digitalWrite(txPin, LOW);
  delay(100);
  
  digitalWrite(rxPin, HIGH);
  delay(100);
  digitalWrite(rxPin, LOW);
  delay(100);

  Serial.println("Cable connectivity test completed.");
}

void testCableVoltage() {
  // Measure and print the voltage on the USB port
  int sensorValue = analogRead(usbpo);
  float voltage = sensorValue * (3.3 / 4095.0) * 2; // Assuming a voltage divider for higher voltages
  Serial.print("USB Port Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  Serial.println("Cable voltage test completed.");
}
