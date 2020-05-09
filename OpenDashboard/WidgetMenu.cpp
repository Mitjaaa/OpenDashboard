#include "WidgetMenu.h"
#include <thread>
#include "TimeWidget.h"
#include "SettingsWidget.h"
#include "ODashboardApp.h"

BEGIN_EVENT_TABLE(WidgetMenu, wxFrame)
	EVT_BUTTON(25000, OnClickHide)
	EVT_BUTTON(25001, OnClickSettings)
END_EVENT_TABLE()


WidgetMenu::WidgetMenu() : WidgetFrame("Menu", false, false, wxID_ANY)
{
	int width = wxDisplay().GetGeometry().GetWidth();
	int height = wxDisplay().GetGeometry().GetHeight();

	SetWindowStyle(wxSTAY_ON_TOP | wxFRAME_TOOL_WINDOW);
	UpdateSize(wxSize(150, height), false);
	SetPosition(wxPoint(width-150, 0));
	SetBackgroundColour(wxColour(46, 46, 46));

	widgetsText = new wxStaticText(this, wxID_ANY, "Widgets", wxPoint(40, 5), wxSize(20, 20));
	widgetsText->SetFont(wxFont(15,
		wxFONTFAMILY_DEFAULT,
		wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_NORMAL,
		false));
	widgetsText->SetForegroundColour(wxColour(39, 232, 167));

	showhide = new wxButton(this, 25000, "hide", wxPoint(0, height-25), wxSize(150, 25), wxBORDER_NONE);
	showhide->SetBackgroundColour(wxColour(64, 64, 64));			
	showhide->SetForegroundColour(wxColour(39, 232, 167));
	showhide->SetCursor(wxCURSOR_HAND);

	settings = new wxButton(this, 25001, "settings", wxPoint(0, height - 55), wxSize(150, 25), wxBORDER_NONE);
	settings->SetBackgroundColour(wxColour(64, 64, 64));
	settings->SetForegroundColour(wxColour(223, 69, 118));
	settings->SetCursor(wxCURSOR_HAND);

	widgetsPanel = new wxPanel(this, wxID_ANY, wxPoint(0, 20), wxSize(150, height-75));

	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	scroller = new ScrollableWidgets(widgetsPanel, wxPoint(0, 20), wxSize(150, height-95));
	sizer->Add(scroller, 1);
	widgetsPanel->SetSizer(sizer);
}
	
WidgetMenu::~WidgetMenu()		
{
}

void WidgetMenu::OnClickHide(wxCommandEvent& event)
{
	int width = wxDisplay().GetGeometry().GetWidth();
	int height = wxDisplay().GetGeometry().GetHeight();

	if (isShown) {
		//hideAllItems();

		widgetsText->SetPosition(wxPoint(40, 50));
		showhide->SetPosition(wxPoint(0, 0));	
		showhide->SetLabel("show");
		SetSize(wxSize(150, 25));
		SetPosition(wxPoint(width - 150, height - 25));

		isShown = false;
	}
	else {
		//showAllItems();	

		widgetsText->SetPosition(wxPoint(40, 5));
		showhide->SetPosition(wxPoint(0, height - 25));
		showhide->SetLabel("hide");
		SetSize(wxSize(150, height));
		SetPosition(wxPoint(width - 150, 0));

		isShown = true;
	}
}

void WidgetMenu::OnClickSettings(wxCommandEvent& event)
{
	SettingsWidget* settings = new SettingsWidget();
	settings->Show();
	ODashboardApp::getApp()->addToVector(settings);
}


