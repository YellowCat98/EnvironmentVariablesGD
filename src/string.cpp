#include "env.hpp"

namespace env = EnvironmentVariables;

size_t env::string::size() const {
    return data.size();
}

const char* env::string::c_str() const {
    return data.c_str();
}

const std::string& env::string::str() const {
    return data;
}

std::string env::string::parse_data(const std::string& str) {
    std::string result;
    size_t start = 0;

    while (start < str.size()) {
        size_t percentPos1 = str.find("%", start);

        if (percentPos1 == std::string::npos) {
            result += str.substr(start);
            break;
        }

        size_t percentPos2 = str.find("%", percentPos1 + 1);

        if (percentPos2 == std::string::npos) {
            result += str.substr(percentPos1);
            break;
        }

        result += str.substr(start, percentPos1 - start);

        std::string envVarName = str.substr(percentPos1 + 1, percentPos2 - percentPos1 - 1);

        result += env::Manager::get()->getVariableValue(envVarName);

        start = percentPos2 + 1; // btw did you know that if we changed the plus with an equals sign the game would slowly and slowly allocate more and more memory until it leaks
    }

    return result;
}