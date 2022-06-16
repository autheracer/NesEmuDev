#include <iostream>
#include "AddrMode.h"

using namespace std;

//Constructor
AddrMode::AddrMode(CpuReg& cpuReg, MemMap& mem):
    cpuReg(cpuReg),
    mem   (mem   ){
}

~AddrMode::AddrMode(){
}

