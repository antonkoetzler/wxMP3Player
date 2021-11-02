#include "SongList.h"

SongList::SongList(wxWindow* parent) : wxListBox(parent, SONGLIST, wxDefaultPosition, wxDefaultSize)
{
	directory = nullptr;
	listSongs();
}

void SongList::listSongs()
{
	wxString defaultDirectory = wxGetCwd() + "/../songs";
	directory = new wxDir(defaultDirectory);

	if (directory->IsOpened())
	{
		wxString filename;
		bool fileFound = directory->GetFirst(
			&filename,
			wxEmptyString,
			wxDIR_FILES
		);

		while (fileFound)
		{
			this->Append(filename);
			fileFound = directory->GetNext(&filename);
		}
	}

	delete directory; directory = nullptr;
}

