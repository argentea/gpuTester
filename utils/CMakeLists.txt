set(TARGET_NAME utils)
file(GLOB SOURCES
        *.cpp
        *.c)

set(UTILSDIR "${CMAKE_CURRENT_LIST_DIR}"
    CACHE PATH "utils directory")

add_library(${TARGET_NAME} STATIC ${SOURCES})
