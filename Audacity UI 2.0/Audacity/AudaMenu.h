#pragma once
#include "AudaPanel.h"

using namespace std;

class AudaMenu : public AudaPanel{

    //DECLARE_EVENT_TABLE()

private:
	wxStaticText* m_titleText;
    wxSizer* m_menuSizer;

public:
    AudaMenu(
        wxWindow* parent,
        const wxString& title,
        const wxColour& borderColor = OUTLINE_COLOR,
        int borderSize = 5,
        wxWindowID windowId = wxID_ANY,
        const wxPoint& position = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxBackgroundStyle::wxBG_STYLE_TRANSPARENT,
        const wxString& panelName = wxString::FromAscii(wxPanelNameStr)
    );

    void OnMouseEnter(wxMouseEvent& event);
    void OnMouseExit(wxMouseEvent& event);
    
    void PendingOnMouseEnter(wxMouseEvent& event);
    void PendingOnMouseExit(wxMouseEvent& event);
};