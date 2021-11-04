#include "MusicControls.h"

MusicControls::MusicControls(wxWindow* parent, wxSize& size) : wxWindow(parent, MUSICCONTROLS, wxDefaultPosition, size)
{
	SetBackgroundColour(wxColour(52, 60, 92));

	loadMusicControls();
}

void MusicControls::loadMusicControls()
{
	controlsSizer = new wxBoxSizer(wxHORIZONTAL);

	imageBitmap.LoadFile("../img/playButton.jpeg", wxBITMAP_TYPE_JPEG);

	if (imageBitmap.IsOk())
		controlsSizer->Add(new wxBitmapButton(this, PLAYBUTTON, imageBitmap), 0, wxCENTER);
}

