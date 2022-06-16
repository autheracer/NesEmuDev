
#ifndef IMPLYMODE_H
#define IMPLYMODE_H

//header for ImplyMode class
#include "../MemMap/MemMap.h"
#include "../CpuReg/CpuReg.h"

class ImplyMode: public AddrMode{
    public:
        ImplyMode(CpuReg& cpuReg, MemMap& mem);
        ~ImplyMode();

        //cal addr and return the operand based on addr mode
        virtual  int getOperand();

        //set next PC
        virtual void setNextPC();

    //protected:
};

#endif
