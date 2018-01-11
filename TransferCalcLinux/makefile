VPATH = ../Source ../../googletest/googletest/src

GOOGLETSTOBJS = gtest_main.o gtest-all.o

all : TransferCalc.exe UnitTest_TransferCalc.exe
	chmod a+x ./TransferCalc.exe
	chmod a+x ./UnitTest_TransferCalc.exe

%.o : %.cpp
	g++ -c  $^ -I../../googletest/googletest/include -I../../googletest/googletest
	
%.o : %.cc
	g++ -c -pthread $^ -I../../googletest/googletest/include -I../../googletest/googletest

TransferCalc.exe : TransferCalc.o TCLog.o DimParam.o
	g++ -o $@ $^
	
UnitTest_TransferCalc.exe : gtest_main.o gtest-all.o TCLog.o DimParam.o UnitTest_TransferCalc.o
	g++ -pthread -o $@ $^
	
clean:
	rm -f *.exe *.o