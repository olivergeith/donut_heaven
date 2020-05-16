// This is a demonstration on how to use an input device to trigger changes on your neo pixels.
// You should wire a momentary push button to connect from ground to a digital IO pin.  When you
// press the button it will change to a new pixel animation.  Note that you need to press the
// button once to start the first animation!

#include <Adafruit_NeoPixel.h>

#include "DonutHeaven.h"

// Parameter 1 = number of pixels in strip,  neopixel stick has 8
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream, correct for neopixel stick
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip), correct for neopixel stick

Adafruit_NeoPixel donutHeavenStrip = Adafruit_NeoPixel(19, 6, NEO_GRB + NEO_KHZ800);
DonutHeaven donutHeaven(donutHeavenStrip);

int millies = 0;
int deltaMillies = 25;

void setup() {

	millies = 0;

	donutHeavenStrip.setBrightness(255);
	donutHeavenStrip.begin();
	donutHeavenStrip.show(); // Initialize all pixels to 'off'

}

void loop() {
	millies = millies + deltaMillies;

	if (millies >= 10000)
		millies = 0;

	drawDonutHeaven();
	delay(deltaMillies);
}

int donutMode = 7;

void drawDonutHeaven() {

	switch (donutMode) {
	default:
	case 0:
		donutHeaven.drawLetterLauflichtSmooth(millies);
		break;
	case 1:
		donutHeaven.drawFlashingDonut(millies);
		break;
	case 2:
		donutHeaven.drawWheelAllColors(millies);
		break;
	case 3:
		donutHeaven.drawBarGraphWheeled(millies);
		break;
	case 4:
		donutHeaven.drawLauflichtRandomColor(millies);
		break;
	case 5:
		donutHeaven.drawWheelAllColors(millies);
		break;
	case 6:
		donutHeaven.drawWheelColorful(6);
		break;
	case 7:
		donutHeaven.drawBarGraphWheeledColorfull(millies);
		break;

	}
	if (millies == 0) {
		donutMode++;
		if (donutMode == 8)
			donutMode = 0;
	}

}

