#pragma once
#include "wx/wx.h"

class MainFrame : public wxFrame
{
public:
	MainFrame();
	~MainFrame();

	void OnFocus(wxFocusEvent& event);

	DECLARE_EVENT_TABLE();

private:
	void initDashboard();
	bool inForeground = true;
};

