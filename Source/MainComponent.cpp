/*==============================================================================
//  MainComponent.cpp
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

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent ()
{
 	customLook = new ZenLookAndFeel();
 	LookAndFeel::setDefaultLookAndFeel(customLook);

    //addAndMakeVisible (slider = new Slider ("new slider"));
    //slider->setRange (0, 10, 0);
    //slider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    //slider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    //slider->addListener (this);

    /*addAndMakeVisible (testButton = new TextButton ("Test Button"));
    testButton->setButtonText ("Test button");
	testButton->setColour(TextButton::textColourOnId, Colour(0xffd7d7d7));
	testButton->setColour(TextButton::textColourOffId, Colour(0xff6a6a6a));
    //testButton->setConnectedEdges (Button::ConnectedOnBottom);	
    testButton->addListener (this);*/

	//addAndMakeVisible(slider7 = new Slider("new slider"));
	//slider7->setRange(0, 10, 0);
	//slider7->setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	//slider7->setTextBoxStyle(Slider::TextBoxLeft, false, 80, 20);
	//slider7->addListener(this);

    //addAndMakeVisible (slider2 = new Slider ("new slider"));
    //slider2->setRange (0, 10, 0);
    //slider2->setSliderStyle (Slider::LinearHorizontal);
    //slider2->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    //slider2->addListener (this);
	//
    //addAndMakeVisible (slider3 = new Slider ("new slider"));
    //slider3->setRange (0, 10, 0);
    //slider3->setSliderStyle (Slider::LinearVertical);
    //slider3->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    //slider3->addListener (this);
	
	addAndMakeVisible(label = new Label("new label", "label text"));
	label->setFont(Font(15.00f, Font::plain));
	label->setJustificationType(Justification::centredLeft);
	label->setEditable(false, false, false);
	label->setColour(TextEditor::textColourId, Colours::black);
	label->setColour(TextEditor::backgroundColourId, Colour(0x00000000));
	
    //addAndMakeVisible (textEditor = new TextEditor ("new text editor"));
    //textEditor->setMultiLine (false);
    //textEditor->setReturnKeyStartsNewLine (false);
    //textEditor->setReadOnly (false);
    //textEditor->setScrollbarsShown (true);
    //textEditor->setCaretVisible (true);
    //textEditor->setPopupMenuEnabled (true);
    //textEditor->setText (TRANS("textEditor"));
	//
    //addAndMakeVisible (comboBox = new ComboBox ("new combo box"));
    //comboBox->setEditableText (false);
    //comboBox->setJustificationType (Justification::centredLeft);
    //comboBox->setTextWhenNothingSelected (String());
    //comboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    //comboBox->addItem (TRANS("Combobox1"), 1);
    //comboBox->addItem (TRANS("Combobox2"), 2);
    //comboBox->addListener (this);
	//
    //addAndMakeVisible (groupComponent = new GroupComponent ("new group", "group"));
    //groupComponent->setTextLabelPosition (Justification::centredLeft);
	//
    //addAndMakeVisible (hyperlinkButton = new HyperlinkButton ("new hyperlink", URL ("http://www.juce.com")));
    //hyperlinkButton->setTooltip ("http://www.soniczentropy.com");
	//
    //addAndMakeVisible (viewport = new Viewport ("new viewport"));
	//
    //addAndMakeVisible (toggleButton = new ToggleButton ("new toggle button"));
    //toggleButton->addListener (this);
	//
    //addAndMakeVisible (tabbedComponent = new TabbedComponent (TabbedButtonBar::TabsAtTop));
    //tabbedComponent->setTabBarDepth (30);
    //tabbedComponent->addTab (TRANS("Tab 0"), Colours::lightgrey, 0, false);
    //tabbedComponent->addTab (TRANS("Tab 1"), Colours::lightgrey, 0, false);
    //tabbedComponent->addTab (TRANS("Tab 2"), Colours::lightgrey, 0, false);
    //tabbedComponent->setCurrentTabIndex (0);
	//
    //addAndMakeVisible (treeView = new TreeView ("new treeview"));

    //addAndMakeVisible (imageButton = new ImageButton ("new button"));
    //imageButton->setButtonText (TRANS("ImageButton"));
    //imageButton->addListener (this);
	//
    //imageButton->setImages (false, true, true,
    //                        ImageCache::getFromMemory (normalButton_png, normalButton_pngSize), 0.800f, Colour (0x00000000),
    //                        Image(), 1.000f, Colour (0x00000000),
    //                        Image(), 1.000f, Colour (0x00000000));
    //addAndMakeVisible (slider4 = new Slider ("new slider"));
    //slider4->setRange (0, 10, 0);
    //slider4->setSliderStyle (Slider::LinearHorizontal);
    //slider4->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    //slider4->addListener (this);

    //addAndMakeVisible (slider5 = new Slider ("new slider"));
    //slider5->setRange (0, 10, 0);
    //slider5->setSliderStyle (Slider::LinearBar);
    //slider5->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    //slider5->addListener (this);
	//
    //addAndMakeVisible (slider6 = new Slider ("new slider"));
    //slider6->setRange (0, 10, 0);
    //slider6->setSliderStyle (Slider::IncDecButtons);
    //slider6->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    //slider6->addListener (this);

    

	//addAndMakeVisible(filmStripKnob = new ZenRotaryFilmStripSlider("MainKnob", 63));
addAndMakeVisible(filmStripKnob = new ZenRotaryFilmStripSlider("MainKnob", 63));
	filmStripKnob->setTextBoxStyle(ZenRotaryFilmStripSlider::TextBoxCentered, false, 48, 20);
	filmStripKnob->setTextValueSuffix(" dB");
	filmStripKnob->setSize(64, 64);

    setSize (800, 600);
}

MainComponent::~MainComponent()
{
	customLook = nullptr;
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
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xffdde76f));
}

void MainComponent::resized()
{
    //slider->setBounds (16, 70, 150, 128);
    //testButton->setBounds (24, 222, 150, 24);
    //slider2->setBounds (24, 270, 150, 24);
    //slider3->setBounds (192, 70, 88, 224);
    label->setBounds (24, 302, 150, 24);
    //textEditor->setBounds (24, 342, 150, 24);
    //comboBox->setBounds (24, 382, 150, 24);
    //groupComponent->setBounds (24, 422, 200, 150);
    //hyperlinkButton->setBounds (200, 358, 150, 24);
    //viewport->setBounds (240, 422, 150, 150);
    //toggleButton->setBounds (217, 318, 150, 24);
    //tabbedComponent->setBounds (328, 86, 200, 150);
    //treeView->setBounds (464, 326, 150, 48);
    //imageButton->setBounds (416, 518, 88, 24);
    //slider4->setBounds (304, 270, 150, 24);
    //slider5->setBounds (472, 270, 150, 24);
    //slider6->setBounds (424, 430, 200, 24);
    //slider7->setBounds (312, 40, 150, 32);
	filmStripKnob->setBounds(20, 20, filmStripKnob->getWidth(), filmStripKnob->getHeight());

}

void MainComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    if (sliderThatWasMoved == slider)
    {
    }
    else if (sliderThatWasMoved == slider2)
    {
    }
    else if (sliderThatWasMoved == slider3)
    {
    }
    else if (sliderThatWasMoved == slider4)
    {
    }
    else if (sliderThatWasMoved == slider5)
    {
    }
    else if (sliderThatWasMoved == slider6)
    {
    }
    else if (sliderThatWasMoved == slider7)
    {
    }
}

void MainComponent::buttonClicked (Button* buttonThatWasClicked)
{
    if (buttonThatWasClicked == testButton)
    {
        
    }
    else if (buttonThatWasClicked == toggleButton)
    {
        
    }
    else if (buttonThatWasClicked == imageButton)
    {
        
    }
}

void MainComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    if (comboBoxThatHasChanged == comboBox)
    {
        //add combo box handling code here..
       
    }

}
