#include "WidgetMenu.h"
#include "SettingsWidget.h"
#include "ODashboardApp.h"
#include "Colors.h"

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
	SetPosition(wxPoint(width - 150, 0));
	SetBackgroundColour(color3);

	widgetsText = new wxStaticText(this, wxID_ANY, "Widgets", wxPoint(40, 5), wxSize(20, 20));
	widgetsText->SetFont(wxFont(15,
		wxFONTFAMILY_DEFAULT,
		wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_NORMAL,
		false));
	widgetsText->SetForegroundColour(textcolor1);

	showhide = new wxButton(this, 25000, "hide", wxPoint(0, height - 25), wxSize(150, 25), wxBORDER_NONE);
	showhide->SetBackgroundColour(color1);
	showhide->SetForegroundColour(textcolor1);
	showhide->SetCursor(wxCURSOR_HAND);

	settings = new wxButton(this, 25001, "settings", wxPoint(0, height - 55), wxSize(150, 25), wxBORDER_NONE);
	settings->SetBackgroundColour(color1);
	settings->SetForegroundColour(textcolor3);
	settings->SetCursor(wxCURSOR_HAND);

	widgetsPanel = new wxPanel(this, wxID_ANY, wxPoint(0, 20), wxSize(150, height - 75));

	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	scroller = new ScrollableWidgets(widgetsPanel, wxPoint(0, 20), wxSize(150, height - 95));
	sizer->Add(scroller, 1);
	widgetsPanel->SetSizer(sizer);
}

WidgetMenu::~WidgetMenu() {}

void WidgetMenu::OnClickHide(wxCommandEvent& event)
{
	int width = wxDisplay().GetGeometry().GetWidth();
	int height = wxDisplay().GetGeometry().GetHeight();

	if (isShown) {
		widgetsText->SetPosition(wxPoint(40, 50));
		showhide->SetPosition(wxPoint(0, 0));
		showhide->SetLabel("show");
		SetSize(wxSize(150, 25));
		SetPosition(wxPoint(width - 150, height - 25));

		isShown = false;
	}
	else {
		widgetsText->SetPosition(wxPoint(40, 5));
		showhide->SetPosition(wxPoint(0, height - 25));
		showhide->SetLabel("hide");
		SetSize(wxSize(150, height));
		SetPosition(wxPoint(width - 150, 0));

		isShown = true;
	}
}

bool settingsActive = false;
SettingsWidget* settingsWidget = nullptr;

void WidgetMenu::OnClickSettings(wxCommandEvent& event)
{
	if (settingsActive) {
		settingsWidget->Hide();
		settings->SetForegroundColour(textcolor3);

		//save settings


		ODashboardApp::getApp()->removeFromWidgets(settingsWidget);
	}
	else {
		if(settingsWidget == nullptr) 
			settingsWidget = new SettingsWidget();

		settings->SetForegroundColour(textcolor4);

		
		//load settings
		
		settingsWidget->resetPosition();
		settingsWidget->Show();
		ODashboardApp::getApp()->addToWidgets(settingsWidget);
	}

	settingsActive = !settingsActive;
}


