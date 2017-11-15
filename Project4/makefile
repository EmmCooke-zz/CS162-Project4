CXX = g++
CXXFLAGS =  -std=c++0x
CXXFLAGS +=   -Wall
CXXFLAGS +=   -pedantic-errors
CXXFLAGS +=   -g
#CXXFLAGS +=   -O3
LDFLAGS =  -lboost_date_time
OBJS = 
SRCS = 
HEADERS = 

#target: dependencies
#rule to build
#

ProjectName: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o ProjectName

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c   $(@:.o=.cpp)

.PHONY: clean
clean:
	rm ${OBJS} ProjectName

zip:
	zip -D ProjectName_Cooke_Emmet.zip ${HEADERS} ${SRCS} makefile
