#pragma once
#include "MainFrame.h"

class ODashboardApp : public wxApp
{

private:
	static ODashboardApp* instance;

public:
	ODashboardApp();
	~ODashboardApp();

	static const int keycomb1 = 27;
	static const int keycomb2 = 9;
	static ODashboardApp* getApp();

public:
	virtual bool OnInit();
	MainFrame* mainframe = nullptr;
};

