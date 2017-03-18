#include "PacketEvent.h"

PacketEvent::PacketEvent(int clientID, std::string information, GameEntity* p) : id{ clientID }, info{ information }, player{ p } 
{
}