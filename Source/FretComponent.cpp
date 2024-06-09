/*
  ==============================================================================

    FretComponent.cpp
    Created: 20 Apr 2024 6:14:51pm
    Author:  gugli

  ==============================================================================
*/

#include <JuceHeader.h>
#include "FretComponent.h"

//==============================================================================
FretComponent::FretComponent(const char* name, int midiNoteNumber)
    :   m_name(name), m_midiNoteNumber(midiNoteNumber)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

FretComponent::~FretComponent()
{
}

void FretComponent::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    auto defaultColor = getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId);

    auto backgroundColor = m_active ? juce::Colours::lightcoral : juce::Colours::white;

    g.fillAll (backgroundColor);

    auto localBounds = getLocalBounds();
    auto width = float(localBounds.getWidth());
    auto height = float(localBounds.getHeight());

    g.setColour (juce::Colours::brown);
    juce::Line<float> fretLine(juce::Point<float>(width, 0), juce::Point<float>(width, height));
    g.drawLine(fretLine, m_fretTickness);

    // draw the string
    g.setColour(juce::Colours::black);
    auto midPoint = localBounds.getHeight() / 2.0f;
    juce::Line<float> line(juce::Point<float>(0, midPoint), juce::Point<float>(float(width), midPoint));
    g.drawLine(line, 2.0f);

    auto text = std::to_string(m_midiNoteNumber);

    g.setColour (juce::Colours::blue);
    g.setFont (14.0f);
    g.drawText (text, getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
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
