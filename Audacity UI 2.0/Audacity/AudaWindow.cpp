#include "Auda.h"

bool AudaApplication::OnInit() {

    AudaFrame* appFrame = new AudaFrame(title, position, size);
    appFrame->Show();

    return true;
}

wxIMPLEMENT_APP(AudaApplication);