
#include <iostream>
#include "MemByteTest.h"
#include "assert.h"

using namespace std;

//Constructor
MemByteTest::MemByteTest(){
}

//runTest
void MemByteTest::runTest(){
    int golden;

    //Test Constructor with 100
    golden = 0;
    MemByte memByte();
    assert( (golden == memByte.read()) );

    //Test write with 123
    golden = 123;
    memByte.write(golden);
    assert( (golden == memByte.read()) );
    //Test write with 201
    golden = 201;
    memByte.write(golden);
    assert( (golden == memByte.read()) );
    //Test write with  99
    golden =  99;
    memByte.write(golden);
    assert( (golden == memByte.read()) );
    //Test write with  99
    golden =  256;
    memByte.write(golden);
    assert( (golden == memByte.read()) );

    cout << "Pass MemByteTest !" << "\n";
}

