
# mini projet AP4A - sensor scanning

EXE = AP4A_Final


CXX = g++ -g -Wall -O 

SRC = $(wildcard *.cpp)

OBJ = $(SRC:.cpp=.o)


%.o: %.cpp 
	$(CXX) -o $@ -c $< 

$(EXE) : $(OBJ) 
	$(CXX) -o $@  $^ 


clean_linux:
	@rm -f *.o  *.txt  $(EXE) *~
	
clean_Windows:
	del /Q /F *.o  *.txt  $(EXE).exe
