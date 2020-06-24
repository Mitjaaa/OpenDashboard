#pragma once
#include <wx/wx.h>
#include "WidgetFrame.h"

class ImageWindow : public wxWindow
{
public:
	ImageWindow(wxWindow* parent, wxPoint pos, wxSize size, WidgetFrame* parentframe);
	~ImageWindow();

	wxBoxSizer* sizer = nullptr;
	wxSize imgSize;

	wxImage image;

	wxString imgFile;
	wxBitmapType imgFormat;

	void setImage(wxString file, wxBitmapType format);

	void paintEvent(wxPaintEvent& evt);
	void resize();

	int factor = 1;

	WidgetFrame* parent = nullptr;
	void OnImageClick(wxMouseEvent& event);

	DECLARE_EVENT_TABLE()

private:
	bool isImageSet = false;
};

