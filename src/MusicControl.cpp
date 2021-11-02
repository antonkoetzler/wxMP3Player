#include "MusicControl.h"

MusicControl::MusicControl(wxWindow* parent) : wxPanel(parent, MUSICCONTROL)
{
	SetBackgroundColour(wxColour(*wxWHITE));
	this->SetSize(wxSize(400, 400));
}

