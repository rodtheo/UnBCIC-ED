# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.3

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rodtheo/Bioinfo/UnB-Mec/UnBCIC-ED/resolucoes/trabalho1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rodtheo/Bioinfo/UnB-Mec/UnBCIC-ED/resolucoes/trabalho1/build

# Include any dependencies generated for this target.
include src/CMakeFiles/trabalho1.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/trabalho1.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/trabalho1.dir/flags.make

src/CMakeFiles/trabalho1.dir/main.c.o: src/CMakeFiles/trabalho1.dir/flags.make
src/CMakeFiles/trabalho1.dir/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rodtheo/Bioinfo/UnB-Mec/UnBCIC-ED/resolucoes/trabalho1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/trabalho1.dir/main.c.o"
	cd /Users/rodtheo/Bioinfo/UnB-Mec/UnBCIC-ED/resolucoes/trabalho1/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/trabalho1.dir/main.c.o   -c /Users/rodtheo/Bioinfo/UnB-Mec/UnBCIC-ED/resolucoes/trabalho1/src/main.c

src/CMakeFiles/trabalho1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/trabalho1.dir/main.c.i"
	cd /Users/rodtheo/Bioinfo/UnB-Mec/UnBCIC-ED/resolucoes/trabalho1/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /Users/rodtheo/Bioinfo/UnB-Mec/UnBCIC-ED/resolucoes/trabalho1/src/main.c > CMakeFiles/trabalho1.dir/main.c.i

src/CMakeFiles/trabalho1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/trabalho1.dir/main.c.s"
	cd /Users/rodtheo/Bioinfo/UnB-Mec/UnBCIC-ED/resolucoes/trabalho1/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /Users/rodtheo/Bioinfo/UnB-Mec/UnBCIC-ED/resolucoes/trabalho1/src/main.c -o CMakeFiles/trabalho1.dir/main.c.s

src/CMakeFiles/trabalho1.dir/main.c.o.requires:

.PHONY : src/CMakeFiles/trabalho1.dir/main.c.o.requires

src/CMakeFiles/trabalho1.dir/main.c.o.provides: src/CMakeFiles/trabalho1.dir/main.c.o.requires
	$(MAKE) -f src/CMakeFiles/trabalho1.dir/build.make src/CMakeFiles/trabalho1.dir/main.c.o.provides.build
.PHONY : src/CMakeFiles/trabalho1.dir/main.c.o.provides

src/CMakeFiles/trabalho1.dir/main.c.o.provides.build: src/CMakeFiles/trabalho1.dir/main.c.o


src/CMakeFiles/trabalho1.dir/pilha.c.o: src/CMakeFiles/trabalho1.dir/flags.make
src/CMakeFiles/trabalho1.dir/pilha.c.o: ../src/pilha.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rodtheo/Bioinfo/UnB-Mec/UnBCIC-ED/resolucoes/trabalho1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/trabalho1.dir/pilha.c.o"
	cd /Users/rodtheo/Bioinfo/UnB-Mec/UnBCIC-ED/resolucoes/trabalho1/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/trabalho1.dir/pilha.c.o   -c /Users/rodtheo/Bioinfo/UnB-Mec/UnBCIC-ED/resolucoes/trabalho1/src/pilha.c

src/CMakeFiles/trabalho1.dir/pilha.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/trabalho1.dir/pilha.c.i"
	cd /Users/rodtheo/Bioinfo/UnB-Mec/UnBCIC-ED/resolucoes/trabalho1/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /Users/rodtheo/Bioinfo/UnB-Mec/UnBCIC-ED/resolucoes/trabalho1/src/pilha.c > CMakeFiles/trabalho1.dir/pilha.c.i

src/CMakeFiles/trabalho1.dir/pilha.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/trabalho1.dir/pilha.c.s"
	cd /Users/rodtheo/Bioinfo/UnB-Mec/UnBCIC-ED/resolucoes/trabalho1/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /Users/rodtheo/Bioinfo/UnB-Mec/UnBCIC-ED/resolucoes/trabalho1/src/pilha.c -o CMakeFiles/trabalho1.dir/pilha.c.s

src/CMakeFiles/trabalho1.dir/pilha.c.o.requires:

.PHONY : src/CMakeFiles/trabalho1.dir/pilha.c.o.requires

src/CMakeFiles/trabalho1.dir/pilha.c.o.provides: src/CMakeFiles/trabalho1.dir/pilha.c.o.requires
	$(MAKE) -f src/CMakeFiles/trabalho1.dir/build.make src/CMakeFiles/trabalho1.dir/pilha.c.o.provides.build
.PHONY : src/CMakeFiles/trabalho1.dir/pilha.c.o.provides

src/CMakeFiles/trabalho1.dir/pilha.c.o.provides.build: src/CMakeFiles/trabalho1.dir/pilha.c.o


# Object files for target trabalho1
trabalho1_OBJECTS = \
"CMakeFiles/trabalho1.dir/main.c.o" \
"CMakeFiles/trabalho1.dir/pilha.c.o"

# External object files for target trabalho1
trabalho1_EXTERNAL_OBJECTS =

../bin/trabalho1: src/CMakeFiles/trabalho1.dir/main.c.o
../bin/trabalho1: src/CMakeFiles/trabalho1.dir/pilha.c.o
../bin/trabalho1: src/CMakeFiles/trabalho1.dir/build.make
../bin/trabalho1: src/CMakeFiles/trabalho1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rodtheo/Bioinfo/UnB-Mec/UnBCIC-ED/resolucoes/trabalho1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ../../bin/trabalho1"
	cd /Users/rodtheo/Bioinfo/UnB-Mec/UnBCIC-ED/resolucoes/trabalho1/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/trabalho1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/trabalho1.dir/build: ../bin/trabalho1

.PHONY : src/CMakeFiles/trabalho1.dir/build

src/CMakeFiles/trabalho1.dir/requires: src/CMakeFiles/trabalho1.dir/main.c.o.requires
src/CMakeFiles/trabalho1.dir/requires: src/CMakeFiles/trabalho1.dir/pilha.c.o.requires

.PHONY : src/CMakeFiles/trabalho1.dir/requires

src/CMakeFiles/trabalho1.dir/clean:
	cd /Users/rodtheo/Bioinfo/UnB-Mec/UnBCIC-ED/resolucoes/trabalho1/build/src && $(CMAKE_COMMAND) -P CMakeFiles/trabalho1.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/trabalho1.dir/clean

src/CMakeFiles/trabalho1.dir/depend:
	cd /Users/rodtheo/Bioinfo/UnB-Mec/UnBCIC-ED/resolucoes/trabalho1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rodtheo/Bioinfo/UnB-Mec/UnBCIC-ED/resolucoes/trabalho1 /Users/rodtheo/Bioinfo/UnB-Mec/UnBCIC-ED/resolucoes/trabalho1/src /Users/rodtheo/Bioinfo/UnB-Mec/UnBCIC-ED/resolucoes/trabalho1/build /Users/rodtheo/Bioinfo/UnB-Mec/UnBCIC-ED/resolucoes/trabalho1/build/src /Users/rodtheo/Bioinfo/UnB-Mec/UnBCIC-ED/resolucoes/trabalho1/build/src/CMakeFiles/trabalho1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/trabalho1.dir/depend

