#ifndef DigitLedDisplay_h
#define DigitLedDisplay_h

#if (defined(__AVR__))
#include <avr/pgmspace.h>
#else
#include <pgmspace.h>
#endif

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

const static byte decimalMask = B10000000;
const static byte numTable [] PROGMEM = {
    B01111110, // 0
	B00110000, // 1
	B01101101, // 2
	B01111001, // 3
	B00110011, // 4
	B01011011, // 5
	B01011111, // 6
	B01110000, // 7
	B01111111, // 8
	B01111011, // 9
};

const static byte charTable [] PROGMEM = {
	B01110111, // A
	B01111111, // B
	B01001110, // C
	B01111110, // D
	B01001111, // E
	B01000111, // F
	B01011111, // G
	B00110111, // H
	B00110000, // I
	B00111000, // J
	B00110111, // K
	B00001110, // L
	B01111111, // M
	B01111111, // N
	B01111110, // O
	B01100111, // P
	B11111110, // Q
	B00110111, // R
	B01011011, // S
	B00001111, // T
	B00111011, // U
	B00111011, // V
	B01111111, // W
	B00110111, // X
	B00110011, // Y
	B01101101, // Z
};

const static byte symbolTable [] PROGMEM = {
	B00000001, // -
};

class DigitLedDisplay
{
	private:
		int DIN_PIN;
		int CS_PIN;
		int CLK_PIN;
		int _digitLimit;
		void table(byte address, int val);
		void table(byte address, char character);

	public:
		DigitLedDisplay(int dinPin, int csPin, int clkPin);
		void setBright(int brightness);
		void setDigitLimit(int limit);
		void printInt(long number, byte startDigit = 0);
		void printFloat(double number, byte startDigit = 0);
		void printChar(char character, byte startDigit = 0);
		void printString(String str, byte startDigit = 0);
		void write(byte address, byte data);
		void clear();
		void on();
		void off();		
};

#endif	//DigitLedDisplay.h
