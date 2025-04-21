/*
  ==============================================================================

    TriplePlayConnect.h
    Created: 21 Apr 2024 10:11:32am
    Author:  gugli

  ==============================================================================
*/

#pragma once
#include "IMidiInputTarget.h"

class TriplePlayConnect : public juce::MidiInputCallback {
private:
    IMidiInputTarget* m_pMidiInputTarget;
    std::unique_ptr<juce::MidiInput> m_midiInputPtr;
    std::shared_ptr<juce::MidiInputCallback> m_midiInputCallbackPtr;

private:
    void handleIncomingMidiMessage(juce::MidiInput* source, const juce::MidiMessage& message) override;
    juce::String getDeviceName() const;

public:
    TriplePlayConnect(IMidiInputTarget* pMidiInputTarget);
    ~TriplePlayConnect();

    std::function<void(int)> onSongSelect;

    void setMidiInputCallback(std::shared_ptr<juce::MidiInputCallback>& midiInputCallbackPtr);
    void clearMidiInputCallback();
};
