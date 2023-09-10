#include <iostream>
#include "IndirIdxMode.h"
#include "NesEmuDevConst.h"

using namespace std;

//Constructor
IndirIdxMode::IndirIdxMode(CpuReg& cpuReg, MemMap& mem):
    cpuReg(cpuReg),
    mem   (mem   ){
}

~IndirIdxMode::IndirIdxMode(){
}

//getOperand
int IndirIdxMode::getOperand(){
    int indirAddr;
    int addrLSB  ;
    int addrMSB  ;
    int addr     ;
    int operand  ;

    indirAddr = mem.read( cpuReg.readPC()+1 );
    //read mem[indirAddr  ] for addrLSB 
    addrLSB = mem.read( indirAddr   );
    //read mem[indirAddr+1] for addrMSB
    addrMSB = mem.read( indirAddr+1 );
    //shift addrMSB and add with addrLSB
    addr    = (addrMSB<<BITS_PER_BYTE) + addrLSB + cpuReg.readY();
    //read mem[addr] for operand
    operand = mem.read( addr );

    return  operand;
}

//setNextPC
void IndirIdxMode::setNextPC(){
    //update PC+=2
    cpuReg.writePC( cpuReg.readPC()+2 );
}
