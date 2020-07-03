#include "SettingsWidget.h"
#include "ODashboardApp.h"
#include "Colors.h"
#include "ClrPicker.h"

SettingsWidget::SettingsWidget() : WidgetFrame("Settings", true, true, 24002)
{
	int width = wxDisplay().GetGeometry().GetWidth();
	int height = wxDisplay().GetGeometry().GetHeight();

	SetWindowStyle(wxSTAY_ON_TOP | wxFRAME_TOOL_WINDOW);
	UpdateSize(wxSize(500, 400), true);
	SetPosition(wxPoint(((width / 2) - GetSize().x / 2) - 150, (height / 2) - GetSize().y / 2));
	SetBackgroundColour(color2);


	settingPanel = new wxPanel(this, wxID_ANY, wxPoint(127, 15), wxSize(this->GetSize().x - 131, this->GetSize().y - 19));
	settingPanel->SetBackgroundColour(color1);

	settChoosePanel = new wxPanel(this, wxID_ANY, wxPoint(2, 15), wxSize(123, this->GetSize().y - 19));
	settChoosePanel->SetBackgroundColour(color1);

	// Children for settChoosePanel
	wxButton* appBtn = new wxButton(settChoosePanel, 24400, "App-Settings", wxPoint(2, 4), wxSize(117, 25), wxBORDER_NONE);
	appBtn->SetBackgroundColour(color2);
	appBtn->SetForegroundColour(textcolor1);
	appBtn->SetCursor(wxCURSOR_HAND);
	appBtn->Bind(wxEVT_BUTTON, &SettingsWidget::OnAppBtn, this);

	wxButton* colorsBtn = new wxButton(settChoosePanel, 24401, "Colors", wxPoint(2, 36), wxSize(117, 25), wxBORDER_NONE);
	colorsBtn->SetBackgroundColour(color2);
	colorsBtn->SetForegroundColour(textcolor1);
	colorsBtn->SetCursor(wxCURSOR_HAND);
	colorsBtn->Bind(wxEVT_BUTTON, &SettingsWidget::OnColorsBtn, this);

	wxButton* keybBtn = new wxButton(settChoosePanel, 24402, "Keybinds", wxPoint(2, 68), wxSize(117, 25), wxBORDER_NONE);
	keybBtn->SetBackgroundColour(color2);
	keybBtn->SetForegroundColour(textcolor1);
	keybBtn->SetCursor(wxCURSOR_HAND);
	keybBtn->Bind(wxEVT_BUTTON, &SettingsWidget::OnKeybBtn, this);
}

SettingsWidget::~SettingsWidget() {}


void SettingsWidget::resetPosition()
{
	int width = wxDisplay().GetGeometry().GetWidth();
	int height = wxDisplay().GetGeometry().GetHeight();
	SetPosition(wxPoint(((width / 2) - GetSize().x / 2) - 150, (height / 2) - GetSize().y / 2));
}



void SettingsWidget::OnClose(wxCommandEvent& event)
{
	ODashboardApp::getApp()->menu->OnClickSettings(event);
}

void SettingsWidget::OnAppBtn(wxCommandEvent& event)
{
	if (settingPanel != nullptr)
		settingPanel->DestroyChildren();

	//Children for settingPanel
	wxStaticText* autosTitle = new wxStaticText(settingPanel, wxID_ANY, "AUTOSTART", wxPoint(10, 10), wxSize(65, 15), 0, "");
	autosTitle->SetForegroundColour(textcolor5);
	autosTitle->SetFont(wxFont(8,
		wxFONTFAMILY_DECORATIVE,
		wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_BOLD,	
		false));

	wxCheckBox* autosCheckBox = new wxCheckBox(settingPanel, 24403, "Open on startup", wxPoint(10, 35));
	autosCheckBox->SetForegroundColour(textcolor6);	
	autosCheckBox->Bind(wxEVT_CHECKBOX, [=](wxCommandEvent& event) 
	{
		if (autostart)
			autostart = false;
		else
			autostart = true;
	});
}

void SettingsWidget::OnColorsBtn(wxCommandEvent& event)
{
	if(settingPanel != nullptr)
		settingPanel->DestroyChildren();

	//Children for settingPanel
	wxStaticText* clrpTitle = new wxStaticText(settingPanel, wxID_ANY, "TEXTCOLORS", wxPoint(10, 10), wxSize(65, 15), 0, "");
	clrpTitle->SetForegroundColour(textcolor5);
	clrpTitle->SetFont(wxFont(8,
		wxFONTFAMILY_DECORATIVE,
		wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_BOLD,
		false));


	ClrPicker* clrPicker01 = new ClrPicker(settingPanel, wxID_ANY, color3, "", wxPoint(10, 35), wxSize(35, 30));
	/*clrPicker->Bind(wxEVT_PAINT, [=](wxPaintEvent& event) 
	{
		wxPaintDC dc(clrPicker);
		wxRect rect(0, 0, dc.GetSize().GetWidth(), dc.GetSize().GetHeight());

		dc.SetBrush(wxBrush(color3));
		dc.SetPen(wxPen(color1));
		dc.DrawRectangle(rect);

		dc.SetTextForeground(textcolor5);
	});*/

}

void SettingsWidget::OnKeybBtn(wxCommandEvent& event)
{
	if (settingPanel != nullptr)
		settingPanel->DestroyChildren();

	//Children for settingPanel
	new wxButton(settingPanel, wxID_ANY, "Test3", wxPoint(0, 50));
}

