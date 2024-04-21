/*
  ==============================================================================

    FretboardComponent.h
    Created: 21 Apr 2024 8:45:27am
    Author:  gugli

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "StringComponent.h"
#include "TriplePlayConnect.h"
#include "IMidiInputTarget.h"

//==============================================================================
/*
*/
class FretboardComponent  : public juce::Component, public IMidiInputTarget
{
public:
    FretboardComponent();
    ~FretboardComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:    // implementation
    void onNoteOn(int channel, int noteNumber, std::uint8_t velocity) override;
    void onNoteOff(int channel, int noteNumber, std::uint8_t velocity) override;

private:    // fields
    std::vector<int> m_startingMidiNoteNumbers{ 64, 59, 55, 50, 45, 40 };
    std::vector<std::unique_ptr<StringComponent>> m_strings;
    std::unique_ptr<TriplePlayConnect> m_triplePlayConnectPtr;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FretboardComponent)
};
