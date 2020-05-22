#pragma once
#include "MainFrame.h"
#include "TimeWidget.h"
#include "WidgetMenu.h"
#include "ImageWidget.h"

#include "windows_listener.h"

#include <list>
#include <thread>

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
	void initWidgetclasses();
	virtual bool OnInit();

	void changeState();
	void UpdateWidgets();
	
	void implementWidget(WidgetFrame* widget);

	void createSelectedWidget(wxCommandEvent& event);

	MainFrame* mainframe = nullptr;
	WidgetMenu* menu = nullptr;

	std::vector<WidgetFrame*> widgets;
	std::vector<WidgetFrame*> widgetClasses;

	void addToWidgets(WidgetFrame* widget);
	void addToWidgetclasses(WidgetFrame* widget);
	void removeFromWidgets(WidgetFrame* widget);

};
	
