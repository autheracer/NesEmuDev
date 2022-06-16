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
    Reg& PC = cpuReg.getPC();

    //read mem[PC+1] for the address of operand
    addr    = mem.read( PC.read()+1 );
    //read mem[addr] for operand
    operand = mem.read( addr );

    return  operand;
}

//setNextPC
void ZPMode::setNextPC(){
    Reg& PC = cpuReg.getPC();
    //update PC+=2
    PC.write( PC.read()+2 );
}
