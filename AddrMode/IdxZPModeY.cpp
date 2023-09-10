#include <iostream>
#include "IdxZPModeY.h"
#include "NesEmuDevConst.h"

using namespace std;

//Constructor
IdxZPModeY::IdxZPModeY(CpuReg* cpuReg, MemMap* mem):
    AddrMode(cpuReg, mem){
}

//getOperand
int IdxZPModeY::getOperand(){
    int addr   ;
    int operand  ;

    //read mem[PC+1], and add with X for the address of operand
    addr    = mem->read( cpuReg->readPC()+1 ) + cpuReg->readY();
    //wrap the addr to 8-bit
    addr &= MAX_VALUE_BYTE(1);
    //read mem[addr] for operand
    operand = mem->read( addr );

    return  operand;
}

//setNextPC
void IdxZPModeY::setNextPC(){
    //update PC+=2
    cpuReg->writePC( cpuReg->readPC()+2 );
}
