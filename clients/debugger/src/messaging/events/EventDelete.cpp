#include "messaging/events/EventDelete.h"

#include <elephantlogger/log.h>


using namespace collab;


void EventDelete::receive(MessageDelete & message) const {
    LOG_DEBUG(0, "EventDelete (Server)");
}

