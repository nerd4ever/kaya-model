//
// Created by sobrito on 09/01/2022.
//

#ifndef KAYA_MODEL_IWEBHOOK_H
#define KAYA_MODEL_IWEBHOOK_H

#include <nerd4ever/kaya/model/Event.h>

namespace nerd4ever::kaya::model {

    class IWebhook {
    public:
        virtual Event *getTriggerEvent() = 0;
    };
}


#endif //KAYA_MODEL_IWEBHOOK_H
