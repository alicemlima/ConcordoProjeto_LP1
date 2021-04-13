#include "channel.h"

Channel::Channel()
{
    this->nameChannel = "";
    this->type = "";
}

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

// ChannelText::ChannelText(string nc, string tp) : Channel(nc, tp)
// {
//     this->out = true;
// }

// ChannelText::~ChannelText(){}

// void ChannelText::sendMessage(string ms)
// {
//     Message* newMessage = new Message(ms);
//     messages.push_back(newMessage);
// }

// void ChannelText::listMessages()
// {
//     if (messages.empty())
//     {
//         cout << "\n-> Sem mensagens a serem exibidas!" << endl;
//     }
//     else
//     {
//         for (auto itr:messages)
//         {
//             cout << itr->getEnviadapor() << "<" << itr->getData_hora() << ">: " << itr->getConteudo();
//         }
//     }
    
// }

// void ChannelText::initChannel(string nc)
// {
//     cout << "\n-> Entrou no canal \'" << nc << "\'!" << endl;
                    
//     cout << "\n ############## CONCORDO - CANAIS DE TEXTO ##############" << endl;
//     cout << "                   \'" << nc << "\'" << endl;
//     cout << "\nDigite o comando desejado: \n"<< endl;
//     string comando;
//     cin >> comando;
                    
//     if (comando == "sendMessage")
//     {
//         string cont;
//         cin >> cont;

//         sendMessage(cont);
//     }
//     else if (comando == "listMessages")
//     {
//         listMessages();
//     }
//     else if (comando == "out")
//     {
//         setout(false);
//     }
// }

// ChannelVoice::ChannelVoice(string nc, string tp) : Channel(nc, tp)
// {
//     LastMessage = NULL;
//     this->out = true;
// }

// ChannelVoice::~ChannelVoice(){}

// void ChannelVoice::sendMessage(string ms)
// {
//     Message* newMessage = new Message(ms);
//     LastMessage = newMessage;
// }

// void ChannelVoice::listMessages()
// {
//     if (LastMessage == NULL)
//     {
//         cout << "\n-> Sem mensagens a serem exibidas!" << endl;
//     }
//     else
//     {
//         cout << LastMessage->getEnviadapor() << "<" << LastMessage->getData_hora() << ">: " << LastMessage->getConteudo() << endl;
//     }
// }

// void ChannelVoice::initChannel(string nc)
// {
//     cout << "\n-> Entrou no canal \'" << nc << "\'!" << endl;
                    
//     cout << "\n ############## CONCORDO - CANAIS DE VOZ ##############" << endl;
//     cout << "                   \'" << nc << "\'" << endl;
//     cout << "\nDigite o comando desejado: \n"<< endl;
    
//     string comando;
//     cin >> comando;
    
//     if (comando == "sendMessage")
//     {
//         string cont;
//         cin >> cont;

//         sendMessage(cont);
//     }
//     else if (comando == "listMessages")
//     {
//         listMessages();
//     }
//     else if (comando == "out")
//     {
//         setout(false);
//     }
// }

// void ChannelText::setout(bool o)
// {
//     out = o;
// }
// bool ChannelText::getout()
// {
//     return out;
// }

// void ChannelVoice::setout(bool o)
// {
//     out = o;
// }
// bool ChannelVoice::getout()
// {
//     return out;
// }