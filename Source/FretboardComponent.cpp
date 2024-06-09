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
        auto stringComponentPtr = std::make_unique<StringComponent>(numberOfFrets, m_startingMidiNoteNumbers[index]);
        addAndMakeVisible(*stringComponentPtr);
        m_strings.push_back(std::move(stringComponentPtr));
    }

    m_triplePlayConnectPtr = std::make_unique<TriplePlayConnect>(this);
}

FretboardComponent::~FretboardComponent()
{
}

void FretboardComponent::paint (juce::Graphics& /* g */)
{
}

void FretboardComponent::resized()
{
    auto localBounds = getLocalBounds();

    auto stringHeight = localBounds.getHeight() / int(m_strings.size());
    for (auto& stringCompPtr : m_strings) {
        auto rect = localBounds.removeFromTop(stringHeight);
        stringCompPtr->setBounds(rect);
    }
}

int FretboardComponent::getIdealHeight(int width) const
{
    return int(width / m_aspectRatio);
}

void FretboardComponent::onNoteOn(int channel, int noteNumber, std::uint8_t /* velocity */)
{
    auto index = channel - 1;
    if (index < 6) {
        m_strings[index]->setActive(noteNumber);
    }
}

void FretboardComponent::onNoteOff(int channel, int noteNumber, std::uint8_t /* velocity */)
{
    auto index = channel - 1;
    if (index < 6) {
        m_strings[index]->resetActive(noteNumber);
    }
}
