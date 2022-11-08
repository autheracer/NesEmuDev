
#include <iostream>
#include "Reg.h"
#include "NesEmuDevConst.h"

using namespace std;

//Constructor
Reg::Reg(int size):
    size(size),
    MemByte(){
}

//write
void Reg::write(int dataIn){
    try{
        if(dataIn > MAX_VALUE_BYTE(size))
            throw dataIn;
    }
    catch(int dataIn){
        cout << "Set Value=" << dataIn << " to a " << size << "-byte Register." << "\n";
    }

    this->data = dataIn;
}
