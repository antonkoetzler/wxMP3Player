#include "App.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	mainWindow = new Frame();
	mainWindow->Show();

	return true;
}

