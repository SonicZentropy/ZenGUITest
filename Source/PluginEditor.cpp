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
	compBoundsConstrain = new ComponentBoundsConstrainer();
	compBoundsConstrain->setSizeLimits(100, 100, 1600, 900);
	addAndMakeVisible(resizeComponent = new ResizableCornerComponent(this, compBoundsConstrain));
	
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
	resizeComponent->setBounds(getWidth() - 16, getHeight() - 16, 16, 16);
}
