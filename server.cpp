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
			participantIDs.erase(participantIDs.begin() + i);
		}
	}
}

// Retorna o vector participantIDs para serem chamadados e listados no arquivo system.cpp
std::vector <int> Server::listParticipants()
{
    return participantIDs;
}

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

void Server::createChannel(string nc, string tp)
{
    if (channels.empty())
    {
        if (tp == "voz")
        {
            ChannelVoice* newChannelvoice = new ChannelVoice(nc);
            channels.push_back(newChannelvoice);
        }
        else if (tp == "texto")
        {
            ChannelText* newChanneltext = new ChannelText(nc);
            channels.push_back(newChanneltext);
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
                    ChannelText* newChanneltext = new ChannelText(nc);
                    channels.push_back(newChanneltext);
                }
                else if (itr->getType() == "texto" && tp == "voz")
                {
                    ChannelVoice* newChannelvoice = new ChannelVoice(nc);
                    channels.push_back(newChannelvoice);
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
            ChannelVoice* newChannelvoice = new ChannelVoice(nc);
            channels.push_back(newChannelvoice);
        }
        else if (tp == "texto")
        {
            ChannelText* newChanneltext = new ChannelText(nc);
            channels.push_back(newChanneltext);
        }
    }
}