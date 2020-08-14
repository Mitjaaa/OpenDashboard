#pragma once
#include <wx/wx.h>
#include <wx/display.h>
#include "WidgetFrame.h"

class SettingsWidget : public WidgetFrame
{
public:
	SettingsWidget();
	~SettingsWidget();

	void resetPosition();
	void RefreshPanels(wxColour newColour);

	//std::vector<std::string> split(std::string strToSplit, char delimeter);
	void loadSettings();
	void saveSettings();


	// settings
	bool autostart = false;
	float transparency = 127.5;

private:
	void OnClose(wxCommandEvent& event) override;
	wxPanel* settChoosePanel = nullptr;
	wxPanel* settingPanel = nullptr;

	void OnAppBtn(wxCommandEvent& event);
	void OnColorsBtn(wxCommandEvent& event);
	void OnKeybBtn(wxCommandEvent& event);

	int initTextcolours();
	int initBGColours(int space);
	int initOtherColours(int space);
};

