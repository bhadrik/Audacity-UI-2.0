#pragma once

#include "wx/wx.h"

/*
* Declaring color palatte
*/

class AudaColor {
public:
    static wxColour* L1_100; //33
    static wxColour* L1_75; //40
    static wxColour* L1_50; //45
    static wxColour* L2_100; //53
    static wxColour* L2_75; //72
    static wxColour* L2_50; //111
    static wxColour* L3_100; //116
    static wxColour* L3_75; //214
};


class AudaTitleBar :public wxWindow
{
public:
    AudaTitleBar(wxWindow* parent, wxPoint pos, wxSize size, wxColour color);

    //wxSize DoGetBestClientSize() const override;

private:
    void OnMouseLeftDown(wxMouseEvent& event);

    void OnMouseLeftUp(wxMouseEvent&);

    void OnMouseMotion(wxMouseEvent& event);

    void OnMouseCaptureLost(wxMouseCaptureLostEvent&);

    void FinishDrag();

    wxPoint m_dragStartMouse;
    wxPoint m_dragStartWindow;
    bool m_dragging;
};


class AudaFrame : public wxFrame
{
public:
    AudaFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
};