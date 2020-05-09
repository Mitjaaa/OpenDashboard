#pragma once
#include "wx/wx.h"
#include "WidgetFrame.h"

class ScrollableWidgets : public wxScrolledWindow
{
public:
	ScrollableWidgets(wxWindow* parent, wxPoint pos, wxSize size);
	~ScrollableWidgets();

	wxBoxSizer* sizer = nullptr;
	void addToSizer(WidgetFrame* widget);
	void WidgetSelected(wxCommandEvent& event);
	void configureSizer();
};

