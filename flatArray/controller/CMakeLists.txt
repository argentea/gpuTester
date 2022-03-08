set(TARGET_NAME facontroller)
file(GLOB SOURCES
        *.cpp
        *.c)

set(FACONTROLLERDIR "${CMAKE_CURRENT_LIST_DIR}"
    CACHE PATH "flat array controller directory")

add_library(${TARGET_NAME} STATIC ${SOURCES})

