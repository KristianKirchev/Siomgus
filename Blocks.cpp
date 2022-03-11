#include "Blocks.h"
#include "Hash.h"
void Block::find_checksum(){
    //64-8
    SeaHash h;
    unsigned char list[28*8] = {0};
    memcpy(list,&this->parent,sizeof(unsigned long long));
    memcpy(list+sizeof(unsigned long long),&this->size,sizeof(unsigned long long));
    memcpy(list+sizeof(unsigned long long)*2,this->value,sizeof(char)*size);
    this->checksum = h.hash(list,sizeof(unsigned long long)*2+sizeof(char)*size);
    //std::hash<char *> ptr_hash;
    //std::string str((list);
    //ptr_hash(list);
    //this->checksum = hash.hash();
    //unsigned long long int checksum = hash.hash(&k.base_block,sizeof(k.base_block));
    //k.checksum = checksum;
}