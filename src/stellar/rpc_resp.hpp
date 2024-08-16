#ifndef RPC_RESP_HPP
#define RPC_RESP_HPP

#include <iostream>
#include <string>
#include <optional>
#include <stdexcept>
#include <cstdint>

#include "../base.hpp"

void LogGreen(const char *msg)
{
    std::cout << "NitrogenData_Log\n";
    std::cout << msg << std::endl;
}

void LogRed(const char *msg)
{
    std::cerr << msg << std::endl;
    std::cout << msg << std::endl;
    perror(msg);
    exit(EXIT_FAILURE);
}

void LogRunError(const char *msg)
{
    perror(msg);
    throw std::runtime_error(msg);
}

struct GetEventsDataEvents
{
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

struct GetEventDataResult
{
    std::vector<GetEventsDataResponse> events;
    uint32_t latestLedger;
};

struct GetEventsDataResponse
{
    std::string jsonrpc;
    uint16_t id;
    GetEventDataResult result;
};

struct GetNetworkDataResult
{
    std::string friendbotUrl;
    std::string passphrase;
    uint32_t protocolVersion;
};

struct GetNetworkDataResponse
{
    std::string jsonrpc;
    uint32_t id;
    GetNetworkDataResult result;
};

struct GetFeeStatsResult
{
    std::vector<GetSorobanInclusionFee> sorobanInclusionFee;
};

struct GetSorobanInclusionFee
{
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

struct GetFeeStats
{
    std::string jsonrpc;
    uint32_t id;
    GetFeeStatsResult result;
};

class Response
{
public:
    Response();
    GetEventsDataResponse GetEventsResponse(json getEvents);
    GetNetworkDataResponse GetNetworkResponse(json getNetwork);
    GetFeeStats GetFeeStatsResponse(json getFeeStats);
    ~Response();
};

#endif