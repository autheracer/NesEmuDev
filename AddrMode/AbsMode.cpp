#include <iostream>
#include "AbsMode.h"
#include "NesEmuDevConst.h"

using namespace std;

//Constructor
AbsMode::AbsMode(CpuReg& cpuReg, MemMap& mem):
    cpuReg(cpuReg),
    mem   (mem   ){
}

~AbsMode::AbsMode(){
}

//getOperand
int AbsMode::getOperand(){
    int addrLSB  ;
    int addrMSB  ;
    int addr     ;
    Reg& PC = cpuReg.getPC();

    //read mem[PC+1] for addr's LSB part
    addrLSB = mem.read( PC.read()+1 );
    //read mem[PC+2] for addr's MSB part
    addrMSB = mem.read( PC.read()+2 );
    //shift addrMSB and add with addrLSB
    addr    = addrMSB<<BITS_PER_BYTE + addrLSB;
    //read mem[addr] for operand
    operand = mem.read( addr );

    return  operand;
}

//setNextPC
void AbsMode::setNextPC(){
    Reg& PC = cpuReg.getPC();
    //update PC+=3
    PC.write( PC.read()+3 );
}
