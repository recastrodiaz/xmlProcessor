TARGET  := dtdExe
CSRCS   := 
CXXSRCS := DtdDocument.cpp DtdBalise.cpp AttList.cpp AttDef.cpp DtdElement.cpp ElementAttBase.cpp ElementAtt.cpp ElementAttList.cpp DtdTest.cpp 
INCLUDE  = 
LDFLAGS  = 
LIBS     = 

OBJS    := ${CXXSRCS:.cpp=.o} 
OBJS    += ${CSRCS:.c=.o} 
DEPS    := ${CXXSRCS:.cpp=.dep} 
DEPS    += ${CSRCS:.c=.dep} 
XDEPS   := $(wildcard ${DEPS}) 

CXXFLAGS = -Wno-write-strings -O2 -Wall -fPIC

.PHONY: all clean distclean 
all:: ${TARGET} 

ifneq (${XDEPS},) 
include ${XDEPS} 
endif 

${TARGET}: ${OBJS} 
	${CXX} ${LDFLAGS} -o $@ $^ ${LIBS} 
	-rm -f *~ *.o *.dep 

 %.o: %.cpp %.c
	g++ ${INCLUDE} ${CXXFLAGS} -o $@ -c $< 
	
 %.o: %.c
	${CXX} ${INCLUDE} ${CXXFLAGS} -o $@ -c $< 

${DEPS}: %.dep: %.cpp Makefile 
	${CXX} ${CXXFLAGS} -M $< > $@ 

clean:: 
	-rm -f *~ *.o *.dep ${TARGET} 

distclean:: clean
