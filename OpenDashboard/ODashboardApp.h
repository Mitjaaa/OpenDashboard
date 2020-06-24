#pragma once
#include <wx/wx.h>
#include <thread>
#include "MainFrame.h"
#include "WidgetMenu.h"
#include "WidgetFrame.h"
#include "TimeWidget.h"
#include "ImageWidget.h"
#include "windows_listener.h"

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

	MainFrame* mainframe = nullptr;
	void initWidgetclasses();
	virtual bool OnInit();

	void changeState();

	void UpdateWidgets();
	void implementWidgets();
	void createSelectedWidget(wxCommandEvent& event);

	WidgetMenu* menu = nullptr;
	int menuEntries = 0;

	std::vector<WidgetFrame*> widgets;
	std::vector<WidgetFrame*> widgetClasses;

	void addToWidgets(WidgetFrame* widget);
	void addToWidgetclasses(WidgetFrame* widget);
	void removeFromWidgets(WidgetFrame* widget);

};

