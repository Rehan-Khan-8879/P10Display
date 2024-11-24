// Include necessary libraries

#include <RF24.h>

// Define NRF24L01 pins and setup
RF24 radio(9, 10);
const byte address[6] = "00001";

// LCD setup


void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Initialize NRF24L01
  if (!radio.begin()) {
    while (1); // Halt if NRF24 initialization fails
  }
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();

}

void loop() {
  if (radio.available()) {
    char receivedData[32] = ""; // Buffer for incoming data
    radio.read(&receivedData, sizeof(receivedData)); // Read data
    // Got the data here
    Serial.println(receivedData);
  }
}