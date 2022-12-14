#include "Auda.h"
#include "../resource.h"

class AudaApplication : public wxApp
{
private:
    wxPoint position = wxDefaultPosition;
    wxString title = (wxString)"Auda App";
    wxSize size = wxSize(500, 400);
    wxFont mainFont = wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    AudaFrame* appFrame = new AudaFrame(title, position, size);

public:
    virtual bool OnInit();
};

bool AudaApplication::OnInit() {

    // Default Debug log
    wxLog::SetActiveTarget(new wxLogStderr());

    //const wxSize sizeM = appFrame->GetTextExtent("M");
    appFrame->SetClientSize(appFrame->FromDIP(size));
    appFrame->SetIcon(wxICON(IDI_ICON1));
    appFrame->SetFont(mainFont);
    appFrame->Show();

    SetTopWindow(appFrame);

    return true;
}

wxIMPLEMENT_APP(AudaApplication);