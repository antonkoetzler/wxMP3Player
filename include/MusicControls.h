#pragma once

#include <wx/wx.h>

enum { MUSICCONTROLS = wxID_HIGHEST + 1, PLAYBUTTON = wxID_HIGHEST + 1 };

class MusicControls : public wxWindow
{
public:
	MusicControls(wxWindow*, wxSize&);

	void loadMusicControls();

private:
	wxBoxSizer* controlsSizer;

	// For loading images
	wxBitmap imageBitmap;
};

