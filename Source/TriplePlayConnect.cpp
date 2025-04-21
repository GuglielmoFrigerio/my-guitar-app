/*
  ==============================================================================

    TriplePlayConnect.cpp
    Created: 21 Apr 2024 10:11:32am
    Author:  gugli

  ==============================================================================
*/

#include "pch.h"
#include "TriplePlayConnect.h"

void TriplePlayConnect::handleIncomingMidiMessage(juce::MidiInput* source, const juce::MidiMessage& message)
{
    auto midiInputCallbackPtr = m_midiInputCallbackPtr;
    if (midiInputCallbackPtr != nullptr)
        midiInputCallbackPtr->handleIncomingMidiMessage(source, message);

    //auto desc = message.getDescription();
    //DBG("midi event: " << desc);

    if (message.isNoteOn()) {
        auto channel = message.getChannel();
        auto noteNumber = message.getNoteNumber();
        auto velocity = message.getVelocity();
        m_pMidiInputTarget->onNoteOn(channel, noteNumber, velocity);

        DBG("note on. channel " << channel << " note: " << noteNumber << " velocity: " << velocity);
    }
    else if (message.isNoteOff()) {
        auto channel = message.getChannel();
        auto noteNumber = message.getNoteNumber();
        auto velocity = message.getVelocity();
        m_pMidiInputTarget->onNoteOff(channel, noteNumber, velocity);
        DBG("note off. channel " << channel << " note: " << noteNumber << " velocity: " << velocity);
    }
    //else if (message.isController()) {
    //    auto controllerNumber = message.getControllerNumber();
    //    auto controllerValue = message.getControllerValue();
    //}
    else if (message.isProgramChange()) {

        auto pcn = message.getProgramChangeNumber();
        if (onSongSelect != nullptr)
            onSongSelect(pcn);

    }
}

juce::String TriplePlayConnect::getDeviceName() const
{
    auto osType = juce::SystemStats::getOperatingSystemType();
    return ((osType & juce::SystemStats::Windows) != 0) ? "TriplePlay Connect" : "TriplePlay Connect TP Guitar";
}

TriplePlayConnect::TriplePlayConnect(IMidiInputTarget* pMidiInputTarget)
    : m_pMidiInputTarget(pMidiInputTarget)
{
    auto deviceName = getDeviceName();
    auto inputDevices = juce::MidiInput::getAvailableDevices();
    for (auto& deviceInfo : inputDevices) {
        if (deviceInfo.name == deviceName) {
            m_midiInputPtr = juce::MidiInput::openDevice(deviceInfo.identifier, this);
            m_midiInputPtr->start();
            break;
        }
    }
}

TriplePlayConnect::~TriplePlayConnect()
{
    if (m_midiInputPtr != nullptr) {
        m_midiInputPtr->stop();
        m_midiInputPtr = nullptr;
    }
}

void TriplePlayConnect::setMidiInputCallback(std::shared_ptr<juce::MidiInputCallback>& midiInputCallbackPtr)
{
    m_midiInputCallbackPtr = midiInputCallbackPtr;
}

void TriplePlayConnect::clearMidiInputCallback()
{
    m_midiInputCallbackPtr = nullptr;
}
