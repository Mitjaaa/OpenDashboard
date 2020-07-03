#include "Colors.h"


inline bool exists(const std::string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

wxColour textcolor1 = wxColour(39, 232, 167);
wxColour textcolor2 = wxColour(105, 203, 214);
wxColour textcolor3 = wxColour(223, 69, 118);
wxColour textcolor4 = wxColour(223, 140, 157);
wxColour textcolor5 = wxColour(191, 191, 191);
wxColour textcolor6 = wxColour(255, 255, 255);

wxColour closecolor = wxColour(255, 66, 66);

wxColour color1 = wxColour(64, 64, 64);
wxColour color2 = wxColour(52, 52, 52);
wxColour color3 = wxColour(46, 46, 46);
wxColour color4 = wxColour(34, 34, 34);
wxColour color5 = wxColour(191, 191, 191);

void loadColours()
{
	/*static wxColour* textcolor1; //neon-green
	static wxColour* textcolor2; //light blue	
	static wxColour* textcolor3; //pink
	static wxColour* textcolor4; //light pink

	static wxColour* closecolor; //red		

	static wxColour* bgcolor1; //light grey
	static wxColour* bgcolor2; //grey*/

	if (exists("ODashboard_settings.txt")) {

	}
}
