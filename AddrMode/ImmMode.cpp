#include <iostream>
#include "ImmMode.h"

using namespace std;

//Constructor
ImmMode::ImmMode(CpuReg* cpuReg, MemMap* mem):
    AddrMode(cpuReg, mem){
}

//getOperand
int ImmMode::getOperand(){
    int operand  ;
    //read mem[PC+1] for operand 
    operand = mem->read( cpuReg->readPC()+1 );

    return  operand;
}

//setNextPC
void ImmMode::setNextPC(){
    //update PC+=2
    cpuReg->writePC( cpuReg->readPC()+2 );
}
