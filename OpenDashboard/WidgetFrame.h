#pragma once
#include "wx/wx.h"

class WidgetFrame : public wxFrame
{
public:
	WidgetFrame();
	~WidgetFrame();
	WidgetFrame(WidgetFrame const&) = delete;
	WidgetFrame(WidgetFrame&&) = delete;
	WidgetFrame& operator = (WidgetFrame const&) = delete;
	WidgetFrame& operator = (WidgetFrame&&) = delete;


	void OnLeftDown(wxMouseEvent& event);
	void OnMouseMove(wxMouseEvent& event);
	void OnLeftUp(wxMouseEvent& event);

	DECLARE_EVENT_TABLE();

private:
	wxPoint mouseDownPos;
	bool capturing = false;
};

