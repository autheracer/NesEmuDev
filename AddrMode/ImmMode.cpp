#include <iostream>
#include "ImmMode.h"

using namespace std;

//Constructor
ImmMode::ImmMode(CpuReg& cpuReg, MemMap& mem):
    cpuReg(cpuReg),
    mem   (mem   ){
}

~ImmMode::ImmMode(){
}

//getOperand
int ImmMode::getOperand(){
    Reg& PC = cpuReg.getPC();

    //read mem[PC+1] for operand 
    operand = mem.read( PC.read()+1 );

    return  operand;
}

//setNextPC
void ImmMode::setNextPC(){
    Reg& PC = cpuReg.getPC();
    //update PC+=2
    PC.write( PC.read()+2 );
}
