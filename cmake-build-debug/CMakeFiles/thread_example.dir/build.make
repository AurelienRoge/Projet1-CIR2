# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
CMAKE_COMMAND = "A:\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "A:\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\aurel\Documents\GitHub\Projet1-CIR2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\aurel\Documents\GitHub\Projet1-CIR2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\thread_example.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\thread_example.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\thread_example.dir\flags.make

CMakeFiles\thread_example.dir\source.cpp.obj: CMakeFiles\thread_example.dir\flags.make
CMakeFiles\thread_example.dir\source.cpp.obj: ..\source.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\aurel\Documents\GitHub\Projet1-CIR2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/thread_example.dir/source.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\thread_example.dir\source.cpp.obj /FdCMakeFiles\thread_example.dir\ /FS -c C:\Users\aurel\Documents\GitHub\Projet1-CIR2\source.cpp
<<

CMakeFiles\thread_example.dir\source.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/thread_example.dir/source.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\thread_example.dir\source.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\aurel\Documents\GitHub\Projet1-CIR2\source.cpp
<<

CMakeFiles\thread_example.dir\source.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/thread_example.dir/source.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\thread_example.dir\source.cpp.s /c C:\Users\aurel\Documents\GitHub\Projet1-CIR2\source.cpp
<<

# Object files for target thread_example
thread_example_OBJECTS = \
"CMakeFiles\thread_example.dir\source.cpp.obj"

# External object files for target thread_example
thread_example_EXTERNAL_OBJECTS =

thread_example.exe: CMakeFiles\thread_example.dir\source.cpp.obj
thread_example.exe: CMakeFiles\thread_example.dir\build.make
thread_example.exe: CMakeFiles\thread_example.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\aurel\Documents\GitHub\Projet1-CIR2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable thread_example.exe"
	"A:\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\thread_example.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\thread_example.dir\objects1.rsp @<<
 /out:thread_example.exe /implib:thread_example.lib /pdb:C:\Users\aurel\Documents\GitHub\Projet1-CIR2\cmake-build-debug\thread_example.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\thread_example.dir\build: thread_example.exe
.PHONY : CMakeFiles\thread_example.dir\build

CMakeFiles\thread_example.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\thread_example.dir\cmake_clean.cmake
.PHONY : CMakeFiles\thread_example.dir\clean

CMakeFiles\thread_example.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\aurel\Documents\GitHub\Projet1-CIR2 C:\Users\aurel\Documents\GitHub\Projet1-CIR2 C:\Users\aurel\Documents\GitHub\Projet1-CIR2\cmake-build-debug C:\Users\aurel\Documents\GitHub\Projet1-CIR2\cmake-build-debug C:\Users\aurel\Documents\GitHub\Projet1-CIR2\cmake-build-debug\CMakeFiles\thread_example.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\thread_example.dir\depend
