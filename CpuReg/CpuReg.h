
#ifndef CPUREG_H
#define CPUREG_H

//header for CpuReg class
#include "../MemByte/Reg.h"

class CpuReg{
    public:
        CpuReg();

        void writePC(int value);
        void writeSP(int value);
        void writeA (int value);
        void writeX (int value);
        void writeY (int value);
        void writeP (int value);

        void writeC(int bitValue);
        void writeZ(int bitValue);
        void writeI(int bitValue);
        void writeD(int bitValue);
        void writeB(int bitValue);
        void writeV(int bitValue);
        void writeN(int bitValue);

         int readPC();
         int readSP();
         int readA ();
         int readX ();
         int readY ();
         int readP ();

         int readC();
         int readZ();
         int readI();
         int readD();
         int readB();
         int readV();
         int readN();

    private:
        Reg  PC; //ProgramCounter
        Reg  SP; //StackPointer
        Reg  A ; //Accumulator
        Reg  X ; //Index Register X
        Reg  Y ; //Index Register Y
        Reg  P ; //Processor Status

        void writePbit(int bitValue, int bitPosition);
         int  readPbit(int bitPosition);
};

#endif
