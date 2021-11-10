#include "MusicControls.h"

BEGIN_EVENT_TABLE(MusicControls, wxWindow)
	EVT_BUTTON(PLAYBUTTON, MusicControls::TogglePlay)
	EVT_BUTTON(SHUFFLE, MusicControls::ToggleShuffle)
	EVT_BUTTON(PLAYNEXT, MusicControls::PlayNext)
END_EVENT_TABLE()

MusicControls::MusicControls(wxWindow* parent, wxSize& size) : wxWindow(parent, MUSICCONTROLS, wxDefaultPosition, size)
{
	SetBackgroundColour(wxColour(52, 60, 92));

	// Allocating controlsSizer
	loadMusicControls();

	this->SetSizer(mainSizer);
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
		new wxBitmapButton(this, SHUFFLE, imageBitmap, wxDefaultPosition, wxSize(50, 50)),
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
		new wxBitmapButton(this, PLAYPREVIOUS, imageBitmap, wxDefaultPosition, wxSize(50, 50)),
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
		new wxBitmapButton(this, PLAYBUTTON, imageBitmap, wxDefaultPosition, wxSize(50, 50)),
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
		new wxBitmapButton(this, PLAYNEXT, imageBitmap, wxDefaultPosition, wxSize(50, 50)),
		0,
		wxALL | wxALIGN_CENTRE,
		5
	);

	controlsSizer->AddStretchSpacer();


	// Allocating mainSizer
	mainSizer = new wxBoxSizer(wxVERTICAL);

	mainSizer->Add(
		new wxSlider(this, MUSICGAUGE, 0, 0, 60, wxDefaultPosition, wxSize(275, 30)),
		0,
		wxALL | wxALIGN_CENTRE,
		15
	);
	mainSizer->Add(
		controlsSizer,
		0,
		wxALL | wxALIGN_CENTRE
	);
}

void MusicControls::SetMediaPlayer(wxString songName)
{
	if (mediaPlayer != nullptr)
	{
		delete mediaPlayer; mediaPlayer = nullptr;
	}

	wxString songPath = wxGetCwd() + "/../songs/" + songName;

	mediaPlayer = new wxMediaCtrl(
		this,
		MEDIA,
		songPath,
		wxDefaultPosition,
		wxDefaultSize
	);

	mediaPlayer->Play();
}

void MusicControls::TogglePlay(wxCommandEvent& evt)
{
	wxMediaState mediaState = mediaPlayer->GetState();

	switch (mediaState)
	{
		case wxMEDIASTATE_PLAYING:
			mediaPlayer->Pause();
			break;
		case wxMEDIASTATE_PAUSED:
			mediaPlayer->Play();
	}
}

void MusicControls::ToggleShuffle(wxCommandEvent& evt)
{
	if (shuffle)
		shuffle = false;
	else
		shuffle = true;
}

void MusicControls::PlayNext(wxCommandEvent& evt)
{
	if (!shuffle)
		shuffle = true;
	else
		shuffle = false;
}
