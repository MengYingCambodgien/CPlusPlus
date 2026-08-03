target = it_science
dependency = 

CXX = g++

create: $(target).cpp $(addsuffix .cpp, $(dependency))
	@$(CXX) $^ -o $(basename $<).exe && $(basename $<).exe

commit: $(target).cpp $(addsuffix .cpp, $(dependency))
	git add $^ Makefile && git commit -m "update"



.PHONY: clean
clean: 
	@$(if $(wildcard *.exe), del /F /Q *.exe)
