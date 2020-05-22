#include "ODashboardApp.h"

wxIMPLEMENT_APP(ODashboardApp);	

ODashboardApp* ODashboardApp::instance = new ODashboardApp(); 


ODashboardApp::ODashboardApp()
{
}

ODashboardApp::~ODashboardApp()
{
}

void listenForActivation()
{
	windows_listener listen = *new windows_listener();
}

ODashboardApp* ODashboardApp::getApp()
{
	if (instance == NULL) {
		instance = new ODashboardApp();
	}
	
	return instance;
}

void ODashboardApp::initWidgetclasses()
{
	implementWidget(new TimeWidget(true));
	implementWidget(new ImageWidget());

	menu->scroller->configureSizer();
}

bool ODashboardApp::OnInit()
{
	menu = new WidgetMenu();
	widgets = *new std::vector<WidgetFrame*>();

	mainframe = new MainFrame();
	changeState();
	initWidgetclasses();

	std::thread t1(listenForActivation);
	t1.detach();
	
	return true;
}

void ODashboardApp::changeState()
{
	if (mainframe->IsShown()) {
		mainframe->Hide();
		menu->Hide();

		unsigned int vSize = widgets.size();
		for (unsigned int i = 0; i < vSize; i++) {
			widgets[i]->Hide();
		}
	}
	else {
		mainframe->Show();
		menu->Show();

		UpdateWidgets();
	}
}

void ODashboardApp::UpdateWidgets() {
	unsigned int vSize = widgets.size();
	for (unsigned int i = 0; i < vSize; i++) {
		if(!widgets[i]->IsShown())
			widgets[i]->Show();
	}
}

void ODashboardApp::implementWidget(WidgetFrame* widget) {
	menu->scroller->addToSizer(widget);
	addToWidgetclasses(widget);
}

void ODashboardApp::createSelectedWidget(wxCommandEvent& event)
{
	//if (event.GetId() == 24000) addToWidgets(new TimeWidget(true));
	//if (event.GetId() == 24001) addToWidgets(new ImageWidget());
	//Add more WidgetIDs				

	unsigned int vSize = widgetClasses.size();
	for (unsigned int i = 0; i < vSize; i++) {
		if (event.GetId() == widgetClasses[i]->handlerID) {
			addToWidgets(widgetClasses[i]->createNewObj());
			break;
		}
	}

	UpdateWidgets();
}


void ODashboardApp::addToWidgets(WidgetFrame* widget)
{
	widgets.push_back(widget);
	widget->SetVectorIndex(widgets.size());

	WidgetFrame* test = new TimeWidget(true);
	widgetClasses.push_back(test);
	implementWidget(test);
}

void ODashboardApp::addToWidgetclasses(WidgetFrame* widget)
{
	widgetClasses.push_back(widget);
}

void ODashboardApp::removeFromWidgets(WidgetFrame* widget)
{
	unsigned int vSize = widgets.size();
	for (unsigned int i = 0; i < vSize; i++) {
		if (widgets[i] == widget) {
			widgets.erase(widgets.begin() + i);
			break;	
		}
	}
}
	