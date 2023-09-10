SHELL=/usr/bin/bash
INC=-I ./includes
CPPC=g++
TEST=-D TEST_FUNC

MemByteTest: MemByteTest.o
	${CPPC} MemByteTest.o -o main.out
	./main.out
MemByteTest.o: ./MemByte/MemByte.cpp
	${CPPC} ${INC} ${TEST} -o MemByteTest.o ./MemByte/MemByte.cpp -c
MemByte.o: ./MemByte/MemByte.cpp 
	${CPPC} ${INC} ./MemByte/MemByte.cpp -c
Reg.o: ./MemByte/Reg.cpp 
	${CPPC} ${INC} ./MemByte/Reg.cpp -c

CpuRegTest: CpuRegTest.o Reg.o MemByte.o
	${CPPC} CpuRegTest.o Reg.o MemByte.o -o main.out
	./main.out
CpuRegTest.o: ./CpuReg/CpuReg.cpp
	${CPPC} ${INC} ${TEST} -o CpuRegTest.o ./CpuReg/CpuReg.cpp -c
CpuReg.o: ./CpuReg/CpuReg.cpp 
	${CPPC} ${INC} ./CpuReg/CpuReg.cpp -c

MemMapTest: MemMapTest.o MemByte.o
	${CPPC} MemMapTest.o MemByte.o -o main.out
	./main.out
MemMapTest.o: ./MemMap/MemMap.cpp 
	${CPPC} ${INC} ${TEST} -o MemMapTest.o ./MemMap/MemMap.cpp -c
MemMap.o: ./MemMap/MemMap.cpp 
	${CPPC} ${INC} ./MemMap/MemMap.cpp -c

AbsMode.o:      ./AddrMode/AbsMode.cpp
	${CPPC} ${INC} ./AddrMode/AbsMode.cpp      -c
AccMode.o:      ./AddrMode/AccMode.cpp
	${CPPC} ${INC} ./AddrMode/AccMode.cpp      -c
AddrMode.o:     ./AddrMode/AddrMode.cpp
	${CPPC} ${INC} ./AddrMode/AddrMode.cpp     -c
IdxAbsModeX.o:  ./AddrMode/IdxAbsModeX.cpp
	${CPPC} ${INC} ./AddrMode/IdxAbsModeX.cpp  -c
IdxAbsModeY.o:  ./AddrMode/IdxAbsModeY.cpp
	${CPPC} ${INC} ./AddrMode/IdxAbsModeY.cpp  -c
IdxIndirMode.o: ./AddrMode/IdxIndirMode.cpp
	${CPPC} ${INC} ./AddrMode/IdxIndirMode.cpp -c
IdxZPModeX.o:   ./AddrMode/IdxZPModeX.cpp
	${CPPC} ${INC} ./AddrMode/IdxZPModeX.cpp   -c
IdxZPModeY.o:   ./AddrMode/IdxZPModeY.cpp
	${CPPC} ${INC} ./AddrMode/IdxZPModeY.cpp   -c
ImmMode.o:      ./AddrMode/ImmMode.cpp
	${CPPC} ${INC} ./AddrMode/ImmMode.cpp      -c
ImplyMode.o:    ./AddrMode/ImplyMode.cpp
	${CPPC} ${INC} ./AddrMode/ImplyMode.cpp    -c
IndirIdxMode.o: ./AddrMode/IndirIdxMode.cpp
	${CPPC} ${INC} ./AddrMode/IndirIdxMode.cpp -c
IndirMode.o:    ./AddrMode/IndirMode.cpp
	${CPPC} ${INC} ./AddrMode/IndirMode.cpp    -c
RelatMode.o:    ./AddrMode/RelatMode.cpp
	${CPPC} ${INC} ./AddrMode/RelatMode.cpp    -c
ZPMode.o:       ./AddrMode/ZPMode.cpp
	${CPPC} ${INC} ./AddrMode/ZPMode.cpp       -c

CpuInstr.o: ./CpuInstr/CpuInstr.cpp 
	${CPPC} ${INC} ./CpuInstr/CpuInstr.cpp -c

AdcTest: AdcTest.o CpuInstr.o AddrMode.o AbsMode.o AccMode.o IdxAbsModeX.o IdxAbsModeY.o IdxIndirMode.o IdxZPModeX.o IdxZPModeY.o ImmMode.o ImplyMode.o IndirIdxMode.o IndirMode.o RelatMode.o ZPMode.o MemByte.o Reg.o CpuReg.o MemMap.o
	${CPPC} AdcTest.o CpuInstr.o AddrMode.o AbsMode.o AccMode.o IdxAbsModeX.o IdxAbsModeY.o IdxIndirMode.o IdxZPModeX.o IdxZPModeY.o ImmMode.o ImplyMode.o IndirIdxMode.o IndirMode.o RelatMode.o ZPMode.o MemByte.o Reg.o CpuReg.o MemMap.o -o main.out
	./main.out
AdcTest.o: ./CpuInstr/Adc.cpp
	${CPPC} ${INC} ${TEST} -o AdcTest.o ./CpuInstr/Adc.cpp -c
Adc.o: ./CpuInstr/Adc.cpp 
	${CPPC} ${INC} ./CpuInstr/Adc.cpp -c

clean:
	rm -rf *.o
    
