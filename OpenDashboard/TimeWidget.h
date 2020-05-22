#pragma once
#include "wx/wx.h"
#include "WidgetFrame.h"
#include "WidgetText.h"
#include <thread>

class TimeWidget : public WidgetFrame
{
public:

    TimeWidget();
	TimeWidget(bool secondsOption);
	~TimeWidget();

    TimeWidget(TimeWidget const&) = delete;
    TimeWidget(TimeWidget&&) = delete;
    TimeWidget& operator = (TimeWidget const&) = delete;
    TimeWidget& operator = (TimeWidget&&) = delete;

    WidgetFrame* parent;
    bool secondsOption;

    WidgetFrame* createNewObj() override;
    
private:
    WidgetText* time;
    
};
    