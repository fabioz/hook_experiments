# Specify compiler
CC=cl.exe

# Specify linker
LINK=link.exe

CC_FLAGS=/EHsc -I"minhook\include" -DUNICODE -D_UNICODE /EHsc /Zi /O1 /W3

TARGET_NAME=check_minhook_$(TARGET_PLATFORM)

# Link the object files into a binary
all : check_minhook.o
    $(LINK) libMinHook.x64.lib /DLL /DEBUG /OPT:REF /OPT:ICF /LIBPATH:"minhook\build\VC14\lib\Release" /out:$(TARGET_NAME).dll check_minhook.o

# Compile the source files into object files
check_minhook.o : check_minhook.cpp
    $(CC) /c check_minhook.cpp $(CC_FLAGS) /Focheck_minhook.o
    
# Clean target
clean :
    del $(TARGET_NAME).dll
    del $(TARGET_NAME).exp
    del $(TARGET_NAME).lib
    del *.o
    del *.pdb