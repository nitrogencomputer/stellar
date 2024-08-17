#include "rpc.hpp"
#include "rpc_resp.hpp"
#include "../base.hpp"

static int max_header_values = 5;
GetEventsDataResponse rpc::RPC::GetEvents(int id, int startledger, std::vector<std::unordered_map<std::string, std::string>> filters,
                                          std::vector<std::string> contractIds, std::vector<std::vector<std::string>> topics, int pagelimit)
{
    json params;
    params["id"] = id;
    params["jsonrpc"] = "2.0";
    params["method"] = "getEvents";

    params["params"] = {{"startLedger", startledger}, {"filters", filters}};
    params["params"]["filters"] = {{"type", "contract"}, {"contractIds", contractIds}, {"topics", topics}};
    params["params"]["pagination"] = {"limit", pagelimit};

    Stellar *stellar = new Stellar();

    auto getEvents = stellar->stellar_forward_call(baseurl, params);
    if (getEvents == std::nullopt)
    {
        stellar->Log("empty data returned", {});
        return {};
    }
    auto eventResp = json::parse(getEvents);
    Response response;
    auto eventsDataResponse = response.GetEventsResponse(eventResp);
    return eventsDataResponse;
}

GetFeeStats rpc::RPC::GetFeeStats(int id)
{
    json params;
    params["id"] = id;
    params["jsonrpc"] = "2.0";
    params["method"] = "getFeeStats";

    Stellar *stellar = new Stellar();
    auto getFeeStats = stellar->stellar_forward_call(baseurl, params);
    if (getFeeStats == std::nullopt)
    {
        stellar->Log("empty data returned", {});
        return {};
    }
    auto feeStatsResp = json::parse(getFeeStats);
    Response response;
    auto feeStatsData = response.GetFeeStatsResponse(feeStatsResp);
    return feeStatsData;
}

GetHealthDataResponse rpc::RPC::GetHealth(int id)
{
    json params;
    params["id"] = id;
    params["jsonrpc"] = "2.0";
    params["method"] = "getHealth";

    Stellar *stellar = new Stellar();
    auto getHealth = stellar->stellar_forward_call(baseurl, params);
    if (getHealth == std::nullopt)
    {
        stellar->Log("empty data returned", {});
        return {};
    }
    auto eventResp = json::parse(getHealth); Response response;
    auto healthstats = response.GetHealthResponse(eventResp);
    return healthstats;
}

json rpc::RPC::GetLatestLedger(int id)
{
    json params;
    params["id"] = id;
    params["jsonrpc"] = "2.0";
    params["method"] = "getLatestLedger";

    Stellar *stellar = new Stellar();
    auto getLatestLedger = stellar->stellar_forward_call(baseurl, params);
    if (getLatestLedger == std::nullopt)
    {
        stellar->Log("empty data returned", {});
        return {};
    }
    auto eventResp = json::parse(getLatestLedger);
    return eventResp;
}

GetNetworkDataResponse rpc::RPC::GetNetwork(int id)
{
    json params;
    params["id"] = id;
    params["jsonrpc"] = "2.0";
    params["method"] = "getNetwork";

    Stellar *stellar = new Stellar();
    stellar->Log("GetNetwork_Payload", params);
    auto getNetwork = stellar->stellar_forward_call(baseurl, params);
    if (getNetwork == std::nullopt)
    {
        stellar->Log("empty data returned", {});
        return {};
    }
    auto eventResp = json::parse(getNetwork);
    Response response;
    stellar->Log("GetNetworkEvent_Resp", eventResp);
    auto NetworkDataResponse = response.GetNetworkResponse(eventResp);
    return NetworkDataResponse;
}

json rpc::RPC::GetTransaction(int txId, std::string txHash)
{

    json params;
    params["id"] = txId;
    params["jsonrpc"] = "2.0";
    params["method"] = "getTransaction";
    params["params"] = {"hash", txHash};

    Stellar *stellar = new Stellar();
    auto getTransaction = stellar->stellar_forward_call(baseurl, params);
    if (getTransaction == std::nullopt)
    {
        stellar->Log("empty data returned", {});
        return {};
    }
    auto eventResp = json::parse(getTransaction);
    return eventResp;
}

json rpc::RPC::GetTransactions(int id, int startLedger, int pagelimit)
{
    json params;
    params["jsonrpc"] = "2.0";
    params["id"] = id;
    params["method"] = "getTransactions";
    params["params"] = {"startLedger", startLedger};
    params["params"]["pagination"] = {"limit", pagelimit};

    Stellar *stellar = new Stellar();
    stellar->Log("GetTransactions_Payload", params);
    auto getTransactions = stellar->stellar_forward_call(baseurl, params);
    if (getTransactions == std::nullopt)
    {
        stellar->Log("empty data returned", {});
        return {};
    }
    auto txResp = json::parse(getTransactions);
    return txResp;
}

json rpc::RPC::SendTransactions(int id, std::string txHash)
{
    json params;
    params["jsonrpc"] = "2.0";
    params["id"] = id;
    params["method"] = "sendTransaction";
    params["params"] = {"transaction", txHash};

    Stellar *stellar = new Stellar();
    stellar->Log("sendTransaction_Payload", params);
    auto sendTransaction = stellar->stellar_forward_call(baseurl, params);
    if (sendTransaction == std::nullopt)
    {
        stellar->Log("empty data returned", {});
        return {};
    }
    auto sendTxResp = json::parse(sendTransaction);
    return sendTxResp;
}

json rpc::RPC::GetLedgerEntries(int id, json LedgerParams)
{
    json params;
    params["id"] = id;
    params["jsonrpc"] = "2.0";
    params["method"] = "getLedgerEntries";
    params["params"] = LedgerParams;

    Stellar *stellar = new Stellar();
    auto getLedgerEntries = stellar->stellar_forward_call(baseurl, params);
    if (getLedgerEntries == std::nullopt)
    {
        stellar->Log("empty data returned", {});
        return {};
    }
    auto eventResp = json::parse(getLedgerEntries);
    return eventResp;
}
