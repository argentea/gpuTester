set(TARGET_NAME faDatabase)
file(GLOB SOURCES
        *.cpp
		*.cu
        *.c)

set(FADATABASEDIR "${CMAKE_CURRENT_LIST_DIR}"
    CACHE PATH "flat array database directory")

add_library(${TARGET_NAME} STATIC ${SOURCES})
target_include_directories(${TARGET_NAME} PUBLIC ${FACONTROLLERDIR})
target_link_libraries(${TARGET_NAME} ${FACONTROLLER})
