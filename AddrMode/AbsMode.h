
#ifndef ABSMODE_H
#define ABSMODE_H

//header for AbsMode class
#include "../MemMap/MemMap.h"
#include "../CpuReg/CpuReg.h"
#include "../AddrMode/AddrMode.h"

class AbsMode: public AddrMode{
    public:
        AbsMode(CpuReg* cpuReg, MemMap* mem);

        //cal addr and return the operand based on addr mode
        virtual  int getOperand();

        //set next PC
        virtual void setNextPC();

    //protected:
};

#endif
