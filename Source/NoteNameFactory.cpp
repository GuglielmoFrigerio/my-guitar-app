/*
  ==============================================================================

    NoteNameFactory.cpp
    Created: 21 Apr 2025 3:44:31pm
    Author:  gugli

  ==============================================================================
*/
#include "pch.h"
#include "NoteNameFactory.h"

std::string NoteNameFactory::getNoteName(int midiNoteNumber)
{
    auto index = midiNoteNumber % 12;
    return m_names[index];
}

std::string WholeNoteNameFactory::getNoteName(int midiNoteNumber)
{
    auto index = midiNoteNumber % 12;
    return m_names[index];
}
