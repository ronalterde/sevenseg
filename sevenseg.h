#include <cstdint>

class SevenSegmentDecoderOne {
public:
	static uint8_t decode(uint8_t input) {
		switch(input) {
		case 0:
			return 0b00111111;
		case 1:
			return 0b00000110;
		case 2:
			return 0b01011011;
		case 3:
			return 0b01001111;
		case 4:
			return 0b01100110;
		case 5:
			return 0b01101101;
		case 6:
			return 0b01111101;
		case 7:
			return 0b00000111;
		case 8:
			return 0b01111111;
		case 9:
			return 0b01101111;
		default:
			return 0;
		}
	}
};

class SevenSegmentDecoderTwo {
public:
	static uint8_t decode(uint8_t input) {
		bool A = input & 0x01;
		bool B = input & 0x02;
		bool C = input & 0x04;
		bool D = input & 0x08;

		bool a = (!A | B | C | D) & (A | B | !C | D);
		bool b = (!A | B | !C | D) & (A | !B | !C | D);
		bool c = A | !B | C | D;
		bool d = (!A | B | C | D) & (A | B | !C | D) & (!A| !B | !C | D);
		bool e = (!A & !B & !C & !D) | (!A & B & !C & !D) | (!A & B & C & !D) | (!A & !B & !C & D);
		bool f = (!A | B | C | D) & (A | !B | C | D) & (!A | !B | C | D) & (!A | !B | !C | D);
		bool g = (A | B | C | D) & (!A | B | C | D) & (!A | !B | !C | D);

		return (a | (b<<1) | (c<<2) | (d<<3) | (e<<4) | (f<<5) | (g<<6));
	}
};

