# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/Embedded2/Opdracht3_CGI_MQTT/sensor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/Embedded2/Opdracht3_CGI_MQTT/sensor/Build

# Include any dependencies generated for this target.
include CMakeFiles/env-cgi.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/env-cgi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/env-cgi.dir/flags.make

CMakeFiles/env-cgi.dir/main.c.o: CMakeFiles/env-cgi.dir/flags.make
CMakeFiles/env-cgi.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Embedded2/Opdracht3_CGI_MQTT/sensor/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/env-cgi.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/env-cgi.dir/main.c.o   -c /home/pi/Embedded2/Opdracht3_CGI_MQTT/sensor/main.c

CMakeFiles/env-cgi.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/env-cgi.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/Embedded2/Opdracht3_CGI_MQTT/sensor/main.c > CMakeFiles/env-cgi.dir/main.c.i

CMakeFiles/env-cgi.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/env-cgi.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/Embedded2/Opdracht3_CGI_MQTT/sensor/main.c -o CMakeFiles/env-cgi.dir/main.c.s

# Object files for target env-cgi
env__cgi_OBJECTS = \
"CMakeFiles/env-cgi.dir/main.c.o"

# External object files for target env-cgi
env__cgi_EXTERNAL_OBJECTS =

env-cgi: CMakeFiles/env-cgi.dir/main.c.o
env-cgi: CMakeFiles/env-cgi.dir/build.make
env-cgi: /usr/lib/libwiringPi.so
env-cgi: CMakeFiles/env-cgi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/Embedded2/Opdracht3_CGI_MQTT/sensor/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable env-cgi"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/env-cgi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/env-cgi.dir/build: env-cgi

.PHONY : CMakeFiles/env-cgi.dir/build

CMakeFiles/env-cgi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/env-cgi.dir/cmake_clean.cmake
.PHONY : CMakeFiles/env-cgi.dir/clean

CMakeFiles/env-cgi.dir/depend:
	cd /home/pi/Embedded2/Opdracht3_CGI_MQTT/sensor/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Embedded2/Opdracht3_CGI_MQTT/sensor /home/pi/Embedded2/Opdracht3_CGI_MQTT/sensor /home/pi/Embedded2/Opdracht3_CGI_MQTT/sensor/Build /home/pi/Embedded2/Opdracht3_CGI_MQTT/sensor/Build /home/pi/Embedded2/Opdracht3_CGI_MQTT/sensor/Build/CMakeFiles/env-cgi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/env-cgi.dir/depend
