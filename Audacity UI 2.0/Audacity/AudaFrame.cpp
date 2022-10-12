#include "Auda.h"

AudaFrame::AudaFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(NULL, wxID_ANY,
    title, pos, size, wxNO_BORDER)
{
    SetBackgroundColour(*AudaColor::L1_100);
    AudaTitleBar* titleBar = new AudaTitleBar(this, wxDefaultPosition, wxSize(300, 30), *AudaColor::L2_100);
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(titleBar);
    SetSizer(sizer);
    Layout();
}