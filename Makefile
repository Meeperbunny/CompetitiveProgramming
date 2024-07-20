# Makefile for Codeforces problem setup

# Default target if just 'make' is called
default: run

# Target to create folder in the current directory and copy template files with prefix "_"
create:
	mkdir -p archives/$(folder)
	for file in $(files); do \
		cp template.cpp $=_$${file}.cpp; \
	done

# Target to compile and run the default program or a specified file
run:
ifeq ($(file),)
	g++ source.cpp -g -Wall -Wextra -Wfatal-errors -DIAN_DEBUG -o source.exe
	./source.exe
	rm -f source.exe
else
	g++ $(file) -g -Wall -Wextra -Wfatal-errors -DIAN_DEBUG -o $(basename $(file)).exe
	./$(basename $(file)).exe
	rm -f $(basename $(file)).exe
endif

# Clean up generated files
clean:
	rm -rf *.exe

# Prevent make from treating arguments as targets
%:
	@:

# Variables for the create target
folder := $(word 2,$(MAKECMDGOALS))
files := $(wordlist 3,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))

# Convert the rest of the command line arguments to file names
.PHONY: default create run clean