
#include <iostream>
#include "MemMap.h"
#include "NesEmuDevConst.h"

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


#ifdef TEST_FUNC

    #include "assert.h"

    //test function
    int main(){

        MemMap memMap;
        int golden;
        int size  ;

        size = 1024;

        memMap.init(size);

        //Test write and read
        for(int addr=0; addr<size; addr++) {
            golden = addr % BYTE_MAX_VALUE;
            memMap.write(addr, golden);
            assert( (golden == memMap.read(addr)) );
        }

        cout << "Pass MemMapTest !" << "\n";

        return 0;
    }

#endif
