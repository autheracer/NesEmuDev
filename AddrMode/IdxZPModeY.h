
#ifndef IDXZPMODEY_H
#define IDXZPMODEY_H

//header for AddrMode class
#include "../MemMap/MemMap.h"
#include "../CpuReg/CpuReg.h"
#include "../AddrMode/AddrMode.h"

class IdxZPModeY: public AddrMode{
    public:
        IdxZPModeY(CpuReg* cpuReg, MemMap* mem);

        //cal addr and return the operand based on addr mode
        virtual  int getOperand();

        //set next PC
        virtual void setNextPC();

    //protected:
};

#endif
