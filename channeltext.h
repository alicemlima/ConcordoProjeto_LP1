#ifndef CHANNEL_TEXT_H
#define CHANNEL_TEXT_H

#include "channel.h"
#include <vector>

class Channeltext : public Channel
{
private:
	std::vector<Message> messages;
public:
	Channeltext(string nc, string tp);
	~Channeltext();
};

#endif