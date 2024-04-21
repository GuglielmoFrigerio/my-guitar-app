/*
  ==============================================================================

    IMidiInputTarget.h
    Created: 21 Apr 2024 10:11:05am
    Author:  gugli

  ==============================================================================
*/

#pragma once
#include <cstdint>

class IMidiInputTarget {
public:
    virtual ~IMidiInputTarget() {}

    virtual void onNoteOn(int channel, int noteNumber, std::uint8_t velocity) = 0;
    virtual void onNoteOff(int channel, int noteNumber, std::uint8_t velocity) = 0;
};
