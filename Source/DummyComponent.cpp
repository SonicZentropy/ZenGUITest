/*==============================================================================
//  FILENAME
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date DATE
//  Copyright (C) 2016 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: Generic GUI Component Class
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
===============================================================================*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "DummyComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainComponent::MainComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..

 	customLook = new ZenLookAndFeel();
 	LookAndFeel::setDefaultLookAndFeel(customLook);
    //[/Constructor_pre]

    addAndMakeVisible (slider = new Slider ("new slider"));
    slider->setRange (0, 10, 0);
    slider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    slider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    slider->setColour (Slider::textBoxTextColourId, Colour (0xffd70a0a));
    slider->addListener (this);

    addAndMakeVisible (testButton = new TextButton ("Test Button"));
    testButton->setButtonText (TRANS("new button"));
    testButton->setConnectedEdges (Button::ConnectedOnBottom);
    testButton->addListener (this);

    addAndMakeVisible (slider2 = new Slider ("new slider"));
    slider2->setRange (0, 10, 0);
    slider2->setSliderStyle (Slider::LinearHorizontal);
    slider2->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    slider2->addListener (this);

    addAndMakeVisible (slider3 = new Slider ("new slider"));
    slider3->setRange (0, 10, 0);
    slider3->setSliderStyle (Slider::LinearVertical);
    slider3->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    slider3->addListener (this);

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("label text")));
    label->setFont (Font ("Futura Book", 15.00f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (textEditor = new TextEditor ("new text editor"));
    textEditor->setMultiLine (false);
    textEditor->setReturnKeyStartsNewLine (false);
    textEditor->setReadOnly (false);
    textEditor->setScrollbarsShown (true);
    textEditor->setCaretVisible (true);
    textEditor->setPopupMenuEnabled (true);
    textEditor->setColour (TextEditor::backgroundColourId, Colour (0x00ffffff));
    textEditor->setColour (TextEditor::highlightColourId, Colour (0x005fa01c));
    textEditor->setColour (TextEditor::outlineColourId, Colour (0xc05fa01c));
    textEditor->setText (TRANS("textEditor"));

    addAndMakeVisible (comboBox = new ComboBox ("new combo box"));
    comboBox->setEditableText (false);
    comboBox->setJustificationType (Justification::centredLeft);
    comboBox->setTextWhenNothingSelected (String());
    comboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox->addItem (TRANS("Combobox1"), 1);
    comboBox->addItem (TRANS("Combobox2"), 2);
    comboBox->addListener (this);

    addAndMakeVisible (groupComponent = new GroupComponent ("new group",
                                                            TRANS("group")));
    groupComponent->setTextLabelPosition (Justification::centredLeft);

    addAndMakeVisible (hyperlinkButton = new HyperlinkButton (TRANS("new hyperlink"),
                                                              URL ("http://www.juce.com")));
    hyperlinkButton->setTooltip (TRANS("http://www.juce.com"));

    addAndMakeVisible (viewport = new Viewport ("new viewport"));

    addAndMakeVisible (toggleButton = new ToggleButton ("new toggle button"));
    toggleButton->addListener (this);

    addAndMakeVisible (tabbedComponent = new TabbedComponent (TabbedButtonBar::TabsAtTop));
    tabbedComponent->setTabBarDepth (30);
    tabbedComponent->addTab (TRANS("Tab 0"), Colours::lightgrey, 0, false);
    tabbedComponent->addTab (TRANS("Tab 1"), Colours::lightgrey, 0, false);
    tabbedComponent->addTab (TRANS("Tab 2"), Colours::lightgrey, 0, false);
    tabbedComponent->setCurrentTabIndex (0);

    addAndMakeVisible (treeView = new TreeView ("new treeview"));

    addAndMakeVisible (imageButton = new ImageButton ("new button"));
    imageButton->setButtonText (TRANS("ImageButton"));
    imageButton->addListener (this);

    imageButton->setImages (false, true, true,
                            ImageCache::getFromMemory (normalButton_png, normalButton_pngSize), 0.800f, Colour (0x00000000),
                            Image(), 1.000f, Colour (0x00000000),
                            Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (slider4 = new Slider ("new slider"));
    slider4->setRange (0, 10, 0);
    slider4->setSliderStyle (Slider::LinearHorizontal);
    slider4->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    slider4->addListener (this);

    addAndMakeVisible (slider5 = new Slider ("new slider"));
    slider5->setRange (0, 10, 0);
    slider5->setSliderStyle (Slider::LinearBar);
    slider5->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    slider5->addListener (this);

    addAndMakeVisible (slider6 = new Slider ("new slider"));
    slider6->setRange (0, 10, 0);
    slider6->setSliderStyle (Slider::IncDecButtons);
    slider6->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    slider6->addListener (this);

    addAndMakeVisible (slider7 = new Slider ("new slider"));
    slider7->setRange (0, 10, 0);
    slider7->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    slider7->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    slider7->addListener (this);


    //[UserPreSize]
	addAndMakeVisible(filmStripKnob = new ZenRotaryFilmStripSlider("MainKnob", 63));

	filmStripKnob->setSize(96, 96);

    //[/UserPreSize]

    setSize (800, 600);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MainComponent::~MainComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	customLook = nullptr;
    //[/Destructor_pre]

    slider = nullptr;
    testButton = nullptr;
    slider2 = nullptr;
    slider3 = nullptr;
    label = nullptr;
    textEditor = nullptr;
    comboBox = nullptr;
    groupComponent = nullptr;
    hyperlinkButton = nullptr;
    viewport = nullptr;
    toggleButton = nullptr;
    tabbedComponent = nullptr;
    treeView = nullptr;
    imageButton = nullptr;
    slider4 = nullptr;
    slider5 = nullptr;
    slider6 = nullptr;
    slider7 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xffdde76f));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    slider->setBounds (16, 70, 150, 128);
    testButton->setBounds (24, 222, 150, 24);
    slider2->setBounds (24, 270, 150, 24);
    slider3->setBounds (192, 70, 88, 224);
    label->setBounds (24, 302, 150, 24);
    textEditor->setBounds (24, 342, 150, 24);
    comboBox->setBounds (24, 382, 150, 24);
    groupComponent->setBounds (24, 422, 200, 150);
    hyperlinkButton->setBounds (200, 358, 150, 24);
    viewport->setBounds (240, 422, 150, 150);
    toggleButton->setBounds (217, 318, 150, 24);
    tabbedComponent->setBounds (328, 86, 200, 150);
    treeView->setBounds (464, 326, 150, 48);
    imageButton->setBounds (416, 518, 88, 24);
    slider4->setBounds (304, 270, 150, 24);
    slider5->setBounds (472, 270, 150, 24);
    slider6->setBounds (424, 430, 200, 24);
    slider7->setBounds (312, 40, 150, 32);
    //[UserResized] Add your own custom resize handling here..

	filmStripKnob->setBounds(20, 20, filmStripKnob->getWidth(), filmStripKnob->getHeight());

    //[/UserResized]
}

void MainComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == slider)
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
        //[/UserSliderCode_slider]
    }
    else if (sliderThatWasMoved == slider2)
    {
        //[UserSliderCode_slider2] -- add your slider handling code here..
        //[/UserSliderCode_slider2]
    }
    else if (sliderThatWasMoved == slider3)
    {
        //[UserSliderCode_slider3] -- add your slider handling code here..
        //[/UserSliderCode_slider3]
    }
    else if (sliderThatWasMoved == slider4)
    {
        //[UserSliderCode_slider4] -- add your slider handling code here..
        //[/UserSliderCode_slider4]
    }
    else if (sliderThatWasMoved == slider5)
    {
        //[UserSliderCode_slider5] -- add your slider handling code here..
        //[/UserSliderCode_slider5]
    }
    else if (sliderThatWasMoved == slider6)
    {
        //[UserSliderCode_slider6] -- add your slider handling code here..
        //[/UserSliderCode_slider6]
    }
    else if (sliderThatWasMoved == slider7)
    {
        //[UserSliderCode_slider7] -- add your slider handling code here..
        //[/UserSliderCode_slider7]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void MainComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == testButton)
    {
        //[UserButtonCode_testButton] -- add your button handler code here..
        //[/UserButtonCode_testButton]
    }
    else if (buttonThatWasClicked == toggleButton)
    {
        //[UserButtonCode_toggleButton] -- add your button handler code here..
        //[/UserButtonCode_toggleButton]
    }
    else if (buttonThatWasClicked == imageButton)
    {
        //[UserButtonCode_imageButton] -- add your button handler code here..
        //[/UserButtonCode_imageButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void MainComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox)
    {
        //[UserComboBoxCode_comboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="800" initialHeight="600">
  <BACKGROUND backgroundColour="ffdde76f"/>
  <SLIDER name="new slider" id="c12454ff12de9f88" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="16 70 150 128" textboxtext="ffd70a0a"
          min="0" max="10" int="0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <TEXTBUTTON name="Test Button" id="f3f9c3eea26dc199" memberName="testButton"
              virtualName="" explicitFocusOrder="0" pos="24 222 150 24" buttonText="new button"
              connectedEdges="8" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="new slider" id="4217afd346a601f1" memberName="slider2"
          virtualName="" explicitFocusOrder="0" pos="24 270 150 24" min="0"
          max="10" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="new slider" id="efcf0875377516df" memberName="slider3"
          virtualName="" explicitFocusOrder="0" pos="192 70 88 224" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <LABEL name="new label" id="250fd4d686ad19c1" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="24 302 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Futura Book" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="e1d93a5d750e4e9e" memberName="textEditor"
              virtualName="" explicitFocusOrder="0" pos="24 342 150 24" bkgcol="ffffff"
              hilitecol="5fa01c" outlinecol="c05fa01c" initialText="textEditor"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <COMBOBOX name="new combo box" id="5a62404b2a9b05c6" memberName="comboBox"
            virtualName="" explicitFocusOrder="0" pos="24 382 150 24" editable="0"
            layout="33" items="Combobox1&#10;Combobox2" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <GROUPCOMPONENT name="new group" id="eb03a942a845d102" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="24 422 200 150" title="group"
                  textpos="33"/>
  <HYPERLINKBUTTON name="new hyperlink" id="469a8293a3b48043" memberName="hyperlinkButton"
                   virtualName="" explicitFocusOrder="0" pos="200 358 150 24" tooltip="http://www.juce.com"
                   buttonText="new hyperlink" connectedEdges="0" needsCallback="0"
                   radioGroupId="0" url="http://www.juce.com"/>
  <VIEWPORT name="new viewport" id="a6eb3a36464cdb98" memberName="viewport"
            virtualName="" explicitFocusOrder="0" pos="240 422 150 150" vscroll="1"
            hscroll="1" scrollbarThickness="18" contentType="0" jucerFile=""
            contentClass="" constructorParams=""/>
  <TOGGLEBUTTON name="new toggle button" id="414c083f20d492cb" memberName="toggleButton"
                virtualName="" explicitFocusOrder="0" pos="217 318 150 24" buttonText="new toggle button"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TABBEDCOMPONENT name="new tabbed component" id="433d1d3d06fc65b8" memberName="tabbedComponent"
                   virtualName="" explicitFocusOrder="0" pos="328 86 200 150" orientation="top"
                   tabBarDepth="30" initialTab="0">
    <TAB name="Tab 0" colour="ffd3d3d3" useJucerComp="0" contentClassName=""
         constructorParams="" jucerComponentFile=""/>
    <TAB name="Tab 1" colour="ffd3d3d3" useJucerComp="0" contentClassName=""
         constructorParams="" jucerComponentFile=""/>
    <TAB name="Tab 2" colour="ffd3d3d3" useJucerComp="0" contentClassName=""
         constructorParams="" jucerComponentFile=""/>
  </TABBEDCOMPONENT>
  <TREEVIEW name="new treeview" id="631b29eb5098e3d" memberName="treeView"
            virtualName="" explicitFocusOrder="0" pos="464 326 150 48" rootVisible="1"
            openByDefault="0"/>
  <IMAGEBUTTON name="new button" id="ae72e20646f11f5d" memberName="imageButton"
               virtualName="" explicitFocusOrder="0" pos="416 518 88 24" buttonText="ImageButton"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="normalButton_png" opacityNormal="0.80000001192092895508"
               colourNormal="0" resourceOver="" opacityOver="1" colourOver="0"
               resourceDown="" opacityDown="1" colourDown="0"/>
  <SLIDER name="new slider" id="1d42d4374a132ef1" memberName="slider4"
          virtualName="" explicitFocusOrder="0" pos="304 270 150 24" min="0"
          max="10" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="new slider" id="f6bc29a214a7fbf8" memberName="slider5"
          virtualName="" explicitFocusOrder="0" pos="472 270 150 24" min="0"
          max="10" int="0" style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="new slider" id="108b5f1959eb0835" memberName="slider6"
          virtualName="" explicitFocusOrder="0" pos="424 430 200 24" min="0"
          max="10" int="0" style="IncDecButtons" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="new slider" id="76a1c1865d19de9e" memberName="slider7"
          virtualName="" explicitFocusOrder="0" pos="312 40 150 32" min="0"
          max="10" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
