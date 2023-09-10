
#ifndef MEMMAP_H
#define MEMMAP_H

#include "../MemByte/MemByte.h"

//header for MemMap class
class MemMap{
    public:
        MemMap();
        ~MemMap();

        virtual void  init(int size=1);
                int   read(int addr=0);
                void  write(int addr=0, int value=0);

    private:
        int      size;
        MemByte  *mem;
}; 

#endif
