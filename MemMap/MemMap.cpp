
#include <iostream>
#include "MemMap.h"

using namespace std;

//Constructor
MemMap::MemMap():
    size(0),
    mem(NULL){
}
//Destructor
MemMap::~MemMap(){
    delete [] mem;
}

//init
void MemMap::init(int size){
    this->size = size;
    this->mem  = new MemByte[ size ];
}

//read
int MemMap::read(int addr){
    try{
        if(addr > this->size)
            throw addr;
    }
    catch(int addr){
        cout << "Read illegal Addr=" << hex << addr << "\n";
    }
    
    return mem[addr].read();
}

//write
void MemMap::write(int addr, int dataIn){
    try{
        if(addr > this->size)
            throw addr;
    }
    catch(int addr){
        cout << "Write to illegal Addr=" << hex << addr << "\n";
    }
    
    mem[addr].write(dataIn);
}
