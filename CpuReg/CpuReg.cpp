
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
Reg & CpuReg::getPC(){
    return PC;
}
Reg & CpuReg::getSP(){
    return SP;
}
Reg & CpuReg::getA(){
    return A;
}
Reg & CpuReg::getX(){
    return X;
}
Reg & CpuReg::getY(){
    return Y;
}
Reg & CpuReg::getP(){
    return P;
}


#ifdef TEST_FUNC

    #include "assert.h"

    //test function
    int main(){

        CpuReg cpuReg;

        Reg  PC;
        Reg  SP;
        Reg  A ;
        Reg  X ;
        Reg  Y ;
        Reg  P ;
        
        PC = cpuReg.getPC();
        SP = cpuReg.getSP();
        A  = cpuReg.getA ();
        X  = cpuReg.getX ();
        Y  = cpuReg.getY ();
        P  = cpuReg.getP ();
        
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

        cout << "Pass CpuRegTest!" << "\n";

        return 0;
    }

#endif
