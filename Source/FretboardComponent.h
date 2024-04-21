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

//==============================================================================
/*
*/
class FretboardComponent  : public juce::Component
{
public:
    FretboardComponent();
    ~FretboardComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    std::vector<std::unique_ptr<StringComponent>> m_strings;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FretboardComponent)
};
