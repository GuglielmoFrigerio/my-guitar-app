/*
  ==============================================================================

    GraphicTestComponent.h
    Created: 20 Apr 2024 5:16:36pm
    Author:  gugli

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "StringComponent.h"

//==============================================================================
/*
*/
class GraphicTestComponent  : public juce::Component
{
public:
    GraphicTestComponent();
    ~GraphicTestComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    StringComponent m_stringComponent;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GraphicTestComponent)
};
