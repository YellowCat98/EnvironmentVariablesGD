#include "env.hpp"

namespace env = EnvironmentVariables;

env::Manager* env::Manager::instance = nullptr;

env::Manager* env::Manager::get() {
    if (instance == nullptr) {
        instance = new env::Manager();
    }

    return instance;
}

void env::Manager::setVariable(const std::string& name, const std::string& value) {
    if (envVars.find(name) == envVars.end()) {
        envVars.insert({name, value});
    }
}

std::string env::Manager::getVariableValue(const std::string& value) {
    return envVars[value];
}

void env::Manager::removeVariable(const std::string& value) {
    envVars.erase(value);
}

std::map<std::string, std::string> env::Manager::getAllVariables() {
    return envVars;
}