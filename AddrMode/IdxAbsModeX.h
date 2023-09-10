
#ifndef IDXABSMODEX_H
#define IDXABSMODEX_H

//header for IdxAbsModeX class
#include "../MemMap/MemMap.h"
#include "../CpuReg/CpuReg.h"

class IdxAbsModeX: public AddrMode{
    public:
        IdxAbsModeX(CpuReg& cpuReg, MemMap& mem);
        ~IdxAbsModeX();

        //cal addr and return the operand based on addr mode
        virtual  int getOperand();

        //set next PC
        virtual void setNextPC();

    //protected:
};

#endif
