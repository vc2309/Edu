CXX = g++
CXXFLAGS = -std=c++14 -Werror=vla -MMD
EXEC = main

OBJECTS = main.o integer.o unary.o binary.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}	
