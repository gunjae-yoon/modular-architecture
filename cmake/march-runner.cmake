set(CMAKE_TARGET_NAME "march-runner")

add_executable(${CMAKE_TARGET_NAME}
	src/cpp/app/march_runner.cpp
)

target_include_directories(${CMAKE_TARGET_NAME} PRIVATE
	include
	src/cpp
)

target_link_libraries(${CMAKE_TARGET_NAME} PRIVATE
	march
	dl
	pthread
	march_data_strings
	march_data_integers
)
