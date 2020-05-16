/*
 * DonutHeaven.cpp
 *
 *  Created on: 11.02.2016
 *      Author: Oliver
 */

#include "DonutHeaven.h"

DonutHeaven::DonutHeaven(Adafruit_NeoPixel strip) {
	this->strip = strip;
	init();
}

DonutHeaven::~DonutHeaven() {
	// TODO Auto-generated destructor stub
}

void DonutHeaven::init() {
	animating = false;
	animationStep = 0;
	lauflichtStep = 0;
	laufLichtColor = getColorRed(255);
	max = strip.numPixels();

}

int inkr = 24;
int bright = 0;
void DonutHeaven::drawFlashingDonut(int millies) {

	bright = bright + inkr;
	if (bright > 255) {
		inkr = -64;
		bright = 255;
	}
	if (bright < 0) {
		inkr = 24;
		bright = 0;
	}

	for (int i = 0; i < anzLetters; i++) {
		for (int i = 0; i < strip.numPixels(); i++) {
			strip.setPixelColor(i, strip.Color(0, 0, 0));
		}
	}

//	if (animating) {
	drawLetter(1, getColorRed(bright));

//	}
	animating = !animating;
	strip.show();
}

void DonutHeaven::drawWheel(int step) {
	animationStep = animationStep + step;
	if (animationStep >= 256)
		animationStep = 0;
	for (int i = 0; i < strip.numPixels(); i++) {
		strip.setPixelColor(i, Wheel(animationStep));
	}
	strip.show();
}

void DonutHeaven::drawWheelColorful(int step) {
	animationStep = animationStep + step;
	if (animationStep >= 256)
		animationStep = 0;
	for (int i = 0; i < strip.numPixels(); i++) {
		strip.setPixelColor(i, Wheel(animationStep));
	}
	strip.show();
}

void DonutHeaven::drawWheelAllColors(int millies) {
	animationStep = animationStep + 4;
	if (animationStep >= 256)
		animationStep = 0;
	for (int i = 0; i < strip.numPixels(); i++) {
		strip.setPixelColor(i,
				Wheel(animationStep + i * 256 / strip.numPixels() / 3));
	}
	strip.show();
}

void DonutHeaven::drawLauflichtRandomColor(int millies) {
	if (millies % 50 == 0) {
		if (lauflichtStep == strip.numPixels()) {
			lauflichtStep = 0;
			laufLichtColor = getRandomColor(255);
		}
		for (int i = 0; i < strip.numPixels(); i++) {
			if (i == lauflichtStep || i == lauflichtStep - 1) {
				strip.setPixelColor(i, laufLichtColor);
			} else {
				strip.setPixelColor(i, 0, 0, 0);
			}
		}
		lauflichtStep = lauflichtStep + 1;
		strip.show();
	}
}

void DonutHeaven::drawLetterLauflicht(int millies) {
	if (millies % 75 == 0) {
		if (lauflichtStep == anzLetters) {
			lauflichtStep = 0;
			init();
		}
		for (int i = 0; i < anzLetters; i++) {
			if (i == lauflichtStep) {
				drawLetterColored(i);
			} else {
				drawLetter(i, strip.Color(0, 0, 0));
			}
		}
		lauflichtStep = lauflichtStep + 1;
		strip.show();
	}
}
void DonutHeaven::drawLetterLauflichtSmooth(int millies) {
	if (millies % 75 == 0) {
		if (lauflichtStep == strip.numPixels()) {
			lauflichtStep = 0;
			init();
		}
		for (int i = 0; i < strip.numPixels(); i++) {
			if (i < lauflichtStep) {
				strip.setPixelColor(i, getColorForStripIndex(i));
			} else {
				strip.setPixelColor(i, strip.Color(0, 0, 0));
			}
		}
		lauflichtStep = lauflichtStep + 1;
		strip.show();
	}
}

void DonutHeaven::drawLetter(int index, uint32_t color) {
	switch (index) {
	default:
	case 0: // D
		strip.setPixelColor(0, color);
		strip.setPixelColor(1, color);
		break;
	case 1: // O
		strip.setPixelColor(2, color);
		strip.setPixelColor(3, color);
		strip.setPixelColor(4, color);
		strip.setPixelColor(5, color);
		break;
	case 2: // n
		strip.setPixelColor(6, color);
		strip.setPixelColor(7, color);
		break;
	case 3: // u
		strip.setPixelColor(8, color);
		break;
	case 4: // t
		strip.setPixelColor(9, color);
		break;
	case 5: // H
		strip.setPixelColor(10, color);
		strip.setPixelColor(11, color);
		break;
	case 6: // e
		strip.setPixelColor(12, color);
		break;
	case 7: // a
		strip.setPixelColor(13, color);
		strip.setPixelColor(14, color);
		break;
	case 8: // v
		strip.setPixelColor(15, color);
		break;
	case 9: // e
		strip.setPixelColor(16, color);
		break;
	case 10: //n
		strip.setPixelColor(17, color);
		strip.setPixelColor(18, color);
		break;
	}
}

void DonutHeaven::drawLetterColored(int index) {
	int lettercolor = 144;
	switch (index) {
	default:
	case 0: // D
		strip.setPixelColor(0, Wheel(lettercolor));
		strip.setPixelColor(1, Wheel(lettercolor));
		break;
	case 1: // O
		strip.setPixelColor(2, Wheel(0));
		strip.setPixelColor(3, Wheel(0));
		strip.setPixelColor(4, Wheel(0));
		strip.setPixelColor(5, Wheel(0));
		break;
	case 2: // n
		strip.setPixelColor(6, Wheel(lettercolor));
		strip.setPixelColor(7, Wheel(lettercolor));
		break;
	case 3: // u
		strip.setPixelColor(8, Wheel(lettercolor));
		break;
	case 4: // t
		strip.setPixelColor(9, Wheel(lettercolor));
		break;
	case 5: // H
		strip.setPixelColor(10, Wheel(lettercolor));
		strip.setPixelColor(11, Wheel(lettercolor));
		break;
	case 6: // e
		strip.setPixelColor(12, Wheel(lettercolor));
		break;
	case 7: // a
		strip.setPixelColor(13, Wheel(lettercolor));
		strip.setPixelColor(14, Wheel(lettercolor));
		break;
	case 8: // v
		strip.setPixelColor(15, Wheel(lettercolor));
		break;
	case 9: // e
		strip.setPixelColor(16, Wheel(lettercolor));
		break;
	case 10: //n
		strip.setPixelColor(17, Wheel(lettercolor));
		strip.setPixelColor(18, Wheel(lettercolor));
		break;
	}
}

uint32_t DonutHeaven::getColorForLetter(int index) {
	int lettercolor = 144;
	switch (index) {
	default:
	case 0: // D
		return Wheel(lettercolor);
	case 1: // O
		return Wheel(0);
	}
}
uint32_t DonutHeaven::getColorForStripIndex(int index) {
	int lettercolor = 156;
	switch (index) {
	default:
	case 0:
		return Wheel(lettercolor);
	case 2: // O
	case 3: // O
	case 4: // O
	case 5: // O
		return Wheel(0);
	}
}

void DonutHeaven::drawBarGraphWheeled(int millies) {
	if (millies % 100 == 0) {
		if (lauflichtStep == strip.numPixels()) {
			lauflichtStep = 0;
			laufLichtColor = laufLichtColor + 16;
			if (laufLichtColor >= 256)
				laufLichtColor = 0;
		}
		for (int i = 0; i < strip.numPixels(); i++) {
			if (i <= lauflichtStep) {
				strip.setPixelColor(i, Wheel(laufLichtColor));
			} else {
				strip.setPixelColor(i, 0, 0, 0);
			}
		}
		lauflichtStep = lauflichtStep + 1;
		strip.show();
	}
}

void DonutHeaven::drawBarGraphWheeledColorfull(int millies) {
	if (millies % 100 == 0) {
		int center = strip.numPixels() / 2 + 1;
		if (lauflichtStep == center) {
			lauflichtStep = 0;
			laufLichtColor = laufLichtColor + 16;
			if (laufLichtColor >= 256)
				laufLichtColor = 0;
		}
		for (int i = 0; i < strip.numPixels(); i++) {
			if (i <= lauflichtStep || i >= strip.numPixels() - lauflichtStep) {
				strip.setPixelColor(i, Wheel(laufLichtColor + i * 4));
			} else {
				strip.setPixelColor(i, 0, 0, 0);
			}
		}
		lauflichtStep = lauflichtStep + 1;
		strip.show();
	}
}

uint32_t DonutHeaven::getRandomColor(int brightness) {
	return Wheel(random(256));
}

uint32_t DonutHeaven::getColorRotGelbGruen(int color) {
	switch (color) {
	default:
	case 0:
		return Wheel(0);
	case 1:
		return Wheel(16);
	case 2:
		return Wheel(64);

	}
}

uint32_t DonutHeaven::getColorRed(int brightness) {
	return strip.Color(brightness, 0, 0);
}

uint32_t DonutHeaven::getColorWhite(int brightness) {
	return strip.Color(brightness, brightness, brightness);
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t DonutHeaven::Wheel(byte WheelPos) {
	WheelPos = 255 - WheelPos;
	if (WheelPos < 85) {
		return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
	}
	if (WheelPos < 170) {
		WheelPos -= 85;
		return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
	}
	WheelPos -= 170;
	return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
