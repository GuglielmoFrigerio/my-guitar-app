/*
  ==============================================================================

    StringComponent.h
    Created: 20 Apr 2024 5:24:44pm
    Author:  gugli

  ==============================================================================
*/

#pragma once

#include "NoteNameFactory.h"
#include "FretComponent.h"

//==============================================================================
/*
*/
class StringComponent  : public juce::Component
{
public:
    StringComponent(int fretCount, int startingMidiNoteNumber, std::shared_ptr<INoteNameFactory> noteNameFactoryPtr);
    ~StringComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    void setActive(int midiNoteNumber);
    void resetActive(int midiNoteNumber);

private:
    int m_startingMidiNoteNumber;
    std::vector<std::unique_ptr<FretComponent>> m_frets;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StringComponent)
};
