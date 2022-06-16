#include <iostream>
#include "IdxIndirMode.h"
#include "NesEmuDevConst.h"

using namespace std;

//Constructor
IdxIndirMode::IdxIndirMode(CpuReg& cpuReg, MemMap& mem):
    cpuReg(cpuReg),
    mem   (mem   ){
}

~IdxIndirMode::IdxIndirMode(){
}

//getOperand
int IdxIndirMode::getOperand(){
    int indirAddr;
    int addrLSB  ;
    int addrMSB  ;
    int addr     ;
    Reg& PC = cpuReg.getPC();
    Reg&  X = cpuReg.getX();

    indirAddr = mem.read( PC.read()+1 ) + X.read();
    //read mem[indirAddr  ] for addrLSB 
    addrLSB = mem.read( indirAddr   );
    //read mem[indirAddr+1] for addrMSB
    addrMSB = mem.read( indirAddr+1 );
    //shift addrMSB and add with addrLSB
    addr    = addrMSB<<BITS_PER_BYTE + addrLSB;
    //read mem[addr] for operand
    operand = mem.read( addr );

    return  operand;
}

//setNextPC
void IdxIndirMode::setNextPC(){
    Reg& PC = cpuReg.getPC();
    //update PC+=2
    PC.write( PC.read()+2 );
}
