#include "MusicControls.h"

BEGIN_EVENT_TABLE(MusicControls, wxWindow)
	EVT_BUTTON(PLAYBUTTON, MusicControls::TogglePlay)
	EVT_BUTTON(SHUFFLE, MusicControls::ToggleShuffle)
	EVT_BUTTON(PLAYNEXT, MusicControls::PlayNext)
	EVT_BUTTON(PLAYPREVIOUS, MusicControls::PlayPrevious)
	EVT_SCROLL_THUMBRELEASE(MusicControls::ChangeCurrentTimePlaying)
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

	musicGauge = new wxSlider(
		this,
		MUSICGAUGE,
		0,
		0,
		60,
		wxDefaultPosition,
		wxSize(275, 30)
	);

	mainSizer->Add(
		musicGauge,
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

void MusicControls::SetMediaPlayer(wxString songName, SongList* songs)
{
	if (playlist != nullptr)
		playlist = nullptr;
	if (mediaPlayer != nullptr)
	{
		delete mediaPlayer; mediaPlayer = nullptr;
	}

	playlist = songs;

	wxString songPath = wxGetCwd() + "/../songs/" + songName;

	songCache.push_back(songPath);

	mediaPlayer = new wxMediaCtrl(
		this,
		MEDIA,
		songPath,
		wxDefaultPosition,
		wxDefaultSize
	);

	if (musicGaugeTimer != nullptr)
	{
		delete musicGaugeTimer; musicGaugeTimer = nullptr;
	}
	musicGaugeTimer = new UpdateGauge(mediaPlayer, musicGauge, playlist);

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
	if (playlist != nullptr)
	{
		int nextSongIndex;

		songCache.push_back(playlist->GetString(playlist->GetSelection()));

		if (shuffle)
			nextSongIndex = (rand() % playlist->GetCount() + 1) - 1;
		else
		{
			nextSongIndex =  playlist->GetSelection() + 1;

			// Checking to see if we're currently on the last song of the playlist
			if (nextSongIndex > (playlist->GetCount() - 1))
				nextSongIndex = 0;
		}

		// Loading the next song
		wxString songName = playlist->GetString(nextSongIndex);
		wxString songDirectory = wxGetCwd() + "/../songs/" + songName;

		mediaPlayer->Load(songDirectory);
		mediaPlayer->Play();

		playlist->SetSelection(nextSongIndex);
	}
}

void MusicControls::PlayPrevious(wxCommandEvent& evt)
{
	mediaPlayer->Load(songCache[songCache.size() - 1]);
	mediaPlayer->Play();
	songCache.pop_back();
}

void MusicControls::ChangeCurrentTimePlaying(wxScrollEvent& evt)
{
	musicGauge->SetValue(evt.GetPosition());
	mediaPlayer->Seek(evt.GetPosition() * 1000);
}
