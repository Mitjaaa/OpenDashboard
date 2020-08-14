#include "CalculatorWidget.h"



CalculatorWidget::CalculatorWidget() : WidgetFrame("Calculator", true, true, 24005)
{
	SetBackgroundColour(bgcolours[2].clr);
	UpdateSize(wxSize(350, 500), true);

	number0 = new wxButton(this, wxID_ANY, "0", wxPoint(5, 440), wxSize(105, 50));
	
	number1 = new wxButton(this, wxID_ANY, "1", wxPoint(5, 385), wxSize(50, 50));
	number2 = new wxButton(this, wxID_ANY, "2", wxPoint(60, 385), wxSize(50, 50));
	number3 = new wxButton(this, wxID_ANY, "3", wxPoint(115, 385), wxSize(50, 50));

	number4 = new wxButton(this, wxID_ANY, "4", wxPoint(5, 330), wxSize(50, 50));
	number5 = new wxButton(this, wxID_ANY, "5", wxPoint(60, 330), wxSize(50, 50));
	number6 = new wxButton(this, wxID_ANY, "6", wxPoint(115, 330), wxSize(50, 50));

	number7 = new wxButton(this, wxID_ANY, "7", wxPoint(5, 275), wxSize(50, 50));
	number8 = new wxButton(this, wxID_ANY, "8", wxPoint(60, 275), wxSize(50, 50));
	number9 = new wxButton(this, wxID_ANY, "9", wxPoint(115, 275), wxSize(50, 50));
}


CalculatorWidget::~CalculatorWidget()
{
}
	

WidgetFrame* CalculatorWidget::createNewObj()
{
	return new CalculatorWidget();
}
