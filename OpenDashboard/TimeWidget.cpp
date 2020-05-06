#include "TimeWidget.h"
#include <thread>

void runTime(WidgetText* timeText) {
	while (1) {
		time_t current_time = time(NULL);
		tm* getTime = localtime(&current_time);
		std::string realtime = "";

		if (int(std::to_string(getTime->tm_hour).length()) == 1) {
			realtime += "0" + std::to_string(getTime->tm_hour);
		}
		else {
			realtime += std::to_string(getTime->tm_hour);
		}

		realtime += ":";

		if (int(std::to_string(getTime->tm_min).length()) == 1) {
			realtime += "0" + std::to_string(getTime->tm_min);
		}
		else {
			realtime += std::to_string(getTime->tm_min);
		}

		timeText->SetLabel(realtime);
		Sleep(1000);
	}
}

TimeWidget::TimeWidget() : WidgetFrame("Time"), parent(this)
{
	time = new WidgetText(this, wxID_ANY, "00:00", wxPoint(23, 5), wxSize(200, 100), 0, "", this->getWidgetFrame());
	time->SetFont(wxFont(60, 
		wxFONTFAMILY_DEFAULT, 
		wxFONTSTYLE_NORMAL, 
		wxFONTWEIGHT_NORMAL, 
		false));
	time->SetForegroundColour(wxColour(39, 232, 167));

	SetBackgroundColour(wxColour(46, 46, 46));
	SetSize(wxSize(250, 100));

	std::thread time(runTime, time);
	time.detach();
}

TimeWidget::~TimeWidget()
{
}
