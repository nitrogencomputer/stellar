#include "rpc_resp.hpp"

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

void from_json(const json& j,GetFeeStatsResult& e) {
    j.at("sorobanInclusionFee").get_to(e.sorobanInclusionFee);
}

void from_json(const json& j, GetFeeStats& e) {
    j.at("jsonrpc").get_to(e.jsonrpc);
    j.at("id").get_to(e.id);
    j.at("result").get_to(e.result);
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
