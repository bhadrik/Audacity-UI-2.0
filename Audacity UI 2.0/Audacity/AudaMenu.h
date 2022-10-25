#pragma once
#include "AudaPanel.h"

using namespace std;

class AudaMenu : public AudaPanel{

    //DECLARE_EVENT_TABLE()

private:
    wxStaticText* m_titleText;
    wxSizer* m_menuSizer;
    bool m_overText = false;
    bool m_overPanel = false;

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
    void OnMouseDown(wxMouseEvent& event);
    void OnMouseUp(wxMouseEvent& event);
    
    void Text_OnMouseEnter(wxMouseEvent& event);
    void Text_OnMouseExit(wxMouseEvent& event);
};