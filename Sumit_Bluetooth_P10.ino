#include <DMD.h>
#include <TimerOne.h>
#include <SPI.h>
#include <SystemFont5x7.h>

#define WIDTH 3  // Number of P10 modules horizontally
#define HEIGHT 1 // Number of P10 modules vertically

DMD dmd(WIDTH, HEIGHT);
String message = "";  // Variable to store received message
bool newMessage = false;  // Flag to check for new messages

void ScanDMD() {
  dmd.scanDisplayBySPI();
}

void setup() {

  Serial.begin(9600);   // Initialize serial communication for HC-05
  Timer1.initialize(5000);
  Timer1.attachInterrupt(ScanDMD);
  dmd.clearScreen(true);  // Clear display at start
}

void loop() {
  if (Serial.available() > 0) {
    message = Serial.readString();  // Read the entire incoming message
    newMessage = true;  // Set flag to display the new message
  }

  if (newMessage) {
    displayMessage(message);
    newMessage = false;  // Reset flag after displaying
  }
}

void displayMessage(String msg) {
  dmd.clearScreen(true);  // Clear display for new message
  dmd.selectFont(System5x7);
  dmd.drawMarquee(msg.c_str(), msg.length(), (32 * WIDTH) - 1, 0);

  // Display message indefinitely until new message arrives
  while (!Serial.available()) {  // Loop until a new message is received
    dmd.stepMarquee(-1, 0);
    delay(50);  // Adjust speed of scrolling
  }
}