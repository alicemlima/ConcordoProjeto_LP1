#ifndef CHANNEL_H
#define CHANNEL_H

#include "message.h"

#include <vector>

class Channel
{
protected:
	string nameChannel;
	string type;
public:	
	Channel();
	Channel(string nc, string tp);
	~Channel();

	static Channel* channelLog;

	string getNamechannel();
	void setNamechannel(string nc);

	string getType();
	void setType(string type);
};
#endif