
#ifndef CPUREG_H
#define CPUREG_H

//header for CpuReg class
#include "../MemByte/Reg.h"

class CpuReg{
    public:
        CpuReg();
        Reg & getPC();
        Reg & getSP();
        Reg & getA ();
        Reg & getX ();
        Reg & getY ();
        Reg & getP ();

    private:
        Reg  PC; //ProgramCounter
        Reg  SP; //StackPointer
        Reg  A ; //Accumulator
        Reg  X ; //Index Register X
        Reg  Y ; //Index Register Y
        Reg  P ; //Processor Status
};

#endif
