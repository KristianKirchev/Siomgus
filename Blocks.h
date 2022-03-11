#pragma once
#include <iostream>
#include <string>
#include <cstring>


class Block
{
private:
    unsigned long long int parent;
    char value[100];
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
    char* get_value(){
        return this->value;
    }
    size_t get_size(){
        return this->size;
    }
    ~Block(){};
    void print_block(){
        std::cout<<"{\nparent = "<<this->parent<<";"<<std::endl;
        std::cout<<"value = "<<(char *)this->value<<";"<<std::endl;
        std::cout<<"size = "<<this->size<<";"<<std::endl;
        std::cout<<"checksum = "<<this->checksum<<";\n}"<<std::endl;
    }
    void hex(){
        char list[28*8] = {0};
        memcpy(list,&this->parent,sizeof(unsigned long long));
        
        memcpy(list+sizeof(unsigned long long),&this->size,sizeof(size_t));
        memcpy(list+sizeof(unsigned long long)+sizeof(size_t),this->value,sizeof(char)*size);
        for(size_t i = 0;i<28*8;i++){
            std::cout<<(short int)list[i]<<",";
            
        }
        std::cout<<std::endl;
    }
    void fromhex(char list[28*8]){
        memcpy(&this->parent,list,sizeof(unsigned long long));
        memcpy(&this->size,list+sizeof(unsigned long long),sizeof(size_t));
        memcpy(this->value,list+sizeof(unsigned long long)+sizeof(size_t),sizeof(char)*size);
        this->find_checksum();
    }
};



