#pragma once

#include <wx/wx.h>

enum { YT2MP3 };

class MenuBar : public wxMenuBar
{
public:
	MenuBar();
	void Exit(wxCommandEvent&);
	void Youtube2MP3(wxCommandEvent&);
	void ConvertToMP3(wxCommandEvent&);

private:
	wxMenu* file;
		wxMenuItem* exit;
	
	wxMenu* add;
		wxMenuItem* yt2mp3; // Youtube to mp3's a song
};

