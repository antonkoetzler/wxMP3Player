#pragma once

#include <wx/wx.h>
#include <wx/dir.h>

class SongList : public wxListBox
{
public:
	SongList(wxWindow*, wxWindowID);

private:
	wxDir* directory;
};

