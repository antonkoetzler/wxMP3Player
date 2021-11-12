#pragma once

#include <wx/wx.h>
#include <wx/mediactrl.h>
#include <stdlib.h>
#include <vector>
#include "SongList.h"

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

	void SetMediaPlayer(wxString, SongList*);
	void TogglePlay(wxCommandEvent&);
	void ToggleShuffle(wxCommandEvent&);
	void PlayNext(wxCommandEvent&);
	void PlayPrevious(wxCommandEvent&);

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
	SongList* playlist = nullptr;
	std::vector<wxString> songCache;
};
