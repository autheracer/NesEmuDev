
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
void MemByte::write(int value){
    try{
        if(value > MAX_VALUE_BYTE(1))
            throw value;
    }
    catch(int value){
        cout << "Set Value=" << value << " to a Byte." << "\n";
    }

    this->data = value;
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
