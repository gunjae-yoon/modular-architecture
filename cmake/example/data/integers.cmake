set(CMAKE_TARGET_NAME "march_data_integers")
set(EXAMPLE_BASE_DIRECTORY "${CMAKE_SOURCE_DIR}/example/cpp/data/integers")

add_library(${CMAKE_TARGET_NAME} SHARED
	${EXAMPLE_BASE_DIRECTORY}/integers.cpp
)

target_include_directories(${CMAKE_TARGET_NAME} PRIVATE
	include
)

target_link_libraries(${CMAKE_TARGET_NAME}
	march
)

install(
	FILES ${EXAMPLE_BASE_DIRECTORY}/integers.h
	DESTINATION ${CMAKE_INSTALL_PREFIX}/include/march/data/impl
)

install(
	FILES ${PROJECT_BINARY_DIR}/lib${CMAKE_TARGET_NAME}.so
	DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
)
