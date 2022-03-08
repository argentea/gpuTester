set(TARGET_NAME fadynamicParall)
file(GLOB SOURCES
        *.cpp
		*.cu
        *.c)

set(FADPDIR "${CMAKE_CURRENT_LIST_DIR}"
    CACHE PATH "flat array dynamicParall directory")

add_library(${TARGET_NAME} STATIC ${SOURCES})
target_include_directories(${TARGET_NAME} PUBLIC ${FACONTROLLERDIR} ${FADATABASEDIR})
target_link_libraries(${TARGET_NAME} facontroller faDatabase)

set_property(TARGET ${TARGET_NAME} PROPERTY CUDA_SEPARABLE_COMPILATION ON)
