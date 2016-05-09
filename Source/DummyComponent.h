/*==============================================================================
//  FILENAME
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

#ifndef __JUCE_HEADER_C3D72AEDB8396B3__
#define __JUCE_HEADER_C3D72AEDB8396B3__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "ZenLookAndFeel.h"
#include "ZenRotaryFilmStripSlider.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainComponent  : public Component,
                       public SliderListener,
                       public ButtonListener,
                       public ComboBoxListener
{
public:
    //==============================================================================
    MainComponent ();
    ~MainComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	ScopedPointer<LookAndFeel> customLook;
	ScopedPointer<ZenRotaryFilmStripSlider> filmStripKnob;
    //[/UserVariables]

    //==============================================================================
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

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_C3D72AEDB8396B3__
