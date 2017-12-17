#include "sevenseg.h"
#include "gtest/gtest.h"

#define DECODER SevenSegmentDecoderOne
// #define DECODER SevenSegmentDecoderTwo

TEST(SevenSegmentDecoderTest, resemblesTruthTable) {
// 				  -gfedcba	
	ASSERT_EQ(	0b00111111, DECODER::decode(0));
	ASSERT_EQ(	0b00000110, DECODER::decode(1));
	ASSERT_EQ(	0b01011011, DECODER::decode(2));
	ASSERT_EQ(	0b01001111, DECODER::decode(3));
	ASSERT_EQ(	0b01100110, DECODER::decode(4));
	ASSERT_EQ(	0b01101101, DECODER::decode(5));
	ASSERT_EQ(	0b01111101, DECODER::decode(6));
	ASSERT_EQ(	0b00000111, DECODER::decode(7));
	ASSERT_EQ(	0b01111111, DECODER::decode(8));
	ASSERT_EQ(	0b01101111, DECODER::decode(9));
}
