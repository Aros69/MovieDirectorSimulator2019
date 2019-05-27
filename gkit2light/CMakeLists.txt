cmake_minimum_required(VERSION 3.7)
project(MovieDirectorSimulator2019)
set(CMAKE_DIR "CMake")

include(${CMAKE_DIR}/cmakeConfiguration.cmake)

include_directories(${PROJECT_SOURCE_DIR}/gKit)
include_directories(${PROJECT_SOURCE_DIR}/MovieDirectorSimulator2019/Anim)

message(STATUS ${PROJECT_SOURCE_DIR})

# Create the list of src files for gkit
# Not reccomended practice by cmake developer because you must reload cmake when new files added
file(GLOB_RECURSE GKIT_SRC_FILES
        "${PROJECT_SOURCE_DIR}/gKit/*")
file(GLOB_RECURSE MDS2019_SRC_FILES
        "${PROJECT_SOURCE_DIR}/MovieDirectorSimulator2019/*")

include(${CMAKE_DIR}/addDependencies.cmake)

# Create execute file
add_executable(MDS2019.exe
        ${GKIT_SRC_FILES}
        ${MDS2019_SRC_FILES})

# Link SDL2, OpenGL and GLEW
target_link_libraries(MDS2019.exe
        ${SDL2_LIBRARIES}
        ${SDL2_IMG_LIBRARIES}
        ${GLEW_LIBRARIES}
        ${OPENGL_LIBRARIES})




