﻿# CMakeList.txt : CMake project for 3.2-moduli, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("3.2-moduli")

# Add source to this project's executable.
add_executable (3.2-moduli "3.2-moduli.cpp" "3.2-moduli.h" "Vector.cpp")


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 3.2-moduli PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
