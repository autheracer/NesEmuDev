
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
void Reg::write(int value){
    try{
        if(value > MAX_VALUE_BYTE(size))
            throw value;
    }
    catch(int value){
        cout << "Set Value=" << value << " to a " << size << "-byte Register." << "\n";
    }

    this->data = value;
}
