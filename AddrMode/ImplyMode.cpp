#include <iostream>
#include "ImplyMode.h"

using namespace std;

//Constructor
ImplyMode::ImplyMode(CpuReg& cpuReg, MemMap& mem):
    cpuReg(cpuReg),
    mem   (mem   ){
}

~ImplyMode::ImplyMode(){
}

//getOperand
int ImplyMode::getOperand(){
    return 0;
}

//setNextPC
void ImplyMode::setNextPC(){
    //update PC+=1
    cpuReg.writePC( cpuReg.readPC()+1 );
}
