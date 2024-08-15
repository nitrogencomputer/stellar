#include "rpc.hpp"
#include "../base.hpp"

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
    params["params"] = {{"startLedger", startledger}, {"filters", filters}};
    params["params"]["filters"] = {{"type", "contract"}, {"contractIds", contractIds}, {"topics", topics}};
    params["params"]["pagination"] = {"limit", pagelimit};

    /* object initialization from base class */
    /* to call related functions for calls */
    Stellar *stellar = new Stellar();

    /* we're using the sample http client */
    /* its a forwarded call to the stellar chain */
    /* and then we parse the string data returned */
    auto getEvents = stellar->stellar_forward_call(baseurl, params);
    auto eventResp = json::parse(getEvents);
    return eventResp;
}

json rpc::RPC::GetFeeStats(int id)
{
    /* the parameters are fed in json format */
    /* for nested data we feed it like a multi */
    /* dimensional array value set */
    json params;
    params["id"] = id;
    params["jsonrpc"] = "2.0";
    params["method"] = "getFeeStats";

    /* object initialization from base class */
    /* to call related functions for calls */
    Stellar *stellar = new Stellar();

    /* we're using the sample http client */
    /* its a forwarded call to the stellar chain */
    /* and then we parse the string data returned */
    auto getFeeStats = stellar->stellar_forward_call(baseurl, params);
    auto eventResp = json::parse(getFeeStats);
    return eventResp;
}

json rpc::RPC::GetHealth(int id)
{
    /* the parameters are fed in json format */
    /* for nested data we feed it like a multi */
    /* dimensional array value set */
    json params;
    params["id"] = id;
    params["jsonrpc"] = "2.0";
    params["method"] = "getHealth";


    /* object initialization from base class */
    /* to call related functions for calls */
    Stellar *stellar = new Stellar();

    /* we're using the sample http client */
    /* its a forwarded call to the stellar chain */
    /* and then we parse the string data returned */
    auto getHealth = stellar->stellar_forward_call(baseurl, params);
    auto eventResp = json::parse(getHealth);
    return eventResp;
}

json rpc::RPC::GetLatestLedger(int id)
{
    /* the parameters are fed in json format */
    /* for nested data we feed it like a multi */
    /* dimensional array value set */
    json params;
    params["id"] = id;
    params["jsonrpc"] = "2.0";
    params["method"] = "getLatestLedger";

    /* object initialization from base class */
    /* to call related functions for calls */
    Stellar *stellar = new Stellar();

    /* we're using the sample http client */
    /* its a forwarded call to the stellar chain */
    /* and then we parse the string data returned */
    auto getLatestLedger = stellar->stellar_forward_call(baseurl, params);
    auto eventResp = json::parse(getLatestLedger);
    return eventResp;
}

json rpc::RPC::GetNetwork(int id)
{
    /* the parameters are fed in json format */
    /* for nested data we feed it like a multi */
    /* dimensional array value set */
    json params;
    params["id"] = id;
    params["jsonrpc"] = "2.0";
    params["method"] = "getNetwork";

    /* object initialization from base class */
    /* to call related functions for calls */
    Stellar *stellar = new Stellar();
    stellar->Log("GetNetwork_Payload", params);
    /* we're using the sample http client */
    /* its a forwarded call to the stellar chain */
    /* and then we parse the string data returned */
    auto getNetwork = stellar->stellar_forward_call(baseurl, params);
    auto eventResp = json::parse(getNetwork);
    stellar->Log("GetNetworkEvent_Resp",eventResp);
    return eventResp;
}

json rpc::RPC::GetTransaction(int txId, std::string txHash)
{

    /* the parameters are fed in json format */
    /* for nested data we feed it like a multi */
    /* dimensional array value set */
    json params;
    params["id"] = txId;
    params["jsonrpc"] = "2.0";
    params["method"] = "getTransaction";
    params["params"] = {"hash", txHash};

    /* object initialization from base class */
    /* to call related functions for calls */
    Stellar *stellar = new Stellar();

    /* we're using the sample http client */
    /* its a forwarded call to the stellar chain */
    /* and then we parse the string data returned */
    auto getTransaction = stellar->stellar_forward_call(baseurl, params);
    auto eventResp = json::parse(getTransaction);
    return eventResp;
}

json rpc::RPC::GetTransactions(int id, int startLedger, int pagelimit)
{
    json params;
    params["jsonrpc"] ="2.0";
    params["id"] = id;
    params["method"] = "getTransactions";
    params["params"] = {"startLedger",startLedger};
    params["params"]["pagination"] = {"limit",pagelimit};

    Stellar* stellar = new Stellar();
    stellar->Log("GetTransactions_Payload", params);
    auto getTransactions = stellar->stellar_forward_call(baseurl, params);
    auto txResp = json::parse(getTransactions);
    return txResp;
}

json rpc::RPC::GetLedgerEntries(int id, json LedgerParams)
{
    /* the parameters are fed in json format */
    /* for nested data we feed it like a multi */
    /* dimensional array value set */
    json params;
    params["id"] = id;
    params["jsonrpc"] = "2.0";
    params["method"] = "getLedgerEntries";
    params["params"] = LedgerParams;

    /* object initialization from base class */
    /* to call related functions for calls */
    Stellar *stellar = new Stellar();

    /* we're using the sample http client */
    /* its a forwarded call to the stellar chain */
    /* and then we parse the string data returned */
    auto getLedgerEntries = stellar->stellar_forward_call(baseurl, params);
    auto eventResp = json::parse(getLedgerEntries);
    return eventResp;
}
