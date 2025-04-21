/*
  ==============================================================================

    StringComponent.cpp
    Created: 20 Apr 2024 5:24:44pm
    Author:  gugli

  ==============================================================================
*/

#include "pch.h"
#include "StringComponent.h"

int g_firstFretWidth = 30;

//==============================================================================
StringComponent::StringComponent(int fretCount, int startingMidiNoteNumber, std::shared_ptr<INoteNameFactory> noteNameFactoryPtr)
    : m_startingMidiNoteNumber(startingMidiNoteNumber)
{
    for (auto index = 1; index <= fretCount; ++index) {
        auto name = std::to_string(index);
        m_frets.push_back(std::make_unique<FretComponent>(name.c_str(), startingMidiNoteNumber, index, noteNameFactoryPtr));
        startingMidiNoteNumber++;
    }

    for (auto& fret : m_frets) {
        addAndMakeVisible(*fret);
    }
}

StringComponent::~StringComponent()
{
}

void StringComponent::paint (juce::Graphics& /* g */)
{
}

void StringComponent::resized()
{
    auto localBounds = getLocalBounds();
    auto initialWidth = localBounds.getWidth();
    for (auto index = 1; index <= m_frets.size(); ++index) {
        auto [width, start] = FretComponent::getWidthAndStart(index, int(m_frets.size()), float (initialWidth));
        if (index == 1)
            width = g_firstFretWidth;

        auto fretRect = localBounds.removeFromLeft(width);
        auto& fret = m_frets[index - 1];
        fret->setBounds(fretRect);
    }
}

void StringComponent::setActive(int midiNoteNumber)
{
    auto index = midiNoteNumber - m_startingMidiNoteNumber;
    if (index < m_frets.size()) {
        m_frets[index]->setActive();
    }
}

void StringComponent::resetActive(int midiNoteNumber)
{
    auto index = midiNoteNumber - m_startingMidiNoteNumber;
    if (index < m_frets.size()) {
        m_frets[index]->resetActive();
    }
}
