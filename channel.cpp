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

void ChannelText::listMessages()
{
    if (messages.empty())
    {
        cout << "\n-> Sem mensagens a serem exibidas!" << endl;
    }
    else
    {
        for (auto itr:messages)
        {
            cout << itr->getEnviadapor() << itr->getData_hora() << ": " << itr->getConteudo();
        }
    }
    
}

ChannelVoice::ChannelVoice(string nc, string tp) : Channel(nc, tp)
{
    LastMessage = NULL;
}

ChannelVoice::~ChannelVoice(){}

void ChannelVoice::sendMessage(string ms)
{
    Message* newMessage = new Message(ms);
    LastMessage = newMessage;
}

void ChannelVoice::listMessages()
{
    if (LastMessage == NULL)
    {
        cout << "\n-> Sem mensagens a serem exibidas!" << endl;
    }
    else
    {
        cout << LastMessage->getEnviadapor() << LastMessage->getData_hora() << ": " << LastMessage->getConteudo() << endl;
    }
}