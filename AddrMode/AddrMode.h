
#ifndef ADDRMODE_H
#define ADDRMODE_H

//header for AddrMode class
#include "../MemMap/MemMap.h"
#include "../CpuReg/CpuReg.h"

class AddrMode{
    public:
        AddrMode(CpuReg& cpuReg, MemMap& mem);
        ~AddrMode();

        //cal addr and return the operand based on addr mode
        virtual  int getOperand()=0;

        //set next PC
        virtual void setNextPC()=0;

    protected:
        CpuReg&    cpuReg;
        MemMap&    mem   ;
 
        int        operand  ;
        int        condition;
};

#endif
