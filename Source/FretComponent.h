/*
  ==============================================================================

    FretComponent.h
    Created: 20 Apr 2024 6:14:51pm
    Author:  gugli

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class FretComponent  : public juce::Component
{
public:
    FretComponent(const char *name, int midiNoteNumber);
    ~FretComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    static std::tuple<int, int> getWidthAndStart(int fretNumber, int numberOfFrets, float componentWidth);

    void setActive();
    void resetActive();

private:
    static float getStringLength(int fretNumber, float componentWidth);

private:    // fields
    int m_midiNoteNumber;
    juce::String m_name;
    bool m_active = false;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FretComponent)
};
