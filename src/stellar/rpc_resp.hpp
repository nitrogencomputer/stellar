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

struct GetFeeStatsResult {
    std::vector<GetSorobanInclusionFee> sorobanInclusionFee;
};

struct GetSorobanInclusionFee {
    std::string max;
    std::string min;
    std::string mode;
    std::string p10;
    std::string p20;
    std::string p30;
    std::string p40;
    std::string p50;
    std::string p60;
    std::string p70;
    std::string p80;
    std::string p90;
    std::string p95;
    std::string p99;
    std::string transactionCount;
    uint32_t ledgerCount;
};

struct GetFeeStats {
    std::string jsonrpc;
    uint32_t id;
    GetFeeStatsResult result;
};

void from_json(const json& j, GetSorobanInclusionFee& e){
    j.at("max").get_to(e.max);
    j.at("min").get_to(e.min);
    j.at("p10").get_to(e.p10);
    j.at("p20").get_to(e.p20);
    j.at("p30").get_to(e.p30);
    j.at("p40").get_to(e.p40);
    j.at("p50").get_to(e.p50);
    j.at("p60").get_to(e.p60);
    j.at("p70").get_to(e.p70);
    j.at("p80").get_to(e.p80);
    j.at("p90").get_to(e.p90);
    j.at("p95").get_to(e.p95);
    j.at("p99").get_to(e.p99);
    j.at("transactionCount").get_to(e.transactionCount);
    j.at("ledgerCount").get_to(e.ledgerCount);
}

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