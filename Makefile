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

CpuInstr.o: ./CpuInstr/CpuInstr.cpp 
	${CPPC} ${INC} ./CpuInstr/CpuInstr.cpp -c

clean:
	rm -rf *.o
    
