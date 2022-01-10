//
// Created by sobrito on 09/01/2022.
//

#include <nerd4ever/kaya/model/Event.h>
#include <json/json.h>

using namespace nerd4ever::kaya::model;

const std::string &Event::getName() const {
    return name;
}

void Event::setName(const std::string &value) {
    Event::name = value;
}

const std::string &Event::getIdentifier() const {
    return identifier;
}

void Event::setIdentifier(const std::string &value) {
    Event::identifier = value;
}

void Event::setParameter(const std::string &field, const std::string &value) {
    auto it = parameters.find(field);
    if (it == parameters.end()) parameters.insert({field, value});
    else it->second = value;
}

std::string Event::getParameter(const std::string &field) {
    auto it = parameters.find(field);
    if (it == parameters.end()) return {};
    return it->second;
}

bool Event::hasParameter(const std::string &field) {
    auto it = parameters.find(field);
    return it != parameters.end();
}

std::string Event::jsonEncode() {
    Json::Value jData;
    jData["name"] = name;
    jData["identifier"] = identifier;
    for (const auto &p: parameters) jData["parameters"][p.first] = p.second;
    Json::StreamWriterBuilder builder;
    builder["indentation"] = "";
    return Json::writeString(builder, jData);
}

std::shared_ptr<Event> Event::parser(const std::string &data, std::string &error) {
    try {
        error = {};
        Json::Value jData;
        Json::CharReaderBuilder builder;
        Json::CharReader *reader = builder.newCharReader();
        std::string jsonError;
        bool parsingSuccessful = reader->parse(data.c_str(), data.c_str() + data.size(), &jData, &jsonError);
        if (!parsingSuccessful) throw std::runtime_error(jsonError.c_str());

        if (!jData.isMember("name") || !jData["name"].isString() ||
            !jData.isMember("identifier") || !jData["identifier"].isString()) {
            throw std::runtime_error("Bad format, name and identifier are required");
        }
        auto evt = std::make_shared<Event>();
        evt->setName(jData["name"].asString());
        evt->setIdentifier(jData["identifier"].asString());

        if (jData.isMember("parameters")) {
            if (!jData["parameters"].isObject()) throw std::runtime_error("The parameter must be of type object");
            auto jParameters = jData["parameters"];
            for (Json::Value::const_iterator itr = jParameters.begin(); itr != jParameters.end(); itr++) {
                std::string key = itr.key().asString();
                if (!jParameters[key].isString()) throw std::runtime_error("Only string parameters are supported");
                evt->setParameter(key, jParameters[key].asString());
            }
        }
        return evt;
    } catch (std::exception &ex) {
        error = ex.what();
        return nullptr;
    }
}

