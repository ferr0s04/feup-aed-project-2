cmake_minimum_required(VERSION 3.26)
project(Proj2_AED)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proj2_AED main.cpp
        src/Application.cpp
        src/Application.h
        src/Airport.cpp
        src/Airport.h
        src/Airline.cpp
        src/Airline.h
        src/Flight.cpp
        src/Flight.h
        src/Graph.cpp
        src/Graph.h
        src/Script.cpp
        src/Script.h
        src/DataHandler.cpp
        src/DataHandler.h)

find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "docs/output")
    if(NOT EXISTS "docs/output")
        file(MAKE_DIRECTORY "docs/output")
    endif()

    set(DOXYGEN_IN "docs/Doxyfile")
    set(DOXYGEN_OUT "Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)

    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY ""
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)