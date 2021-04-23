#include "server.h"

Server::Server(string ns)
{
    this->nameServer = ns;
    this->descript = "Sem descrição";
    this->usuarioDonoId = User::userLog->getId();
    this->inviteCode = "";
    participantIDs.push_back(usuarioDonoId);
}

// Retorna o ID do usuário dono do servidor
// O usuário dono só é alteradorado na sua criação, não necessitando de uma função set
int Server::getUsuariodonoid()
{
    return usuarioDonoId;
}

//Métodos getter e setter dos atributos da classe Server
string Server::getNameserver()
{
    return nameServer;
}
void Server::setNameserver(string ns)
{
    nameServer = ns; 
}

string Server::getDescript()
{
    return descript;
}
void Server::setDescript(string dt)
{
    descript = dt;
}

string Server::getInvitecode()
{
    return inviteCode;
}
void Server::setInvitecode(string in)
{
    inviteCode = in;
}

// Adiciona o ID de um novo usuário no vector participantIDs
void Server::addUser(int id)
{
    if (participantIDs.empty())
    {
        participantIDs.push_back(id);
    }
    else
    {
        int aux_part = participantIDs.size();
        for (int i = 0; i < aux_part; i++)
        {
            if (participantIDs[i] == id)
            {
                break;
            }
        }
        participantIDs.push_back(id);
    }
}

// Adiciona o ID de um  usuário do vector participantIDs
void Server::removeUser(int id)
{
    int aux_part = participantIDs.size();
    for (int i = 0; i < aux_part; i++)
	{
		if (participantIDs[i] == id)
		{
            cout << participantIDs[i] << endl;
			participantIDs.erase(participantIDs.begin() + i);
            break;
		}
	}
}

// Retorna o vector Channels
std::vector <Channel*> Server::getChannels()
{
    return channels;
}

// Retorna o vector ChannelsText
std::vector <ChannelText*> Server::getChannelText()
{
    return ChannelsText;
}

// Retorna o vector ChannelsVoice
std::vector <ChannelVoice*> Server::getChannelVoice()
{
    return ChannelsVoice;
}

// Retorna o vector participantIDs para serem chamadados e listados no arquivo system.cpp
std::vector <int> Server::getParticipants()
{
    return participantIDs;
}

// Comando dos Canais
// Pocurar canais - se existir = true e se não existir = false
bool Server::searchChannel(string nc)
{
    for (auto itr:channels)
    {
        if (itr->getNamechannel() == nc)
        {
            return true;
        }
    }
    return false;
}

// Criar canais - parâmetros: nome e tipo
void Server::createChannel(string nc, string tp)
{
    if (channels.empty())
    {
        if (tp == "voz")
        {
            ChannelVoice* newChannelvoice = new ChannelVoice(nc, tp);
            channels.push_back(newChannelvoice);
            ChannelsVoice.push_back(newChannelvoice);
            cout << "\n-> Canal de Voz \'" << nc << "\' criado!" << endl;
        }
        else if (tp == "texto")
        {
            ChannelText* newChanneltext = new ChannelText(nc, tp);
            channels.push_back(newChanneltext);
            ChannelsText.push_back(newChanneltext);
            cout << "\n-> Canal de texto \'" << nc << "\' criado!" << endl;
        }
    }
    else if (searchChannel(nc) == true)
    {
        for (auto itr:channels)
        {
            if (itr->getNamechannel() == nc)
            {
                if (itr->getType() == "voz" && tp == "texto")
                {
                    ChannelText* newChanneltext = new ChannelText(nc, tp);
                    channels.push_back(newChanneltext);
                    ChannelsText.push_back(newChanneltext);
                    cout << "\n-> Canal de texto \'" << nc << "\' criado!" << endl;
                }
                else if (itr->getType() == "texto" && tp == "voz")
                {
                    ChannelVoice* newChannelvoice = new ChannelVoice(nc, tp);
                    channels.push_back(newChannelvoice);
                    ChannelsVoice.push_back(newChannelvoice);
                    cout << "\n-> Canal de Voz \'" << nc << "\' criado!" << endl;
                }
                else
                {
                    cout << "\nCanal de " << tp << "\'" << nc << "\' já existe!" << endl;
                }
            }
        }
    }
    else
    {
        if (tp == "voz")
        {
            ChannelVoice* newChannelvoice = new ChannelVoice(nc, tp);
            channels.push_back(newChannelvoice);
            ChannelsVoice.push_back(newChannelvoice);
            cout << "\n-> Canal de Voz \'" << nc << "\' criado!" << endl;
        }
        else if (tp == "text o")
        {
            ChannelText* newChanneltext = new ChannelText(nc, tp);
            channels.push_back(newChanneltext);
            ChannelsText.push_back(newChanneltext);
            cout << "\n-> Canal de texto \'" << nc << "\' criado!" << endl;
        }
    }
}

// Listar Canais do servidor
void Server::listChannel()
{
    if (channels.empty())
    {
        cout << "Você não possui Canais, crie ou entre em um!" << endl;
    }
    else 
    {
        cout << "\n#canais de texto" << endl;
        for (auto itr:channels)
        {
            if (itr->getType() == "texto")
            {
                cout << itr->getNamechannel() << endl;
            }
        }
        cout << "\n#canais de voz" << endl;
        for (auto itr:channels)
        {
            if (itr->getType() == "Voz")
            {
                cout << itr->getNamechannel() << endl;
            }
        
        }
    }
}

// Entra em um canal do servidor
void Server::enterChannel(string nc, string tp)
{
    if (searchChannel(nc) == true)
    {
        if (tp == "texto")
        {
            for (auto itr:ChannelsText)
            {
                if (itr->getNamechannel() == nc)
                {
                    Channel::channelLog = itr;
                    do
                    {
                        itr->initChannel(nc);
                    } while (itr->getOut() == true);
                    
                }
            }
        }
        else if (tp == "voz")
        {
            for (auto itr:ChannelsVoice)
            {
                if (itr->getNamechannel() == nc)
                {
                    Channel::channelLog = itr;
                    itr->initChannel(nc);
                }
            }
        }
    }
    else
    {
        cout << "\nCanal \'" << nc << "\' não existe!" << endl;
    }
}

// Sair de um canal do servidor
void Server::leaveServer()
{
    Server::serverLog = NULL;
    cout << "Saindo do Servidor \'" << this->getNameserver() << "\'!" << endl;
}

// Menu para comando do servidor
void Server::initServer()
{
    string comando;
    cin >> comando;
    if (comando == "createChannel")
    {
        string channelname, channeltype;
        cin >> channelname >> channeltype;

        createChannel(channelname, channeltype);
    }
    else if (comando == "listChannel")
    {
        listChannel();
    }
    else if (comando == "enterChannel")
    {
        cout << "\nDigite o nome e o tipo: " << endl;
        string channelname, channeltype;
        cin >> channelname >> channeltype;
        enterChannel(channelname, channeltype);
    }
    else if (comando == "leaveServer")
    {
        leaveServer();
    }
}