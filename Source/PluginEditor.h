/*==============================================================================
//  PluginProcessorEditor.h
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

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "MainComponent.h"


//==============================================================================
/**
*/
class ZenGuitestAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    explicit ZenGuitestAudioProcessorEditor (ZenGuitestAudioProcessor&);
    ~ZenGuitestAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    ZenGuitestAudioProcessor& processor;
	ScopedPointer<MainComponent> mainComponent;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ZenGuitestAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
