#Copyright(C) PlotnikovFA "ControlWork v4 main" 2021
# Specify compiler
CC=gcc
 
# Specify linker
LINK=gcc
 
# Build all target
.PHONY : all
all : app
 
# Link the object files and dependent libraries into a binary
app : main.o
	$(LINK) -o app main.o -lstdc++
 
# Compile the source files into object files
main.o : main.cpp
	$(CC) -c main.cpp -o main.o
 
# Clean target
.PHONY : clean
clean :
	rm main.o app
	
# Install target
.PHONY : install
install :
	@ mkdir bin
	@ cp app bin/
	@ echo "Инсталяция завершена успешно!"
	
# Uninstall target
.PHONY : uninstall
uninstall :
	rm -Rfv bin
	@ echo "Деинсталяция завершена успешно!"
	

