#ifndef HASHMAPC__BUILD_HASHFUNCTIONSEAHASH_H
#define HASHMAPC__BUILD_HASHFUNCTIONSEAHASH_H
#include <string>
#include <cstring>
class SeaHash{
private:
    unsigned long long int k2 = 0x16f11fe89b0d677c;
    unsigned long long int k3 = 0xb480a793d8e6c86c;
    unsigned long long int k4 = 0x6fe2e5aaf078ebc9;
    unsigned long long int k1 =  0x14f994a4c5259381;
    unsigned long long int state  = k1 ^ k3;
    unsigned long long blockup(const char* str,unsigned long long int size, unsigned long long int *list){
        unsigned long int p = 0x6eed0e9da4d94a4f;
        std::memcpy(list, str, sizeof(char) * size);
        for(int i = 1;i<28;i++){
            list[i] ^= (list[i-1]*p)^(((p>>32)>>(list[i-1]>>62)));
        }
        return size;
    }
    inline unsigned long long int func(unsigned long int val){
        unsigned long int p = 0x6eed0e9da4d94a4f;
        val = p * val;
        val = val ^ ((val >> 32) >> (val >> 62));
        val = p * val;
        return val;
    }
public:
    template<class T>
    unsigned long long int hash(T* str,unsigned long long int size){
        unsigned long long int list[28] = {0};
        unsigned long long int val = this->blockup((char*)str, size,list);
        for (unsigned short int i = 0; i < 28; i += 4)
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
        this->k2 = 8920607189712563318;
        this->k3 = 80223359080497538;
        this->k4 = 1669506508102161614;
        this->k1 =  1802886206017102246;
        return val;
    }
};
#endif //HASHMAPC__BUILD_HASHFUNCTIONSEAHASH_H
