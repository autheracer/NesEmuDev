#include <iostream>
#include "IdxZPMode.h"

using namespace std;

//Constructor
IdxZPMode::IdxZPMode(CpuReg& cpuReg, MemMap& mem):
    cpuReg(cpuReg),
    mem   (mem   ){
}

~IdxZPMode::IdxZPMode(){
}

//getOperand
int IdxZPMode::getOperand(){
    int addr   ;
    Reg&  X = cpuReg.getX() ;
    Reg& PC = cpuReg.getPC();

    //read mem[PC+1], and add with X for the address of operand
    addr    = mem.read( PC.read()+1 ) + X.read();
    //read mem[addr] for operand
    operand = mem.read( addr );

    return  operand;
}

//setNextPC
void IdxZPMode::setNextPC(){
    Reg& PC = cpuReg.getPC();
    //update PC+=2
    PC.write( PC.read()+2 );
}
