#include "SettingsWidget.h"
#include "ODashboardApp.h"
#include "Colors.h"
#include "ClrPicker.h"
#include "Globals.h"
#include <iostream>
#include <fstream>

SettingsWidget::SettingsWidget() : WidgetFrame("Settings", true, true, 24002)
{
	loadSettings();

	int width = wxDisplay().GetGeometry().GetWidth();
	int height = wxDisplay().GetGeometry().GetHeight();

	SetWindowStyle(wxSTAY_ON_TOP | wxFRAME_TOOL_WINDOW);
	UpdateSize(wxSize(500, 400), true);
	SetPosition(wxPoint(((width / 2) - GetSize().x / 2) - 150, (height / 2) - GetSize().y / 2));
	SetBackgroundColour(bgcolours[1].clr);


	settingPanel = new wxPanel(this, wxID_ANY, wxPoint(127, 15), wxSize(this->GetSize().x - 131, this->GetSize().y - 19));
	settingPanel->SetBackgroundColour(bgcolours[0].clr);

	settChoosePanel = new wxPanel(this, wxID_ANY, wxPoint(2, 15), wxSize(123, this->GetSize().y - 19));
	settChoosePanel->SetBackgroundColour(bgcolours[0].clr);

	// Children for settChoosePanel
	wxButton* appBtn = new wxButton(settChoosePanel, 24400, "App-Settings", wxPoint(2, 4), wxSize(117, 25), wxBORDER_NONE);
	appBtn->SetBackgroundColour(bgcolours[1].clr);
	appBtn->SetForegroundColour(textcolours[0].clr);
	appBtn->SetCursor(wxCURSOR_HAND);
	appBtn->Bind(wxEVT_BUTTON, &SettingsWidget::OnAppBtn, this);

	wxButton* colorsBtn = new wxButton(settChoosePanel, 24401, "Colors", wxPoint(2, 36), wxSize(117, 25), wxBORDER_NONE);
	colorsBtn->SetBackgroundColour(bgcolours[1].clr);
	colorsBtn->SetForegroundColour(textcolours[0].clr);
	colorsBtn->SetCursor(wxCURSOR_HAND);
	colorsBtn->Bind(wxEVT_BUTTON, &SettingsWidget::OnColorsBtn, this);

	wxButton* keybBtn = new wxButton(settChoosePanel, 24402, "Keybinds", wxPoint(2, 68), wxSize(117, 25), wxBORDER_NONE);
	keybBtn->SetBackgroundColour(bgcolours[1].clr);
	keybBtn->SetForegroundColour(textcolours[0].clr);		
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

void SettingsWidget::RefreshPanels(wxColour newColour)
{
	unsigned int c1Size = settingPanel->GetChildren().size();
	for (unsigned int j = 0; j < c1Size; j++) {
		if (settingPanel->GetChildren()[j]->GetForegroundColour() == oldColour.clr)
			settingPanel->GetChildren()[j]->SetForegroundColour(newColour);

		if (settingPanel->GetChildren()[j]->GetBackgroundColour() == oldColour.clr)
			settingPanel->GetChildren()[j]->SetBackgroundColour(newColour);
	}

	unsigned int c2Size = settChoosePanel->GetChildren().size();
	for (unsigned int j = 0; j < c2Size; j++) {
		if (settChoosePanel->GetChildren()[j]->GetForegroundColour() == oldColour.clr)
			settChoosePanel->GetChildren()[j]->SetForegroundColour(newColour);

		if (settChoosePanel->GetChildren()[j]->GetBackgroundColour() == oldColour.clr)
			settChoosePanel->GetChildren()[j]->SetBackgroundColour(newColour);
	}

	settingPanel->Refresh();
	settingPanel->Update();

	settChoosePanel->Refresh();
	settChoosePanel->Update();
}

void SettingsWidget::loadSettings()
{
	std::string line;
	std::ifstream settings("config.txt");
	if (settings.is_open())
	{
		while (getline(settings, line))
		{
			if (line.rfind("#", 0) != 0 && !line.empty()) {
				std::vector<std::string> splitted = split(line, "=");
				
				if (splitted[0] == "autostart") 
				{
					autostart = atoi(splitted[1].c_str());
				}
				else if (splitted[0] == "transparency")
				{	
					transparency = atoi(splitted[1].c_str());
					ODashboardApp::getApp()->mainframe->SetTransparent(transparency);
					ODashboardApp::getApp()->mainframe->Update();
					ODashboardApp::getApp()->mainframe->Refresh();
				}
			}	
		}
		settings.close();
	}
}

void SettingsWidget::saveSettings()
{
	std::ofstream settings("config.txt");
	if (settings.is_open())
	{
		settings << "### this is a temporary comment.\n\n\n";

		settings << "## App-Settings ##\n";
		settings << "autostart=" + std::to_string(autostart) + "\n";
		settings << "transparency=" + std::to_string(transparency).substr(0, std::to_string(transparency).length() - 5) + "\n";
		
		std::string clr = "main-background-color=3|1=" + colours[1].clr.GetAsString().erase(0, 4).ToStdString();
		clr = clr.substr(0, clr.length() - 1) + "\n";
		clr.erase(remove(clr.begin(), clr.end(), ','), clr.end());
		settings << clr + "\n\n\n";
				
		settings << "## Colors ##\n";
		settings << "# textcolours #\n";
		for (unsigned int i = 0; i < textcolours.size(); i++)
		{
			if (!textcolours[i].autoSetting) continue	;

			if (textcolours[i].clr.GetAsString().starts_with("rgb")) {
				std::string clr = "color=1|" + std::to_string(i) + "=" + textcolours[i].clr.GetAsString().erase(0, 4).ToStdString();
				clr = clr.substr(0, clr.length() - 1) + "\n";
				clr.erase(remove(clr.begin(), clr.end(), ','), clr.end());		

				settings << clr;
			} 
			else
			{
				settings << "color=1|" + std::to_string(i) + "=" + textcolours[i].clr.GetAsString() + "\n";	
			}
		}
		settings << "\n";

		settings << "# backgroundcolours #\n";
		for (unsigned int i = 0; i < bgcolours.size(); i++)
		{
			if (!bgcolours[i].autoSetting) continue;

			if (bgcolours[i].clr.GetAsString().starts_with("rgb")) {
				std::string clr = "color=2|" + std::to_string(i) + "=" + bgcolours[i].clr.GetAsString().erase(0, 4).ToStdString();
				clr = clr.substr(0, clr.length() - 1) + "\n";
				clr.erase(remove(clr.begin(), clr.end(), ','), clr.end());

				settings << clr;
			}
			else
			{
				settings << "color=2|" + std::to_string(i) + "=" + bgcolours[i].clr.GetAsString() + "\n";
			}
		}
		settings << "\n";

		settings << " # other colours #\n";
		for (unsigned int i = 0; i < colours.size(); i++)
		{
			if (!colours[i].autoSetting) continue;

			if (colours[i].clr.GetAsString().starts_with("rgb")) {
				std::string clr = "color=3|" + std::to_string(i) + "=" + colours[i].clr.GetAsString().erase(0, 4).ToStdString();
				clr = clr.substr(0, clr.length() - 1) + "\n";
				clr.erase(remove(clr.begin(), clr.end(), ','), clr.end());

				settings << clr;
			}
			else
			{
				settings << "color=3|" + std::to_string(i) + "=" + colours[i].clr.GetAsString() + "\n";
			}
		}
		settings << "\n";

		settings << "## Keybinds ##\n";	
		settings.close();
	}
}



void SettingsWidget::OnClose(wxCommandEvent& event)
{
	saveSettings();	
	ODashboardApp::getApp()->menu->OnClickSettings(event);
}

void SettingsWidget::OnAppBtn(wxCommandEvent& event)
{
	if (settingPanel != nullptr)
		settingPanel->DestroyChildren();

	//Children for settingPanel
	wxStaticText* autosTitle = new wxStaticText(settingPanel, wxID_ANY, "AUTOSTART", wxPoint(10, 10), wxSize(65, 15), 0, "");
	autosTitle->SetForegroundColour(textcolours[4].clr);
	autosTitle->SetFont(wxFont(8,
		wxFONTFAMILY_DECORATIVE,
		wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_BOLD,	
		false));

	wxCheckBox* autosCheckBox = new wxCheckBox(settingPanel, 24403, "Open on startup", wxPoint(13, 35));
	autosCheckBox->SetValue(autostart);
	autosCheckBox->SetForegroundColour(textcolours[5].clr);
	autosCheckBox->Bind(wxEVT_CHECKBOX, [=](wxCommandEvent& event) 
	{
		if (autostart)
			autostart = false;
		else
			autostart = true;
	});


	wxStaticText* textcTitle = new wxStaticText(settingPanel, wxID_ANY, "SCREEN", wxPoint(10, 85), wxSize(50, 15), 0, "");
	textcTitle->SetForegroundColour(textcolours[4].clr);
	textcTitle->SetFont(wxFont(8,
		wxFONTFAMILY_DECORATIVE,
		wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_BOLD,
		false));

	wxStaticText* transpText = new wxStaticText(settingPanel, wxID_ANY, "Transparency:", wxPoint(13, 110), wxSize(73, 15), 0, "");
	transpText->SetForegroundColour(textcolours[5].clr);

	wxTextCtrl* transpCtrl = new wxTextCtrl(settingPanel, wxID_ANY, std::to_string(transparency).substr(0, std::to_string(transparency).length()-5), wxPoint(93, 111), wxSize(35, 15), wxBORDER_NONE); // 127.5 is temp -> later load from config
	transpCtrl->SetBackgroundColour(bgcolours[1].clr);
	transpCtrl->SetForegroundColour(textcolours[0].clr);		
	transpCtrl->Bind(wxEVT_TEXT, [=](wxCommandEvent& event) {
		if (!isStrDigit(transpCtrl->GetValue().ToStdString()))
			transpCtrl->SetValue(removeLetters(transpCtrl->GetValue().ToStdString()));

		if (atoi(transpCtrl->GetValue()) < 1)
			transpCtrl->SetValue("1");

		if (atoi(transpCtrl->GetValue()) > 255)
			transpCtrl->SetValue("255");

		transparency = atoi(transpCtrl->GetValue());
		ODashboardApp::getApp()->mainframe->SetTransparent(transparency);
		// save to config
		});


	wxStaticText* colorText = new wxStaticText(settingPanel, wxID_ANY, "Color:", wxPoint(13, 135), wxSize(35, 15), 0, "");
	colorText->SetForegroundColour(textcolours[5].clr);
	
	ClrPicker* clrPicker = new ClrPicker(settingPanel, wxID_ANY, colours[1].section, colours[1].index, true, "", wxPoint(53	, 135), wxSize(35, 30));
}

void SettingsWidget::OnColorsBtn(wxCommandEvent& event)
{
	if(settingPanel != nullptr)
		settingPanel->DestroyChildren();
					 
	// Children for settingPanel
	
	
	// textcolours
	int tspace = initTextcolours();
	
	// backgroundcolours
	int bgspace = initBGColours(tspace);
		
	// other colours
	initOtherColours(bgspace);
}

void SettingsWidget::OnKeybBtn(wxCommandEvent& event)
{
	if (settingPanel != nullptr)
		settingPanel->DestroyChildren();

	//Children for settingPanel
 
}

int SettingsWidget::initTextcolours()
{
	wxStaticText* textcTitle = new wxStaticText(settingPanel, wxID_ANY, "TEXTCOLORS", wxPoint(10, 10), wxSize(65, 15), 0, "");
	textcTitle->SetForegroundColour(textcolours[4].clr);
	textcTitle->SetFont(wxFont(8,
		wxFONTFAMILY_DECORATIVE,
		wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_BOLD,
		false));

	unsigned int textcSize = textcolours.size();
	int factorX = 0;
	int factorY = 0;

	for (unsigned int i = 0; i < textcSize; i++)
	{
		if (i % 5 == 0 && i != 0) {
			factorX = 0;
			factorY++;
		}

		wxStaticText* clrpText = new wxStaticText(settingPanel, wxID_ANY, std::to_string(i + 1), wxPoint(10 + (factorX * 70), 35 + (factorY * 50)), wxSize(10, 15), 0, "");
		clrpText->SetForegroundColour(textcolours[5].clr);
		ClrPicker* clrPicker = new ClrPicker(settingPanel, wxID_ANY, textcolours[i].section, textcolours[i].index, false, "", wxPoint(20 + (factorX * 70), 35 + (factorY * 50)), wxSize(35, 30));

		factorX++;
	}

	return (factorY+1) * 50 + 30;
}

int SettingsWidget::initBGColours(int space)
{
	wxStaticText* bgTitle = new wxStaticText(settingPanel, wxID_ANY, "BACKGROUNDCOLORS", wxPoint(10, 10 + space), wxSize(65, 15), 0, "");
	bgTitle->SetForegroundColour(textcolours[4].clr);
	bgTitle->SetFont(wxFont(8,
		wxFONTFAMILY_DECORATIVE,
		wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_BOLD,
		false));

	unsigned int bgSize = bgcolours.size();
	int factorX = 0;
	int factorY = 0;

	for (unsigned int i = 0; i < bgSize; i++)
	{
		if (i % 5 == 0 && i != 0) {
			factorX = 0;
			factorY++;
		}

		wxStaticText* clrpText = new wxStaticText(settingPanel, wxID_ANY, std::to_string(i + 1), wxPoint(10 + (factorX * 70), 35 + (factorY * 50) + space), wxSize(10, 15), 0, "");
		clrpText->SetForegroundColour(textcolours[5].clr);
		ClrPicker* clrPicker = new ClrPicker(settingPanel, wxID_ANY, bgcolours[i].section, bgcolours[i].index, false, "", wxPoint(20 + (factorX * 70), 35 + (factorY * 50) + space), wxSize(35, 30));

		factorX++;
	}

	return space + ((factorY + 1) * 50) + 30;
}

int SettingsWidget::initOtherColours(int space)
{
	wxStaticText* otTitle = new wxStaticText(settingPanel, wxID_ANY, "OTHER COLORS", wxPoint(10, 10 + space), wxSize(65, 15), 0, "");
	otTitle->SetForegroundColour(textcolours[4].clr);
	otTitle->SetFont(wxFont(8,
		wxFONTFAMILY_DECORATIVE,
		wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_BOLD,
		false));

	unsigned int bgSize = colours.size();
	int factorX = 0;
	int factorY = 0;

	for (unsigned int i = 0; i < bgSize; i++)
	{
		if (colours[i].autoSetting) {
			if (i % 5 == 0 && i != 0) {
				factorX = 0;
				factorY++;
			}

			wxStaticText* clrpText = new wxStaticText(settingPanel, wxID_ANY, std::to_string(i + 1), wxPoint(10 + (factorX * 70), 35 + (factorY * 50) + space), wxSize(10, 15), 0, "");
			clrpText->SetForegroundColour(textcolours[5].clr);
			ClrPicker* clrPicker = new ClrPicker(settingPanel, wxID_ANY, colours[i].section, colours[i].index, false, "", wxPoint(20 + (factorX * 70), 35 + (factorY * 50) + space), wxSize(35, 30));

			factorX++;
		}	
	}

	return space + (factorY * 50) + 30;
}
