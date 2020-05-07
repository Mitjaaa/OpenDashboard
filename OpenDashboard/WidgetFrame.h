#pragma once
#include "wx/wx.h"

class WidgetFrame : public wxFrame
{
public:
	WidgetFrame(std::string name, bool useEvents, int idForHandlers);
	~WidgetFrame();
	WidgetFrame(WidgetFrame const&) = delete;
	WidgetFrame(WidgetFrame&&) = delete;
    WidgetFrame& operator = (WidgetFrame const&) = delete;
    WidgetFrame& operator = (WidgetFrame&&) = delete;

	void OnLeftDown(wxMouseEvent& event);
	void OnMouseMove(wxMouseEvent& event);
	void OnLeftUp(wxMouseEvent& event);

	WidgetFrame* getWidgetFrame();	
	std::string widgetName;
	int handlerID = 0;

	DECLARE_EVENT_TABLE();

private:
	wxPoint mouseDownPos;
	bool capturing = false;
	bool events = false;
};

