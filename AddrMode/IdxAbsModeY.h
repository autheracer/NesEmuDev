
#ifndef IDXABSMODEY_H
#define IDXABSMODEY_H

//header for IdxAbsModeY class
#include "../MemMap/MemMap.h"
#include "../CpuReg/CpuReg.h"

class IdxAbsModeY: public AddrMode{
    public:
        IdxAbsModeY(CpuReg& cpuReg, MemMap& mem);
        ~IdxAbsModeY();

        //cal addr and return the operand based on addr mode
        virtual  int getOperand();

        //set next PC
        virtual void setNextPC();

    //protected:
};

#endif
