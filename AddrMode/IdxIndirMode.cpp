#include <iostream>
#include "IdxIndirMode.h"
#include "NesEmuDevConst.h"

using namespace std;

//Constructor
IdxIndirMode::IdxIndirMode(CpuReg* cpuReg, MemMap* mem):
    AddrMode(cpuReg, mem){
}

//getOperand
int IdxIndirMode::getOperand(){
    int indirAddr;
    int addrLSB  ;
    int addrMSB  ;
    int addr     ;
    int operand  ;

    indirAddr = mem->read( cpuReg->readPC()+1 ) + cpuReg->readX();
    indirAddr &= MAX_VALUE_BYTE(1);
    //read mem[indirAddr  ] for addrLSB 
    addrLSB = mem->read( indirAddr   );
    //read mem[indirAddr+1] for addrMSB
    addrMSB = mem->read( indirAddr+1 );
    //shift addrMSB and add with addrLSB
    addr    = (addrMSB<<BITS_PER_BYTE) + addrLSB;
    //read mem[addr] for operand
    operand = mem->read( addr );

    return  operand;
}

//setNextPC
void IdxIndirMode::setNextPC(){
    //update PC+=2
    cpuReg->writePC( cpuReg->readPC()+2 );
}
