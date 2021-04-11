#include "channel.h"

Channel::Channel(string nc, string tp)
{
    this->nameChannel = nc;
    this->type = tp;
}

Channel::~Channel(){}

string Channel::getNamechannel()
{
    return nameChannel;
}

void Channel::setNamechannel(string nc)
{
    nameChannel = nc;
}

string Channel::getType()
{
    return type;
}

void Channel::setType(string tp)
{
    type = tp;
}

ChannelText::ChannelText(string nc, string tp) : Channel(nc, tp)
{}

ChannelText::~ChannelText(){}

void ChannelText::sendMessage(string ms)
{
    Message* newMessage = new Message(ms);
    messages.push_back(newMessage);
}


ChannelVoice::ChannelVoice(string nc, string tp) : Channel(nc, tp)
{}

ChannelVoice::~ChannelVoice(){}

void ChannelVoice::sendMessage(string ms)
{
    Message* newMessage = new Message(ms);
    LastMessage = newMessage;
}