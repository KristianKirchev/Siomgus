#include "Hash.h"
#include <iostream>
#include "Blockchain.h"

Block blockchain[100];

int main(int argc, char const *argv[])
{
    //2770557896819123658 Syomga is sus 15.99 + sha256sum + llu hex rollback 
    Blockchain b;
    
    unsigned long long int begining = 2770557896819123658;
    char ll[] = "salmonela";

    Block k = Block();
    k.set(begining,ll,sizeof(ll));
    std::cout<<b.addNode(k.get_parent(),k.get_value(),k.get_size(),k.get_checksum())<<std::endl;
    k.hex();
    Block k1 = Block();
    char hexi[] = {
        -54,-91,-114,101,-70,-1,114,38,10,0,0,0,0,0,0,0,115,97,108,109,111,110,101,108,97,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    };
    k1.fromhex(hexi);
    k1.print_block();
    //unsigned long long int checksum = hash.hash(&k.base_block,sizeof(k.base_block));
    //k.checksum = checksum;
    //k.print_block();
    return 0;
}
