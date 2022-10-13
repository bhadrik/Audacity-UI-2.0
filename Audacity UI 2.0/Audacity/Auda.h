#pragma once

#include "wx/wx.h"

#define L1_100_COLOR AudaColor::L1_100
#define L1_75_COLOR AudaColor::L1_75
#define L1_50_COLOR AudaColor::L1_50
#define L2_100_COLOR AudaColor::L2_100
#define L2_75_COLOR AudaColor::L2_75
#define L2_50_COLOR AudaColor::L2_50
#define L3_100_COLOR AudaColor::L3_100
#define L3_75_COLOR AudaColor::L3_75
#define OUTLINE_COLOR AudaColor::outlineCommon

// Color palette
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

    // access color by name
    static wxColour* outlineCommon;
};



class AudaPanel : public wxPanel {
    DECLARE_EVENT_TABLE()

public:
    AudaPanel(wxWindow* parent, wxSize size, wxPoint position);

    void paintEvent(wxPaintEvent& evt);

    void render(wxDC& dc);

    void SetBorderColor(wxColor color);

    void SetBorderSize(int size);

    void UpdateBorder(wxRect rect);

private:
    wxColor m_borderColor = *OUTLINE_COLOR;
    int m_borderSize = 1;
};


class AudaTitleBar : public AudaPanel
{
public:
    AudaTitleBar(wxWindow* parent, wxPoint pos, int height, wxColour color);

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


class AudaApplication : public wxApp
{
private:
    wxPoint position = wxDefaultPosition;
    wxString title = (wxString)"Auda App";
    wxSize size = wxSize(500, 400);

public:
    virtual bool OnInit();
};