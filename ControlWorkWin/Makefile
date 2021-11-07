#$(VERBOSE).SILENT:
FileName = "c:\LabTest"
# Specify compiler
CC=cl.exe

# Specify linker
LINK=link.exe

# Build all target
all : app

# Link the object files and dependent libraries into a binary
app : main.o
	$(LINK) /OUT:app.exe main.o 

# Compile the source files into object files
main.o : main.cpp
	$(CC) /c main.cpp /Fomain.o

# Clean target
clean :
	del main.o app.exe

# Install target
install :
	copy app.exe $(FileName)

# Uninstall target
uninstall :
!if exists($(FileName)) 
    	del $(FileName)
	@echo File uninstalled!
#^^^^^
!else
	!error $(FileName) does not exist!
#^^^^^ !directives don't have to be indented, though.
#
!endif
