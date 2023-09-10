
#ifndef ZPMODE_H
#define ZPMODE_H

//header for ZPMode class
#include "../MemMap/MemMap.h"
#include "../CpuReg/CpuReg.h"
#include "../AddrMode/AddrMode.h"

class ZPMode: public AddrMode{
    public:
        ZPMode(CpuReg* cpuReg, MemMap* mem);

        //cal addr and return the operand based on addr mode
        virtual  int getOperand();

        //set next PC
        virtual void setNextPC();

    //protected:
};

#endif
