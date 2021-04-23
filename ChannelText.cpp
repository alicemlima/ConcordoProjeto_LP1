#include "ChannelText.h"

ChannelText::ChannelText(string nc, string tp) : Channel(nc, tp)
{
    this->out = true;
}

ChannelText::~ChannelText(){}

void ChannelText::sendMessage(string ms)
{
    Message* newMessage = new Message(ms);
    messages.push_back(newMessage);
}

//Retorna o vector messages
std::vector <Message*> ChannelText::getMessages()
{
    return messages;
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
            cout << itr->getEnviadapor() << "<" << itr->getData_hora() << ">: " << itr->getConteudo();
        }
    }
    
}

void ChannelText::initChannel(string nc)
{
    cout << "\n-> Entrou no canal \'" << nc << "\'!" << endl;
                    
    cout << "\n ############## CONCORDO - CANAIS DE TEXTO ##############" << endl;
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
    else if (comando == "leaveChannel")
    {
        leaveChannel(false);
    }
}

void ChannelText::leaveChannel(bool o)
{
    out = o;
    Channel::channelLog = NULL;
    cout << "Saindo do canal \'" << this->getNamechannel() << "\'!" << endl;
}

bool ChannelText::getOut()
{
    return out;
}