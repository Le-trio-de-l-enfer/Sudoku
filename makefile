# Makefile with dependencies management (Q4)

CXX        = clang++
CXXFLAGS   = -Wall  -std=c++17
DEPFLAGS   = -MMD
LDFLAGS    =
SRCS       = Sudoku.cpp Main.cpp
OBJS       = $(SRCS:.cpp=.o)
TARGET     = sudoku
DEPS	   = $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c  $<

clean:
	rm -f *.o *.d

mrproper: clean
	rm -f $(TARGET)

exe: $(TARGET)
	./$(TARGET)

-include $(DEPS)