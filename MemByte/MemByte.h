
#ifndef MEMBYTE_H
#define MEMBYTE_H
//header for MemByte class
class MemByte{
    public:
        MemByte();
        int  read();           //return data for this MemByte
        virtual void write(int value); //set data for this MemByte

    protected:
        int data;           //data for this MemByte
};

#endif
