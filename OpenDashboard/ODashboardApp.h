#pragma once
#include "MainFrame.h"
#include "WidgetFrame.h"
#include "TimeWidget.h"
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
	void addWidgets();
	MainFrame* mainframe = nullptr;
	
	std::vector<WidgetFrame*> widgets;
	void addToVector(std::vector<WidgetFrame*>& widgets, WidgetFrame* widget);

	/*template<typename Base, typename T>
	inline bool instanceof(const T* ptr) {
		return dynamic_cast<const Base*>(ptr) != nullptr;
	}*/
};
	
