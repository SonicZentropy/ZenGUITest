/*==============================================================================
//  PluginProcessorEditor.cpp
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date DATE
//  Copyright (C) 2016 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: Base Editor Class
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
===============================================================================*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
ZenGuitestAudioProcessorEditor::ZenGuitestAudioProcessorEditor (ZenGuitestAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
	addAndMakeVisible(mainComponent = new MainComponent());

    setSize (800, 600);
	ZEN_COMPONENT_DEBUG_ATTACH(this);
}

ZenGuitestAudioProcessorEditor::~ZenGuitestAudioProcessorEditor()
{
}

//==============================================================================
void ZenGuitestAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::black);
}

void ZenGuitestAudioProcessorEditor::resized()
{

}
