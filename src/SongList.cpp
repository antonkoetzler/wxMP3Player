#include "SongList.h"

SongList::SongList(wxWindow* parent, wxWindowID id) : wxListBox(parent, id, wxDefaultPosition, wxDefaultSize)
{
	this->Insert("Hello", 0);
	this->Insert("Another song", 1);

	directory = new wxDir(wxGetCwd());
	if (directory->IsOpened()) std::cout << directory->GetName() << std::endl;
}

