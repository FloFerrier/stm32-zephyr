cmake_minimum_required(VERSION 3.20.0)

set(BOARD nucleo_f446re)

find_package(Zephyr)
project(stm32-zephyr)

set(BINARY_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(SOURCE_DIR  ${CMAKE_SOURCE_DIR}/src)
set(TEST_DIR    ${CMAKE_CURRENT_SOURCE_DIR}/test)

message(INFO " CMAKE_BUILD_TYPE= ${CMAKE_BUILD_TYPE}")

if(CMAKE_BUILD_TYPE STREQUAL Debug)
	include_directories(${SOURCE_DIR})
	add_subdirectory(${SOURCE_DIR})
	message(INFO " Debug selected.")

elseif(CMAKE_BUILD_TYPE STREQUAL Release)
	include_directories(${SOURCE_DIR})
	add_subdirectory(${SOURCE_DIR})
	message(INFO " Release selected.")

elseif(CMAKE_BUILD_TYPE STREQUAL Test)
	include_directories(${TEST_DIR})
	add_subdirectory(${TEST_DIR})
	message(INFO " Test selected.")

else()
	message(ERROR " Specify CMAKE_BUILD_TYPE as Debug, Test or Release")

endif()