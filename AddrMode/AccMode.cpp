#include <iostream>
#include "AccMode.h"

using namespace std;

//Constructor
AccMode::AccMode(CpuReg* cpuReg, MemMap* mem):
    AddrMode(cpuReg, mem){
}

//getOperand
int AccMode::getOperand(){
    return 0;
}

//setNextPC
void AccMode::setNextPC(){
    //update PC+=1
    cpuReg->writePC( cpuReg->readPC()+1 );
}
