
#ifndef RELATMODE_H
#define RELATMODE_H

//header for RelatMode class
#include "../MemMap/MemMap.h"
#include "../CpuReg/CpuReg.h"

class RelatMode: public AddrMode{
    public:
        RelatMode(CpuReg& cpuReg, MemMap& mem);
        ~RelatMode();

        //cal addr and return the operand based on addr mode
        virtual  int getOperand();

        //set next PC
        virtual void setNextPC();

    //protected:
};

#endif
