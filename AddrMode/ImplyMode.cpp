#include <iostream>
#include "ImplyMode.h"

using namespace std;

//Constructor
ImplyMode::ImplyMode(CpuReg* cpuReg, MemMap* mem):
    AddrMode(cpuReg, mem){
}

//getOperand
int ImplyMode::getOperand(){
    return 0;
}

//setNextPC
void ImplyMode::setNextPC(){
    //update PC+=1
    cpuReg->writePC( cpuReg->readPC()+1 );
}
