#include "MusicControls.h"

MusicControls::MusicControls(wxWindow* parent, wxSize& size) : wxWindow(parent, MUSICCONTROLS, wxDefaultPosition, size)
{
	SetBackgroundColour(wxColour(52, 60, 92));

	loadMusicControls();
}

void MusicControls::loadMusicControls()
{
	controlsSizer = new wxBoxSizer(wxHORIZONTAL);

	// Used to center the sizer
	controlsSizer->AddStretchSpacer();

	// Shuffle
	imageBitmap.LoadFile("../img/Shuffle.png", wxBITMAP_TYPE_PNG);
	if (!imageBitmap.IsOk())
	{
		std::cout << "Error loading Shuffle.png" << std::endl;
		Close(true);
	}
	controlsSizer->Add(
		new wxBitmapButton(this, SHUFFLE, imageBitmap, wxDefaultPosition, wxSize(80, 80)),
		0,
		wxALL | wxALIGN_CENTRE,
		5
	);

	// Play previous
	imageBitmap.LoadFile("../img/PlayPrevious.png", wxBITMAP_TYPE_PNG);
	if (!imageBitmap.IsOk())
	{
		std::cout << "Error loading PlayPrevious.png" << std::endl;
		Close(true);
	}
	controlsSizer->Add(
		new wxBitmapButton(this, PLAYPREVIOUS, imageBitmap, wxDefaultPosition, wxSize(80, 80)),
		0,
		wxALL | wxALIGN_CENTRE,
		5
	);

	// Play button
	imageBitmap.LoadFile("../img/PlayButton.png", wxBITMAP_TYPE_PNG);
	if (!imageBitmap.IsOk())
	{
		std::cout << "Error loading PlayButton.png" << std::endl;
		Close(true);
	}
	controlsSizer->Add(
		new wxBitmapButton(this, PLAYBUTTON, imageBitmap, wxDefaultPosition, wxSize(80, 80)),
		0,
		wxALL | wxALIGN_CENTRE,
		5
	);

	// Play next
	imageBitmap.LoadFile("../img/PlayNext.png", wxBITMAP_TYPE_PNG);
	if (!imageBitmap.IsOk())
	{
		std::cout << "Error loading PlayNext.png" << std::endl;
		Close(true);
	}
	controlsSizer->Add(
		new wxBitmapButton(this, PLAYNEXT, imageBitmap, wxDefaultPosition, wxSize(80, 80)),
		0,
		wxALL | wxALIGN_CENTRE,
		5
	);

	controlsSizer->AddStretchSpacer();

	this->SetSizer(controlsSizer);
}

