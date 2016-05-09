/*==============================================================================
//  ZenLookAndFeel.h
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 3 Apr 2016 2:53:25pm
//  Copyright (C) 2016 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: Generic Header File
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
===============================================================================*/

#ifndef ZENLOOKANDFEEL_H_INCLUDED
#define ZENLOOKANDFEEL_H_INCLUDED

#include "JuceHeader.h"
#include "ZenBinaryData.h"
#include "ZenLabel.h"

class ZenLookAndFeel : public LookAndFeel_V3
{
public:
	ZenLookAndFeel();
	void drawRotarySlider(Graphics&, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, Slider&) override;
	void drawLabel(Graphics& g, Label& label) override;
	Font getLabelFont(Label& label) override;
	//int getSliderThumbRadius(Slider&) override;
	void drawButtonBackground(Graphics&, Button&, const Colour& backgroundColour, bool isMouseOverButton, bool isButtonDown) override;
	void drawButtonShape(Graphics& g, const Path& outline, Colour baseColour, float height);

	Slider::SliderLayout getSliderLayout(Slider& slider) override;
	ZenLabel* createZenSliderTextBox(Slider& slider);

	//void drawLabel(Graphics&, Label&) override;
	//Label* createSliderTextBox(Slider&) override;
protected:
	Image topImage;
	Font defaultFont;

	//ScopedPointer<ImageCache> imageCache;
	Image testImg, bypassImg, knobImage;

};

class SliderLabelComp : public Label
{
public:
	SliderLabelComp() : Label(String::empty, String::empty) {}

	void mouseWheelMove(const MouseEvent&, const MouseWheelDetails&) override {}
};

/** Takes a path (SVG), the center x and y coordinates for a given component, and the angle for rotation
*** Returns the proper affine transform to control the knob*/
//static AffineTransform createTransformForKnobPath(Path path, float centreX, float centreY, float rotAngle);

#endif  // ZENLOOKANDFEEL_H_INCLUDED
