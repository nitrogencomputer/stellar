#include <iostream>
#include <string>

class Stellar {
    private:
    public:
    static size_t stellar_call_back(void* contents, size_t content_size, size_t user_buffer, void* userdata);
    void stellar_forward_call(std::string& url, const char** hparams, std::string params);
};