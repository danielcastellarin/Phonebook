# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\danie\CLionProjects\Phonebook

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\danie\CLionProjects\Phonebook\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\Phonebook.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Phonebook.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Phonebook.dir\flags.make

CMakeFiles\Phonebook.dir\main.c.obj: CMakeFiles\Phonebook.dir\flags.make
CMakeFiles\Phonebook.dir\main.c.obj: ..\main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\danie\CLionProjects\Phonebook\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Phonebook.dir/main.c.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1420~1.275\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Phonebook.dir\main.c.obj /FdCMakeFiles\Phonebook.dir\ /FS -c C:\Users\danie\CLionProjects\Phonebook\main.c
<<

CMakeFiles\Phonebook.dir\main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Phonebook.dir/main.c.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1420~1.275\bin\Hostx86\x86\cl.exe > CMakeFiles\Phonebook.dir\main.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\danie\CLionProjects\Phonebook\main.c
<<

CMakeFiles\Phonebook.dir\main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Phonebook.dir/main.c.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1420~1.275\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Phonebook.dir\main.c.s /c C:\Users\danie\CLionProjects\Phonebook\main.c
<<

# Object files for target Phonebook
Phonebook_OBJECTS = \
"CMakeFiles\Phonebook.dir\main.c.obj"

# External object files for target Phonebook
Phonebook_EXTERNAL_OBJECTS =

Phonebook.exe: CMakeFiles\Phonebook.dir\main.c.obj
Phonebook.exe: CMakeFiles\Phonebook.dir\build.make
Phonebook.exe: CMakeFiles\Phonebook.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\danie\CLionProjects\Phonebook\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Phonebook.exe"
	"C:\Program Files\JetBrains\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Phonebook.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1420~1.275\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Phonebook.dir\objects1.rsp @<<
 /out:Phonebook.exe /implib:Phonebook.lib /pdb:C:\Users\danie\CLionProjects\Phonebook\cmake-build-debug\Phonebook.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Phonebook.dir\build: Phonebook.exe

.PHONY : CMakeFiles\Phonebook.dir\build

CMakeFiles\Phonebook.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Phonebook.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Phonebook.dir\clean

CMakeFiles\Phonebook.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\danie\CLionProjects\Phonebook C:\Users\danie\CLionProjects\Phonebook C:\Users\danie\CLionProjects\Phonebook\cmake-build-debug C:\Users\danie\CLionProjects\Phonebook\cmake-build-debug C:\Users\danie\CLionProjects\Phonebook\cmake-build-debug\CMakeFiles\Phonebook.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\Phonebook.dir\depend

