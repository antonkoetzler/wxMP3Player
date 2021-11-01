#pragma once

#include <wx/wx.h>
#include "SongList.h"
#include "MenuBar.h"

class Frame : public wxFrame
{
public:
	Frame();
	virtual ~Frame();	

private:
	wxDECLARE_EVENT_TABLE();

	MenuBar* menubar;
	SongList* songs;
};

