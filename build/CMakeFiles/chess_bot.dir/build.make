# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 4.0

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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/College/Year4/Project/C00251168-Chess-Bot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/College/Year4/Project/C00251168-Chess-Bot/build

# Include any dependencies generated for this target.
include CMakeFiles/chess_bot.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/chess_bot.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/chess_bot.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chess_bot.dir/flags.make

CMakeFiles/chess_bot.dir/codegen:
.PHONY : CMakeFiles/chess_bot.dir/codegen

CMakeFiles/chess_bot.dir/src/board.cpp.obj: CMakeFiles/chess_bot.dir/flags.make
CMakeFiles/chess_bot.dir/src/board.cpp.obj: CMakeFiles/chess_bot.dir/includes_CXX.rsp
CMakeFiles/chess_bot.dir/src/board.cpp.obj: C:/College/Year4/Project/C00251168-Chess-Bot/src/board.cpp
CMakeFiles/chess_bot.dir/src/board.cpp.obj: CMakeFiles/chess_bot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/College/Year4/Project/C00251168-Chess-Bot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chess_bot.dir/src/board.cpp.obj"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess_bot.dir/src/board.cpp.obj -MF CMakeFiles/chess_bot.dir/src/board.cpp.obj.d -o CMakeFiles/chess_bot.dir/src/board.cpp.obj -c C:/College/Year4/Project/C00251168-Chess-Bot/src/board.cpp

CMakeFiles/chess_bot.dir/src/board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess_bot.dir/src/board.cpp.i"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/College/Year4/Project/C00251168-Chess-Bot/src/board.cpp > CMakeFiles/chess_bot.dir/src/board.cpp.i

CMakeFiles/chess_bot.dir/src/board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess_bot.dir/src/board.cpp.s"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/College/Year4/Project/C00251168-Chess-Bot/src/board.cpp -o CMakeFiles/chess_bot.dir/src/board.cpp.s

CMakeFiles/chess_bot.dir/src/evaluation.cpp.obj: CMakeFiles/chess_bot.dir/flags.make
CMakeFiles/chess_bot.dir/src/evaluation.cpp.obj: CMakeFiles/chess_bot.dir/includes_CXX.rsp
CMakeFiles/chess_bot.dir/src/evaluation.cpp.obj: C:/College/Year4/Project/C00251168-Chess-Bot/src/evaluation.cpp
CMakeFiles/chess_bot.dir/src/evaluation.cpp.obj: CMakeFiles/chess_bot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/College/Year4/Project/C00251168-Chess-Bot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/chess_bot.dir/src/evaluation.cpp.obj"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess_bot.dir/src/evaluation.cpp.obj -MF CMakeFiles/chess_bot.dir/src/evaluation.cpp.obj.d -o CMakeFiles/chess_bot.dir/src/evaluation.cpp.obj -c C:/College/Year4/Project/C00251168-Chess-Bot/src/evaluation.cpp

CMakeFiles/chess_bot.dir/src/evaluation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess_bot.dir/src/evaluation.cpp.i"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/College/Year4/Project/C00251168-Chess-Bot/src/evaluation.cpp > CMakeFiles/chess_bot.dir/src/evaluation.cpp.i

CMakeFiles/chess_bot.dir/src/evaluation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess_bot.dir/src/evaluation.cpp.s"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/College/Year4/Project/C00251168-Chess-Bot/src/evaluation.cpp -o CMakeFiles/chess_bot.dir/src/evaluation.cpp.s

CMakeFiles/chess_bot.dir/src/main.cpp.obj: CMakeFiles/chess_bot.dir/flags.make
CMakeFiles/chess_bot.dir/src/main.cpp.obj: CMakeFiles/chess_bot.dir/includes_CXX.rsp
CMakeFiles/chess_bot.dir/src/main.cpp.obj: C:/College/Year4/Project/C00251168-Chess-Bot/src/main.cpp
CMakeFiles/chess_bot.dir/src/main.cpp.obj: CMakeFiles/chess_bot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/College/Year4/Project/C00251168-Chess-Bot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/chess_bot.dir/src/main.cpp.obj"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess_bot.dir/src/main.cpp.obj -MF CMakeFiles/chess_bot.dir/src/main.cpp.obj.d -o CMakeFiles/chess_bot.dir/src/main.cpp.obj -c C:/College/Year4/Project/C00251168-Chess-Bot/src/main.cpp

CMakeFiles/chess_bot.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess_bot.dir/src/main.cpp.i"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/College/Year4/Project/C00251168-Chess-Bot/src/main.cpp > CMakeFiles/chess_bot.dir/src/main.cpp.i

CMakeFiles/chess_bot.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess_bot.dir/src/main.cpp.s"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/College/Year4/Project/C00251168-Chess-Bot/src/main.cpp -o CMakeFiles/chess_bot.dir/src/main.cpp.s

CMakeFiles/chess_bot.dir/src/makeMove.cpp.obj: CMakeFiles/chess_bot.dir/flags.make
CMakeFiles/chess_bot.dir/src/makeMove.cpp.obj: CMakeFiles/chess_bot.dir/includes_CXX.rsp
CMakeFiles/chess_bot.dir/src/makeMove.cpp.obj: C:/College/Year4/Project/C00251168-Chess-Bot/src/makeMove.cpp
CMakeFiles/chess_bot.dir/src/makeMove.cpp.obj: CMakeFiles/chess_bot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/College/Year4/Project/C00251168-Chess-Bot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/chess_bot.dir/src/makeMove.cpp.obj"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess_bot.dir/src/makeMove.cpp.obj -MF CMakeFiles/chess_bot.dir/src/makeMove.cpp.obj.d -o CMakeFiles/chess_bot.dir/src/makeMove.cpp.obj -c C:/College/Year4/Project/C00251168-Chess-Bot/src/makeMove.cpp

CMakeFiles/chess_bot.dir/src/makeMove.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess_bot.dir/src/makeMove.cpp.i"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/College/Year4/Project/C00251168-Chess-Bot/src/makeMove.cpp > CMakeFiles/chess_bot.dir/src/makeMove.cpp.i

CMakeFiles/chess_bot.dir/src/makeMove.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess_bot.dir/src/makeMove.cpp.s"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/College/Year4/Project/C00251168-Chess-Bot/src/makeMove.cpp -o CMakeFiles/chess_bot.dir/src/makeMove.cpp.s

CMakeFiles/chess_bot.dir/src/move.cpp.obj: CMakeFiles/chess_bot.dir/flags.make
CMakeFiles/chess_bot.dir/src/move.cpp.obj: CMakeFiles/chess_bot.dir/includes_CXX.rsp
CMakeFiles/chess_bot.dir/src/move.cpp.obj: C:/College/Year4/Project/C00251168-Chess-Bot/src/move.cpp
CMakeFiles/chess_bot.dir/src/move.cpp.obj: CMakeFiles/chess_bot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/College/Year4/Project/C00251168-Chess-Bot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/chess_bot.dir/src/move.cpp.obj"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess_bot.dir/src/move.cpp.obj -MF CMakeFiles/chess_bot.dir/src/move.cpp.obj.d -o CMakeFiles/chess_bot.dir/src/move.cpp.obj -c C:/College/Year4/Project/C00251168-Chess-Bot/src/move.cpp

CMakeFiles/chess_bot.dir/src/move.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess_bot.dir/src/move.cpp.i"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/College/Year4/Project/C00251168-Chess-Bot/src/move.cpp > CMakeFiles/chess_bot.dir/src/move.cpp.i

CMakeFiles/chess_bot.dir/src/move.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess_bot.dir/src/move.cpp.s"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/College/Year4/Project/C00251168-Chess-Bot/src/move.cpp -o CMakeFiles/chess_bot.dir/src/move.cpp.s

CMakeFiles/chess_bot.dir/src/moveGeneration.cpp.obj: CMakeFiles/chess_bot.dir/flags.make
CMakeFiles/chess_bot.dir/src/moveGeneration.cpp.obj: CMakeFiles/chess_bot.dir/includes_CXX.rsp
CMakeFiles/chess_bot.dir/src/moveGeneration.cpp.obj: C:/College/Year4/Project/C00251168-Chess-Bot/src/moveGeneration.cpp
CMakeFiles/chess_bot.dir/src/moveGeneration.cpp.obj: CMakeFiles/chess_bot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/College/Year4/Project/C00251168-Chess-Bot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/chess_bot.dir/src/moveGeneration.cpp.obj"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess_bot.dir/src/moveGeneration.cpp.obj -MF CMakeFiles/chess_bot.dir/src/moveGeneration.cpp.obj.d -o CMakeFiles/chess_bot.dir/src/moveGeneration.cpp.obj -c C:/College/Year4/Project/C00251168-Chess-Bot/src/moveGeneration.cpp

CMakeFiles/chess_bot.dir/src/moveGeneration.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess_bot.dir/src/moveGeneration.cpp.i"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/College/Year4/Project/C00251168-Chess-Bot/src/moveGeneration.cpp > CMakeFiles/chess_bot.dir/src/moveGeneration.cpp.i

CMakeFiles/chess_bot.dir/src/moveGeneration.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess_bot.dir/src/moveGeneration.cpp.s"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/College/Year4/Project/C00251168-Chess-Bot/src/moveGeneration.cpp -o CMakeFiles/chess_bot.dir/src/moveGeneration.cpp.s

CMakeFiles/chess_bot.dir/src/moveValidation.cpp.obj: CMakeFiles/chess_bot.dir/flags.make
CMakeFiles/chess_bot.dir/src/moveValidation.cpp.obj: CMakeFiles/chess_bot.dir/includes_CXX.rsp
CMakeFiles/chess_bot.dir/src/moveValidation.cpp.obj: C:/College/Year4/Project/C00251168-Chess-Bot/src/moveValidation.cpp
CMakeFiles/chess_bot.dir/src/moveValidation.cpp.obj: CMakeFiles/chess_bot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/College/Year4/Project/C00251168-Chess-Bot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/chess_bot.dir/src/moveValidation.cpp.obj"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess_bot.dir/src/moveValidation.cpp.obj -MF CMakeFiles/chess_bot.dir/src/moveValidation.cpp.obj.d -o CMakeFiles/chess_bot.dir/src/moveValidation.cpp.obj -c C:/College/Year4/Project/C00251168-Chess-Bot/src/moveValidation.cpp

CMakeFiles/chess_bot.dir/src/moveValidation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess_bot.dir/src/moveValidation.cpp.i"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/College/Year4/Project/C00251168-Chess-Bot/src/moveValidation.cpp > CMakeFiles/chess_bot.dir/src/moveValidation.cpp.i

CMakeFiles/chess_bot.dir/src/moveValidation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess_bot.dir/src/moveValidation.cpp.s"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/College/Year4/Project/C00251168-Chess-Bot/src/moveValidation.cpp -o CMakeFiles/chess_bot.dir/src/moveValidation.cpp.s

CMakeFiles/chess_bot.dir/src/search.cpp.obj: CMakeFiles/chess_bot.dir/flags.make
CMakeFiles/chess_bot.dir/src/search.cpp.obj: CMakeFiles/chess_bot.dir/includes_CXX.rsp
CMakeFiles/chess_bot.dir/src/search.cpp.obj: C:/College/Year4/Project/C00251168-Chess-Bot/src/search.cpp
CMakeFiles/chess_bot.dir/src/search.cpp.obj: CMakeFiles/chess_bot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/College/Year4/Project/C00251168-Chess-Bot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/chess_bot.dir/src/search.cpp.obj"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess_bot.dir/src/search.cpp.obj -MF CMakeFiles/chess_bot.dir/src/search.cpp.obj.d -o CMakeFiles/chess_bot.dir/src/search.cpp.obj -c C:/College/Year4/Project/C00251168-Chess-Bot/src/search.cpp

CMakeFiles/chess_bot.dir/src/search.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess_bot.dir/src/search.cpp.i"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/College/Year4/Project/C00251168-Chess-Bot/src/search.cpp > CMakeFiles/chess_bot.dir/src/search.cpp.i

CMakeFiles/chess_bot.dir/src/search.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess_bot.dir/src/search.cpp.s"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/College/Year4/Project/C00251168-Chess-Bot/src/search.cpp -o CMakeFiles/chess_bot.dir/src/search.cpp.s

CMakeFiles/chess_bot.dir/src/uciConversion.cpp.obj: CMakeFiles/chess_bot.dir/flags.make
CMakeFiles/chess_bot.dir/src/uciConversion.cpp.obj: CMakeFiles/chess_bot.dir/includes_CXX.rsp
CMakeFiles/chess_bot.dir/src/uciConversion.cpp.obj: C:/College/Year4/Project/C00251168-Chess-Bot/src/uciConversion.cpp
CMakeFiles/chess_bot.dir/src/uciConversion.cpp.obj: CMakeFiles/chess_bot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/College/Year4/Project/C00251168-Chess-Bot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/chess_bot.dir/src/uciConversion.cpp.obj"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess_bot.dir/src/uciConversion.cpp.obj -MF CMakeFiles/chess_bot.dir/src/uciConversion.cpp.obj.d -o CMakeFiles/chess_bot.dir/src/uciConversion.cpp.obj -c C:/College/Year4/Project/C00251168-Chess-Bot/src/uciConversion.cpp

CMakeFiles/chess_bot.dir/src/uciConversion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess_bot.dir/src/uciConversion.cpp.i"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/College/Year4/Project/C00251168-Chess-Bot/src/uciConversion.cpp > CMakeFiles/chess_bot.dir/src/uciConversion.cpp.i

CMakeFiles/chess_bot.dir/src/uciConversion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess_bot.dir/src/uciConversion.cpp.s"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/College/Year4/Project/C00251168-Chess-Bot/src/uciConversion.cpp -o CMakeFiles/chess_bot.dir/src/uciConversion.cpp.s

CMakeFiles/chess_bot.dir/src/undoMove.cpp.obj: CMakeFiles/chess_bot.dir/flags.make
CMakeFiles/chess_bot.dir/src/undoMove.cpp.obj: CMakeFiles/chess_bot.dir/includes_CXX.rsp
CMakeFiles/chess_bot.dir/src/undoMove.cpp.obj: C:/College/Year4/Project/C00251168-Chess-Bot/src/undoMove.cpp
CMakeFiles/chess_bot.dir/src/undoMove.cpp.obj: CMakeFiles/chess_bot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/College/Year4/Project/C00251168-Chess-Bot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/chess_bot.dir/src/undoMove.cpp.obj"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess_bot.dir/src/undoMove.cpp.obj -MF CMakeFiles/chess_bot.dir/src/undoMove.cpp.obj.d -o CMakeFiles/chess_bot.dir/src/undoMove.cpp.obj -c C:/College/Year4/Project/C00251168-Chess-Bot/src/undoMove.cpp

CMakeFiles/chess_bot.dir/src/undoMove.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess_bot.dir/src/undoMove.cpp.i"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/College/Year4/Project/C00251168-Chess-Bot/src/undoMove.cpp > CMakeFiles/chess_bot.dir/src/undoMove.cpp.i

CMakeFiles/chess_bot.dir/src/undoMove.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess_bot.dir/src/undoMove.cpp.s"
	C:/TDM-GCC-32/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/College/Year4/Project/C00251168-Chess-Bot/src/undoMove.cpp -o CMakeFiles/chess_bot.dir/src/undoMove.cpp.s

# Object files for target chess_bot
chess_bot_OBJECTS = \
"CMakeFiles/chess_bot.dir/src/board.cpp.obj" \
"CMakeFiles/chess_bot.dir/src/evaluation.cpp.obj" \
"CMakeFiles/chess_bot.dir/src/main.cpp.obj" \
"CMakeFiles/chess_bot.dir/src/makeMove.cpp.obj" \
"CMakeFiles/chess_bot.dir/src/move.cpp.obj" \
"CMakeFiles/chess_bot.dir/src/moveGeneration.cpp.obj" \
"CMakeFiles/chess_bot.dir/src/moveValidation.cpp.obj" \
"CMakeFiles/chess_bot.dir/src/search.cpp.obj" \
"CMakeFiles/chess_bot.dir/src/uciConversion.cpp.obj" \
"CMakeFiles/chess_bot.dir/src/undoMove.cpp.obj"

# External object files for target chess_bot
chess_bot_EXTERNAL_OBJECTS =

C:/College/Year4/Project/C00251168-Chess-Bot/chess_bot.exe: CMakeFiles/chess_bot.dir/src/board.cpp.obj
C:/College/Year4/Project/C00251168-Chess-Bot/chess_bot.exe: CMakeFiles/chess_bot.dir/src/evaluation.cpp.obj
C:/College/Year4/Project/C00251168-Chess-Bot/chess_bot.exe: CMakeFiles/chess_bot.dir/src/main.cpp.obj
C:/College/Year4/Project/C00251168-Chess-Bot/chess_bot.exe: CMakeFiles/chess_bot.dir/src/makeMove.cpp.obj
C:/College/Year4/Project/C00251168-Chess-Bot/chess_bot.exe: CMakeFiles/chess_bot.dir/src/move.cpp.obj
C:/College/Year4/Project/C00251168-Chess-Bot/chess_bot.exe: CMakeFiles/chess_bot.dir/src/moveGeneration.cpp.obj
C:/College/Year4/Project/C00251168-Chess-Bot/chess_bot.exe: CMakeFiles/chess_bot.dir/src/moveValidation.cpp.obj
C:/College/Year4/Project/C00251168-Chess-Bot/chess_bot.exe: CMakeFiles/chess_bot.dir/src/search.cpp.obj
C:/College/Year4/Project/C00251168-Chess-Bot/chess_bot.exe: CMakeFiles/chess_bot.dir/src/uciConversion.cpp.obj
C:/College/Year4/Project/C00251168-Chess-Bot/chess_bot.exe: CMakeFiles/chess_bot.dir/src/undoMove.cpp.obj
C:/College/Year4/Project/C00251168-Chess-Bot/chess_bot.exe: CMakeFiles/chess_bot.dir/build.make
C:/College/Year4/Project/C00251168-Chess-Bot/chess_bot.exe: CMakeFiles/chess_bot.dir/linkLibs.rsp
C:/College/Year4/Project/C00251168-Chess-Bot/chess_bot.exe: CMakeFiles/chess_bot.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:/College/Year4/Project/C00251168-Chess-Bot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable C:/College/Year4/Project/C00251168-Chess-Bot/chess_bot.exe"
	"C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/chess_bot.dir/objects.a
	C:/TDM-GCC-32/bin/ar.exe qc CMakeFiles/chess_bot.dir/objects.a @CMakeFiles/chess_bot.dir/objects1.rsp
	C:/TDM-GCC-32/bin/c++.exe -Wl,--whole-archive CMakeFiles/chess_bot.dir/objects.a -Wl,--no-whole-archive -o C:/College/Year4/Project/C00251168-Chess-Bot/chess_bot.exe -Wl,--out-implib,libchess_bot.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/chess_bot.dir/linkLibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/chess_bot.dir/build: C:/College/Year4/Project/C00251168-Chess-Bot/chess_bot.exe
.PHONY : CMakeFiles/chess_bot.dir/build

CMakeFiles/chess_bot.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chess_bot.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chess_bot.dir/clean

CMakeFiles/chess_bot.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/College/Year4/Project/C00251168-Chess-Bot C:/College/Year4/Project/C00251168-Chess-Bot C:/College/Year4/Project/C00251168-Chess-Bot/build C:/College/Year4/Project/C00251168-Chess-Bot/build C:/College/Year4/Project/C00251168-Chess-Bot/build/CMakeFiles/chess_bot.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/chess_bot.dir/depend

