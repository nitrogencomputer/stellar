#include "rpc.hpp"
#include "./base.hpp"

/* we can allow up to 5 header values to be passed */
static int max_header = 5;
json rpc::RPC::GetEvents(int id, int startledger, std::vector<std::unordered_map<std::string, std::string>> filters,
                        std::vector<std::string> contractIds, std::vector<std::vector<std::string>> topics, int pagelimit)
{
    /* the parameters are fed in json format */
    /* for nested data we feed it like a multi */
    /* dimensional array value set */
    json params;
    params["id"] = id;
    params["jsonrpc"] = "2.0";
    params["method"] = "getEvents";
    
    /* the filter is a vector of an unordered map */
    /* and takes in strings for both key & values */
    params["params"] = {{"startLedger",startledger},{"filters", filters}};
    params["params"]["filters"] = {{"type","contract"},{"contractIds",contractIds},{"topics",topics}};
    params["params"]["pagination"] = {"limit", pagelimit};

    /* from the max_header initialised set the headers */
    /* let each header value feed a const char* value */
    const char** headers = (const char**) new char[max_header];
    headers[0] = "Content-Type:application/json";
    headers[1] = "Accept:application/json";

    /* object initialization from base class */
    /* to call related functions for calls */
    Stellar* stellar = new Stellar();

    /* we're using the sample http client */
    /* its a forwarded call to the stellar chain */
    /* and then we parse the string data returned */
    auto getEvents = stellar->stellar_forward_call(baseurl,headers,params);
    auto eventResp = json::parse(getEvents);
    return eventResp;
}