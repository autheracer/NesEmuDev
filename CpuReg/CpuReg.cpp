
#include <iostream>
#include "CpuReg.h"
#include "NesEmuDevConst.h"

using namespace std;

//Constructor
CpuReg::CpuReg():
    PC(2),
    SP(1),
    A (1),
    X (1),
    Y (1),
    P (1){
}

//return register pointers
Reg& CpuReg::getPC(){
    return PC;
}
Reg& CpuReg::getSP(){
    return SP;
}
Reg& CpuReg::getA(){
    return A;
}
Reg& CpuReg::getX(){
    return X;
}
Reg& CpuReg::getY(){
    return Y;
}
Reg& CpuReg::getP(){
    return P;
}

void CpuReg::writePbit(int bitValue, int bitPosition){
    int originalValue;
    int bitValueMask;
    int writeValue;
    originalValue = P.read();
    bitValueMask = (bitValue) ?  (0x1 << bitPosition) : 
                                ~(0x1 << bitPosition) ;
    writeValue = (bitValue) ? (originalValue | bitValueMask) :
                              (originalValue & bitValueMask) ;
    P.write(writeValue);
}

int CpuReg::readPbit(int bitPosition){
    const int bitValueMask = (1 << bitPosition);
    int readValue;
    int bitValue;
    readValue = P.read();
    bitValue = (readValue & bitValueMask) >> bitPosition;
    return bitValue;
}

void CpuReg::writeC(int bitValue){
    writePbit(bitValue, 0);
}

void CpuReg::writeZ(int bitValue){
    writePbit(bitValue, 1);
}

void CpuReg::writeI(int bitValue){
    writePbit(bitValue, 2);
}

void CpuReg::writeD(int bitValue){
    writePbit(bitValue, 3);
}

void CpuReg::writeB(int bitValue){
    writePbit(bitValue, 4);
}

void CpuReg::writeV(int bitValue){
    writePbit(bitValue, 6);
}

void CpuReg::writeN(int bitValue){
    writePbit(bitValue, 7);
}

int CpuReg::readC(){
    return readPbit(0);
}

int CpuReg::readZ(){
    return readPbit(1);
}

int CpuReg::readI(){
    return readPbit(2);
}

int CpuReg::readD(){
    return readPbit(3);
}

int CpuReg::readB(){
    return readPbit(4);
}

int CpuReg::readV(){
    return readPbit(6);
}

int CpuReg::readN(){
    return readPbit(7);
}

#ifdef TEST_FUNC

    #include "assert.h"

    //test function
    int main(){

        CpuReg cpuReg;

        Reg&  PC = cpuReg.getPC();;
        Reg&  SP = cpuReg.getSP();;
        Reg&  A  = cpuReg.getA ();;
        Reg&  X  = cpuReg.getX ();;
        Reg&  Y  = cpuReg.getY ();;
        Reg&  P  = cpuReg.getP ();;
        
        PC.write(MAX_VALUE_BYTE(2));
        SP.write(MAX_VALUE_BYTE(1));
        A.write (MAX_VALUE_BYTE(1));
        X.write (MAX_VALUE_BYTE(1));
        Y.write (MAX_VALUE_BYTE(1));
        P.write (MAX_VALUE_BYTE(1));

        assert( (MAX_VALUE_BYTE(2) == PC.read()) );
        assert( (MAX_VALUE_BYTE(1) == SP.read()) );
        assert( (MAX_VALUE_BYTE(1) == A.read ()) );
        assert( (MAX_VALUE_BYTE(1) == X.read ()) );
        assert( (MAX_VALUE_BYTE(1) == Y.read ()) );
        assert( (MAX_VALUE_BYTE(1) == P.read ()) );

        // P = 0xff
        cpuReg.writeC(0); // P = 0xfe
        cpuReg.writeZ(1); // P = 0xfe
        cpuReg.writeI(0); // P = 0xfa
        cpuReg.writeD(1); // P = 0xfa
        cpuReg.writeB(0); // P = 0xea
        cpuReg.writeV(1); // P = 0xea
        cpuReg.writeN(0); // P = 0x6a

        assert( (0x6a == P.read ()) );
        assert( (0 == cpuReg.readC()) );
        assert( (1 == cpuReg.readZ()) );
        assert( (0 == cpuReg.readI()) );
        assert( (1 == cpuReg.readD()) );
        assert( (0 == cpuReg.readB()) );
        assert( (1 == cpuReg.readV()) );
        assert( (0 == cpuReg.readN()) );

        cout << "Pass CpuRegTest!" << "\n";

        return 0;
    }

#endif
