#include "WidgetFrame.h"
#include "ODashboardApp.h"
#include <thread>

BEGIN_EVENT_TABLE(WidgetFrame, wxFrame)
    EVT_LEFT_DOWN(OnLeftDown)
    EVT_LEFT_UP(OnLeftUp)
    EVT_MOTION(OnMouseMove)
END_EVENT_TABLE()

WidgetFrame::WidgetFrame() : wxFrame(nullptr, 11001, "OpenDashboard")
{
	SetWindowStyle(wxSTAY_ON_TOP | wxFRAME_TOOL_WINDOW);
}

WidgetFrame::~WidgetFrame() 
{
}   

void WidgetFrame::OnLeftDown(wxMouseEvent& event)
{
    CaptureMouse();
    capturing = true;

    const auto eventSource = static_cast<wxWindow*>(event.GetEventObject());
    const auto screenPosClicked = eventSource->ClientToScreen(event.GetPosition());
    const auto origin = GetPosition();

    mouseDownPos = screenPosClicked - origin;
}

void WidgetFrame::OnMouseMove(wxMouseEvent& event)
{
    if (event.Dragging() && event.LeftIsDown())
    {
        const auto screenPosCurrent = ClientToScreen(event.GetPosition());
        Move(screenPosCurrent - mouseDownPos);
    }
}

void WidgetFrame::OnLeftUp(wxMouseEvent& event)
{
    if (capturing) {
        ReleaseMouse();
        capturing = false;
    }
}
		