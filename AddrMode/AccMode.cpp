#include <iostream>
#include "AccMode.h"

using namespace std;

//Constructor
AccMode::AccMode(CpuReg& cpuReg, MemMap& mem):
    cpuReg(cpuReg),
    mem   (mem   ){
}

~AccMode::AccMode(){
}

//getOperand
int AccMode::getOperand(){
    return 0;
}

//setNextPC
void AccMode::setNextPC(){
    Reg& PC = cpuReg.getPC();
    //update PC+=1
    PC.write( PC.read()+1 );
}
