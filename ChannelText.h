#ifndef CHANNEL_TEXT_H
#define CHANNEL_TEXT_H

#include "channel.h"
#include <vector>

class ChannelText : public Channel
{
private:
	std::vector<Message*> messages;
	bool out;
public:
	ChannelText(string nc, string tp);
	~ChannelText();

	void sendMessage(string ms);
	void listMessages();
	void initChannel(string nc);

	void setout(bool o);
	bool getout();
};


#endif