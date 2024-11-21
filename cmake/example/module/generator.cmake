set(CMAKE_TARGET_NAME "march_module_generator")
set(EXAMPLE_BASE_DIRECTORY "${CMAKE_SOURCE_DIR}/example/cpp/module/generator")

add_library(${CMAKE_TARGET_NAME} SHARED
	${EXAMPLE_BASE_DIRECTORY}/generator.cpp
)

target_include_directories(${CMAKE_TARGET_NAME} PRIVATE
	include
)

target_link_libraries(${CMAKE_TARGET_NAME}
	march
	march_data_strings
	march_data_integers
)

install(
	FILES ${EXAMPLE_BASE_DIRECTORY}/generator.h
	DESTINATION ${CMAKE_INSTALL_PREFIX}/include/march/module/impl
)

install(
	FILES ${PROJECT_BINARY_DIR}/lib${CMAKE_TARGET_NAME}.so
	DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
)
