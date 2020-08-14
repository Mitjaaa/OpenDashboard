#include "Colors.h"
#include "Globals.h"


globalColour oldColour = globalColour(0, 0, 0, 0, 0, false);

//section 1: text
globalColour textcolor1 = globalColour(39, 232, 167, 1, 0, true);
globalColour textcolor2 = globalColour(105, 203, 214, 1, 1, true);
globalColour textcolor3 = globalColour(223, 69, 118, 1, 2, true);
globalColour textcolor4 = globalColour(223, 140, 157, 1, 3, true);
globalColour textcolor5 = globalColour(191, 191, 191, 1, 4, true);
globalColour textcolor6 = globalColour(255, 255, 255, 1, 5, true);
globalColour textcolor7 = globalColour(255, 66, 66, 1, 6, true);

std::vector<globalColour> textcolours = *new std::vector<globalColour>();


//section 2: background
globalColour bgcolor1 = globalColour(64, 64, 64, 2, 0, true);	
globalColour bgcolor2 = globalColour(52, 52, 52, 2, 1, true);
globalColour bgcolor3 = globalColour(46, 46, 46, 2, 2, true);
globalColour bgcolor4 = globalColour(34, 34, 34, 2, 3, true);

std::vector<globalColour> bgcolours = *new std::vector<globalColour>();


//section 3: general colours for all purposes
globalColour color1 = globalColour(191, 191, 191, 3, 0, true);
globalColour backgroundColour = globalColour(0, 0, 0, 3, 1, false);


std::vector<globalColour> colours = *new std::vector<globalColour>();


void initColours() {
	textcolours.push_back(textcolor1);
	textcolours.push_back(textcolor2);
	textcolours.push_back(textcolor3);
	textcolours.push_back(textcolor4);
	textcolours.push_back(textcolor5);
	textcolours.push_back(textcolor6);
	textcolours.push_back(textcolor7); 

	bgcolours.push_back(bgcolor1);
	bgcolours.push_back(bgcolor2);
	bgcolours.push_back(bgcolor3);
	bgcolours.push_back(bgcolor4);

	colours.push_back(color1);
	colours.push_back(backgroundColour);

	std::string line;
	std::ifstream settings("config.txt");

	if (settings.is_open())
	{
		while (getline(settings, line))
		{
			if (line.rfind("#", 0) != 0 && !line.empty())
			{
				std::vector<std::string> splitted = split(line, "=");
				
				if (splitted[0] == "main-background-color")
				{
					int index = atoi(split(splitted[1], "|")[1].c_str());

					if (splitted[2] == "white")
						splitted[2] = "255 255 255";
					else if (splitted[2] == "black")
						splitted[2] = "0 0 0";

					colours[index].clr = wxColour(
						atoi(split(splitted[2], " ")[0].c_str()),
						atoi(split(splitted[2], " ")[1].c_str()),
						atoi(split(splitted[2], " ")[2].c_str())
					);

				}
				else if(splitted[0] == "color")
				{
					int section = atoi(split(splitted[1], "|")[0].c_str());
					int index = atoi(split(splitted[1], "|")[1].c_str());


					if (splitted[2] == "white")
						splitted[2] = "255 255 255";
					else if (splitted[2] == "black")
						splitted[2] = "0 0 0";


					switch (section) {
					case 1:
						textcolours[index].clr = wxColour(
							atoi(split(splitted[2], " ")[0].c_str()),
							atoi(split(splitted[2], " ")[1].c_str()),
							atoi(split(splitted[2], " ")[2].c_str())
						);
						break;
					case 2:
						bgcolours[index].clr = wxColour(
							atoi(split(splitted[2], " ")[0].c_str()),
							atoi(split(splitted[2], " ")[1].c_str()),
							atoi(split(splitted[2], " ")[2].c_str())
						);
						break;
					case 3:
						colours[index].clr = wxColour(
							atoi(split(splitted[2], " ")[0].c_str()),
							atoi(split(splitted[2], " ")[1].c_str()),
							atoi(split(splitted[2], " ")[2].c_str())
						);
						break;
					}
				}
			}
		}
	}
}