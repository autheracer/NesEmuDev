
#ifndef INDIRIDXMODE_H
#define INDIRIDXMODE_H

//header for IndirIdxMode class
#include "../MemMap/MemMap.h"
#include "../CpuReg/CpuReg.h"

class IndirIdxMode: public AddrMode{
    public:
        IndirIdxMode(CpuReg& cpuReg, MemMap& mem);
        ~IndirIdxMode();

        //cal addr and return the operand based on addr mode
        virtual  int getOperand();

        //set next PC
        virtual void setNextPC();

    //protected:
};

#endif
