# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/robin/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/183.5153.40/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/robin/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/183.5153.40/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/tuto1.exe.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tuto1.exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tuto1.exe.dir/flags.make

CMakeFiles/tuto1.exe.dir/src/gKit/app.cpp.o: CMakeFiles/tuto1.exe.dir/flags.make
CMakeFiles/tuto1.exe.dir/src/gKit/app.cpp.o: ../src/gKit/app.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tuto1.exe.dir/src/gKit/app.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tuto1.exe.dir/src/gKit/app.cpp.o -c /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/app.cpp

CMakeFiles/tuto1.exe.dir/src/gKit/app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tuto1.exe.dir/src/gKit/app.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/app.cpp > CMakeFiles/tuto1.exe.dir/src/gKit/app.cpp.i

CMakeFiles/tuto1.exe.dir/src/gKit/app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tuto1.exe.dir/src/gKit/app.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/app.cpp -o CMakeFiles/tuto1.exe.dir/src/gKit/app.cpp.s

CMakeFiles/tuto1.exe.dir/src/gKit/app_camera.cpp.o: CMakeFiles/tuto1.exe.dir/flags.make
CMakeFiles/tuto1.exe.dir/src/gKit/app_camera.cpp.o: ../src/gKit/app_camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tuto1.exe.dir/src/gKit/app_camera.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tuto1.exe.dir/src/gKit/app_camera.cpp.o -c /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/app_camera.cpp

CMakeFiles/tuto1.exe.dir/src/gKit/app_camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tuto1.exe.dir/src/gKit/app_camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/app_camera.cpp > CMakeFiles/tuto1.exe.dir/src/gKit/app_camera.cpp.i

CMakeFiles/tuto1.exe.dir/src/gKit/app_camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tuto1.exe.dir/src/gKit/app_camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/app_camera.cpp -o CMakeFiles/tuto1.exe.dir/src/gKit/app_camera.cpp.s

CMakeFiles/tuto1.exe.dir/src/gKit/app_time.cpp.o: CMakeFiles/tuto1.exe.dir/flags.make
CMakeFiles/tuto1.exe.dir/src/gKit/app_time.cpp.o: ../src/gKit/app_time.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tuto1.exe.dir/src/gKit/app_time.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tuto1.exe.dir/src/gKit/app_time.cpp.o -c /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/app_time.cpp

CMakeFiles/tuto1.exe.dir/src/gKit/app_time.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tuto1.exe.dir/src/gKit/app_time.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/app_time.cpp > CMakeFiles/tuto1.exe.dir/src/gKit/app_time.cpp.i

CMakeFiles/tuto1.exe.dir/src/gKit/app_time.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tuto1.exe.dir/src/gKit/app_time.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/app_time.cpp -o CMakeFiles/tuto1.exe.dir/src/gKit/app_time.cpp.s

CMakeFiles/tuto1.exe.dir/src/gKit/color.cpp.o: CMakeFiles/tuto1.exe.dir/flags.make
CMakeFiles/tuto1.exe.dir/src/gKit/color.cpp.o: ../src/gKit/color.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/tuto1.exe.dir/src/gKit/color.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tuto1.exe.dir/src/gKit/color.cpp.o -c /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/color.cpp

CMakeFiles/tuto1.exe.dir/src/gKit/color.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tuto1.exe.dir/src/gKit/color.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/color.cpp > CMakeFiles/tuto1.exe.dir/src/gKit/color.cpp.i

CMakeFiles/tuto1.exe.dir/src/gKit/color.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tuto1.exe.dir/src/gKit/color.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/color.cpp -o CMakeFiles/tuto1.exe.dir/src/gKit/color.cpp.s

CMakeFiles/tuto1.exe.dir/src/gKit/draw.cpp.o: CMakeFiles/tuto1.exe.dir/flags.make
CMakeFiles/tuto1.exe.dir/src/gKit/draw.cpp.o: ../src/gKit/draw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/tuto1.exe.dir/src/gKit/draw.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tuto1.exe.dir/src/gKit/draw.cpp.o -c /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/draw.cpp

CMakeFiles/tuto1.exe.dir/src/gKit/draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tuto1.exe.dir/src/gKit/draw.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/draw.cpp > CMakeFiles/tuto1.exe.dir/src/gKit/draw.cpp.i

CMakeFiles/tuto1.exe.dir/src/gKit/draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tuto1.exe.dir/src/gKit/draw.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/draw.cpp -o CMakeFiles/tuto1.exe.dir/src/gKit/draw.cpp.s

CMakeFiles/tuto1.exe.dir/src/gKit/gamepads.cpp.o: CMakeFiles/tuto1.exe.dir/flags.make
CMakeFiles/tuto1.exe.dir/src/gKit/gamepads.cpp.o: ../src/gKit/gamepads.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/tuto1.exe.dir/src/gKit/gamepads.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tuto1.exe.dir/src/gKit/gamepads.cpp.o -c /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/gamepads.cpp

CMakeFiles/tuto1.exe.dir/src/gKit/gamepads.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tuto1.exe.dir/src/gKit/gamepads.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/gamepads.cpp > CMakeFiles/tuto1.exe.dir/src/gKit/gamepads.cpp.i

CMakeFiles/tuto1.exe.dir/src/gKit/gamepads.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tuto1.exe.dir/src/gKit/gamepads.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/gamepads.cpp -o CMakeFiles/tuto1.exe.dir/src/gKit/gamepads.cpp.s

CMakeFiles/tuto1.exe.dir/src/gKit/image.cpp.o: CMakeFiles/tuto1.exe.dir/flags.make
CMakeFiles/tuto1.exe.dir/src/gKit/image.cpp.o: ../src/gKit/image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/tuto1.exe.dir/src/gKit/image.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tuto1.exe.dir/src/gKit/image.cpp.o -c /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/image.cpp

CMakeFiles/tuto1.exe.dir/src/gKit/image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tuto1.exe.dir/src/gKit/image.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/image.cpp > CMakeFiles/tuto1.exe.dir/src/gKit/image.cpp.i

CMakeFiles/tuto1.exe.dir/src/gKit/image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tuto1.exe.dir/src/gKit/image.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/image.cpp -o CMakeFiles/tuto1.exe.dir/src/gKit/image.cpp.s

CMakeFiles/tuto1.exe.dir/src/gKit/image_hdr.cpp.o: CMakeFiles/tuto1.exe.dir/flags.make
CMakeFiles/tuto1.exe.dir/src/gKit/image_hdr.cpp.o: ../src/gKit/image_hdr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/tuto1.exe.dir/src/gKit/image_hdr.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tuto1.exe.dir/src/gKit/image_hdr.cpp.o -c /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/image_hdr.cpp

CMakeFiles/tuto1.exe.dir/src/gKit/image_hdr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tuto1.exe.dir/src/gKit/image_hdr.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/image_hdr.cpp > CMakeFiles/tuto1.exe.dir/src/gKit/image_hdr.cpp.i

CMakeFiles/tuto1.exe.dir/src/gKit/image_hdr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tuto1.exe.dir/src/gKit/image_hdr.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/image_hdr.cpp -o CMakeFiles/tuto1.exe.dir/src/gKit/image_hdr.cpp.s

CMakeFiles/tuto1.exe.dir/src/gKit/image_io.cpp.o: CMakeFiles/tuto1.exe.dir/flags.make
CMakeFiles/tuto1.exe.dir/src/gKit/image_io.cpp.o: ../src/gKit/image_io.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/tuto1.exe.dir/src/gKit/image_io.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tuto1.exe.dir/src/gKit/image_io.cpp.o -c /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/image_io.cpp

CMakeFiles/tuto1.exe.dir/src/gKit/image_io.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tuto1.exe.dir/src/gKit/image_io.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/image_io.cpp > CMakeFiles/tuto1.exe.dir/src/gKit/image_io.cpp.i

CMakeFiles/tuto1.exe.dir/src/gKit/image_io.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tuto1.exe.dir/src/gKit/image_io.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/image_io.cpp -o CMakeFiles/tuto1.exe.dir/src/gKit/image_io.cpp.s

CMakeFiles/tuto1.exe.dir/src/gKit/mat.cpp.o: CMakeFiles/tuto1.exe.dir/flags.make
CMakeFiles/tuto1.exe.dir/src/gKit/mat.cpp.o: ../src/gKit/mat.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/tuto1.exe.dir/src/gKit/mat.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tuto1.exe.dir/src/gKit/mat.cpp.o -c /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/mat.cpp

CMakeFiles/tuto1.exe.dir/src/gKit/mat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tuto1.exe.dir/src/gKit/mat.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/mat.cpp > CMakeFiles/tuto1.exe.dir/src/gKit/mat.cpp.i

CMakeFiles/tuto1.exe.dir/src/gKit/mat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tuto1.exe.dir/src/gKit/mat.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/mat.cpp -o CMakeFiles/tuto1.exe.dir/src/gKit/mat.cpp.s

CMakeFiles/tuto1.exe.dir/src/gKit/mesh.cpp.o: CMakeFiles/tuto1.exe.dir/flags.make
CMakeFiles/tuto1.exe.dir/src/gKit/mesh.cpp.o: ../src/gKit/mesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/tuto1.exe.dir/src/gKit/mesh.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tuto1.exe.dir/src/gKit/mesh.cpp.o -c /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/mesh.cpp

CMakeFiles/tuto1.exe.dir/src/gKit/mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tuto1.exe.dir/src/gKit/mesh.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/mesh.cpp > CMakeFiles/tuto1.exe.dir/src/gKit/mesh.cpp.i

CMakeFiles/tuto1.exe.dir/src/gKit/mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tuto1.exe.dir/src/gKit/mesh.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/mesh.cpp -o CMakeFiles/tuto1.exe.dir/src/gKit/mesh.cpp.s

CMakeFiles/tuto1.exe.dir/src/gKit/orbiter.cpp.o: CMakeFiles/tuto1.exe.dir/flags.make
CMakeFiles/tuto1.exe.dir/src/gKit/orbiter.cpp.o: ../src/gKit/orbiter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/tuto1.exe.dir/src/gKit/orbiter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tuto1.exe.dir/src/gKit/orbiter.cpp.o -c /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/orbiter.cpp

CMakeFiles/tuto1.exe.dir/src/gKit/orbiter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tuto1.exe.dir/src/gKit/orbiter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/orbiter.cpp > CMakeFiles/tuto1.exe.dir/src/gKit/orbiter.cpp.i

CMakeFiles/tuto1.exe.dir/src/gKit/orbiter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tuto1.exe.dir/src/gKit/orbiter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/orbiter.cpp -o CMakeFiles/tuto1.exe.dir/src/gKit/orbiter.cpp.s

CMakeFiles/tuto1.exe.dir/src/gKit/program.cpp.o: CMakeFiles/tuto1.exe.dir/flags.make
CMakeFiles/tuto1.exe.dir/src/gKit/program.cpp.o: ../src/gKit/program.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/tuto1.exe.dir/src/gKit/program.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tuto1.exe.dir/src/gKit/program.cpp.o -c /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/program.cpp

CMakeFiles/tuto1.exe.dir/src/gKit/program.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tuto1.exe.dir/src/gKit/program.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/program.cpp > CMakeFiles/tuto1.exe.dir/src/gKit/program.cpp.i

CMakeFiles/tuto1.exe.dir/src/gKit/program.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tuto1.exe.dir/src/gKit/program.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/program.cpp -o CMakeFiles/tuto1.exe.dir/src/gKit/program.cpp.s

CMakeFiles/tuto1.exe.dir/src/gKit/rgbe.cpp.o: CMakeFiles/tuto1.exe.dir/flags.make
CMakeFiles/tuto1.exe.dir/src/gKit/rgbe.cpp.o: ../src/gKit/rgbe.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/tuto1.exe.dir/src/gKit/rgbe.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tuto1.exe.dir/src/gKit/rgbe.cpp.o -c /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/rgbe.cpp

CMakeFiles/tuto1.exe.dir/src/gKit/rgbe.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tuto1.exe.dir/src/gKit/rgbe.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/rgbe.cpp > CMakeFiles/tuto1.exe.dir/src/gKit/rgbe.cpp.i

CMakeFiles/tuto1.exe.dir/src/gKit/rgbe.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tuto1.exe.dir/src/gKit/rgbe.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/rgbe.cpp -o CMakeFiles/tuto1.exe.dir/src/gKit/rgbe.cpp.s

CMakeFiles/tuto1.exe.dir/src/gKit/text.cpp.o: CMakeFiles/tuto1.exe.dir/flags.make
CMakeFiles/tuto1.exe.dir/src/gKit/text.cpp.o: ../src/gKit/text.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/tuto1.exe.dir/src/gKit/text.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tuto1.exe.dir/src/gKit/text.cpp.o -c /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/text.cpp

CMakeFiles/tuto1.exe.dir/src/gKit/text.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tuto1.exe.dir/src/gKit/text.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/text.cpp > CMakeFiles/tuto1.exe.dir/src/gKit/text.cpp.i

CMakeFiles/tuto1.exe.dir/src/gKit/text.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tuto1.exe.dir/src/gKit/text.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/text.cpp -o CMakeFiles/tuto1.exe.dir/src/gKit/text.cpp.s

CMakeFiles/tuto1.exe.dir/src/gKit/texture.cpp.o: CMakeFiles/tuto1.exe.dir/flags.make
CMakeFiles/tuto1.exe.dir/src/gKit/texture.cpp.o: ../src/gKit/texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/tuto1.exe.dir/src/gKit/texture.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tuto1.exe.dir/src/gKit/texture.cpp.o -c /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/texture.cpp

CMakeFiles/tuto1.exe.dir/src/gKit/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tuto1.exe.dir/src/gKit/texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/texture.cpp > CMakeFiles/tuto1.exe.dir/src/gKit/texture.cpp.i

CMakeFiles/tuto1.exe.dir/src/gKit/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tuto1.exe.dir/src/gKit/texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/texture.cpp -o CMakeFiles/tuto1.exe.dir/src/gKit/texture.cpp.s

CMakeFiles/tuto1.exe.dir/src/gKit/uniforms.cpp.o: CMakeFiles/tuto1.exe.dir/flags.make
CMakeFiles/tuto1.exe.dir/src/gKit/uniforms.cpp.o: ../src/gKit/uniforms.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/tuto1.exe.dir/src/gKit/uniforms.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tuto1.exe.dir/src/gKit/uniforms.cpp.o -c /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/uniforms.cpp

CMakeFiles/tuto1.exe.dir/src/gKit/uniforms.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tuto1.exe.dir/src/gKit/uniforms.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/uniforms.cpp > CMakeFiles/tuto1.exe.dir/src/gKit/uniforms.cpp.i

CMakeFiles/tuto1.exe.dir/src/gKit/uniforms.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tuto1.exe.dir/src/gKit/uniforms.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/uniforms.cpp -o CMakeFiles/tuto1.exe.dir/src/gKit/uniforms.cpp.s

CMakeFiles/tuto1.exe.dir/src/gKit/vec.cpp.o: CMakeFiles/tuto1.exe.dir/flags.make
CMakeFiles/tuto1.exe.dir/src/gKit/vec.cpp.o: ../src/gKit/vec.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/tuto1.exe.dir/src/gKit/vec.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tuto1.exe.dir/src/gKit/vec.cpp.o -c /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/vec.cpp

CMakeFiles/tuto1.exe.dir/src/gKit/vec.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tuto1.exe.dir/src/gKit/vec.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/vec.cpp > CMakeFiles/tuto1.exe.dir/src/gKit/vec.cpp.i

CMakeFiles/tuto1.exe.dir/src/gKit/vec.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tuto1.exe.dir/src/gKit/vec.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/vec.cpp -o CMakeFiles/tuto1.exe.dir/src/gKit/vec.cpp.s

CMakeFiles/tuto1.exe.dir/src/gKit/wavefront.cpp.o: CMakeFiles/tuto1.exe.dir/flags.make
CMakeFiles/tuto1.exe.dir/src/gKit/wavefront.cpp.o: ../src/gKit/wavefront.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/tuto1.exe.dir/src/gKit/wavefront.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tuto1.exe.dir/src/gKit/wavefront.cpp.o -c /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/wavefront.cpp

CMakeFiles/tuto1.exe.dir/src/gKit/wavefront.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tuto1.exe.dir/src/gKit/wavefront.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/wavefront.cpp > CMakeFiles/tuto1.exe.dir/src/gKit/wavefront.cpp.i

CMakeFiles/tuto1.exe.dir/src/gKit/wavefront.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tuto1.exe.dir/src/gKit/wavefront.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/wavefront.cpp -o CMakeFiles/tuto1.exe.dir/src/gKit/wavefront.cpp.s

CMakeFiles/tuto1.exe.dir/src/gKit/widgets.cpp.o: CMakeFiles/tuto1.exe.dir/flags.make
CMakeFiles/tuto1.exe.dir/src/gKit/widgets.cpp.o: ../src/gKit/widgets.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building CXX object CMakeFiles/tuto1.exe.dir/src/gKit/widgets.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tuto1.exe.dir/src/gKit/widgets.cpp.o -c /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/widgets.cpp

CMakeFiles/tuto1.exe.dir/src/gKit/widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tuto1.exe.dir/src/gKit/widgets.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/widgets.cpp > CMakeFiles/tuto1.exe.dir/src/gKit/widgets.cpp.i

CMakeFiles/tuto1.exe.dir/src/gKit/widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tuto1.exe.dir/src/gKit/widgets.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/widgets.cpp -o CMakeFiles/tuto1.exe.dir/src/gKit/widgets.cpp.s

CMakeFiles/tuto1.exe.dir/src/gKit/window.cpp.o: CMakeFiles/tuto1.exe.dir/flags.make
CMakeFiles/tuto1.exe.dir/src/gKit/window.cpp.o: ../src/gKit/window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Building CXX object CMakeFiles/tuto1.exe.dir/src/gKit/window.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tuto1.exe.dir/src/gKit/window.cpp.o -c /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/window.cpp

CMakeFiles/tuto1.exe.dir/src/gKit/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tuto1.exe.dir/src/gKit/window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/window.cpp > CMakeFiles/tuto1.exe.dir/src/gKit/window.cpp.i

CMakeFiles/tuto1.exe.dir/src/gKit/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tuto1.exe.dir/src/gKit/window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/src/gKit/window.cpp -o CMakeFiles/tuto1.exe.dir/src/gKit/window.cpp.s

CMakeFiles/tuto1.exe.dir/tutos/tuto1.cpp.o: CMakeFiles/tuto1.exe.dir/flags.make
CMakeFiles/tuto1.exe.dir/tutos/tuto1.cpp.o: ../tutos/tuto1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_22) "Building CXX object CMakeFiles/tuto1.exe.dir/tutos/tuto1.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tuto1.exe.dir/tutos/tuto1.cpp.o -c /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/tutos/tuto1.cpp

CMakeFiles/tuto1.exe.dir/tutos/tuto1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tuto1.exe.dir/tutos/tuto1.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/tutos/tuto1.cpp > CMakeFiles/tuto1.exe.dir/tutos/tuto1.cpp.i

CMakeFiles/tuto1.exe.dir/tutos/tuto1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tuto1.exe.dir/tutos/tuto1.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/tutos/tuto1.cpp -o CMakeFiles/tuto1.exe.dir/tutos/tuto1.cpp.s

# Object files for target tuto1.exe
tuto1_exe_OBJECTS = \
"CMakeFiles/tuto1.exe.dir/src/gKit/app.cpp.o" \
"CMakeFiles/tuto1.exe.dir/src/gKit/app_camera.cpp.o" \
"CMakeFiles/tuto1.exe.dir/src/gKit/app_time.cpp.o" \
"CMakeFiles/tuto1.exe.dir/src/gKit/color.cpp.o" \
"CMakeFiles/tuto1.exe.dir/src/gKit/draw.cpp.o" \
"CMakeFiles/tuto1.exe.dir/src/gKit/gamepads.cpp.o" \
"CMakeFiles/tuto1.exe.dir/src/gKit/image.cpp.o" \
"CMakeFiles/tuto1.exe.dir/src/gKit/image_hdr.cpp.o" \
"CMakeFiles/tuto1.exe.dir/src/gKit/image_io.cpp.o" \
"CMakeFiles/tuto1.exe.dir/src/gKit/mat.cpp.o" \
"CMakeFiles/tuto1.exe.dir/src/gKit/mesh.cpp.o" \
"CMakeFiles/tuto1.exe.dir/src/gKit/orbiter.cpp.o" \
"CMakeFiles/tuto1.exe.dir/src/gKit/program.cpp.o" \
"CMakeFiles/tuto1.exe.dir/src/gKit/rgbe.cpp.o" \
"CMakeFiles/tuto1.exe.dir/src/gKit/text.cpp.o" \
"CMakeFiles/tuto1.exe.dir/src/gKit/texture.cpp.o" \
"CMakeFiles/tuto1.exe.dir/src/gKit/uniforms.cpp.o" \
"CMakeFiles/tuto1.exe.dir/src/gKit/vec.cpp.o" \
"CMakeFiles/tuto1.exe.dir/src/gKit/wavefront.cpp.o" \
"CMakeFiles/tuto1.exe.dir/src/gKit/widgets.cpp.o" \
"CMakeFiles/tuto1.exe.dir/src/gKit/window.cpp.o" \
"CMakeFiles/tuto1.exe.dir/tutos/tuto1.cpp.o"

# External object files for target tuto1.exe
tuto1_exe_EXTERNAL_OBJECTS =

bin/tuto1.exe: CMakeFiles/tuto1.exe.dir/src/gKit/app.cpp.o
bin/tuto1.exe: CMakeFiles/tuto1.exe.dir/src/gKit/app_camera.cpp.o
bin/tuto1.exe: CMakeFiles/tuto1.exe.dir/src/gKit/app_time.cpp.o
bin/tuto1.exe: CMakeFiles/tuto1.exe.dir/src/gKit/color.cpp.o
bin/tuto1.exe: CMakeFiles/tuto1.exe.dir/src/gKit/draw.cpp.o
bin/tuto1.exe: CMakeFiles/tuto1.exe.dir/src/gKit/gamepads.cpp.o
bin/tuto1.exe: CMakeFiles/tuto1.exe.dir/src/gKit/image.cpp.o
bin/tuto1.exe: CMakeFiles/tuto1.exe.dir/src/gKit/image_hdr.cpp.o
bin/tuto1.exe: CMakeFiles/tuto1.exe.dir/src/gKit/image_io.cpp.o
bin/tuto1.exe: CMakeFiles/tuto1.exe.dir/src/gKit/mat.cpp.o
bin/tuto1.exe: CMakeFiles/tuto1.exe.dir/src/gKit/mesh.cpp.o
bin/tuto1.exe: CMakeFiles/tuto1.exe.dir/src/gKit/orbiter.cpp.o
bin/tuto1.exe: CMakeFiles/tuto1.exe.dir/src/gKit/program.cpp.o
bin/tuto1.exe: CMakeFiles/tuto1.exe.dir/src/gKit/rgbe.cpp.o
bin/tuto1.exe: CMakeFiles/tuto1.exe.dir/src/gKit/text.cpp.o
bin/tuto1.exe: CMakeFiles/tuto1.exe.dir/src/gKit/texture.cpp.o
bin/tuto1.exe: CMakeFiles/tuto1.exe.dir/src/gKit/uniforms.cpp.o
bin/tuto1.exe: CMakeFiles/tuto1.exe.dir/src/gKit/vec.cpp.o
bin/tuto1.exe: CMakeFiles/tuto1.exe.dir/src/gKit/wavefront.cpp.o
bin/tuto1.exe: CMakeFiles/tuto1.exe.dir/src/gKit/widgets.cpp.o
bin/tuto1.exe: CMakeFiles/tuto1.exe.dir/src/gKit/window.cpp.o
bin/tuto1.exe: CMakeFiles/tuto1.exe.dir/tutos/tuto1.cpp.o
bin/tuto1.exe: CMakeFiles/tuto1.exe.dir/build.make
bin/tuto1.exe: /usr/lib/x86_64-linux-gnu/libGLEW.so
bin/tuto1.exe: /usr/lib/x86_64-linux-gnu/libOpenGL.so
bin/tuto1.exe: /usr/lib/x86_64-linux-gnu/libGLX.so
bin/tuto1.exe: /usr/lib/x86_64-linux-gnu/libGLU.so
bin/tuto1.exe: CMakeFiles/tuto1.exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_23) "Linking CXX executable bin/tuto1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tuto1.exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tuto1.exe.dir/build: bin/tuto1.exe

.PHONY : CMakeFiles/tuto1.exe.dir/build

CMakeFiles/tuto1.exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tuto1.exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tuto1.exe.dir/clean

CMakeFiles/tuto1.exe.dir/depend:
	cd /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/cmake-build-debug /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/cmake-build-debug /home/robin/Master/Mif27SynthImg/movie-director-simulator-2019/gkit2light/cmake-build-debug/CMakeFiles/tuto1.exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tuto1.exe.dir/depend

