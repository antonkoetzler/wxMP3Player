#pragma once

#include <wx/wx.h>
#include <wx/mediactrl.h>

enum
{
	MUSICCONTROLS,
	SHUFFLE,
	PLAYPREVIOUS,
	PLAYBUTTON,
	PLAYNEXT,
	MUSICGAUGE,
	MEDIA
};

class MusicControls : public wxWindow
{
public:
	MusicControls(wxWindow*, wxSize&);

	// Allocates controlsSizer
	void loadMusicControls();

	// Sets the media player to play media
	void SetMediaPlayer(wxString);
	void TogglePlay(wxCommandEvent&);
	void ToggleShuffle(wxCommandEvent&);
	void PlayNext(wxCommandEvent&);

private:
	DECLARE_EVENT_TABLE();

	// Sizer to hold controlsSizer and the music gauge
	wxBoxSizer* mainSizer;

	// Holds: Shuffle, play/pause, previous, and next
	wxBoxSizer* controlsSizer;

	// For loading images
	wxBitmap imageBitmap;

	// For playing songs
	wxMediaCtrl* mediaPlayer = nullptr;
	bool shuffle = false;
};
