#pragma once
#include "wx/wx.h"
#include "WidgetFrame.h"
#include "ImageWindow.h"
#include "WidgetText.h"

class ImageWidget : public WidgetFrame
{
public:
	ImageWidget();
	~ImageWidget();

private:
	wxTextCtrl* filepath = nullptr;
	wxButton* chooseFile = nullptr;

	wxChoice* factorChoice = nullptr;
	wxStaticText* factorText = nullptr;

	wxBoxSizer* sizer;
	ImageWindow* image = nullptr;

	wxImage arrow_down;
	wxFileDialog* openFileDialog;
	
	void OnChoose(wxCommandEvent& event);
	void UpdateWidgetSize(wxSize size, bool isImageShowing);
};

