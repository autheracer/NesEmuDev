
#ifndef IDXZPMODEX_H
#define IDXZPMODEX_H

//header for AddrMode class
#include "../MemMap/MemMap.h"
#include "../CpuReg/CpuReg.h"

class IdxZPModeX: public AddrMode{
    public:
        IdxZPModeX(CpuReg& cpuReg, MemMap& mem);
        ~IdxZPModeX();

        //cal addr and return the operand based on addr mode
        virtual  int getOperand();

        //set next PC
        virtual void setNextPC();

    //protected:
};

#endif
