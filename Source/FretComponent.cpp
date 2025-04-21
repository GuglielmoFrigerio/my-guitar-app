/*
  ==============================================================================

    FretComponent.cpp
    Created: 20 Apr 2024 6:14:51pm
    Author:  gugli

  ==============================================================================
*/

#include "pch.h"
#include "FretComponent.h"

float g_firstFretTickness = 10.0f;

//==============================================================================
FretComponent::FretComponent(const char* name, int midiNoteNumber, int fretNumber, std::shared_ptr<INoteNameFactory> noteNameFactoryPtr)
    :   m_name(name), m_midiNoteNumber(midiNoteNumber), m_fretNumber(fretNumber), m_noteNameFactoryPtr(noteNameFactoryPtr)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

FretComponent::~FretComponent()
{
}

void FretComponent::paint (juce::Graphics& g)
{
    auto defaultColor = getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId);

    auto backgroundColor = m_active ? juce::Colours::lightcoral : juce::Colours::lightsalmon;

    g.fillAll (backgroundColor);

    auto localBounds = getLocalBounds();
    auto width = float(localBounds.getWidth());
    auto height = float(localBounds.getHeight());

    // draws the fret
    auto fretTickness = (m_fretNumber == 1) ? g_firstFretTickness : m_fretTickness;
    g.setColour (juce::Colours::brown);
    juce::Line<float> fretLine(juce::Point<float>(width, 0), juce::Point<float>(width, height));
    g.drawLine(fretLine, fretTickness);

    // draws the string
    g.setColour(juce::Colours::black);
    auto midPoint = localBounds.getHeight() / 2.0f;
    juce::Line<float> line(juce::Point<float>(0, midPoint), juce::Point<float>(float(width), midPoint));
    g.drawLine(line, 2.0f);

    // draws circle

    auto noteName = m_noteNameFactoryPtr->getNoteName(m_midiNoteNumber);

    if (!noteName.empty()) {
        float diameter = 20.0;
        auto x = (localBounds.getWidth() - diameter) / 2;
        auto y = (localBounds.getHeight() - diameter) / 2;
        g.setColour(juce::Colours::white);
        g.fillEllipse(x, y, diameter, diameter);

        // draws fret name
        g.setColour(juce::Colours::blue);
        g.setFont(14.0f);
        g.drawText(noteName, localBounds, juce::Justification::centred, true);   // draw some placeholder text
    }
}

void FretComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

std::tuple<int, int> FretComponent::getWidthAndStart(int fretNumber, int numberOfFrets, float componentWidth)
{
    auto lastFretLength = getStringLength(numberOfFrets, componentWidth);
    auto factor = componentWidth / (componentWidth - lastFretLength);
    auto realLength = componentWidth * factor;
    auto firstLength = getStringLength(fretNumber - 1, realLength);
    auto secondLength = getStringLength(fretNumber, realLength);
    return { int(firstLength - secondLength), int (realLength - firstLength) };
}

void FretComponent::setActive()
{
    m_active = true;

    const juce::MessageManagerLock mmLock;
    repaint();
}

void FretComponent::resetActive()
{
    m_active = false;

    const juce::MessageManagerLock mmLock;
    repaint();
}

float FretComponent::getStringLength(int fretNumber, float componentWidth)
{
    return componentWidth / pow(2.0f, (fretNumber / 12.0f));
}
