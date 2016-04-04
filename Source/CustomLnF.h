/*
==============================================================================
This file is part of the JUCE library - "Jules' Utility Class Extensions"
Copyright 2004-11 by Raw Material Software Ltd.
------------------------------------------------------------------------------
JUCE can be redistributed and/or modified under the terms of the GNU General
Public License (Version 2), as published by the Free Software Foundation.
A copy of the license is included in the JUCE distribution, or can be found
online at www.gnu.org/licenses.
JUCE is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
------------------------------------------------------------------------------
To release a closed-source product which uses JUCE, commercial licenses are
available: visit www.rawmaterialsoftware.com/juce for more information.
==============================================================================
*/

#ifndef __JUCE_LookAndFeelCustom_JUCEHEADER__
#define __JUCE_LookAndFeelCustom_JUCEHEADER__

#include "JuceHeader.h"


//==============================================================================
/**
The original Juce look-and-feel.
*/
class /*JUCE_API*/  LookAndFeelCustom : public LookAndFeel
{
public:
	//==============================================================================
	/** Creates the default JUCE look and feel. */
	LookAndFeelCustom();

	/** Destructor. */
	virtual ~LookAndFeelCustom();

	void drawRotarySlider(Graphics & 	g,
		int 	x,
		int 	y,
		int 	width,
		int 	height,
		float 	sliderPosProportional,
		float 	rotaryStartAngle,
		float 	rotaryEndAngle,
		Slider & 	slider) override;




	//==============================================================================
	// All of the stuff from here down has just been copied from the oldLookAndFeel 
	// class and hacked a bit to toy with it.
	//==============================================================================


	//==============================================================================
	/** Draws the lozenge-shaped background for a standard button. */
	void drawButtonBackground(Graphics& g,
		Button& button,
		const Colour& backgroundColour,
		bool isMouseOverButton,
		bool isButtonDown) override;


	/** Draws the contents of a standard ToggleButton. */
	void drawToggleButton(Graphics& g,
		ToggleButton& button,
		bool isMouseOverButton,
		bool isButtonDown) override;

	void drawTickBox(Graphics& g,
		Component& component,
		float x, float y, float w, float h,
		bool ticked,
		bool isEnabled,
		bool isMouseOverButton,
		bool isButtonDown) override;

	//==============================================================================
	void drawProgressBar(Graphics& g, ProgressBar& progressBar,
		int width, int height,
		double progress, const String& textToShow) override;

	//==============================================================================
	void drawScrollbarButton(Graphics& g,
		ScrollBar& scrollbar,
		int width, int height,
		int buttonDirection,
		bool isScrollbarVertical,
		bool isMouseOverButton,
		bool isButtonDown) override;

	void drawScrollbar(Graphics& g,
		ScrollBar& scrollbar,
		int x, int y,
		int width, int height,
		bool isScrollbarVertical,
		int thumbStartPosition,
		int thumbSize,
		bool isMouseOver,
		bool isMouseDown) override;

	ImageEffectFilter* getScrollbarEffect() override;

	//==============================================================================
	void drawTextEditorOutline(Graphics& g,
		int width, int height,
		TextEditor& textEditor) override;

	//==============================================================================
	/** Fills the background of a popup menu component. */
	void drawPopupMenuBackground(Graphics& g, int width, int height) override;

	void drawMenuBarBackground(Graphics& g, int width, int height,
		bool isMouseOverBar,
		MenuBarComponent& menuBar) override;

	//==============================================================================
	void drawComboBox(Graphics& g, int width, int height,
		bool isButtonDown,
		int buttonX, int buttonY,
		int buttonW, int buttonH,
		ComboBox& box) override;

	//virtual const Font getComboBoxFont (ComboBox& box);

	//==============================================================================
	void drawLinearSlider(Graphics& g,
		int x, int y,
		int width, int height,
		float sliderPos,
		float minSliderPos,
		float maxSliderPos,
		const Slider::SliderStyle style,
		Slider& slider) override;

	int getSliderThumbRadius(Slider& slider) override;

	Button* createSliderButton(bool isIncrement) override;

	ImageEffectFilter* getSliderEffect() override;

	//==============================================================================
	void drawCornerResizer(Graphics& g,
		int w, int h,
		bool isMouseOver,
		bool isMouseDragging) override;

	Button* createDocumentWindowButton(int buttonType) override;

	void positionDocumentWindowButtons(DocumentWindow& window,
		int titleBarX, int titleBarY,
		int titleBarW, int titleBarH,
		Button* minimiseButton,
		Button* maximiseButton,
		Button* closeButton,
		bool positionTitleBarButtonsOnLeft) override;


private:
	//==============================================================================
	DropShadowEffect scrollbarShadow;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LookAndFeelCustom);
};


#endif   // __JUCE_LookAndFeelCustom_JUCEHEADER__