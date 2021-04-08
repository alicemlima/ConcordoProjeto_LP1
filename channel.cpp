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