#include <iostream>
#include "RelatMode.h"

using namespace std;

//Constructor
RelatMode::RelatMode(CpuReg& cpuReg, MemMap& mem):
    cpuReg(cpuReg),
    mem   (mem   ){
}

~RelatMode::RelatMode(){
}

//getOperand
int RelatMode::getOperand(){
    int operand  ;
    //read mem[PC+1] for operand 
    operand = mem.read( cpuReg.readPC()+1 );

    return  operand;
}

//setNextPC
void RelatMode::setNextPC(){
    //update PC+=2
    cpuReg.writePC( cpuReg.readPC()+2 );
}
