#pragma once

#include "PacketEvent.h"

class PacketListener {

public:
	virtual void update(PacketEvent* event);

};