#ifndef CHANNEL_H
#define CHANNEL_H

#include "message.h"
// #include "channeltext.h"
// #include "channelvoice.h"

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

// class ChannelText : public Channel
// {
// private:
// 	std::vector<Message*> messages;
// 	bool out;
// public:
// 	ChannelText(string nc, string tp);
// 	~ChannelText();

// 	void sendMessage(string ms);
// 	void listMessages();
// 	void initChannel(string nc);

// 	void setout(bool o);
// 	bool getout();
// };

// class ChannelVoice : public Channel
// {
// private:
// 	Message* LastMessage;
// 	bool out;
// public:
// 	ChannelVoice(string nc, string tp);
// 	~ChannelVoice();

// 	void sendMessage(string ms);
// 	void listMessages();
// 	void initChannel(string nc);

// 	void setout(bool o);
// 	bool getout();
// };
#endif