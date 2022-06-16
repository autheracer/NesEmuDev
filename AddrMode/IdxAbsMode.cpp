#include <iostream>
#include "IdxAbsMode.h"
#include "NesEmuDevConst.h"

using namespace std;

//Constructor
IdxAbsMode::IdxAbsMode(CpuReg& cpuReg, MemMap& mem):
    cpuReg(cpuReg),
    mem   (mem   ){
}

~IdxAbsMode::IdxAbsMode(){
}

//getOperand
int IdxAbsMode::getOperand(){
    int addrLSB  ;
    int addrMSB  ;
    int addr     ;
    Reg&  X = cpuReg.getX() ;
    Reg& PC = cpuReg.getPC();

    //read mem[PC+1] for addr's LSB part
    addrLSB = mem.read( PC.read()+1 );
    //read mem[PC+2] for addr's MSB part
    addrMSB = mem.read( PC.read()+2 );
    //shift addrMSB and add with addrLSB, X
    addr    = addrMSB<<BITS_PER_BYTE + addrLSB + X.read();
    //read mem[addr] for operand
    operand = mem.read( addr );

    return  operand;
}

//setNextPC
void IdxAbsMode::setNextPC(){
    Reg& PC = cpuReg.getPC();
    //update PC+=3
    PC.write( PC.read()+3 );
}
