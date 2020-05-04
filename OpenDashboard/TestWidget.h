#pragma once
#include "WidgetFrame.h"


class TestWidget : public WidgetFrame
{
public:

	TestWidget();
	~TestWidget();

    TestWidget(TestWidget const&) = delete;
    TestWidget(TestWidget&&) = delete;
    TestWidget& operator = (TestWidget const&) = delete;
    TestWidget& operator = (TestWidget&&) = delete;
    
};
