#pragma once

#include <Geode/Geode.hpp>

#ifdef GEODE_IS_WINDOWS
    #ifdef YELLOWCAT98_ENVIRONMENT_VARIABLES_EXPORTING
        #define ENV_DLL __declspec(dllexport)
    #else
        #define ENV_DLL __declspec(dllimport)
    #endif
#else
    #define ENV_DLL __attribute__((visibility("default")))
#endif

namespace EnvironmentVariables {
    class ENV_DLL Manager {
    private:
        Manager() {}
        static Manager* instance;
        std::map<std::string, std::string> envVars;
    public:
        static Manager* get();
        void setVariable(const std::string& name, const std::string& value);
        std::string getVariableValue(const std::string& value);
        void removeVariable(const std::string& value);
        std::map<std::string, std::string> getAllVariables();
    };

    class ENV_DLL string {
    private:
        std::string data;
        std::string parse_data(const std::string& str);
    
    public:
        string() : data("") {}

        string(const std::string& str) : data(parse_data(str)) {}

        string(const char* str) : data(parse_data(str)) {}

        string(const string& other) = default; // this looks so wrong

        string(string&& other) noexcept = default;

        ~string() = default;

        string& operator=(const string& other) = default;

        string& operator=(string&& other) noexcept = default;

        string& operator=(const std::string& str) {
            data = str;
            return *this;
        }

        string& operator=(const char* str) {
            data = str;
            return *this;
        }

        size_t size() const;

        char& operator[](size_t index) {
            return data[index];
        }

        const char& operator[](size_t index) const {
            return data[index];
        }

        const char* c_str() const;

        const std::string& str() const;
    };
}