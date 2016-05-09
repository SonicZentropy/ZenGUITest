/*==============================================================================
//  MainComponent.h
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date DATE
//  Copyright (C) 2016 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: Generic GUI Component Header
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
===============================================================================*/

#ifndef MAINCOMPONENT_H_INCLUDE
#define MAINCOMPONENT_H_INCLUDE

#include "JuceHeader.h"
#include "ZenLookAndFeel.h"
#include "ZenRotaryFilmStripSlider.h"

class MainComponent  : public Component,
                       public SliderListener,
                       public ButtonListener,
                       public ComboBoxListener
{
public:
    
    MainComponent ();
    ~MainComponent();

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;

private:
	ScopedPointer<LookAndFeel> customLook;
	ScopedPointer<ZenRotaryFilmStripSlider> filmStripKnob;
    ScopedPointer<Slider> slider;
    ScopedPointer<TextButton> testButton;
    ScopedPointer<Slider> slider2;
    ScopedPointer<Slider> slider3;
    ScopedPointer<Label> label;
    ScopedPointer<TextEditor> textEditor;
    ScopedPointer<ComboBox> comboBox;
    ScopedPointer<GroupComponent> groupComponent;
    ScopedPointer<HyperlinkButton> hyperlinkButton;
    ScopedPointer<Viewport> viewport;
    ScopedPointer<ToggleButton> toggleButton;
    ScopedPointer<TabbedComponent> tabbedComponent;
    ScopedPointer<TreeView> treeView;
    ScopedPointer<ImageButton> imageButton;
    ScopedPointer<Slider> slider4;
    ScopedPointer<Slider> slider5;
    ScopedPointer<Slider> slider6;
    ScopedPointer<Slider> slider7;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

#endif   // MAINCOMPONENT_H_INCLUDE
