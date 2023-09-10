
#ifndef INDIRMODE_H
#define INDIRMODE_H

//header for IndirMode class
#include "../MemMap/MemMap.h"
#include "../CpuReg/CpuReg.h"
#include "../AddrMode/AddrMode.h"

class IndirMode: public AddrMode{
    public:
        IndirMode(CpuReg* cpuReg, MemMap* mem);

        //cal addr and return the operand based on addr mode
        virtual  int getOperand();

        //set next PC
        virtual void setNextPC();

    private:
        int operand;
};

#endif
