#include <iostream>
#include "Adc.h"

using namespace std;

//Constructor
Adc::Adc(CpuReg* cpuReg, MemMap* mem, e_ADDR_MODE e_addrMode):
    CpuInstr(cpuReg, mem, e_addrMode){
}

Adc::~Adc(){
}

int Adc::performAL(){
    //A,Z,C,N = A+M+C
    int preA;
    int preC;
    int sum;

    int roundSum;
    int C;
    int N;
    int Z;
    int V;

    preA = cpuReg->readA();
    preC = cpuReg->readC();
    sum = preA + operand + preC;

    roundSum = getRoundSum(sum);
    C        = getCarryBit(sum);
    N        = isNegative(roundSum) ? 1 : 0;
    Z        = isZero(roundSum) ? 1 : 0;;
    V        = isOverflow(preA, operand, roundSum) ? 1 : 0;;

    cpuReg->writeC(C);
    cpuReg->writeZ(Z);
    cpuReg->writeV(V);
    cpuReg->writeN(N);
    cpuReg->writeA(roundSum);

    return 1;
}

#ifdef TEST_FUNC

    #include "assert.h"
    #include "NesEmuDevConst.h"

    //test function
    int main(){

        CpuReg cpuReg;
        MemMap memMap;
        int size  ;

        //init CpuReg
        cpuReg.writePC(0x1234);
        cpuReg.writeSP(0x01);
        cpuReg.writeA (0x02);
        cpuReg.writeX (0x03);
        cpuReg.writeY (0x04);
        cpuReg.writeP (0);

        //init mem
        size = 0xffff;
        memMap.init(size);
        for(int addr=0; addr<size; addr++) {
            int memValue;
            memValue = addr & MAX_VALUE_BYTE(1);
            memMap.write(addr, memValue);
        }

        //ADC imme
        CpuInstr* instr = new Adc(&cpuReg, &memMap, e_IMM_MODE);
        //A=0x02, operand=0x35, C=0, PC=0x1234

        instr->exec(); //C=0, Z=0, V=0, N=0, A=0x37, PC=0x1236
        assert( (0x1236 == cpuReg.readPC()) );
        assert( (0x01   == cpuReg.readSP()) );
        assert( (0x37   == cpuReg.readA ()) );
        assert( (0x03   == cpuReg.readX ()) );
        assert( (0x04   == cpuReg.readY ()) );
        assert( (0      == cpuReg.readC ()) );
        assert( (0      == cpuReg.readZ ()) );
        assert( (0      == cpuReg.readI ()) );
        assert( (0      == cpuReg.readD ()) );
        assert( (0      == cpuReg.readB ()) );
        assert( (0      == cpuReg.readV ()) );
        assert( (0      == cpuReg.readN ()) );
        assert( (0x00   == cpuReg.readP ()) );

        cpuReg.writeA (0xc9);
        //A=0xc9, operand=0x37, C=0, PC=0x1236
        instr->exec(); //C=1, Z=1, V=0, N=0, A=0x00, PC=0x1238
        assert( (0x1238 == cpuReg.readPC()) );
        assert( (0x01   == cpuReg.readSP()) );
        assert( (0x00   == cpuReg.readA ()) );
        assert( (0x03   == cpuReg.readX ()) );
        assert( (0x04   == cpuReg.readY ()) );
        assert( (1      == cpuReg.readC ()) );
        assert( (1      == cpuReg.readZ ()) );
        assert( (0      == cpuReg.readI ()) );
        assert( (0      == cpuReg.readD ()) );
        assert( (0      == cpuReg.readB ()) );
        assert( (0      == cpuReg.readV ()) );
        assert( (0      == cpuReg.readN ()) );
        assert( (0x03   == cpuReg.readP ()) );

        delete instr;
        cout << "Pass AdcTest!" << "\n";

        return 0;
    }

#endif
