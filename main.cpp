#include "Hash.h"
#include <iostream>
#include "Blockchain.h"

Block blockchain[100];

int main(int argc, char const *argv[])
{
    Blockchain b;
    
    unsigned long long int begining = 2770557896819123658;
    char ll[] = "salmonelb";

    Block k = Block();
    k.set(begining,ll,sizeof(ll));
    std::cout<<b.addNode(k.get_parent(),k.get_value(),k.get_size(),k.get_checksum())<<std::endl;
    unsigned long long list[28] = {0};
    k.hex((unsigned char *)list);
    Block k1 = Block();
    k1.fromhex((unsigned char *)list);
    k.print_block();
    k1.print_block();
    for(int i = 0;i<28;i++){
        std::cout<<std::hex<<list[i]<<" ";
    }
    std::cout<<std::endl;
    //unsigned long long int checksum = hash.hash(&k.base_block,sizeof(k.base_block));
    //k.checksum = checksum;
    //k.print_block();
    return 0;
}