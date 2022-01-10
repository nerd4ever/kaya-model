//
// Created by sobrito on 09/01/2022.
//

#ifndef KAYA_MODEL_EVENT_H
#define KAYA_MODEL_EVENT_H

#include <string>
#include <map>
#include <memory>

namespace nerd4ever::kaya::model {
    class Event {
    public:
        [[nodiscard]] const std::string &getName() const;

        void setName(const std::string &name);

        [[nodiscard]] const std::string &getIdentifier() const;

        void setIdentifier(const std::string &identifier);

        void setParameter(const std::string &field, const std::string &value);

        std::string getParameter(const std::string &field);

        bool hasParameter(const std::string &field);

        static std::shared_ptr<Event> parser(const std::string &data, std::string &error);

        virtual std::string jsonEncode();

    private:
        std::string name;
        std::string identifier;
        std::map<std::string, std::string> parameters;
    };
}


#endif //KAYA_MODEL_EVENT_H
