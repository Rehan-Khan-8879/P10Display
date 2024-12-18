#include <DMD.h>
#include <TimerOne.h>
#include <SPI.h>
#include <SystemFont5x7.h>

#define DISPLAYS_ACROSS 1   // Number of displays horizontally
#define DISPLAYS_DOWN 1     // Number of displays vertically

// Define pins for P10 module connections
#define A 2
#define B 3
#define C 4
#define S 5
#define L 6
#define R 7
#define G 8
#define D 9
#define OE 10

DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);

void ScanDMD() {
  dmd.scanDisplayBySPI();
}

void setup() {
  Timer1.initialize(5000);               // Timer setup for DMD refresh rate
  Timer1.attachInterrupt(ScanDMD);       // Attach the scan function
  dmd.clearScreen(true);                  // Clear display
}

void loop() {
  String message = "Hello, P10 World!  "; // Store the message in a variable
  dmd.selectFont(SystemFont5x7);         // Set the font

  // Display text with extra space for looping
  dmd.drawMarquee(message.c_str(), message.length(), (32 * DISPLAYS_ACROSS) - 1, 0);

  long lastScrollTime = millis();         // Store the last scroll time

  while (true) {                          // Continuous loop
    dmd.scanDisplayBySPI();               // Refresh the display
    dmd.stepMarquee(-1, 0);               // Move text from right to left
    
    // Check if 10 seconds have passed since the last scroll
    if (millis() - lastScrollTime >= 10000) {
      dmd.clearScreen(true);               // Clear the display
      dmd.drawMarquee(message.c_str(), message.length(), (32 * DISPLAYS_ACROSS) - 1, 0); // Reset marquee
      lastScrollTime = millis();           // Reset last scroll time
      delay(500);                           // Short delay before restarting
    }

    delay(50);                             // Adjust speed of scrolling
  }
}