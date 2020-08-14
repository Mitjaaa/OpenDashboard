#pragma once
#include <wx/wx.h>
#include "globalColour.h"
#include <fstream>

extern globalColour oldColour; //temp colour to have the changed colour saved

//section 1: text
extern std::vector<globalColour> textcolours;

extern globalColour textcolor1; //neon-green
extern globalColour textcolor2; //light blue	
extern globalColour textcolor3; //pink
extern globalColour textcolor4; //light pink
extern globalColour textcolor5; //very light grey
extern globalColour textcolor6; //white
extern globalColour textcolor7; //red


//section 2: background
extern std::vector<globalColour> bgcolours;

extern globalColour bgcolor1; //light grey 1
extern globalColour bgcolor2; //light grey 2
extern globalColour bgcolor3; //grey
extern globalColour bgcolor4; //dark grey


//section 3: general colours for all purposes
extern std::vector<globalColour> colours;

extern globalColour color1; //very light grey
extern globalColour backgroundColour;

extern void initColours();
