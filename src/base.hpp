#ifndef BASE_H 
#define BASE_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <optional>

#include "../json/include/nlohmann/json.hpp"

using json = nlohmann::json;

class Stellar {
    private:
    public:
    static size_t stellar_call_back(void* contents, size_t content_size, size_t user_buffer, void* userdata);
    std::optional<std::string> stellar_forward_call(std::string& url, json params);
    void Log(std::string comments, json data);
};

#endif
