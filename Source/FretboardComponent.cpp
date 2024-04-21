/*
  ==============================================================================

    FretboardComponent.cpp
    Created: 21 Apr 2024 8:45:27am
    Author:  gugli

  ==============================================================================
*/

#include <JuceHeader.h>
#include "FretboardComponent.h"

//==============================================================================
FretboardComponent::FretboardComponent()
{
    auto numberOfFrets = 24;
    for (auto index = 0; index < 6; ++index) {
        auto stringComponentPtr = std::make_unique<StringComponent>(numberOfFrets);
        addAndMakeVisible(*stringComponentPtr);
        m_strings.push_back(std::move(stringComponentPtr));
    }
}

FretboardComponent::~FretboardComponent()
{
}

void FretboardComponent::paint (juce::Graphics& g)
{
}

void FretboardComponent::resized()
{
    auto localBounds = getLocalBounds();

    auto stringHeight = localBounds.getHeight() / m_strings.size();
    for (auto& stringCompPtr : m_strings) {
        auto rect = localBounds.removeFromTop(stringHeight);
        stringCompPtr->setBounds(rect);
    }
}
