#include <iostream>
#include <assert.h>
#include "main.h"
#include <fstream>
#include <iomanip>

void testNumberToPair(int pairNumber,
    TelCoColorCoder::MajorColor expectedMajor,
    TelCoColorCoder::MinorColor expectedMinor)
{
    TelCoColorCoder::ColorPair colorPair =
        TelCoColorCoder::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(
    TelCoColorCoder::MajorColor major,
    TelCoColorCoder::MinorColor minor,
    int expectedPairNumber)
{
    int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

void printColorCodeManualRef(const std::string &filename) {
    std::ofstream manual(filename);
    manual << "Color Code Reference Manual\n";
    manual << "--------------------------------\n";

    for(int major = 0; major < TelCoColorCoder::numberOfMajorColors; ++major) {
        for(int minor = 0; minor < TelCoColorCoder::numberOfMinorColors; ++minor) {
            TelCoColorCoder::ColorPair colorPair(static_cast<TelCoColorCoder::MajorColor>(major),
                                                 static_cast<TelCoColorCoder::MinorColor>(minor));
            int pairNumber = TelCoColorCoder::GetPairNumberFromColor(static_cast<TelCoColorCoder::MajorColor>(major),
                                                                     static_cast<TelCoColorCoder::MinorColor>(minor));
            manual << "Pair Number: " << std::setw(2) << pairNumber << " -> " << colorPair.ToString() << "\n";
        }
    }

    manual.close();
    std::cout << "Reference manual generated: " << filename << std::endl;
}

int main() {
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);

     printColorCodeManualRef("ColorCodeReferenceManual.txt");

    return 0;
}
