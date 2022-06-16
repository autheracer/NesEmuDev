
#ifndef IMMMODE_H
#define IMMMODE_H

//header for ImmMode class
#include "../MemMap/MemMap.h"
#include "../CpuReg/CpuReg.h"

class ImmMode: public AddrMode{
    public:
        ImmMode(CpuReg& cpuReg, MemMap& mem);
        ~ImmMode();

        //cal addr and return the operand based on addr mode
        virtual  int getOperand();

        //set next PC
        virtual void setNextPC();

    //protected:
};

#endif
