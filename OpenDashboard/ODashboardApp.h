#pragma once
#include "MainFrame.h"
#include "WidgetFrame.h"
#include "TestWidget.h"
#include <list>

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
	
	void changeState();
	MainFrame* mainframe = nullptr;
	
	std::vector<WidgetFrame*> widgets;
	void addToVector(std::vector<WidgetFrame*>& widgets, int index);

	//TestWidget* widget = nullptr;
};
	
