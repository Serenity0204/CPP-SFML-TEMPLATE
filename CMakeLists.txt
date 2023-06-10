cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(Project_Name)

#. . . . . . . . . . . . . . . . . . . .
include(GNUInstallDirs)
if(MSVC)
    add_compile_options(/W4)
    add_link_options(/W4)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
else()
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif()

# Set policies
cmake_policy(SET CMP0135 NEW)

# place binaries and libraries according to GNU standards
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})

if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()
#. . . . . . . . . . . . . . . . . . . .

# ------------------------------------
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

enable_testing()

# ------------------------------------

set(SFML_VERSION "2.5.1")

# Declare SFML as an external project
FetchContent_Declare(
  sfml
  URL https://www.sfml-dev.org/files/SFML-${SFML_VERSION}-sources.zip
)

# Build SFML as part of the project
FetchContent_MakeAvailable(sfml)

#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#   Grab all cpp files from includes folder
#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
set(INCLUDES_FOLDER includes)
FILE(GLOB_RECURSE SOURCE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}   "${INCLUDES_FOLDER}/*.cpp" )
#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

ADD_EXECUTABLE(my_test
    _tests/_test_files/my_test.cpp
    ${SOURCE_FILES}
)

target_compile_features(my_test PRIVATE cxx_std_11)  # Specify the C++11 standard explicitly

# Disable deprecated-declarations warning for library-related code
if (CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set_source_files_properties(<library_source_file.cpp> PROPERTIES COMPILE_FLAGS "-Wno-deprecated-declarations")
endif()

ADD_EXECUTABLE(main
    main.cpp
    ${SOURCE_FILES}
)

target_compile_features(main PRIVATE cxx_std_11)  # Specify the C++11 standard explicitly

TARGET_LINK_LIBRARIES(my_test gtest)
TARGET_LINK_LIBRARIES(main gtest)
TARGET_LINK_LIBRARIES(my_test sfml-graphics sfml-window sfml-system)
TARGET_LINK_LIBRARIES(main sfml-graphics sfml-window sfml-system)

## copy resources file to build
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
