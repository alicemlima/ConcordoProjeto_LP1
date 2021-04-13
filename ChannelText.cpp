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
    else if (comando == "out")
    {
        setout(false);
    }
}

void ChannelText::setout(bool o)
{
    out = o;
}
bool ChannelText::getout()
{
    return out;
}