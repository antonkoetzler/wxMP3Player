#include "SongList.h"

SongList::SongList(wxWindow* parent) : wxListBox(parent, SONGLIST)
{
	directory = nullptr;
    readDirectory(wxGetCwd() + "/../songs");
}

void SongList::readDirectory(wxString dir)
{
	directory = new wxDir(dir);

	if (!directory->IsOpened())
		std::cout << "ERROR OPENING DIRECTORY" << std::endl;
	
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

	delete directory; directory = nullptr;
}

