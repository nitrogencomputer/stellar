#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
#include "/Users/mac/Desktop/nitrogen/stellar-sc/json/include/nlohmann/json.hpp"

using json = nlohmann::json;

namespace rpc {
    class RPC {
        private:   
        std::string baseurl;
        public: 
        /* constructors for the RPC class*/
        /* this base constructor holds the baseurl */
        RPC() :baseurl("https://soroban-testnet.stellar.org"){};
        
        /* copy constructor initialisation*/
        RPC(const RPC& stellarRpc);
        ~RPC();

        /* functions for handling output and input streams */
        /* declaration handling lives in the client file */
        friend std::ostream& operator << (std::ostream& stream, const RPC& stellar_rpc);
        friend std::istream& operator >> (std::istream& stream, const RPC& stellar_rpc);

        /* Get Events from stellar soroban smart contract*/
        json GetEvents(int id, int startledger, std::vector<std::unordered_map<std::string, 
                        std::string>>filters, std::vector<std::string> contractIds,std::vector<std::vector<std::string>> topics, int pagelimit);
    };
}