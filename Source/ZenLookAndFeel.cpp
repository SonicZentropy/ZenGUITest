/*==============================================================================
//  ZenLookAndFeel.cpp
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 3 Apr 2016 2:53:25pm
//  Copyright (C) 2016 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: Generic CPP File
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
===============================================================================*/

#include "ZenLookAndFeel.h"

void ZenLookAndFeel::drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider& slider)
{
	const float radius = jmin(width / 2, height / 2) - 2.0f;
	const float centreX = x + width * 0.5f;
	const float centreY = y + height * 0.5f;
	const float rx = centreX - radius;
	const float ry = centreY - radius;
	const float rw = radius * 2.0f;
	const float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
	const bool isMouseOver = slider.isMouseOverOrDragging() && slider.isEnabled();

	const unsigned char pathData[] = {110,109,0,0,80,66,205,204,174,66,98,205,204,54,66,154,153,169,66,154,153,29,66,0,0,169,66,154,153,3,66,51,51,173,66,98,52,51,211,65,51,51,177,66,52,51,175,65,0,0,173,66,103,102,154,65,102,102,160,66,98,154,153,133,65,204,204,147,66,104,102,70,65,102,
		102,138,66,208,204,204,64,51,51,132,66,98,0,205,204,62,0,0,124,66,88,102,166,191,51,51,105,66,116,102,166,63,0,0,80,66,98,51,51,115,64,205,204,54,66,0,0,128,64,51,51,29,66,0,0,0,64,154,153,3,66,98,0,0,0,0,52,51,211,65,102,102,6,64,52,51,175,65,102,102,
		6,65,103,102,154,65,98,51,51,107,65,154,153,133,65,51,51,155,65,104,102,70,65,0,0,180,65,208,204,204,64,98,205,204,204,65,0,205,204,62,102,102,242,65,88,102,166,191,102,102,18,66,116,102,166,63,98,51,51,43,66,51,51,115,64,205,204,68,66,0,0,128,64,205,
		204,94,66,0,0,0,64,98,205,204,120,66,0,0,0,0,102,102,133,66,102,102,6,64,154,153,138,66,102,102,6,65,98,206,204,143,66,50,51,107,65,103,102,152,66,51,51,155,65,103,102,164,66,0,0,180,65,98,103,102,176,66,205,204,204,65,205,204,179,66,102,102,242,65,154,
		153,174,66,102,102,18,66,98,103,102,169,66,153,153,43,66,205,204,168,66,204,204,68,66,0,0,173,66,204,204,94,66,98,0,0,177,66,204,204,120,66,205,204,172,66,102,102,133,66,51,51,160,66,153,153,138,66,98,153,153,147,66,204,204,143,66,51,51,138,66,102,102,
		152,66,0,0,132,66,102,102,164,66,98,154,153,123,66,154,153,176,66,205,204,104,66,0,0,180,66,0,0,80,66,205,204,174,66,99,101,0,0};

	Path path;
	path.loadPathFromData(pathData, sizeof(pathData));
	
	if (radius > 12.0f)
	{
		if (slider.isEnabled())
			g.setColour(slider.findColour(Slider::rotarySliderFillColourId).withAlpha(isMouseOver ? 1.0f : 0.7f));
		else
			g.setColour(Colour(0x80808080));

		const float thickness = 0.7f;

		{
			Path filledArc;
			filledArc.addPieSegment(rx, ry, rw, rw, rotaryStartAngle, angle, thickness);
			g.fillPath(filledArc);
		}

		{
			const float innerRadius = radius * 0.2f;
			Path p;
			p.addTriangle(-innerRadius, 0.0f,
				0.0f, -radius * thickness * 1.1f,
				innerRadius, 0.0f);

			p.addEllipse(-innerRadius, -innerRadius, innerRadius * 2.0f, innerRadius * 2.0f);
						
			AffineTransform gripxform = createTransformForKnobPath(path, centreX, centreY, angle);

			g.fillPath(path, gripxform);

			g.setColour(Colour(0, 0, 0));
			
			
			topImage = ImageFileFormat::loadFrom(File("D:/Temp/toptexture.png"));
			FillType fillType;
			AffineTransform fillxform;
			fillxform = fillxform.scaled(
				JUCE_LIVE_CONSTANT(1.2),
				JUCE_LIVE_CONSTANT(1.2))
				.translated(
					JUCE_LIVE_CONSTANT(35),
					JUCE_LIVE_CONSTANT(14)
					).rotated(
						(angle),
						JUCE_LIVE_CONSTANT(centreX),
						JUCE_LIVE_CONSTANT(centreY));
			fillType.setTiledImage(topImage, fillxform);
			
			/*g.setTiledImageFill(topImage, 
				JUCE_LIVE_CONSTANT(centreX), //108
				JUCE_LIVE_CONSTANT(centreY), //87
				1.0f);
*/
			g.setFillType(fillType);


			Path top;
			top.addEllipse(
				0, //37
				0, //16.8
				path.getBounds().getHorizontalRange().getLength() - 15, 
				path.getBounds().getVerticalRange().getLength() - 15);

			AffineTransform topxform = createTransformForKnobPath(top, centreX, centreY, angle);
			g.fillPath(top, topxform);
				
			Path marker;
			marker.addEllipse(
				(72),
				(22),
				(5),
				(5));
			g.setColour(Colour(228, 228, 228));
			
			AffineTransform markerxform;
			markerxform = markerxform.rotated(angle, centreX, centreY);
			g.fillPath(marker, markerxform);

		}

		if (slider.isEnabled())
			g.setColour(slider.findColour(Slider::rotarySliderOutlineColourId));
		else
			g.setColour(Colour(0x80808080));

		Path outlineArc;
		outlineArc.addPieSegment(rx, ry, rw, rw, rotaryStartAngle, rotaryEndAngle, thickness);
		outlineArc.closeSubPath();

		g.strokePath(outlineArc, PathStrokeType(slider.isEnabled() ? (isMouseOver ? 2.0f : 1.2f) : 0.3f));
	} else
	{
		if (slider.isEnabled())
			g.setColour(slider.findColour(Slider::rotarySliderFillColourId).withAlpha(isMouseOver ? 1.0f : 0.7f));
		else
			g.setColour(Colour(0x80808080));

		Path p;
		p.addEllipse(-0.4f * rw, -0.4f * rw, rw * 0.8f, rw * 0.8f);
		PathStrokeType(rw * 0.1f).createStrokedPath(p, p);

		p.addLineSegment(Line<float>(0.0f, 0.0f, 0.0f, -radius), rw * 0.2f);

		g.fillPath(p, AffineTransform::rotation(angle).translated(centreX, centreY));
	}
}
// #TODO: finish moving paths
/** Takes a path (SVG), the center x and y coordinates for a given component, and the angle for rotation
*** Returns the proper affine transform to control the knob*/
static AffineTransform createTransformForKnobPath(Path path, float centreX, float centreY, float rotAngle)
{
	float gripcenterx = path.getBounds().getCentreX();
	float griptransx = centreX - gripcenterx;
	float gripcentery = path.getBounds().getCentreY();
	float griptransy = centreY - gripcentery;

	AffineTransform gripxform = AffineTransform::translation(griptransx, griptransy);

	gripxform = gripxform.rotated(rotAngle, centreX, centreY);
	return gripxform;
}