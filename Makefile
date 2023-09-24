CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

OBJS = main.o sg_memory.o

student_grades: $(OBJS)
	$(CXX) $(CXXFLAGS) -o student_grades $(OBJS)

main.o: main.cpp sg_memory.h
	$(CXX) $(CXXFLAGS) -c main.cpp

sg_memory.o: sg_memory.cpp sg_memory.h
	$(CXX) $(CXXFLAGS) -c sg_memory.cpp

clean:
	rm -f student_grades $(OBJS)

