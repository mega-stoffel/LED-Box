/* NeoPixel Stick - Examples
 * Adafruit NeoPixel Stick consists of 8x 5050 RGB WS2812B LEDs
 * http://adafruit.com/products/1426
 *
 * Connections:
 * D2 --- DIN
 * 3V3 -- 5VDC
 * G ---- GND (either)
 *
 * Adafruit recommendations:
 * - add a 1000uF capacitor across the power lines 5VDC and GND.
 * - add a 300-500 Ohm resistor on first pixel's data input DIN.
 * - avoid connecting on a live circuit... if you must, connect GND first.
 *
 * Dependencies:
 * https://github.com/adafruit/Adafruit_NeoPixel
 */

#include <Adafruit_NeoPixel.h>

// NeoPixel stick DIN pin
#define DIN_PIN D2

// How many NeoPixels on the stick?
#define NUM_PIXELS 10

// Third parameter:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream (NeoPixel Stick)
//   NEO_KHZ400  400 KHz bitstream for FLORA pixels
//   NEO_KHZ800  800 KHz bitstream for High Density LED strip (NeoPixel Stick)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, DIN_PIN, NEO_GRB + NEO_KHZ400);

int pause = 1000;

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.show(); // Start with all pixels off
  delay(pause);
}

void loop() {
  /*
  Serial.println("Color Wipe Red");
  colorWipe(strip.Color(255, 0, 0), 50);
  delay(pause);

  Serial.println("Color Wipe Green");
  colorWipe(strip.Color(0, 255, 0), 50);
  delay(pause);

  Serial.println("Color Wipe Blue");
  colorWipe(strip.Color(0, 0, 255), 50);
  delay(pause);

  Serial.println("Color Wipe White");
  colorWipe(strip.Color(255, 255, 255), 50);
  delay(pause);

  Serial.println("Color Wipe Cyan");
  colorWipe(strip.Color(0, 255, 255), 50);
  delay(pause);

  Serial.println("Color Wipe Magenta");
  colorWipe(strip.Color(255, 0, 255), 50);
  delay(pause);

  Serial.println("Color Wipe Yellow");
  colorWipe(strip.Color(255, 255, 0), 50);
  delay(pause);

  Serial.println("Color Wipe Black");
  colorWipe(strip.Color(0, 0, 0), 50);
  delay(pause);

  Serial.println("Theater Chase Red");
  theaterChase(strip.Color(127, 0, 0), 50);
  delay(pause);

  Serial.println("Theater Chase Green");
  theaterChase(strip.Color(0, 127, 0), 50);
  delay(pause);

  Serial.println("Theater Chase Blue");
  theaterChase(strip.Color(0, 0, 127), 50);
  delay(pause);

  Serial.println("Theater Chase White");
  theaterChase(strip.Color(127, 127, 127), 50);
  delay(pause);

  Serial.println("Random Colors");
  randomColors(100);
  delay(pause);

  Serial.println("Rainbow");
  rainbow(20);
  delay(pause);

  Serial.println("Rainbow Cycle");
  rainbowCycle(20);
  delay(pause);

 
  Serial.println("Theater Chase Rainbow");
  theaterChaseRainbow(50);
  delay(pause);
*/

  Serial.println("Merlin Fill");
  Merlin_L2R_Fill(500,127,0,0);
  delay(pause);

  Serial.println("Merlin Knight");
  Merlin_Knight(160,100,0,100,4);
  delay(pause);

  Serial.println("Merlin Knight Spur");
  Merlin_Knight_spur(120,100,100,0,8);
  delay(pause);

  Serial.println("Merlin Fill");
  Merlin_L2R_Fill(10,0,25,0);
  delay(pause);
  Serial.println("Merlin Fill");
  Merlin_L2R_Fill(200,0,50,0);
  delay(pause);
  Serial.println("Merlin Fill");
  Merlin_L2R_Fill(100,0,75,0);
  delay(pause);
  Serial.println("Merlin Fill");
  Merlin_L2R_Fill(50,0,100,0);
  delay(pause);

  Serial.println("Merlin Fill Marquee");
  Merlin_L2R_Marquee(500,0,127,0);
  delay(pause);

}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  uint16_t i;
  for(i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

void randomColors(uint8_t wait) {
  uint16_t i, j;
  for(j=0; j<50; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, strip.Color(random(0,255), random(0,255), random(0,255)));
    }
    strip.show();
    delay(wait);
  }
}

void Merlin_L2R_Fill(uint8_t wait, uint8_t rotAnteil, uint8_t gruenAnteil, uint8_t blauAnteil) {

  // Reihenfolge: 7 - 1&8 - 6 - 2&9 - 5 - 3&10 - 4
  // im Programm: 6 - 0&7 - 5 - 1&8 - 4 - 2&9 - 3
  
  strip.setPixelColor(6, rotAnteil,gruenAnteil,blauAnteil);
  strip.show();
  delay(wait);
  strip.setPixelColor(0, rotAnteil,gruenAnteil,blauAnteil);
  strip.setPixelColor(7, rotAnteil,gruenAnteil,blauAnteil);
  strip.show();
  delay(wait);
  strip.setPixelColor(5, rotAnteil,gruenAnteil,blauAnteil);
  strip.show();
  delay(wait);
  strip.setPixelColor(1, rotAnteil,gruenAnteil,blauAnteil);
  strip.setPixelColor(8, rotAnteil,gruenAnteil,blauAnteil);
  strip.show();
  delay(wait);
  strip.setPixelColor(4, rotAnteil,gruenAnteil,blauAnteil);
  strip.show();
  delay(wait);
  strip.setPixelColor(2, rotAnteil,gruenAnteil,blauAnteil);
  strip.setPixelColor(9, rotAnteil,gruenAnteil,blauAnteil);
  strip.show();
  delay(wait);
  strip.setPixelColor(3, rotAnteil,gruenAnteil,blauAnteil);
  strip.show();
  delay(wait);
}

void Merlin_L2R_Marquee(uint8_t wait, uint8_t rotAnteil, uint8_t gruenAnteil, uint8_t blauAnteil) {

  // Reihenfolge: 7 - 1&8 - 6 - 2&9 - 5 - 3&10 - 4
  // im Programm: 6 - 0&7 - 5 - 1&8 - 4 - 2&9 - 3
  
  strip.setPixelColor(6, rotAnteil,gruenAnteil,blauAnteil);
  strip.show();
  delay(wait);
  strip.setPixelColor(0, rotAnteil,gruenAnteil,blauAnteil);
  strip.setPixelColor(7, rotAnteil,gruenAnteil,blauAnteil);
  strip.show();
  delay(wait);
  strip.setPixelColor(5,rotAnteil,gruenAnteil,blauAnteil);
  strip.show();
  delay(wait);
  strip.setPixelColor(1, rotAnteil,gruenAnteil,blauAnteil);
  strip.setPixelColor(8, rotAnteil,gruenAnteil,blauAnteil);
  strip.setPixelColor(6, 0,0,0);
  strip.show();
  delay(wait);
  strip.setPixelColor(4, rotAnteil,gruenAnteil,blauAnteil);
  strip.setPixelColor(0, 0,0,0);
  strip.setPixelColor(7, 0,0,0);
  strip.show();
  delay(wait);
  strip.setPixelColor(2, rotAnteil,gruenAnteil,blauAnteil);
  strip.setPixelColor(9, rotAnteil,gruenAnteil,blauAnteil);
  strip.setPixelColor(5, 0,0,0);
  strip.show();
  delay(wait);
  strip.setPixelColor(3, rotAnteil,gruenAnteil,blauAnteil);
  strip.setPixelColor(1, 0,0,0);
  strip.setPixelColor(8, 0,0,0);
  strip.show();
  delay(wait);
  strip.setPixelColor(4, 0,0,0);
  strip.show();
  delay(wait);
  strip.setPixelColor(2, 0,0,0);
  strip.setPixelColor(9, 0,0,0);
  strip.show();
  delay(wait);
  strip.setPixelColor(3, 0,0,0);
  strip.show();
  delay(wait);
}

void Merlin_Knight(uint8_t wait, uint8_t rotAnteil, uint8_t gruenAnteil, uint8_t blauAnteil, uint8_t nochmal) {

  // Reihenfolge: 7 - 1&8 - 6 - 2&9 - 5 - 3&10 - 4
  // im Programm: 6 - 0&7 - 5 - 1&8 - 4 - 2&9 - 3

  strip.setPixelColor(0, 0,0,0);
  strip.setPixelColor(1, 0,0,0);
  strip.setPixelColor(2, 0,0,0);
  strip.setPixelColor(3, 0,0,0);
  strip.setPixelColor(4, 0,0,0);
  strip.setPixelColor(5, 0,0,0);
  strip.setPixelColor(6, 0,0,0);
  strip.setPixelColor(7, 0,0,0);
  strip.setPixelColor(8, 0,0,0);
  strip.setPixelColor(9, 0,0,0);
  strip.show();

  uint16_t j;

  for(j=0; j<nochmal; j++) {
    strip.setPixelColor(5,0,0,0);
    strip.setPixelColor(6, rotAnteil,gruenAnteil,blauAnteil);
    strip.show();
    delay(wait);
    strip.setPixelColor(6,0,0,0);
    strip.setPixelColor(5, rotAnteil,gruenAnteil,blauAnteil);
    strip.show();
    delay(wait);
    strip.setPixelColor(5,0,0,0);
    strip.setPixelColor(4, rotAnteil,gruenAnteil,blauAnteil);
    strip.show();
    delay(wait);
    strip.setPixelColor(4,0,0,0);
    strip.setPixelColor(3, rotAnteil,gruenAnteil,blauAnteil);
    strip.show();
    delay(wait);
    strip.setPixelColor(3,0,0,0);
    strip.setPixelColor(4, rotAnteil,gruenAnteil,blauAnteil);
    strip.show();
    delay(wait);
    strip.setPixelColor(4,0,0,0);
    strip.setPixelColor(5, rotAnteil,gruenAnteil,blauAnteil);
    strip.show();
    delay(wait);
  }
  strip.setPixelColor(5,0,0,0);
  strip.show();
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

void Merlin_Knight_spur(uint8_t wait, uint8_t rotAnteil, uint8_t gruenAnteil, uint8_t blauAnteil, uint8_t nochmal) {

  // Reihenfolge: 7 - 1&8 - 6 - 2&9 - 5 - 3&10 - 4
  // im Programm: 6 - 0&7 - 5 - 1&8 - 4 - 2&9 - 3

  strip.setPixelColor(0, 0,0,0);
  strip.setPixelColor(1, 0,0,0);
  strip.setPixelColor(2, 0,0,0);
  strip.setPixelColor(3, 0,0,0);
  strip.setPixelColor(4, 0,0,0);
  strip.setPixelColor(5, 0,0,0);
  strip.setPixelColor(6, 0,0,0);
  strip.setPixelColor(7, 0,0,0);
  strip.setPixelColor(8, 0,0,0);
  strip.setPixelColor(9, 0,0,0);
  strip.show();

  uint16_t j;

  for(j=0; j<nochmal; j++) {
    strip.setPixelColor(5,0,0,0);
    strip.setPixelColor(6, rotAnteil,gruenAnteil,blauAnteil);
    strip.show();
    delay(wait);
    strip.setPixelColor(6, rotAnteil/4,gruenAnteil/4,blauAnteil/4);
    strip.setPixelColor(5, rotAnteil,gruenAnteil,blauAnteil);
    strip.show();
    delay(wait);
    strip.setPixelColor(6,0,0,0);
    strip.setPixelColor(5, rotAnteil/4,gruenAnteil/4,blauAnteil/4);
    strip.setPixelColor(4, rotAnteil,gruenAnteil,blauAnteil);
    strip.show();
    delay(wait);
    strip.setPixelColor(5,0,0,0);
    strip.setPixelColor(4, rotAnteil/4,gruenAnteil/4,blauAnteil/4);
    strip.setPixelColor(3, rotAnteil,gruenAnteil,blauAnteil);
    strip.show();
    delay(wait);
    strip.setPixelColor(4,0,0,0);
    strip.show();
    strip.setPixelColor(3, rotAnteil/4,gruenAnteil/4,blauAnteil/4);
    strip.setPixelColor(4, rotAnteil,gruenAnteil,blauAnteil);
    strip.show();
    delay(wait);
    strip.setPixelColor(3,0,0,0);
    strip.setPixelColor(4, rotAnteil/4,gruenAnteil/4,blauAnteil/4);
    strip.setPixelColor(5, rotAnteil,gruenAnteil,blauAnteil);
    strip.show();
    delay(wait);
    strip.setPixelColor(4,0,0,0);
    strip.setPixelColor(5, rotAnteil/4,gruenAnteil/4,blauAnteil/4);
    strip.setPixelColor(6, rotAnteil,gruenAnteil,blauAnteil);
    strip.show();
    delay(wait);
    strip.setPixelColor(5,0,0,0);
    strip.show();
  }
  strip.setPixelColor(5,0,0,0);
  strip.setPixelColor(4,0,0,0);
}


//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  uint16_t j, q, i;
  for (j=0; j<10; j++) {  //do 10 cycles of chasing
    for (q=0; q < 3; q++) {
      for (i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  uint16_t j, q, i;
  for (j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (q=0; q < 3; q++) {
      for (i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
