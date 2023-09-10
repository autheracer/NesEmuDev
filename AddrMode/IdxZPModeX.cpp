#include <iostream>
#include "IdxZPModeX.h"

using namespace std;

//Constructor
IdxZPModeX::IdxZPModeX(CpuReg& cpuReg, MemMap& mem):
    cpuReg(cpuReg),
    mem   (mem   ){
}

~IdxZPModeX::IdxZPModeX(){
}

//getOperand
int IdxZPModeX::getOperand(){
    int addr   ;
    int operand  ;

    //read mem[PC+1], and add with X for the address of operand
    addr    = mem.read( cpuReg.readPC()+1 ) + cpuReg.readX();
    //wrap the addr to 8-bit
    addr &= MAX_VALUE_BYTE(1);
    //read mem[addr] for operand
    operand = mem.read( addr );

    return  operand;
}

//setNextPC
void IdxZPModeX::setNextPC(){
    //update PC+=2
    cpuReg.writePC( cpuReg.readPC()+2 );
}
