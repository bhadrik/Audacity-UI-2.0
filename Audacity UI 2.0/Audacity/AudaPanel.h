#include "Auda.h"

#pragma once

class AudaPanel : public wxPanel {
public:
    AudaPanel(AudaFrame* parent, wxColour borderColor, int borderSize);

    AudaPanel(wxWindow* parent);

    void paintEvent(wxPaintEvent& evt);

    void render(wxDC& dc);

    DECLARE_EVENT_TABLE()

private:
    wxColor m_borderColor = wxColor();
    int m_borderSize = 2;
};