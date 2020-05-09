#pragma once
#include "wx/wx.h"

class WidgetFrame : public wxFrame
{
public:
	WidgetFrame(std::string name, bool useEvents, bool showName, int idForHandlers);
	~WidgetFrame();
	WidgetFrame(WidgetFrame const&) = delete;
	WidgetFrame(WidgetFrame&&) = delete;
    WidgetFrame& operator = (WidgetFrame const&) = delete;
    WidgetFrame& operator = (WidgetFrame&&) = delete;

	void OnLeftDown(wxMouseEvent& event);
	void OnMouseMove(wxMouseEvent& event);
	void OnLeftUp(wxMouseEvent& event);

	void UpdateSize(wxSize size, bool useClose);
	
	void SetVectorIndex(int index);
	int vectorIndex = 0;

	WidgetFrame* getWidgetFrame();
	wxStaticText* wname = nullptr;

	std::string widgetName;
	int handlerID = 0;

	DECLARE_EVENT_TABLE();

private:
	wxPoint mouseDownPos;
	
	wxButton* close;
	void OnClose(wxCommandEvent& event);

	bool capturing = false;
	bool events = false;
};

