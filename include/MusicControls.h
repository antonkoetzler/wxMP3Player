#pragma once

#include <wx/wx.h>

enum
{
	MUSICCONTROLS = wxID_HIGHEST + 1,
	SHUFFLE = wxID_HIGHEST + 1,
	PLAYPREVIOUS = wxID_HIGHEST + 1,
	PLAYBUTTON = wxID_HIGHEST + 1,
	PLAYNEXT = wxID_HIGHEST + 1,
	MUSICGAUGE = wxID_HIGHEST + 1
};

class MusicControls : public wxWindow
{
public:
	MusicControls(wxWindow*, wxSize&);

	// Allocates controlsSizer
	void loadMusicControls();

private:
	// Sizer to hold controlsSizer and the music gauge
	wxBoxSizer* mainSizer;

	// Holds: Shuffle, play/pause, previous, and next
	wxBoxSizer* controlsSizer;

	// For loading images
	wxBitmap imageBitmap;
};

