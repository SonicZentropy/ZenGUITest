/*==============================================================================
//  ZenLabel.cpp
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 21 Apr 2016 3:15:40pm
//  Copyright (C) 2016 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: Generic CPP File
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
===============================================================================*/

#include "ZenLabel.h"

ZenLabel::ZenLabel(String inName, bool inTextHasShadow)
	:Label(inName)
{
	textHasShadow = inTextHasShadow;
	this->setEditable(false, true, false);
}

void ZenLabel::mouseUp(const MouseEvent& e)
{
	if (//editSingleClick
		this->isEditableOnSingleClick()
		&& isEnabled()
		&& contains(e.getPosition())
		&& !(e.mouseWasDraggedSinceMouseDown() || e.mods.isPopupMenu()))
	{
		setColour(Slider::textBoxTextColourId, Colours::black);
		showEditor();
	}
}

void ZenLabel::showEditor()
{
	if (editor == nullptr)
	{
		addAndMakeVisible(editor = createEditorComponent());
		//editor->setColour(TextEditor::textColourId, Colours::black);
		editor->setColour(TextEditor::backgroundColourId, Colour(0x00ffffff));
		editor->setColour(TextEditor::highlightColourId, Colour(0xBBffffff));
		//editor->setColour(TextEditor::outlineColourId, Colour(0xFF00FF00));
		editor->setColour(TextEditor::focusedOutlineColourId, Colour(0xFF00FF00));
		editor->setText(getText(), false);
		editor->setKeyboardType(keyboardType);
		editor->addListener(this);
		editor->grabKeyboardFocus();

		if (editor == nullptr) // may be deleted by a callback
			return;

		editor->setHighlightedRegion(Range<int>(0, textValue.toString().length()));

		resized();
		repaint();

		editorShown(editor);

		enterModalState(false);
		editor->grabKeyboardFocus();
	}
}

void ZenLabel::mouseDrag(const MouseEvent& event)
{
	DBG("In zenLabel mouse drag");
	Component* testcomp = getParentComponent();
	getParentComponent()->mouseDrag(event);
}
