/* #include "Hash.h"
#include "Blocks.h"
unsigned long long int SeaHash::hash(char* str,size_t size){
    unsigned long long int list[30] = {0};
    unsigned long long int val = this->blockup((char*)str, size,list);
    for (unsigned short int i = 0; i < 30; i += 4)
    {
        k1^=list[i] ^ k1;
        k2^=list[i + 1] ^ k2;
        k3^=list[i + 2] ^ k3;
        k4^=list[i + 3] ^ k4;
        k1 = this->func(k1);
        k2 = this->func(k2);
        k3 = this->func(k3);
        k4 = this->func(k4);
    }
    k1 ^= k2;
    k3 ^= k4;
    k1 ^= k3;
    k1 ^= val;
    val = this->func(k1);
    this->k2 = 0x16f11fe89b0d677c;
    this->k3 = 0xb480a793d8e6c86c;
    this->k4 = 0x6fe2e5aaf078ebc9;
    this->k1 =  0x14f994a4c5259381;
    return val;
}


unsigned long long SeaHash::blockup(const char* str,unsigned long long int size, unsigned long long *list){
    //unsigned long int p = 0x6eed0e9da4d94a4f;
    std::memcpy(list, str, sizeof(char) * size);
    // for(long long unsigned int i = 1;i<30;i++){
    //    list[i] ^= (list[i-1]*p)^(((p>>32)>>(list[i-1]>>62)));
    //}
    return size;
} */