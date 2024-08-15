#include <iostream>
#include "./stellar/rpc.hpp"

using namespace rpc;

int main(int argc, char** argv)
{
    RPC* rp = new RPC();
    auto network = rp->GetNetwork(8675309);
    std::cout << network << std::endl;
}
