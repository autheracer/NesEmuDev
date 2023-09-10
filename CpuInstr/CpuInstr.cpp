#include <iostream>
#include "CpuInstr.h"
#include "../AddrMode/AbsMode.h"
#include "../AddrMode/AccMode.h"
#include "../AddrMode/AddrMode.h"
#include "../AddrMode/IdxAbsModeX.h"
#include "../AddrMode/IdxAbsModeY.h"
#include "../AddrMode/IdxIndirMode.h"
#include "../AddrMode/IdxZPModeX.h"
#include "../AddrMode/IdxZPModeY.h"
#include "../AddrMode/ImmMode.h"
#include "../AddrMode/ImplyMode.h"
#include "../AddrMode/IndirIdxMode.h"
#include "../AddrMode/IndirMode.h"
#include "../AddrMode/RelatMode.h"
#include "../AddrMode/ZPMode.h"
#include "NesEmuDevConst.h"


using namespace std;

//Constructor
CpuInstr::CpuInstr(CpuReg* cpuReg, MemMap* mem, e_ADDR_MODE e_addrMode):
    cpuReg(cpuReg),
    mem   (mem   ),
    mode  (NULL  ){
    constructAddrMode(e_addrMode);
}

CpuInstr::~CpuInstr(){
    delete mode;
}

//construct the object for addr mode
void CpuInstr::constructAddrMode(e_ADDR_MODE e_addrMode){
    switch(e_addrMode){
        case e_ABS_MODE:
            mode = new AbsMode(cpuReg, mem);
            break;
        case e_ACC_MODE:
            mode = new AccMode(cpuReg, mem);
            break;
        case e_IDXABS_MODEX:
            mode = new IdxAbsModeX(cpuReg, mem);
            break;
        case e_IDXABS_MODEY:
            mode = new IdxAbsModeY(cpuReg, mem);
            break;
        case e_IDXINDIR_MODE:
            mode = new IdxIndirMode(cpuReg, mem);
            break;
        case e_IDXZP_MODEX:
            mode = new IdxZPModeX(cpuReg, mem);
            break;
        case e_IDXZP_MODEY:
            mode = new IdxZPModeY(cpuReg, mem);
            break;
        case e_IMM_MODE:
            mode = new ImmMode(cpuReg, mem);
            break;
        case e_IMPLY_MODE:
            mode = new ImplyMode(cpuReg, mem);
            break;
        case e_INDIRIDX_MODE:
            mode = new IndirIdxMode(cpuReg, mem);
            break;
        case e_INDIR_MODE:
            mode = new IndirMode(cpuReg, mem);
            break;
        case e_RELAT_MODE:
            mode = new RelatMode(cpuReg, mem);
            break;
        case e_ZP_MODE:
            mode = new ZPMode(cpuReg, mem);
            break;
    }
}

//getOperand
int CpuInstr::getOperand(){
    return mode->getOperand();
}

//performAL
int CpuInstr::performAL(){
    return 0;
}

//setNextPC
void CpuInstr::setNextPC(){
    mode->setNextPC();
}

//exec
void CpuInstr::exec(){
    operand   = getOperand();
    condition = performAL();
    setNextPC();
}

int CpuInstr::getRoundSum(int sum){
    return (sum & MAX_VALUE_BYTE(1));
}

int CpuInstr::getCarryBit(int sum){
    return ((sum & (1 << BITS_PER_BYTE)) >> BITS_PER_BYTE);
}

bool CpuInstr::isNegative(int sum){
    return ((sum & (1 << (BITS_PER_BYTE-1))) >> (BITS_PER_BYTE-1)) ? true : false;
}

bool CpuInstr::isOverflow(int opdA, int opdB, int sum){
    bool isPosOverflow = !isNegative(opdA) && !isNegative(opdB) &&  isNegative(sum);
    bool isNegOverflow =  isNegative(opdA) &&  isNegative(opdB) && !isNegative(sum);
    return (isPosOverflow | isNegOverflow); 
}

bool CpuInstr::isZero(int sum){
    return (sum == 0) ? true : false;
}
