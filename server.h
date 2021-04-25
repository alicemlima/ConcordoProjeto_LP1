#ifndef SERVER_H
#define SERVER_H

#include "channel.h"
#include "ChannelText.h"
#include "ChannelVoice.h"
#include <vector>

class Server
{
private:
	// O ID do usuário que criou o servidor
	int usuarioDonoId; 
	string nameServer,
	descript,
	inviteCode; // Código necessário para se entrar no servidor
	// Vetor de canais que já estão no servidor
	std::vector<Channel*> channels;
	std::vector<ChannelText*> ChannelsText;
	std::vector<ChannelVoice*> ChannelsVoice;
	// Vetor de IDs de usuários que já estão no servidor
	std::vector<int> participantIDs;

public:
	Server(string ns);
	~Server();
	static Server* serverLog;
	int getUsuariodonoid();
	void setUsuariodonoid(int ud);
	string getNameserver();
	void setNameserver(string ns);
	string getDescript();
	void setDescript(string dt);
	string getInvitecode();
	void setInvitecode(string in);
	void addUser(int id);
	void removeUser(int id);
	std::vector <Channel*> getChannels();
	std::vector <ChannelText*> getChannelText();
	std::vector <ChannelVoice*> getChannelVoice();
	std::vector <int> getParticipants();
	bool searchChannel(string nc);
	void createChannel(string nc, string tp);
	void listChannel();
	void enterChannel(string nc, string tp);	
	void leaveServer();
	void initServer();
};

#endif