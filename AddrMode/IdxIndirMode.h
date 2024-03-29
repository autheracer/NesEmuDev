
#ifndef IDXINDIRMODE_H
#define IDXINDIRMODE_H

//header for IdxIndirMode class
#include "../MemMap/MemMap.h"
#include "../CpuReg/CpuReg.h"
#include "../AddrMode/AddrMode.h"

class IdxIndirMode: public AddrMode{
    public:
        IdxIndirMode(CpuReg* cpuReg, MemMap* mem);

        //cal addr and return the operand based on addr mode
        virtual  int getOperand();

        //set next PC
        virtual void setNextPC();

    //protected:
};

#endif
