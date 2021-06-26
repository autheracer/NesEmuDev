
#include <iostream>
#include "MemMapTest.h"
#include "assert.h"

using namespace std;

//Constructor
MemMapTest::MemMapTest(){
}

//runTest
void MemMapTest::runTest(){
    int size = 256;
    //construct
    MemMap mem;
    //init
    mem.init(size);

    //construct a goldenMem
    int *goldenMem = new int[size];

    //Write test
    for(int addr=0; addr<size; addr++){
        mem.write(addr, addr);
        goldenMem[addr] = addr;
    }

    //Read test
    for(int addr=0; addr<size; addr++){
        assert( mem.read(addr) == goldenMem[addr] );
    }

    //Deallocate
    delete [] goldenMem;

    cout << "Pass MemMapTest !" << "\n";
}

