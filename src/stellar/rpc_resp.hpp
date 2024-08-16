#ifndef RPC_RESP_HPP
#define RPC_RESP_HPP

#include <iostream>
#include <string>
#include <optional>
#include <stdexcept>
#include <cstdint>

#include "../base.hpp"

struct GetEventsDataEvents {
    std::string type;
    uint32_t ledger;
    std::string ledgerClosedAt;
    std::string contractId;
    std::string id;
    std::string pagingToken;
    std::vector<std::string> topic;
    std::string value;
    bool inSuccessfulContractCall;
    std::string txHash;
};

struct GetEventDataResult {
    std::vector<GetEventsDataResponse> events;
    uint32_t latestLedger;
};

struct GetEventsDataResponse{
    std::string jsonrpc;
    uint16_t id;
    GetEventDataResult result;
};

struct GetNetworkDataResult {
    std::string friendbotUrl;
    std::string passphrase;
    uint32_t protocolVersion;
};

struct GetNetworkDataResponse {
    std::string jsonrpc;
    uint32_t id;
    GetNetworkDataResult result;
};


void from_json(const json& j, GetEventsDataEvents& e) {
    j.at("type").get_to(e.type);
    j.at("ledger").get_to(e.ledger);
    j.at("ledgerClosedAt").get_to(e.ledgerClosedAt);
    j.at("contractId").get_to(e.contractId);
    j.at("id").get_to(e.id);
    j.at("pagingToken").get_to(e.pagingToken);
    j.at("topic").get_to(e.topic);
    j.at("value").get_to(e.value);
    j.at("inSuccessfulContractCall").get_to(e.inSuccessfulContractCall);
    j.at("txHash").get_to(e.txHash);
}

void from_json(const json& j, GetEventDataResult& r) {
    j.at("events").get_to(r.events);
    j.at("latestLedger").get_to(r.latestLedger);
}

void from_json(const json& j, GetEventsDataResponse& r) {
    j.at("jsonrpc").get_to(r.jsonrpc);
    j.at("id").get_to(r.id);
    j.at("result").get_to(r.result);
}

void from_json(const json& j, GetNetworkDataResult r) {
    j.at("friendbotUrl").get_to(r.friendbotUrl);
    j.at("passphrase").get_to(r.passphrase);
    j.at("protocolVersion").get_to(r.protocolVersion);
} 

void from_json(const json& j, GetNetworkDataResponse& r) {
    j.at("jsonrpc").get_to(r.jsonrpc);
    j.at("id").get_to(r.id);
    j.at("result").get_to(r.result);
}

class Response {
    public:
    Response();
    GetEventsDataResponse GetEventsResponse(json getEvents); 
    GetNetworkDataResponse GetNetworkResponse(json getNetwork);
    ~Response();  
};

#endif