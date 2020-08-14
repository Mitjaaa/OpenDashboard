#include "globalColour.h"

globalColour::globalColour(ChannelType red, ChannelType green, ChannelType blue, int section, int index, bool autoSetting, ChannelType alpha)
	: clr(red, green, blue, alpha), section(section), index(index), autoSetting(autoSetting)
{
}

globalColour::globalColour()
{
}

globalColour::~globalColour()
{
}
