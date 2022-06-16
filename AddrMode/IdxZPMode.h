
#ifndef IDXZPMODE_H
#define IDXZPMODE_H

//header for AddrMode class
#include "../MemMap/MemMap.h"
#include "../CpuReg/CpuReg.h"

class IdxZPMode: public AddrMode{
    public:
        IdxZPMode(CpuReg& cpuReg, MemMap& mem);
        ~IdxZPMode();

        //cal addr and return the operand based on addr mode
        virtual  int getOperand();

        //set next PC
        virtual void setNextPC();

    //protected:
};

#endif
