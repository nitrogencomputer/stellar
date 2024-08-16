#include "base.hpp"
#include <curl/curl.h>

char* convert_string(std::string& datastring){
    char* csfn = (char*) datastring.c_str();
    return csfn;
}

size_t Stellar::stellar_call_back(void *contents, size_t content_size, size_t user_buffer, void *userdata)
{
     size_t real_size = content_size * user_buffer;
    std::string *str = static_cast<std::string *>(userdata);
    str->append(static_cast<char *>(contents), real_size);
    return real_size;
}

std::optional<std::string> Stellar::stellar_forward_call(std::string &url, json params)
{
    CURL* curl =  curl_easy_init();
    std::string buffer;
    json payload = params;
    std::string payload_sparse = payload.dump();
    Log("Payload_Data", payload_sparse.c_str());
    struct curl_slist * headers =  nullptr;
    headers = curl_slist_append(headers, "Content-Type:application/json");
    
    if(!curl) throw std::runtime_error("cannot initialise curl");
    curl_easy_setopt(curl, CURLOPT_URL, convert_string(url));
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload_sparse.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, stellar_call_back);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, convert_string(buffer));
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    CURLcode res = curl_easy_perform(curl);
    if(res != CURLE_OK) throw std::runtime_error("Bad response from server");
    curl_easy_cleanup(curl);
    return buffer;
}

void Stellar::Log(std::string comments, json data)
{
    std::cout << "____ Nitrogen Log ___\n";
    std::cout << comments << data << std::endl;
}
