#ifndef CHANNEL_H
#define CHANNEL_H

#include "message.h"
#include "channeltext.h"
#include "channelvoice.h"

#include <vector>

class Channel
{
protected:
	string nameChannel;
	string type;
public:	
	Channel(string nc, string tp);
	~Channel();

	string getNamechannel();
	void setNamechannel(string nc);

	string getType();
	void setType(string type);
};

#endif	