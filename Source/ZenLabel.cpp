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
	//this->setInterceptsMouseClicks(false, false);
	this->setEditable(false, true, false);
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

// Pass mouse event on to parent so label doesn't interfere with mouse drag changing values
void ZenLabel::mouseUp(const MouseEvent& event)
{
//	DBG("Zen label mouse up");
	Component* parentComp = getParentComponent();
	parentComp->mouseUp(event.getEventRelativeTo(parentComp));
// 	if (//editSingleClick
// 		this->isEditableOnSingleClick()
// 		&& isEnabled()
// 		&& contains(event.getPosition())
// 		&& !(event.mouseWasDraggedSinceMouseDown() || event.mods.isPopupMenu()))
// 	{
// 		setColour(Slider::textBoxTextColourId, Colours::black);
// 		showEditor();
// 	}

}

// Pass mouse event on to parent so label doesn't interfere with mouse drag changing values
void ZenLabel::mouseDrag(const MouseEvent& event)
{
	//DBG("In zenLabel mouse drag");
	Component* parentComp = getParentComponent();	
	parentComp->mouseDrag(event.getEventRelativeTo(parentComp));
}

void ZenLabel::mouseDoubleClick(const MouseEvent& event)
{
	DBG("In ZenLabel::mouseDoubleClick(MouseEvent) ");
	if (isEnabled()
		&& contains(event.getPosition())
		&& !(event.mouseWasDraggedSinceMouseDown() || event.mods.isPopupMenu()))
	{
		setColour(Slider::textBoxTextColourId, Colours::black);
		showEditor();
	}
	//throw std::logic_error("The method or operation is not implemented.");
}

// Pass mouse event on to parent so label doesn't interfere with mouse drag changing values
void ZenLabel::mouseDown(const MouseEvent& event)
{
	//DBG("In ZenLabel::mouseDown(event) ");
	Component* parentComp = getParentComponent();
	parentComp->mouseDown(event.getEventRelativeTo(parentComp));
	//throw std::logic_error("The method or operation is not implemented.");
}


static void copyColourIfSpecified(Label& l, TextEditor& ed, int colourID, int targetColourID)
{
	if (l.isColourSpecified(colourID) || l.getLookAndFeel().isColourSpecified(colourID))
		ed.setColour(targetColourID, l.findColour(colourID));
}

TextEditor* ZenLabel::createEditorComponent()
{
	TextEditor* const ed = new TextEditor(getName());
	ed->applyFontToAllText(getLookAndFeel().getLabelFont(*this));
	copyAllExplicitColoursTo(*ed);

	copyColourIfSpecified(*this, *ed, textWhenEditingColourId, TextEditor::textColourId);
	copyColourIfSpecified(*this, *ed, backgroundWhenEditingColourId, TextEditor::backgroundColourId);
	copyColourIfSpecified(*this, *ed, outlineWhenEditingColourId, TextEditor::focusedOutlineColourId);

	ed->setSize(getWidth() * 2, getHeight());

	return ed;
}

void ZenLabel::editorAboutToBeHidden(TextEditor* textEditor)
{
	if (ComponentPeer* const peer = getPeer())
		peer->dismissPendingTextInput();

	Component::BailOutChecker checker(this);
	listeners.callChecked(checker, &LabelListener::editorHidden, this, *textEditor);
}
