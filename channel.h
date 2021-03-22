#ifndef CHANNEL_H
#define CHANNEL_H

#include "message.h"
#include <vector>

class Channel
{
private:
	string nome;
public:	
	Channel();
	~Channel();
	
};

class TextChannel : public Channel
{
private:
	std::vector<Message> messages;
};

class ChannelVoice : public Channel
{
private:
	Message LastMessage;
};

#endif	