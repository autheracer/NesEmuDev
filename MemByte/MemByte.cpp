
#include <iostream>
#include "MemByte.h"
#include "NesEmuDevConst.h"

using namespace std;

//Constructor
MemByte::MemByte(): 
    data(0){
}

//read
int MemByte::read(){
    return this->data;
}

//write
void MemByte::write(int dataIn){
    try{
        if(dataIn > MAX_VALUE_BYTE(1))
            throw dataIn;
    }
    catch(int dataIn){
        cout << "Set Value=" << dataIn << " to a Byte." << "\n";
    }

    this->data = dataIn;
}


#ifdef TEST_FUNC

    #include "assert.h"

    //test function
    int main(){

        MemByte memByte;
        int golden;

        //Test write and read
        for(int golden=0; golden<MAX_VALUE_BYTE(1); golden++) {
            memByte.write(golden);
            assert( (golden == memByte.read()) );
        }

        cout << "Pass MemByteTest !" << "\n";

        return 0;
    }

#endif
