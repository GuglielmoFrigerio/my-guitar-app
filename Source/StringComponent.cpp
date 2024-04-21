/*
  ==============================================================================

    StringComponent.cpp
    Created: 20 Apr 2024 5:24:44pm
    Author:  gugli

  ==============================================================================
*/

#include <JuceHeader.h>
#include "StringComponent.h"

//==============================================================================
StringComponent::StringComponent(int fretCount, int startingMidiNoteNumber)
{
    for (auto index = 1; index <= fretCount; ++index) {
        auto name = std::to_string(index);
        m_frets.push_back(std::make_unique<FretComponent>(name.c_str(), startingMidiNoteNumber));
        startingMidiNoteNumber++;
    }

    for (auto& fret : m_frets) {
        addAndMakeVisible(*fret);
    }
}

StringComponent::~StringComponent()
{
}

void StringComponent::paint (juce::Graphics& g)
{
}

void StringComponent::resized()
{
    auto localBounds = getLocalBounds();
    auto initialWidth = localBounds.getWidth();
    for (auto index = 1; index <= m_frets.size(); ++index) {
        auto [width, start] = FretComponent::getWidthAndStart(index, m_frets.size(), initialWidth);
        auto fretRect = localBounds.removeFromLeft(width);
        auto& fret = m_frets[index - 1];
        fret->setBounds(fretRect);
    }
}
