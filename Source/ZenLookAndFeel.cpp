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
#include "ZenRotaryFilmStripSlider.h"
#include "ZenLabel.h"

ZenLookAndFeel::ZenLookAndFeel()
{
	//testImg = ImageFileFormat::loadFrom(BinaryData::backgroundImg_png, (size_t)BinaryData::backgroundImg_pngSize);
	//bypassImg = ImageFileFormat::loadFrom(BinaryData::bypassBtnImg_png, (size_t)BinaryData::bypassBtnImg_pngSize);
	//knobImage = ImageFileFormat::loadFrom(ZenBinaryData::zenRotaryKnob_png, (size_t)ZenBinaryData::zenRotaryKnob_pngSize);
	defaultFont = Typeface::createSystemTypefaceFor(BinaryData::FUTURABOOK_TTF, BinaryData::FUTURABOOK_TTFSize);
	
}

void ZenLookAndFeel::drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider& slider)
{
	ZenRotaryFilmStripSlider* zenSlider = dynamic_cast<ZenRotaryFilmStripSlider*>(&slider);
	if (zenSlider != nullptr)
	{
		//DBG("In draw rotary label");
		if (zenSlider->hasValidFilmStrip())
		{
			//int value = (getValue() - getMinimum()) / (getMaximum() - getMinimum()) * (numFrames - 1);
			int value = (zenSlider->getValue() - zenSlider->getMinimum()) / (zenSlider->getMaximum() - zenSlider->getMinimum()) * (zenSlider->numFrames - 1);

			if (zenSlider->filmstripIsHorizontal)
			{
				g.drawImage(zenSlider->getFilmStrip(), 0, 0, zenSlider->getWidth(), zenSlider->getHeight(), value * zenSlider->getFrameWidth(), 0, zenSlider->getFrameWidth(), zenSlider->getFrameHeight());
			}
			else
			{
				g.drawImage(zenSlider->getFilmStrip(), 0, 0, zenSlider->getWidth(), zenSlider->getHeight(), 0, value * zenSlider->getFrameHeight(), zenSlider->getFrameWidth(), zenSlider->getFrameHeight());
			}
			//g.setColour(Colours::whitesmoke);
			//g.drawText(String(zenSlider->getValue()), 0, 0, zenSlider->getWidth() - 2, zenSlider->getHeight() - 2, Justification::centred, false);
		}
	}
	else //If not Zen Slider
	{
		LookAndFeel_V2::drawRotarySlider(g, x, y, width, height, sliderPos, rotaryStartAngle, rotaryEndAngle, slider);
	}
}

void ZenLookAndFeel::drawLabel(Graphics& g, Label& label)
{
	g.fillAll(label.findColour(Label::backgroundColourId));
	//DBG("In draw label");

	if (!label.isBeingEdited())
	{
		//DBG("In draw label not being edited");
		const float alpha = label.isEnabled() ? 1.0f : 0.5f;
		const Font font(getLabelFont(label));

		g.setFont(font);

		Rectangle<int> textArea(label.getBorderSize().subtractedFrom(label.getLocalBounds()));
		
		// Draw shadow
		ZenLabel* zenLabel = dynamic_cast<ZenLabel*>(&label);
		if (zenLabel != nullptr && zenLabel->getTextHasShadow())
		{
			Rectangle<int> shadowArea = textArea;
			shadowArea.setPosition(textArea.getTopLeft().translated(2, 2));
			g.setColour(Colour((juce::uint8)0, 0, 0, (float)0.50f));
			g.drawFittedText(label.getText(), shadowArea, label.getJustificationType(),
				jmax(1, (int)(textArea.getHeight() / font.getHeight())),
				label.getMinimumHorizontalScale());
		}
		
		
		
		//Draw actual text
		g.setColour(label.findColour(Label::textColourId).withMultipliedAlpha(alpha));
		g.drawFittedText(label.getText(), textArea, label.getJustificationType(),
		                 jmax(1, (int)(textArea.getHeight() / font.getHeight())),
		                 label.getMinimumHorizontalScale());

		g.setColour(label.findColour(Label::outlineColourId).withMultipliedAlpha(alpha));
	}
	else if (label.isEnabled())
	{
		//DBG("In draw label is being edited & is enabled");
		g.setColour(label.findColour(Label::outlineColourId));
	}
	if (label.isBeingEdited())
	{
		//DBG("In draw label being Edited");
	}
	g.drawRect(label.getLocalBounds());
}

Font ZenLookAndFeel::getLabelFont(Label& label)
{
	//return label.getFont();
	return Font("Futura Book", 16, Font::plain);
}

// 	const float radius = jmin(width / 2, height / 2) - 2.0f;
// 	const float centreX = x + width * 0.5f;
// 	const float centreY = y + height * 0.5f;
// 	const float rx = centreX - radius;
// 	const float ry = centreY - radius;
// 	const float rw = radius * 2.0f;
// 	const float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
// 	const bool isMouseOver = slider.isMouseOverOrDragging() && slider.isEnabled();
// 
// 	const unsigned char pathData[] = {110,109,0,0,80,66,205,204,174,66,98,205,204,54,66,154,153,169,66,154,153,29,66,0,0,169,66,154,153,3,66,51,51,173,66,98,52,51,211,65,51,51,177,66,52,51,175,65,0,0,173,66,103,102,154,65,102,102,160,66,98,154,153,133,65,204,204,147,66,104,102,70,65,102,
// 		102,138,66,208,204,204,64,51,51,132,66,98,0,205,204,62,0,0,124,66,88,102,166,191,51,51,105,66,116,102,166,63,0,0,80,66,98,51,51,115,64,205,204,54,66,0,0,128,64,51,51,29,66,0,0,0,64,154,153,3,66,98,0,0,0,0,52,51,211,65,102,102,6,64,52,51,175,65,102,102,
// 		6,65,103,102,154,65,98,51,51,107,65,154,153,133,65,51,51,155,65,104,102,70,65,0,0,180,65,208,204,204,64,98,205,204,204,65,0,205,204,62,102,102,242,65,88,102,166,191,102,102,18,66,116,102,166,63,98,51,51,43,66,51,51,115,64,205,204,68,66,0,0,128,64,205,
// 		204,94,66,0,0,0,64,98,205,204,120,66,0,0,0,0,102,102,133,66,102,102,6,64,154,153,138,66,102,102,6,65,98,206,204,143,66,50,51,107,65,103,102,152,66,51,51,155,65,103,102,164,66,0,0,180,65,98,103,102,176,66,205,204,204,65,205,204,179,66,102,102,242,65,154,
// 		153,174,66,102,102,18,66,98,103,102,169,66,153,153,43,66,205,204,168,66,204,204,68,66,0,0,173,66,204,204,94,66,98,0,0,177,66,204,204,120,66,205,204,172,66,102,102,133,66,51,51,160,66,153,153,138,66,98,153,153,147,66,204,204,143,66,51,51,138,66,102,102,
// 		152,66,0,0,132,66,102,102,164,66,98,154,153,123,66,154,153,176,66,205,204,104,66,0,0,180,66,0,0,80,66,205,204,174,66,99,101,0,0};
// 
// 	Path path;
// 	path.loadPathFromData(pathData, sizeof(pathData));
// 	
// 	if (radius > 12.0f)
// 	{
// 		if (slider.isEnabled())
// 			g.setColour(slider.findColour(Slider::rotarySliderFillColourId).withAlpha(isMouseOver ? 1.0f : 0.7f));
// 		else
// 			g.setColour(Colour(0x80808080));
// 
// 		const float thickness = 0.7f;
// 
// 		{
// 			Path filledArc;
// 			filledArc.addPieSegment(rx, ry, rw, rw, rotaryStartAngle, angle, thickness);
// 			g.fillPath(filledArc);
// 		}
// 
// 		{
// 			const float innerRadius = radius * 0.2f;
// 			Path p;
// 			p.addTriangle(-innerRadius, 0.0f,
// 				0.0f, -radius * thickness * 1.1f,
// 				innerRadius, 0.0f);
// 
// 			p.addEllipse(-innerRadius, -innerRadius, innerRadius * 2.0f, innerRadius * 2.0f);
// 						
// 			AffineTransform gripxform = createTransformForKnobPath(path, centreX, centreY, angle);
// 
// 			g.fillPath(path, gripxform);
// 
// 			g.setColour(Colour(0, 0, 0));
// 			
// 			
// 			topImage = ImageFileFormat::loadFrom(File("D:/Temp/toptexture.png"));
// 			FillType fillType;
// 			AffineTransform fillxform;
// 			fillxform = fillxform.scaled(
// 				JUCE_LIVE_CONSTANT(1.2),
// 				JUCE_LIVE_CONSTANT(1.2))
// 				.translated(
// 					JUCE_LIVE_CONSTANT(35),
// 					JUCE_LIVE_CONSTANT(14)
// 					).rotated(
// 						(angle),
// 						JUCE_LIVE_CONSTANT(centreX),
// 						JUCE_LIVE_CONSTANT(centreY));
// 			fillType.setTiledImage(topImage, fillxform);
// 			
// 			/*g.setTiledImageFill(topImage, 
// 				JUCE_LIVE_CONSTANT(centreX), //108
// 				JUCE_LIVE_CONSTANT(centreY), //87
// 				1.0f);
// */
// 			g.setFillType(fillType);
// 
// 
// 			Path top;
// 			top.addEllipse(
// 				0, //37
// 				0, //16.8
// 				path.getBounds().getHorizontalRange().getLength() - 15, 
// 				path.getBounds().getVerticalRange().getLength() - 15);
// 
// 			AffineTransform topxform = createTransformForKnobPath(top, centreX, centreY, angle);
// 			g.fillPath(top, topxform);
// 				
// 			Path marker;
// 			marker.addEllipse(
// 				(72),
// 				(22),
// 				(5),
// 				(5));
// 			g.setColour(Colour(228, 228, 228));
// 			
// 			AffineTransform markerxform;
// 			markerxform = markerxform.rotated(angle, centreX, centreY);
// 			g.fillPath(marker, markerxform);
// 
// 		}
// 
// 		if (slider.isEnabled())
// 			g.setColour(slider.findColour(Slider::rotarySliderOutlineColourId));
// 		else
// 			g.setColour(Colour(0x80808080));
// 
// 		Path outlineArc;
// 		outlineArc.addPieSegment(rx, ry, rw, rw, rotaryStartAngle, rotaryEndAngle, thickness);
// 		outlineArc.closeSubPath();
// 
// 		g.strokePath(outlineArc, PathStrokeType(slider.isEnabled() ? (isMouseOver ? 2.0f : 1.2f) : 0.3f));
// 	} else
// 	{
// 		if (slider.isEnabled())
// 			g.setColour(slider.findColour(Slider::rotarySliderFillColourId).withAlpha(isMouseOver ? 1.0f : 0.7f));
// 		else
// 			g.setColour(Colour(0x80808080));
// 
// 		Path p;
// 		p.addEllipse(-0.4f * rw, -0.4f * rw, rw * 0.8f, rw * 0.8f);
// 		PathStrokeType(rw * 0.1f).createStrokedPath(p, p);
// 
// 		p.addLineSegment(Line<float>(0.0f, 0.0f, 0.0f, -radius), rw * 0.2f);
// 
// 		g.fillPath(p, AffineTransform::rotation(angle).translated(centreX, centreY));
// 	}
//}


/** Takes a path (SVG), the center x and y coordinates for a given component, and the angle for rotation
*** Returns the proper affine transform to control the knob*/
/*
static AffineTransform createTransformForKnobPath(Path path, float centreX, float centreY, float rotAngle)
{
float gripcenterx = path.getBounds().getCentreX();
float griptransx = centreX - gripcenterx;
float gripcentery = path.getBounds().getCentreY();
float griptransy = centreY - gripcentery;

AffineTransform gripxform = AffineTransform::translation(griptransx, griptransy);

gripxform = gripxform.rotated(rotAngle, centreX, centreY);
return gripxform;
}*/


void ZenLookAndFeel::drawButtonBackground(Graphics& g, Button& button, const Colour& backgroundColour,
                                          bool isMouseOverButton, bool isButtonDown)
{
	Colour darkColor(40, 40, 40);
	/*Colour baseColour(backgroundColour.withMultipliedSaturation(button.hasKeyboardFocus(true) ? 1.3f : 0.9f)
		.withMultipliedAlpha(button.isEnabled() ? 0.9f : 0.5f));*/

	Colour baseColour(darkColor.withMultipliedSaturation(button.hasKeyboardFocus(true) ? 1.3f : 0.9f)
	                           .withMultipliedAlpha(button.isEnabled() ? 0.9f : 0.5f));

	if (isButtonDown || isMouseOverButton) baseColour = baseColour.contrasting(isButtonDown ? 0.2f : 0.1f);

	const bool flatOnLeft = button.isConnectedOnLeft();
	const bool flatOnRight = button.isConnectedOnRight();
	const bool flatOnTop = button.isConnectedOnTop();
	const bool flatOnBottom = button.isConnectedOnBottom();

	const float width = button.getWidth() - 1.0f;
	const float height = button.getHeight() - 1.0f;

	if (width > 0 && height > 0)
	{
		const float cornerSize = 4.0f;

		Path outline;
		outline.addRoundedRectangle(0.5f, 0.5f, width, height, cornerSize, cornerSize,
		                            !(flatOnLeft || flatOnTop),
		                            !(flatOnRight || flatOnTop),
		                            !(flatOnLeft || flatOnBottom),
		                            !(flatOnRight || flatOnBottom));

		drawButtonShape(g, outline, baseColour, height);
	}
}

void ZenLookAndFeel::drawButtonShape(Graphics& g, const Path& outline, Colour baseColour, float height)
{
	const float mainBrightness = baseColour.getBrightness();
	const float mainAlpha = baseColour.getFloatAlpha();

	g.setGradientFill(ColourGradient(baseColour.brighter(0.2f), 0.0f, 0.0f,
	                                 baseColour.darker(0.25f), 0.0f, height, false));
	g.fillPath(outline);

	g.setColour(Colours::white.withAlpha(0.4f * mainAlpha * mainBrightness * mainBrightness));
	g.strokePath(outline, PathStrokeType(1.0f), AffineTransform::translation(0.0f, 1.0f)
	             .scaled(1.0f, (height - 1.6f) / height));

	g.setColour(Colours::black.withAlpha(0.4f * mainAlpha));
	g.strokePath(outline, PathStrokeType(1.0f));
}

Slider::SliderLayout ZenLookAndFeel::getSliderLayout(Slider& slider)
{
	// 1. compute the actually visible textBox size from the slider textBox size and some additional constraints
	ZenRotaryFilmStripSlider* zenSlider = dynamic_cast<ZenRotaryFilmStripSlider*>(&slider);
	

	int minXSpace = 0;
	int minYSpace = 0;

	if (zenSlider != nullptr)
	{
		ZenRotaryFilmStripSlider::TextEntryBoxPosition textBoxPos = zenSlider->getTextBoxPosition();

		if (textBoxPos == ZenRotaryFilmStripSlider::TextBoxLeft || textBoxPos == ZenRotaryFilmStripSlider::TextBoxRight) minXSpace = 30;
		else minYSpace = 15;

		Rectangle<int> localBounds = zenSlider->getLocalBounds();

		const int textBoxWidth = jmax(0, jmin(zenSlider->getTextBoxWidth(), localBounds.getWidth() - minXSpace));
		const int textBoxHeight = jmax(0, jmin(zenSlider->getTextBoxHeight(), localBounds.getHeight() - minYSpace));

		Slider::SliderLayout layout;

		// 2. set the textBox bounds

		if (textBoxPos != ZenRotaryFilmStripSlider::NoTextBox)
		{
			if (zenSlider->isBar())
			{
				layout.textBoxBounds = localBounds;
			} else
			{
				layout.textBoxBounds.setWidth(textBoxWidth);
				layout.textBoxBounds.setHeight(textBoxHeight);
				

				//Set X Coordinate of text box
				if (textBoxPos == ZenRotaryFilmStripSlider::TextBoxLeft)
				{
					layout.textBoxBounds.setX(0);
				}
				else if (textBoxPos == ZenRotaryFilmStripSlider::TextBoxRight)
				{
					layout.textBoxBounds.setX(localBounds.getWidth() - textBoxWidth);
				} else /* above or below -> centre horizontally */
				{
					layout.textBoxBounds.setX((localBounds.getWidth() - textBoxWidth) / 2);
// 					int dbgtest = layout.textBoxBounds.getX();
// 					DBG("Center horiz: " << layout.textBoxBounds.getX());
				}

				//Set Y Coordinate of text box
				if (textBoxPos == ZenRotaryFilmStripSlider::TextBoxCentered)
				{
					layout.textBoxBounds.setY((localBounds.getHeight() - textBoxHeight) / 2);
					//DBG("Center Vertical: " << layout.textBoxBounds.getY());
				} else if (textBoxPos == ZenRotaryFilmStripSlider::TextBoxAbove)
				{
					layout.textBoxBounds.setY(0); // Original
					//DBG("in textboxabove");
					
				} else if (textBoxPos == ZenRotaryFilmStripSlider::TextBoxBelow)
				{
					layout.textBoxBounds.setY(localBounds.getHeight() - textBoxHeight);
				}
				else /* left or right -> centre vertically */
				{
					layout.textBoxBounds.setY((localBounds.getHeight() - textBoxHeight) / 2);
				}
			}
		}

		// 3. set the zenSlider bounds
		layout.sliderBounds = localBounds;

		if (zenSlider->isBar())
		{
			layout.sliderBounds.reduce(1, 1); // bar border
		} else
		{
			if (textBoxPos == ZenRotaryFilmStripSlider::TextBoxLeft) layout.sliderBounds.removeFromLeft(textBoxWidth);
			else if (textBoxPos == ZenRotaryFilmStripSlider::TextBoxRight) layout.sliderBounds.removeFromRight(textBoxWidth);
			else if (textBoxPos == ZenRotaryFilmStripSlider::TextBoxAbove) layout.sliderBounds.removeFromTop(textBoxHeight);
			else if (textBoxPos == ZenRotaryFilmStripSlider::TextBoxBelow) layout.sliderBounds.removeFromBottom(textBoxHeight);

			const int thumbIndent = getSliderThumbRadius(*zenSlider);

			if (zenSlider->isHorizontal()) layout.sliderBounds.reduce(thumbIndent, 0);
			else if (zenSlider->isVertical()) layout.sliderBounds.reduce(0, thumbIndent);
		}

		return layout;
	}
	else
	{
		Slider::TextEntryBoxPosition textBoxPos = slider.getTextBoxPosition();

		if (textBoxPos == Slider::TextBoxLeft || textBoxPos == Slider::TextBoxRight) minXSpace = 30;
		else minYSpace = 15;

		Rectangle<int> localBounds = slider.getLocalBounds();

		const int textBoxWidth = jmax(0, jmin(slider.getTextBoxWidth(), localBounds.getWidth() - minXSpace));
		const int textBoxHeight = jmax(0, jmin(slider.getTextBoxHeight(), localBounds.getHeight() - minYSpace));

		Slider::SliderLayout layout;

		// 2. set the textBox bounds

		if (textBoxPos != Slider::NoTextBox)
		{
			if (slider.isBar())
			{
				layout.textBoxBounds = localBounds;
			}
			else
			{
				layout.textBoxBounds.setWidth(textBoxWidth);
				layout.textBoxBounds.setHeight(textBoxHeight);

				if (textBoxPos == Slider::TextBoxLeft) layout.textBoxBounds.setX(0);
				else if (textBoxPos == Slider::TextBoxRight) layout.textBoxBounds.setX(localBounds.getWidth() - textBoxWidth);
				else /* above or below -> centre horizontally */ layout.textBoxBounds.setX((localBounds.getWidth() - textBoxWidth) / 2);

				if (textBoxPos == Slider::TextBoxAbove)
				{
					//layout.textBoxBounds.setY(0); // Original
					DBG("in textboxabove");
					layout.textBoxBounds.setY((localBounds.getHeight() - textBoxHeight) / 2);
				}
				else if (textBoxPos == Slider::TextBoxBelow) layout.textBoxBounds.setY(localBounds.getHeight() - textBoxHeight);
				else /* left or right -> centre vertically */ layout.textBoxBounds.setY((localBounds.getHeight() - textBoxHeight) / 2);
			}
		}

		// 3. set the slider bounds

		layout.sliderBounds = localBounds;

		if (slider.isBar())
		{
			layout.sliderBounds.reduce(1, 1); // bar border
		}
		else
		{
			if (textBoxPos == Slider::TextBoxLeft) layout.sliderBounds.removeFromLeft(textBoxWidth);
			else if (textBoxPos == Slider::TextBoxRight) layout.sliderBounds.removeFromRight(textBoxWidth);
			else if (textBoxPos == Slider::TextBoxAbove) layout.sliderBounds.removeFromTop(textBoxHeight);
			else if (textBoxPos == Slider::TextBoxBelow) layout.sliderBounds.removeFromBottom(textBoxHeight);

			const int thumbIndent = getSliderThumbRadius(slider);

			if (slider.isHorizontal()) layout.sliderBounds.reduce(thumbIndent, 0);
			else if (slider.isVertical()) layout.sliderBounds.reduce(0, thumbIndent);
		}

		return layout;
	}
}


ZenLabel* ZenLookAndFeel::createZenSliderTextBox(Slider& slider)
{

	// Overridden code:
	ZenLabel* const zLabel = new ZenLabel(slider.getName(), true);

	zLabel->setJustificationType(Justification::centred);
	zLabel->setKeyboardType(TextInputTarget::decimalKeyboard);

	zLabel->setColour(Label::textColourId, slider.findColour(Slider::textBoxTextColourId));
	zLabel->setColour(Label::backgroundColourId,
		(slider.getSliderStyle() == Slider::LinearBar || slider.getSliderStyle() == Slider::LinearBarVertical)
		? Colours::transparentBlack
		: slider.findColour(Slider::textBoxBackgroundColourId));
	zLabel->setColour(Label::outlineColourId, slider.findColour(Slider::textBoxOutlineColourId));
	zLabel->setColour(TextEditor::textColourId, slider.findColour(Slider::textBoxTextColourId));
	zLabel->setColour(TextEditor::backgroundColourId,
		slider.findColour(Slider::textBoxBackgroundColourId)
		.withAlpha((slider.getSliderStyle() == Slider::LinearBar || slider.getSliderStyle() == Slider::LinearBarVertical)
			? 0.7f : 1.0f));
	zLabel->setColour(TextEditor::outlineColourId, slider.findColour(Slider::textBoxOutlineColourId));
	zLabel->setColour(TextEditor::highlightColourId, slider.findColour(Slider::textBoxHighlightColourId));

	ZenRotaryFilmStripSlider* zSlider = dynamic_cast<ZenRotaryFilmStripSlider*>(&slider);
	if (NULL != zSlider && zSlider->getHeight() != 0)
	{
		//slider->pimpl->sliderRect
		int sWidth = zSlider->getSliderRect().getWidth();
		int sHeight = zSlider->getSliderRect().getHeight();
		DBG(zSlider->getName() << " HxW: " << zSlider->getHeight() << " x " << String(zSlider->getWidth()));
	}
	
	return zLabel;
}
