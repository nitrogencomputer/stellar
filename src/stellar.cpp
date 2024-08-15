#include "stellar.hpp"
#include <curl/curl.h>

char* convert_string(std::string& datastring){
    char* csfn = (char*) datastring.c_str();
    return csfn;
}

size_t Stellar::stellar_call_back(void *contents, size_t content_size, size_t user_buffer, void *userdata)
{
    size_t real_size = content_size * user_buffer;
    char** str = (char**) userdata;
    if(*str == nullptr){
        *str = new char[real_size];
        char cast_char = static_cast<char>(sizeof(*str));
        memcpy(*str, contents, cast_char);}
    char cast_str = static_cast<char>(sizeof(*str));
    memcpy((void*)real_size,contents, cast_str);
    return real_size;
}

void Stellar::stellar_forward_call(std::string &url, const char** hparams, std::string params)
{
    CURL* curl =  curl_easy_init();
    std::string buffer;
    struct curl_slist * headers =  nullptr;
    for(int i = 0; i < sizeof(hparams); ++i){
        headers = curl_slist_append(headers, hparams[i]);
    }
    if(!curl) perror("cannot initialise curl");
    curl_easy_setopt(curl, CURLOPT_URL, convert_string(url));
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, convert_string(params));
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, stellar_call_back);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, convert_string(buffer));
    CURLcode res = curl_easy_perform(curl);
    if(res != CURLE_OK) perror("Bad response from server");
    curl_easy_cleanup(curl);
}
