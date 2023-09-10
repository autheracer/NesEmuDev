
#ifndef CPUINSTR_H
#define CPUINSTR_H

//header for CpuInstr class
#include "../MemMap/MemMap.h"
#include "../CpuReg/CpuReg.h"
#include "../AddrMode/AddrMode.h"

typedef enum e_addrMode{
   e_ABS_MODE,
   e_ACC_MODE,
   e_IDXABS_MODEX,
   e_IDXABS_MODEY,
   e_IDXINDIR_MODE,
   e_IDXZP_MODEX,
   e_IDXZP_MODEY,
   e_IMM_MODE,
   e_IMPLY_MODE,
   e_INDIRIDX_MODE,
   e_INDIR_MODE,
   e_RELAT_MODE,
   e_ZP_MODE
} e_ADDR_MODE;

class CpuInstr{
    public:
        CpuInstr(CpuReg* cpuReg, MemMap* mem, e_ADDR_MODE e_addrMode);
        ~CpuInstr();

        //exec the instruction
        virtual void exec();

    protected:
        CpuReg*    cpuReg;
        MemMap*    mem   ;
        AddrMode*  mode  ;
 
        int        operand  ;
        int        condition;

        //construct the object for addr mode
        virtual void constructAddrMode(e_ADDR_MODE e_addrMode);

        //cal addr and return the operand based on addr mode
        virtual  int getOperand();

        //perform Arithemtic or Logic calculations
        //return 1 if performing success
        //for branch instr,
        //return 1 if branch is taken otherwise return 0
        virtual  int performAL();

        //ALU functions
        virtual  int getRoundSum(int sum);

        virtual  int getCarryBit(int sum);

        virtual  bool isNegative(int sum);

        virtual  bool isOverflow(int opdA, int opdB, int sum);
        
        virtual  bool isZero(int sum);

        //set next PC
        virtual void setNextPC();
};

#endif
