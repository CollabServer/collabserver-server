#pragma once

#include "messaging/IMessage.h"
#include "messaging/event/debug/EventDebugCreate.h"


namespace collab {


class MessageDebugCreate : public IMessage {
    public:
        MessageDebugCreate() {
            this->m_event = new EventDebugCreate();
        }

        ~MessageDebugCreate() = default;

    private:
        char* m_location;
        char* m_name;

    public:
        void apply() override {
            this->m_event->run(*this);
        }
};


} // End namespace