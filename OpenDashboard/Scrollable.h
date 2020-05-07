#pragma once
#include "wx/wx.h"
#include "WidgetFrame.h"

class Scrollable : public wxScrolledWindow
{
public:
	Scrollable(wxWindow* parent, wxPoint pos, wxSize size);
	~Scrollable();

	wxBoxSizer* sizer = nullptr;
	void addToSizer(WidgetFrame* widget);
	void WidgetSelected(wxCommandEvent& event);
	void configureSizer();

	WidgetFrame* mframe = nullptr;
};

