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

class ZenLookAndFeel : public LookAndFeel_V3
{
public:
	void drawRotarySlider(Graphics&, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, Slider&) override;
	//int getSliderThumbRadius(Slider&) override;


protected:
	Image topImage;
	
};

/** Takes a path (SVG), the center x and y coordinates for a given component, and the angle for rotation
*** Returns the proper affine transform to control the knob*/
static AffineTransform createTransformForKnobPath(Path path, float centreX, float centreY, float rotAngle);

#endif  // ZENLOOKANDFEEL_H_INCLUDED
