#pragma once

#include <wx/wx.h>
#include "MenuBar.h"
#include "SongList.h"
#include "MusicControls.h"

class Frame : public wxFrame
{
public:
	Frame();
	virtual ~Frame();	

private:
	wxDECLARE_EVENT_TABLE();

	// Enables and disables certain features
	// like the music controls and youtube-dl
	wxBoxSizer* controller;
	MenuBar* menubar;
	SongList* songlist;
	MusicControls* musiccontrols;
};

