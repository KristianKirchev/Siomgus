#pragma once
#include "Blocks.h"
#define BlockChainLeng 100
class Blockchain
{
private:
    Block BlockChainSite[BlockChainLeng];
    uint32_t filled = 0;
public:
    Blockchain(){BlockChainSite[0].set(2770557896819123658);this->filled++;};
    ~Blockchain(){};
    bool addNode(unsigned long long parent,void* value,size_t size,unsigned long long checksum){
        if(parent == BlockChainSite[filled-1].get_checksum()){
            BlockChainSite[filled].set(parent,value,size);
            if(BlockChainSite[filled].get_checksum() == checksum){
                filled++;
                return true;
            }
            return false;
        }
        
        return false;
    }
};

