set(CMAKE_TARGET_NAME "march-runner")

add_executable(${CMAKE_TARGET_NAME}
	src/cpp/app/march_runner.cpp
)

target_include_directories(${CMAKE_TARGET_NAME} PRIVATE
	src/cpp
)
