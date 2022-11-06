#include <iostream>
#include "IndirMode.h"
#include "NesEmuDevConst.h"

using namespace std;

//Constructor
IndirMode::IndirMode(CpuReg& cpuReg, MemMap& mem):
    cpuReg(cpuReg),
    mem   (mem   ){
}

~IndirMode::IndirMode(){
}

//getOperand
int IndirMode::getOperand(){
    int indirAddrLSB  ;
    int indirAddrMSB  ;
    int indirAddr     ;
    int addrLSB  ;
    int addrMSB  ;
    int addr     ;
    Reg& PC = cpuReg.getPC();

    //read mem[PC+1] for indirAddr's LSB part
    indirAddrLSB = mem.read( PC.read()+1 );
    //read mem[PC+2] for indirAddr's MSB part
    indirAddrMSB = mem.read( PC.read()+2 );
    //shift indirAddrMSB and add with indirAddrLSB
    indirAddr    = indirAddrMSB<<BITS_PER_BYTE + indirAddrLSB;
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
void IndirMode::setNextPC(){
    Reg& PC = cpuReg.getPC();
    //update PC+=3
    PC.write( operand );
}
