SHELL=/usr/bin/bash
INC=-I ./includes
CPPC=g++

runMemByteTest: runMemByteTest.o MemByteTest.o MemByte.o
	${CPPC} runMemByteTest.o MemByteTest.o MemByte.o -o main.out
runMemByteTest.o: ./MemByte/runMemByteTest.cpp
	${CPPC} ./MemByte/runMemByteTest.cpp -c
MemByteTest.o: ./MemByte/MemByteTest.cpp 
	${CPPC} ./MemByte/MemByteTest.cpp -c
MemByte.o: ./MemByte/MemByte.cpp 
	${CPPC} ${INC} ./MemByte/MemByte.cpp -c
runMemMapTest: runMemMapTest.o MemMapTest.o MemMap.o MemByte.o
	${CPPC} runMemMapTest.o MemMapTest.o MemMap.o MemByte.o -o main.out
runMemMapTest.o: ./MemMap/runMemMapTest.cpp
	${CPPC} ./MemMap/runMemMapTest.cpp -c
MemMapTest.o: ./MemMap/MemMapTest.cpp 
	${CPPC} ./MemMap/MemMapTest.cpp -c
MemMap.o: ./MemMap/MemMap.cpp 
	${CPPC} ${INC} ./MemMap/MemMap.cpp -c
clean:
	rm -rf *.o
    
