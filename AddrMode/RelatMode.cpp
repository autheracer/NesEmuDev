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
    Reg& PC = cpuReg.getPC();

    //read mem[PC+1] for operand 
    operand = mem.read( PC.read()+1 );

    return  operand;
}

//setNextPC
void RelatMode::setNextPC(){
    Reg& PC = cpuReg.getPC();
    //update PC+=2
    PC.write( PC.read()+2 );
}
