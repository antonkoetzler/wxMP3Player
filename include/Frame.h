#pragma once

#include <wx/wx.h>
#include <wx/dir.h>
#include "SongList.h"

class Frame : public wxFrame
{
	public:
		Frame();
		virtual ~Frame();

		// Event functions
		void Exit(wxCommandEvent&);

protected:
	wxDECLARE_EVENT_TABLE();

	// Menubar
	wxMenuBar* menubar;
		wxMenu* file;
			wxMenuItem* exit;
	
	// Listing files
	wxDir* directory;

	SongList* songs;
};

