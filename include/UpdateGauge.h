// A timer for updating the music gauge
#pragma once

#include <wx/wx.h>
#include <wx/mediactrl.h>
#include "SongList.h"

class UpdateGauge : public wxTimer
{
public:
	UpdateGauge(wxMediaCtrl*, wxSlider*, SongList*);

	void Notify() wxOVERRIDE;

private:
	wxMediaCtrl* mediaPlayer;
	wxSlider* musicGauge;
	SongList* playlist;
};

