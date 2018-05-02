CXX = g++-5
CXXFLAGS = -std=c++14 -Werror=vla -MMD
EXEC = a4q4
OBJECTS = cell.o textdisplay.o grid.o main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
