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
FretComponent::FretComponent(const char* name)
    :   m_name(name)
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

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::red);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText (m_name, getLocalBounds(),
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

float FretComponent::getStringLength(int fretNumber, float componentWidth)
{
    return componentWidth / pow(2.0f, (fretNumber / 12.0f));
}
