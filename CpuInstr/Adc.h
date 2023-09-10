
#ifndef ADC_H
#define ADC_H

//header for Adc class
#include "../CpuInstr/CpuInstr.h"

class Adc: public CpuInstr{
    public:
        Adc(CpuReg* cpuReg, MemMap* mem, e_ADDR_MODE e_addrMode);
		~Adc();

    protected:
        //perform Arithemtic or Logic calculations
        //return 1 if performing success
        //for branch instr,
        //return 1 if branch is taken otherwise return 0
        virtual  int performAL();
};

#endif
