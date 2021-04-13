#include "ChannelVoice.h"

ChannelVoice::ChannelVoice(string nc, string tp) : Channel(nc, tp)
{
    LastMessage = NULL;
    this->out = true;
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
        cout << LastMessage->getEnviadapor() << "<" << LastMessage->getData_hora() << ">: " << LastMessage->getConteudo() << endl;
    }
}

void ChannelVoice::initChannel(string nc)
{
    cout << "\n-> Entrou no canal \'" << nc << "\'!" << endl;
                    
    cout << "\n ############## CONCORDO - CANAIS DE VOZ ##############" << endl;
    cout << "                   \'" << nc << "\'" << endl;
    cout << "\nDigite o comando desejado: \n"<< endl;
    
    string comando;
    cin >> comando;
    
    if (comando == "sendMessage")
    {
        string cont;
        cin >> cont;

        sendMessage(cont);
    }
    else if (comando == "listMessages")
    {
        listMessages();
    }
    else if (comando == "out")
    {
        setout(false);
    }
}

void ChannelVoice::setout(bool o)
{
    out = o;
}
bool ChannelVoice::getout()
{
    return out;
}