
#ifndef ACCMODE_H
#define ACCMODE_H

//header for AccMode class
#include "../MemMap/MemMap.h"
#include "../CpuReg/CpuReg.h"

class AccMode: public AddrMode{
    public:
        AccMode(CpuReg& cpuReg, MemMap& mem);
        ~AccMode();

        //cal addr and return the operand based on addr mode
        virtual  int getOperand();

        //set next PC
        virtual void setNextPC();

    //protected:
};

#endif
