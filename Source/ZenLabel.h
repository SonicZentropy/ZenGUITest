/*==============================================================================
//  ZenLabel.h
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 21 Apr 2016 3:15:40pm
//  Copyright (C) 2016 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: Generic Header File
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
===============================================================================*/

#ifndef ZENLABEL_H_INCLUDED
#define ZENLABEL_H_INCLUDED

#include "JuceHeader.h"

class ZenLabel : public Label
{
public:
	ZenLabel(String inName, bool inTextHasShadow = false);
	void mouseUp(const MouseEvent& e) override;
	void showEditor() override;
	bool getTextHasShadow() const { return textHasShadow; }
	void setTextHasShadow(bool inValue) { textHasShadow = inValue; }

	void mouseDrag(const MouseEvent& event) override;
protected:
	bool textHasShadow;
	//TextEditor* createEditorComponent() override;
	//void editorAboutToBeHidden(TextEditor*) override;
	//void focusGained(FocusChangeType) override;
	//void textEditorTextChanged(TextEditor&) override;
	//void textEditorReturnKeyPressed(TextEditor&) override;
	//void textEditorEscapeKeyPressed(TextEditor&) override;
	//void textEditorFocusLost(TextEditor&) override;
};



#endif  // ZENLABEL_H_INCLUDED
