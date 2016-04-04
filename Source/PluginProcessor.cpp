/*==============================================================================
//  PluginProcessor.cpp
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date DATE
//  Copyright (C) 2016 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: Base Processor Class
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
===============================================================================*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
ZenGuitestAudioProcessor::ZenGuitestAudioProcessor()
{
#ifdef JUCE_MSVC
	//Visual Studio mem leak diagnostics settings 
	_CrtSetDbgFlag(0);	//Turn off VS memory dump output
						//_crtBreakAlloc = 307;	//Break on this memory allocation number (When Debug)
#endif

#ifdef JUCE_DEBUG
						//Create Zen_Utils Debug window instance
	debugWindow = ZenDebugEditor::getInstance();
	debugWindow->setSize(400, 400);
	debugWindow->setTopLeftPosition(1900 - debugWindow->getWidth(), 1040 - debugWindow->getHeight());
#endif
}

ZenGuitestAudioProcessor::~ZenGuitestAudioProcessor()
{
}


void ZenGuitestAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        float* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }
	
	/*float* leftData = buffer.getWritePointer(0);  //leftData references left channel now
	float* rightData = buffer.getWritePointer(1); //right data references right channel now
	for (long i = 0; i < buffer.getNumSamples(); i++)
	{
		leftData[i] = 0;
		rightData[i] = 0;
	}*/
}

//==============================================================================
void ZenGuitestAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
}

void ZenGuitestAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
}

//==============================================================================
void ZenGuitestAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback initialization
}

void ZenGuitestAudioProcessor::releaseResources()
{
    // When playback stops, you can use this to free up any spare memory, etc.
}

//==============================================================================
const String ZenGuitestAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool ZenGuitestAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool ZenGuitestAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double ZenGuitestAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int ZenGuitestAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int ZenGuitestAudioProcessor::getCurrentProgram()
{
    return 0;
}

void ZenGuitestAudioProcessor::setCurrentProgram (int index)
{
}

const String ZenGuitestAudioProcessor::getProgramName (int index)
{
    return String();
}

void ZenGuitestAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
bool ZenGuitestAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* ZenGuitestAudioProcessor::createEditor()
{
    return new ZenGuitestAudioProcessorEditor (*this);
}



//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new ZenGuitestAudioProcessor();
}
