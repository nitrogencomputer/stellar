#include "rpc_resp.hpp"
#include "jsontrait.hpp"

GetEventsDataResponse Response::GetEventsResponse(json getEvents)
{
    if(getEvents.size() <= 0) throw std::runtime_error("empty response");
    GetEventsDataResponse eventData = json::parse(getEvents).get<GetEventsDataResponse>();
    if(eventData.jsonrpc.empty())
        throw std::runtime_error("no value returned for rpc version");
    if(eventData.jsonrpc != "2.0" )
        std::cout << "cannot talk to stellar Network\nInvalid JSON rpc version";
        throw std::runtime_error("invalid json rpc version");
    return eventData;
}

GetNetworkDataResponse Response::GetNetworkResponse(json getNetwork)
{
    if(getNetwork.size() <= 0) throw std::runtime_error("empty response");
    GetNetworkDataResponse eventData = json::parse(getNetwork).get<GetNetworkDataResponse>();
    if(eventData.jsonrpc.empty())
        throw std::runtime_error("no value returned for rpc version");
    if(eventData.jsonrpc != "2.0" )
        std::cout << "cannot talk to stellar Network\nInvalid JSON rpc version";
        throw std::runtime_error("invalid json rpc version");
    return eventData;
}

GetFeeStats Response::GetFeeStatsResponse(json getFeeStats)
{
    if(getFeeStats.size() <= 0) throw std::runtime_error("empty response");
    GetFeeStats eventData = json::parse(getFeeStats).get<GetFeeStats>();
    if(eventData.jsonrpc.empty())
        throw std::runtime_error("no value returned for rpc version");
    if(eventData.jsonrpc != "2.0" )
        std::cout << "cannot talk to stellar Network\nInvalid JSON rpc version";
        throw std::runtime_error("invalid json rpc version");
    return eventData;
}
