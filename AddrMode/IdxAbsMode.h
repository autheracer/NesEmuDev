
#ifndef IDXABSMODE_H
#define IDXABSMODE_H

//header for IdxAbsMode class
#include "../MemMap/MemMap.h"
#include "../CpuReg/CpuReg.h"

class IdxAbsMode: public AddrMode{
    public:
        IdxAbsMode(CpuReg& cpuReg, MemMap& mem);
        ~IdxAbsMode();

        //cal addr and return the operand based on addr mode
        virtual  int getOperand();

        //set next PC
        virtual void setNextPC();

    //protected:
};

#endif
