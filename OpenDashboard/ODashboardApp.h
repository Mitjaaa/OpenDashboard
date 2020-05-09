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
	virtual bool OnInit();
	
	void changeState();
	void addWidgetsToMenu();
	void UpdateWidgets();

	void createSelectedWidget(wxCommandEvent& event);

	MainFrame* mainframe = nullptr;
	WidgetMenu* menu = nullptr;

	std::vector<WidgetFrame*> widgets;
	void addToVector(WidgetFrame* widget);
	void removeFromVector(WidgetFrame* widget);

	/*template<typename Base, typename T>
	inline bool instanceof(const T* ptr) {
		return dynamic_cast<const Base*>(ptr) != nullptr;
	}*/
};
	
