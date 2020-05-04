#pragma once
#include "MainFrame.h"
#include "WidgetFrame.h"

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
	bool active = false;

	virtual bool OnInit();
	void changeState();
	MainFrame* mainframe = nullptr;
	WidgetFrame* widget = nullptr;
};

