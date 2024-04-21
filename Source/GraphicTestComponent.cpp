/*
  ==============================================================================

    GraphicTestComponent.cpp
    Created: 20 Apr 2024 5:16:36pm
    Author:  gugli

  ==============================================================================
*/

#include <JuceHeader.h>
#include "GraphicTestComponent.h"

//==============================================================================
GraphicTestComponent::GraphicTestComponent()
    : m_stringComponent(24)
{
    addAndMakeVisible(m_stringComponent);
}

GraphicTestComponent::~GraphicTestComponent()
{
}

void GraphicTestComponent::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    //g.setFont (14.0f);
    //g.drawText ("GraphicTestComponent", getLocalBounds(),
    //            juce::Justification::centred, true);   // draw some placeholder text

    g.setColour(juce::Colours::green);
    g.drawLine(10, 300, 590, 300, 5);
}

void GraphicTestComponent::resized()
{
    m_stringComponent.setBounds(0, 0, getWidth(), getHeight());

}
