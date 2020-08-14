#pragma once
#include <wx/wx.h>
#include "WidgetFrame.h"
#include "Colors.h"

class CalculatorWidget : public WidgetFrame
{
public:
    CalculatorWidget();
    ~CalculatorWidget();

private:
    wxButton* number0;
    wxButton* number1;
    wxButton* number2;
    wxButton* number3;
    wxButton* number4;
    wxButton* number5;
    wxButton* number6;
    wxButton* number7;
    wxButton* number8;
    wxButton* number9;


    WidgetFrame* createNewObj() override;
};

