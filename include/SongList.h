#pragma once

#include <wx/wx.h>
#include <wx/dir.h>

enum { SONGLIST = wxID_HIGHEST + 1 };

class SongList : public wxListBox
{
public:
	SongList(wxWindow*);

	void readDirectory(wxString);

private:
	wxDir* directory;
};

