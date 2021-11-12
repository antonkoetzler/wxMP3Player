// A timer for updating the music gauge
#pragma once

#include <wx/wx.h>
#include <wx/mediactrl.h>

class UpdateGauge : public wxTimer
{
public:
	UpdateGauge(wxMediaCtrl*, wxSlider*);

	void Notify() wxOVERRIDE;

private:
	wxMediaCtrl* mediaPlayer;
	wxSlider* musicGauge; 
};

