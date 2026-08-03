target = it_science
dependency = People

CXX = g++

create: $(target).cpp $(addsuffix .cpp, $(dependency))
	@$(CXX) $^ -o $(basename $<).exe && $(basename $<).exe


.PHONY: clean
clean: 
	@$(if $(wildcard *.exe), del /F /Q *.exe)
