# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Library/Frameworks/Python.framework/Versions/3.11/lib/python3.11/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /Library/Frameworks/Python.framework/Versions/3.11/lib/python3.11/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/grace/Documents/GitHub/ME-433/hw2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/grace/Documents/GitHub/ME-433/hw2/build

# Utility rule file for ELF2UF2Build.

# Include any custom commands dependencies for this target.
include combined/CMakeFiles/ELF2UF2Build.dir/compiler_depend.make

# Include the progress variables for this target.
include combined/CMakeFiles/ELF2UF2Build.dir/progress.make

combined/CMakeFiles/ELF2UF2Build: combined/CMakeFiles/ELF2UF2Build-complete

combined/CMakeFiles/ELF2UF2Build-complete: combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install
combined/CMakeFiles/ELF2UF2Build-complete: combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir
combined/CMakeFiles/ELF2UF2Build-complete: combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download
combined/CMakeFiles/ELF2UF2Build-complete: combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update
combined/CMakeFiles/ELF2UF2Build-complete: combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch
combined/CMakeFiles/ELF2UF2Build-complete: combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure
combined/CMakeFiles/ELF2UF2Build-complete: combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-build
combined/CMakeFiles/ELF2UF2Build-complete: combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/grace/Documents/GitHub/ME-433/hw2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'ELF2UF2Build'"
	cd /Users/grace/Documents/GitHub/ME-433/hw2/build/combined && /Library/Frameworks/Python.framework/Versions/3.11/lib/python3.11/site-packages/cmake/data/bin/cmake -E make_directory /Users/grace/Documents/GitHub/ME-433/hw2/build/combined/CMakeFiles
	cd /Users/grace/Documents/GitHub/ME-433/hw2/build/combined && /Library/Frameworks/Python.framework/Versions/3.11/lib/python3.11/site-packages/cmake/data/bin/cmake -E touch /Users/grace/Documents/GitHub/ME-433/hw2/build/combined/CMakeFiles/ELF2UF2Build-complete
	cd /Users/grace/Documents/GitHub/ME-433/hw2/build/combined && /Library/Frameworks/Python.framework/Versions/3.11/lib/python3.11/site-packages/cmake/data/bin/cmake -E touch /Users/grace/Documents/GitHub/ME-433/hw2/build/combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-done

combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-build: combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/grace/Documents/GitHub/ME-433/hw2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Performing build step for 'ELF2UF2Build'"
	cd /Users/grace/Documents/GitHub/ME-433/hw2/build/elf2uf2 && $(MAKE)

combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure: combined/elf2uf2/tmp/ELF2UF2Build-cfgcmd.txt
combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure: combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/grace/Documents/GitHub/ME-433/hw2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Performing configure step for 'ELF2UF2Build'"
	cd /Users/grace/Documents/GitHub/ME-433/hw2/build/elf2uf2 && /Library/Frameworks/Python.framework/Versions/3.11/lib/python3.11/site-packages/cmake/data/bin/cmake -DCMAKE_MAKE_PROGRAM:FILEPATH=/usr/bin/make "-GUnix Makefiles" -S /Users/grace/Desktop/Pico/pico-sdk/tools/elf2uf2 -B /Users/grace/Documents/GitHub/ME-433/hw2/build/elf2uf2
	cd /Users/grace/Documents/GitHub/ME-433/hw2/build/elf2uf2 && /Library/Frameworks/Python.framework/Versions/3.11/lib/python3.11/site-packages/cmake/data/bin/cmake -E touch /Users/grace/Documents/GitHub/ME-433/hw2/build/combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure

combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download: combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-source_dirinfo.txt
combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download: combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/grace/Documents/GitHub/ME-433/hw2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "No download step for 'ELF2UF2Build'"
	cd /Users/grace/Documents/GitHub/ME-433/hw2/build/combined && /Library/Frameworks/Python.framework/Versions/3.11/lib/python3.11/site-packages/cmake/data/bin/cmake -E echo_append
	cd /Users/grace/Documents/GitHub/ME-433/hw2/build/combined && /Library/Frameworks/Python.framework/Versions/3.11/lib/python3.11/site-packages/cmake/data/bin/cmake -E touch /Users/grace/Documents/GitHub/ME-433/hw2/build/combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download

combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install: combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/grace/Documents/GitHub/ME-433/hw2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'ELF2UF2Build'"
	cd /Users/grace/Documents/GitHub/ME-433/hw2/build/elf2uf2 && /Library/Frameworks/Python.framework/Versions/3.11/lib/python3.11/site-packages/cmake/data/bin/cmake -E echo_append

combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/grace/Documents/GitHub/ME-433/hw2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'ELF2UF2Build'"
	cd /Users/grace/Documents/GitHub/ME-433/hw2/build/combined && /Library/Frameworks/Python.framework/Versions/3.11/lib/python3.11/site-packages/cmake/data/bin/cmake -Dcfgdir= -P /Users/grace/Documents/GitHub/ME-433/hw2/build/combined/elf2uf2/tmp/ELF2UF2Build-mkdirs.cmake
	cd /Users/grace/Documents/GitHub/ME-433/hw2/build/combined && /Library/Frameworks/Python.framework/Versions/3.11/lib/python3.11/site-packages/cmake/data/bin/cmake -E touch /Users/grace/Documents/GitHub/ME-433/hw2/build/combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir

combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch: combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/grace/Documents/GitHub/ME-433/hw2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'ELF2UF2Build'"
	cd /Users/grace/Documents/GitHub/ME-433/hw2/build/combined && /Library/Frameworks/Python.framework/Versions/3.11/lib/python3.11/site-packages/cmake/data/bin/cmake -E echo_append
	cd /Users/grace/Documents/GitHub/ME-433/hw2/build/combined && /Library/Frameworks/Python.framework/Versions/3.11/lib/python3.11/site-packages/cmake/data/bin/cmake -E touch /Users/grace/Documents/GitHub/ME-433/hw2/build/combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch

combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update: combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/grace/Documents/GitHub/ME-433/hw2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No update step for 'ELF2UF2Build'"
	cd /Users/grace/Documents/GitHub/ME-433/hw2/build/combined && /Library/Frameworks/Python.framework/Versions/3.11/lib/python3.11/site-packages/cmake/data/bin/cmake -E echo_append
	cd /Users/grace/Documents/GitHub/ME-433/hw2/build/combined && /Library/Frameworks/Python.framework/Versions/3.11/lib/python3.11/site-packages/cmake/data/bin/cmake -E touch /Users/grace/Documents/GitHub/ME-433/hw2/build/combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update

ELF2UF2Build: combined/CMakeFiles/ELF2UF2Build
ELF2UF2Build: combined/CMakeFiles/ELF2UF2Build-complete
ELF2UF2Build: combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-build
ELF2UF2Build: combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure
ELF2UF2Build: combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download
ELF2UF2Build: combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install
ELF2UF2Build: combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir
ELF2UF2Build: combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch
ELF2UF2Build: combined/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update
ELF2UF2Build: combined/CMakeFiles/ELF2UF2Build.dir/build.make
.PHONY : ELF2UF2Build

# Rule to build all files generated by this target.
combined/CMakeFiles/ELF2UF2Build.dir/build: ELF2UF2Build
.PHONY : combined/CMakeFiles/ELF2UF2Build.dir/build

combined/CMakeFiles/ELF2UF2Build.dir/clean:
	cd /Users/grace/Documents/GitHub/ME-433/hw2/build/combined && $(CMAKE_COMMAND) -P CMakeFiles/ELF2UF2Build.dir/cmake_clean.cmake
.PHONY : combined/CMakeFiles/ELF2UF2Build.dir/clean

combined/CMakeFiles/ELF2UF2Build.dir/depend:
	cd /Users/grace/Documents/GitHub/ME-433/hw2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/grace/Documents/GitHub/ME-433/hw2 /Users/grace/Documents/GitHub/ME-433/hw2/combined /Users/grace/Documents/GitHub/ME-433/hw2/build /Users/grace/Documents/GitHub/ME-433/hw2/build/combined /Users/grace/Documents/GitHub/ME-433/hw2/build/combined/CMakeFiles/ELF2UF2Build.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : combined/CMakeFiles/ELF2UF2Build.dir/depend

