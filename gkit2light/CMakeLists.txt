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
        ${MDS2019_SRC_FILES} src/MovieDirectorSimulator2019/BasicDrawObject.cpp src/MovieDirectorSimulator2019/BasicDrawObject.h src/MovieDirectorSimulator2019/Ground.cpp src/MovieDirectorSimulator2019/Ground.h src/MovieDirectorSimulator2019/Anim/AIController.cpp src/MovieDirectorSimulator2019/Anim/AIController.h src/MovieDirectorSimulator2019/GameCharacter.cpp src/MovieDirectorSimulator2019/GameCharacter.h)

add_executable(shaderKit.exe
        src/shader_kit.cpp
        ${GKIT_SRC_FILES})

# Link SDL2, OpenGL and GLEW
target_link_libraries(MDS2019.exe
        ${SDL2_LIBRARIES}
        ${SDL2_IMG_LIBRARIES}
        ${GLEW_LIBRARIES}
        ${OPENGL_LIBRARIES}
        ${GLUT_LIBRARIES})

# Link SDL2, OpenGL and GLEW
target_link_libraries(shaderKit.exe
        ${SDL2_LIBRARIES}
        ${SDL2_IMG_LIBRARIES}
        ${GLEW_LIBRARIES}
        ${OPENGL_LIBRARIES})




