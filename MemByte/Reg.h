
#ifndef REG_H
#define REG_H

//header for Reg class
#include "MemByte.h"

class Reg: public MemByte{
    public:
        Reg(int size=1);
        virtual void write(int dataIn); //set data for this MemByte
    private:
        int size; //data size(# of byte) of this register
};

#endif
