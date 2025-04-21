/*
  ==============================================================================

    NoteNameFactory.h
    Created: 21 Apr 2025 3:44:31pm
    Author:  gugli

  ==============================================================================
*/

#pragma once

class INoteNameFactory {
public:
    virtual ~INoteNameFactory() {}

    virtual std::string getNoteName(int midiNoteNumber) = 0;
};


class MidiNoteNameFactory : public INoteNameFactory{
    std::string getNoteName(int midiNoteNumber) {
        return std::to_string(midiNoteNumber);
    }
};


class NoteNameFactory : public INoteNameFactory {

private:
    std::vector<std::string> m_names = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };

public:
    std::string getNoteName(int midiNoteNumber);
};

class WholeNoteNameFactory : public INoteNameFactory {

private:
    std::vector<std::string> m_names = { "C", "", "D", "", "E", "F", "", "G", "", "A", "", "B" };

public:
    std::string getNoteName(int midiNoteNumber);
};