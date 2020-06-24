#pragma once
#include <wx/wx.h>
#include <wx/display.h>
#include "ScrollableWidgets.h"

class WidgetMenu : public WidgetFrame
{
public:
	WidgetMenu();
	~WidgetMenu();
	WidgetMenu(WidgetMenu const&) = delete;
	WidgetMenu(WidgetMenu&&) = delete;
	WidgetMenu& operator = (WidgetMenu const&) = delete;
	WidgetMenu& operator = (WidgetMenu&&) = delete;

	void OnClickHide(wxCommandEvent& event);
	void OnClickSettings(wxCommandEvent& event);

	DECLARE_EVENT_TABLE();

public:
	wxPanel* widgetsPanel = nullptr;
	ScrollableWidgets* scroller = nullptr;

private:
	wxButton* showhide = nullptr;
	wxButton* settings = nullptr;

	wxStaticText* widgetsText = nullptr;
	bool isShown = true;

	wxStaticText* placeholder = new wxStaticText(this, wxID_ANY, "");
};

