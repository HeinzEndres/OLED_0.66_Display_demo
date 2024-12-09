#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Description:
//    Small demo code for a 0.66" display and serial output.
//
// History:
//   v1.0    MS      9-Dec-24     First implementation
//   v2.0    HE      9-Dec-24     Added serial output and counting
//
// Board used:
//   Lolin C3 Mini from "esp32" Espressif Systems boards v 2.0.9.
// Libraries required:
//    Adafruit_BusIO v1.16.2
//    ARDUINO_LOLIN_C3_MINIAdafruit GFX Library v1.11.11
//    Adafruit SSD1306 v2.5.13

// Define OLED display dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
// Note: For small display version 0.66" with 64x48 pixels the visible rectangle is (32,16) -> (95,63)!

// Create the SSD1306 display instance (I2C connection)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

void drawClearAndDrawBorder () {
  display.clearDisplay();
  for(int i=32;i<=95;++i) display.drawPixel(i, 16, SSD1306_WHITE);
  for(int i=16;i<=63;++i) display.drawPixel(32, i, SSD1306_WHITE);
  for(int i=32;i<=95;++i) display.drawPixel(i, 63, SSD1306_WHITE);
  for(int i=16;i<=63;++i) display.drawPixel(95, i, SSD1306_WHITE);
}

void setup()
{
   // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  delay(500); // wait for serial to start
  Serial.println("Serial connection started!");

  // Initialize the display
  if (!display.begin(SSD1306_PAGEADDR, 0x3C))
  {
    Serial.println("SSD1306 allocation failed");
    while (1) {}; // Halt if initialization failed
  }
}

int i = 0;
void loop() {
  // Serial output
  Serial.print("Count: ");
  Serial.println(i);
  // Display output
  drawClearAndDrawBorder();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(37,35);
  display.println(i++);
  display.display();
  // ...and delay 1 sec
  delay(1000); 
}
