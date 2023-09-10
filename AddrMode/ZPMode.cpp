#include <iostream>
#include "ZPMode.h"

using namespace std;

//Constructor
ZPMode::ZPMode(CpuReg& cpuReg, MemMap& mem):
    cpuReg(cpuReg),
    mem   (mem   ){
}

~ZPMode::ZPMode(){
}

//getOperand
int ZPMode::getOperand(){
    int addr   ;
    int operand  ;

    //read mem[PC+1] for the address of operand
    addr    = mem.read( cpuReg.readPC()+1 );
    //read mem[addr] for operand
    operand = mem.read( addr );

    return  operand;
}

//setNextPC
void ZPMode::setNextPC(){
    //update PC+=2
    cpuReg.writePC( cpuReg.readPC()+2 );
}
