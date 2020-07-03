#include "TimeWidget.h"
#include <thread>
#include "Colors.h"

void runTime(TimeWidget* widget, WidgetText* timeText, bool seconds) {
	while (!widget->IsBeingDeleted()) {
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

		if (seconds) {
			realtime += ":";

			if (int(std::to_string(getTime->tm_sec).length()) == 1) {
				realtime += "0" + std::to_string(getTime->tm_sec);
			}
			else {
				realtime += std::to_string(getTime->tm_sec);
			}
		}

		timeText->SetLabel(realtime);
		Sleep(1000);
	}
}

TimeWidget::TimeWidget() : WidgetFrame("Time", false, false, 24000) {}

TimeWidget::TimeWidget(bool seconds) : WidgetFrame("Time", true, false, 24000), parent(this), secondsOption(seconds)
{
	time = new WidgetText(this, wxID_ANY, "00:00", wxPoint(23, 5), wxSize(200, 100), 0, "");
	time->SetFont(wxFont(60,
		wxFONTFAMILY_DEFAULT,
		wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_NORMAL,
		false));
	time->SetForegroundColour(textcolor1);

	SetBackgroundColour(color3);

	if (seconds) {
		time->SetPosition(wxPoint(30, 5));
		time->SetSize(wxSize(300, 100));
		UpdateSize(wxSize(375, 100), true);
	}
	else {
		UpdateSize(wxSize(250, 100), true);
	}

	std::thread time(runTime, this, time, seconds);
	time.detach();
}

TimeWidget::~TimeWidget() {}

WidgetFrame* TimeWidget::createNewObj()
{
	return new TimeWidget(true);
}