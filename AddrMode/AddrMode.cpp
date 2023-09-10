#include <iostream>
#include "AddrMode.h"

using namespace std;

//Constructor
AddrMode::AddrMode(){
}
AddrMode::AddrMode(CpuReg* cpuReg, MemMap* mem):
    cpuReg(cpuReg),
    mem   (mem   ){
}

int AddrMode::getOperand(){
    return 0;
}

void AddrMode::setNextPC(){
    return;
}
