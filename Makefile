# Makefile for Codeforces problem setup

# Detect platform
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
    CXX := clang++
else
    CXX := g++
endif

CXXFLAGS = -I ~/include -std=c++17 -g -Wall -Wextra -Wfatal-errors -DIAN_DEBUG -O3

# Default target if just 'make' is called
default: run

# Target to create folder in the current directory and copy template files with prefix "_"
create:
	mkdir -p archive/$(folder)
	for file in $(files); do \
		cp template.cpp $=_$${file}.cpp; \
	done

# Target to compile and run the default program or a specified file
run:
ifeq ($(file),)
	$(CXX) $(CXXFLAGS) source.cpp -o source.exe
	./source.exe
	rm -f source.exe
else
	$(CXX) $(CXXFLAGS) $(file) -o $(basename $(file)).exe
	./$(basename $(file)).exe
	rm -f $(basename $(file)).exe
endif

# Reset source.cpp to the template
reset:
	cp template.cpp source.cpp
	> file.in
	> file.out

# Clean up generated files
clean:
	rm -rf *.exe

# Prevent make from treating arguments as targets
%:
	@:

# Variables for the create target
folder := $(word 2,$(MAKECMDGOALS))
files := $(wordlist 3,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))

.PHONY: default create run clean
