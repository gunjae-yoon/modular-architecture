set(CMAKE_TARGET_NAME "march")

add_library(${CMAKE_TARGET_NAME} SHARED
	src/cpp/march/base/module.cpp
)

target_include_directories(${CMAKE_TARGET_NAME} PRIVATE
	include
	src/cpp
)

install(
	DIRECTORY ${PROJECT_SOURCE_DIR}/include
	DESTINATION ${CMAKE_INSTALL_PREFIX}
)

install(
	FILES ${PROJECT_BINARY_DIR}/lib${CMAKE_TARGET_NAME}.so
	DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
)
