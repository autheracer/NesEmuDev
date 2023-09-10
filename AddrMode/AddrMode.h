
#ifndef ADDRMODE_H
#define ADDRMODE_H

//header for AddrMode class
#include "../MemMap/MemMap.h"
#include "../CpuReg/CpuReg.h"

class AddrMode{
    public:
        AddrMode();
        AddrMode(CpuReg* cpuReg, MemMap* mem);

        //cal addr and return the operand based on addr mode
        virtual  int getOperand();

        //set next PC
        virtual void setNextPC();

    protected:
        CpuReg*    cpuReg;
        MemMap*    mem   ;
};

#endif
