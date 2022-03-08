cmake_minimum_required(VERSION 3.10)

project(gpuTester CUDA CXX)

set(default_build_type "Release")

set(CMAKE_DEBUG_TARGET_PROPERTIES
    INCLUDE_DIRECTORIES
    COMPILE_DEFINITIONS
    POSITION_INDEPENDENT_CODE
    CONTAINER_SIZE_REQUIRED
    LIB_VERSION
   )


if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
    set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE STRING "Choose the type of build." FORCE)
# Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
                 "Debug" "Release")
endif()

if(CMAKE_CONFIGURATION_TYPES)
	set(CMAKE_CONFIGURATION_TYPES Debug Release)
	set(CMAKE_CONFIGURATION_TYPES "${CMAKE_CONFIGURATION_TYPES}" CACHE STRING
		"Reset the configurations to what we need"
		FORCE)
endif()


set(CMAKE_CUDA_ARCHITECTURES "70")

message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -std=c++17 -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -std=c++17 -g -Wall")
set(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} -G -g -prec-div=true")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the output folder where your program will be created
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ferror-limit=1 -Wall -Wextra -Wno-sign-compare -pthread -std=c++17 -I/usr/local/cuda/include ")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmax-errors=1 -Wall -Wextra -Wno-sign-compare -pthread -std=c++17 -I/usr/local/cuda/include")
endif ()


add_subdirectory(utils)
add_subdirectory(flatArray)

add_executable(${PROJECT_NAME} ./main.cpp)


#target_include_directories(${PROJECT_NAME} SYSTEM PUBLIC ${FMM_DIR} ${FSM_DIR} ${FIM_DIR} ${SEGFIM_DIR} ${CUDA_INCLUDE_DIRS} ${GPUDATABASE_DIR} )
#target_link_libraries(${PROJECT_NAME} PUBLIC fmm fsm fim segfim ds)
#target_link_libraries(${PROJECT_NAME} PUBLIC fsmAxis dataBase)
