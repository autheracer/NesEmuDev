#include <iostream>
#include "IdxAbsModeX.h"
#include "NesEmuDevConst.h"

using namespace std;

//Constructor
IdxAbsModeX::IdxAbsModeX(CpuReg* cpuReg, MemMap* mem):
    AddrMode(cpuReg, mem){
}

//getOperand
int IdxAbsModeX::getOperand(){
    int addrLSB  ;
    int addrMSB  ;
    int addr     ;
    int operand  ;

    //read mem[PC+1] for addr's LSB part
    addrLSB = mem->read( cpuReg->readPC()+1 );
    //read mem[PC+2] for addr's MSB part
    addrMSB = mem->read( cpuReg->readPC()+2 );
    //shift addrMSB and add with addrLSB, X
    addr    = (addrMSB<<BITS_PER_BYTE) + addrLSB + cpuReg->readX();
    //read mem[addr] for operand
    operand = mem->read( addr );

    return  operand;
}

//setNextPC
void IdxAbsModeX::setNextPC(){
    //update PC+=3
    cpuReg->writePC( cpuReg->readPC()+3 );
}
