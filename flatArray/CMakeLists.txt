project(flatArray CUDA CXX)

set(FADIR "${CMAKE_CURRENT_LIST_DIR}"
    CACHE PATH "flat array directory")

#
add_subdirectory(controller)
add_subdirectory(database)
add_subdirectory(dynamicParall)

# test
add_executable(${PROJECT_NAME}_test test.cpp)
target_include_directories(${PROJECT_NAME}_test PRIVATE ${FADATABASEDIR} ${FADPDIR})
target_link_libraries(${PROJECT_NAME}_test ${FACONTROLLER} ${FADATABASE} ${FADYNAMICPARALL})
