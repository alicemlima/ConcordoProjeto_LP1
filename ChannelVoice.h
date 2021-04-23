#ifndef CHANNEL_VOICE_H
#define CHANNEL_VOICE_H

#include "channel.h"

class ChannelVoice : public Channel
{
private:
	Message* LastMessage;
	bool out;
public:
	ChannelVoice(string nc, string tp);
	~ChannelVoice();
	Message* getMessages();
	void sendMessage(string ms);
	void listMessages();
	void initChannel(string nc);

	void leaveChannel(bool o);
	bool getOut();
};

#endif