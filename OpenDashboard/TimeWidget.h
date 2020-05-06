#pragma once
#include "WidgetFrame.h"
#include "WidgetText.h"


class TimeWidget : public WidgetFrame
{
public:

	TimeWidget();
	~TimeWidget();

    TimeWidget(TimeWidget const&) = delete;
    TimeWidget(TimeWidget&&) = delete;
    TimeWidget& operator = (TimeWidget const&) = delete;
    TimeWidget& operator = (TimeWidget&&) = delete;

    WidgetFrame* parent;
    
private:
    WidgetText* time;
    
};
    