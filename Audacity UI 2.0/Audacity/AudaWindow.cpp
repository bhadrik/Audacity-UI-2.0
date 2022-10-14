#include "Auda.h"
#include "../resource.h"

class AudaApplication : public wxApp
{
private:
    wxPoint position = wxDefaultPosition;
    wxString title = (wxString)"Auda App";
    wxSize size = wxSize(500, 400);

public:
    virtual bool OnInit();
};

bool AudaApplication::OnInit() {

    title = "Auda app";
    position = wxDefaultPosition;
    size = wxSize(500, 400);

    AudaFrame* appFrame = new AudaFrame(title, position, size);

    appFrame->SetIcon(wxICON(IDI_ICON1));

    appFrame->Show();

    SetTopWindow(appFrame);

    return true;
}

wxIMPLEMENT_APP(AudaApplication);