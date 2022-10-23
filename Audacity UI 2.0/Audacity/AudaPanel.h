#pragma once
#include "AudaColor.h"

class AudaPanel : public wxPanel {
    DECLARE_EVENT_TABLE()

public:
    AudaPanel(
        wxWindow* parent,
        const wxColour& borderColor = OUTLINE_COLOR,
        int borderSize = 5,
        wxWindowID windowId = wxID_ANY,
        const wxPoint& position = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = 2621440L,
        const wxString& panelName = wxString::FromAscii(wxPanelNameStr)
    );

    void paintEvent(wxPaintEvent& evt);

    void render(wxDC& dc);

    void SetBorderColor(wxColor color);

    void SetBorderSize(int size);

private:
    wxColor m_borderColor = OUTLINE_COLOR;
    int m_borderSize = 1;
};