#pragma once

#include <wx/wx.h>
#include "SongList.h"
#include "Menubar.h"

class Frame : public wxFrame
{
	public:
		Frame();
		virtual ~Frame();	

private:
	wxDECLARE_EVENT_TABLE();

	Menubar* menubar;
	
	SongList* songs;
};

