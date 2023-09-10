#include <iostream>
#include "AbsMode.h"
#include "NesEmuDevConst.h"

using namespace std;

//Constructor
AbsMode::AbsMode(CpuReg* cpuReg, MemMap* mem):
    AddrMode(cpuReg, mem){
}

//getOperand
int AbsMode::getOperand(){
    int addrLSB  ;
    int addrMSB  ;
    int addr     ;
    int operand  ;

    //read mem[PC+1] for addr's LSB part
    addrLSB = mem->read( cpuReg->readPC()+1 );
    //read mem[PC+2] for addr's MSB part
    addrMSB = mem->read( cpuReg->readPC()+2 );
    //shift addrMSB and add with addrLSB
    addr    = (addrMSB<<BITS_PER_BYTE) + addrLSB;
    //read mem[addr] for operand
    operand = mem->read( addr );

    return  operand;
}

//setNextPC
void AbsMode::setNextPC(){
    //update PC+=3
    cpuReg->writePC( cpuReg->readPC()+3 );
}
