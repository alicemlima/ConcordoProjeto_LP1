#include "server.h"

Server::Server(string ns)
{
    this->nameServer = ns;
    this->descript = "Adione uma descrição";
    this->usuarioDonoId = User::userLog->getId();
    this->inviteCode = "";
    participantIDs.push_back(usuarioDonoId);
}

int Server::getUsuariodonoid()
{
    return usuarioDonoId;
}

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


void Server::addUser(int id)
{
    if (participantIDs.empty())
    {
        participantIDs.push_back(id);
    }
    else
    {
        for (int i = 0; i < (participantIDs.size()); i++)
        {
            if (participantIDs[i] == id)
            {
                break;
            }
        }
        participantIDs.push_back(id);
    }
}

void Server::removeUser(int id)
{
    for (int i = 0; i < (participantIDs.size()); i++)
	{
		if (participantIDs[i] == id)
		{
			participantIDs.erase(participantIDs.begin() + i);
		}
	}
}

// int Server::listParticipants()
// {
//     for (auto itr:participantIDs)
//     {
//         cout << itr << endl;
//     }
// }