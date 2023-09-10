
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

void CpuReg::writePC(int value){
    PC.write(value);
}

void CpuReg::writeSP(int value){
    SP.write(value);
}

void CpuReg::writeA(int value){
    A.write(value);
}

void CpuReg::writeX(int value){
    X.write(value);
}

void CpuReg::writeY(int value){
    Y.write(value);
}

void CpuReg::writeP(int value){
    P.write(value);
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

int CpuReg::readPC(){
    return PC.read();
}

int CpuReg::readSP(){
    return SP.read();
}

int CpuReg::readA(){
    return A.read();
}

int CpuReg::readX(){
    return X.read();
}

int CpuReg::readY(){
    return Y.read();
}

int CpuReg::readP(){
    return P.read();
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

        cpuReg.writePC(MAX_VALUE_BYTE(2));
        cpuReg.writeSP(MAX_VALUE_BYTE(1));
        cpuReg.writeA (MAX_VALUE_BYTE(1));
        cpuReg.writeX (MAX_VALUE_BYTE(1));
        cpuReg.writeY (MAX_VALUE_BYTE(1));
        cpuReg.writeP (MAX_VALUE_BYTE(1));

        assert( (MAX_VALUE_BYTE(2) == cpuReg.readPC()) );
        assert( (MAX_VALUE_BYTE(1) == cpuReg.readSP()) );
        assert( (MAX_VALUE_BYTE(1) == cpuReg.readA ()) );
        assert( (MAX_VALUE_BYTE(1) == cpuReg.readX ()) );
        assert( (MAX_VALUE_BYTE(1) == cpuReg.readY ()) );
        assert( (MAX_VALUE_BYTE(1) == cpuReg.readP ()) );

        // P = 0xff
        cpuReg.writeC(0); // P = 0xfe
        cpuReg.writeZ(1); // P = 0xfe
        cpuReg.writeI(0); // P = 0xfa
        cpuReg.writeD(1); // P = 0xfa
        cpuReg.writeB(0); // P = 0xea
        cpuReg.writeV(1); // P = 0xea
        cpuReg.writeN(0); // P = 0x6a

        assert( (0x6a == cpuReg.readP()) );
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
