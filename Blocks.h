#pragma once
#include <iostream>
#include <string>
#include <cstring>


class Block
{
private:
    unsigned long long int parent;
    unsigned char value[100];
    size_t size;
    unsigned long long int checksum = 0;
public:

    void find_checksum();
    Block(){};
    void set(unsigned long long int parent,void* value,size_t size){
        this->parent = parent;
        memcpy(this->value,value,sizeof(char)*size);
        this->size = size;
        this->find_checksum();
    };
    void set(unsigned long long int checksum){
        this->checksum = checksum;
    }
    unsigned long long int get_checksum(){
        return this->checksum;
    }
    
    unsigned long long int get_parent(){
        return this->parent;
    }
    unsigned char* get_value(){
        return this->value;
    }
    size_t get_size(){
        return this->size;
    }
    ~Block(){};
    void print_block(){
        std::cout<<"{\nparent = "<<this->parent<<";"<<std::endl;
        std::cout<<"value = "<<(unsigned char *)this->value<<";"<<std::endl;
        std::cout<<"size = "<<this->size<<";"<<std::endl;
        std::cout<<"checksum = "<<std::hex<<this->checksum<<";\n}"<<std::endl;
    }
    void hex( unsigned char list[28*8]){
        
        memcpy(list,&this->parent,sizeof(unsigned long long));
        
        memcpy(list+sizeof(unsigned long long),&this->size,sizeof(size_t));
        memcpy(list+sizeof(unsigned long long)+sizeof(size_t),&this->checksum,sizeof(unsigned long long));
        memcpy(list+sizeof(unsigned long long)*2+sizeof(size_t),this->value,sizeof(char)*size);
        
    }
    void fromhex(unsigned char list[28*8]){
        memcpy(&this->parent,list,sizeof(unsigned long long));
        memcpy(&this->size,list+sizeof(unsigned long long),sizeof(size_t));
        //memcpy(&this->checksum,list+sizeof(unsigned long long)+sizeof(size_t),sizeof(unsigned long long));
        memcpy(this->value,list+sizeof(unsigned long long)*3,sizeof(char)*this->size);
        printf("%s",this->value);
        this->find_checksum();
    }
};



