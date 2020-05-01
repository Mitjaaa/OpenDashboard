#pragma once

#include "wx/wx.h"
#include "MainFrame.h"

class ODashboardApp : public wxApp
{
public:
	ODashboardApp();
	~ODashboardApp();

private:
	MainFrame* mainframe = nullptr;

public:
	virtual bool OnInit();
};

