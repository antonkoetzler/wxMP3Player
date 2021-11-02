#include "SongList.h"

SongList::SongList(wxWindow* parent) : wxListBox(parent, SONGLIST)
{
	directory = nullptr;
}

