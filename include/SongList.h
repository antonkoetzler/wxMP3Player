#pragma once

#include <wx/wx.h>

class SongList : public wxListBox
{
public:
	SongList(wxWindow* parent, wxWindowID id) : wxListBox(parent, id, wxDefaultPosition, wxDefaultSize)
	{
		this->Insert("Hello", 0);
		this->Insert("Bye", 1);
	}
};

