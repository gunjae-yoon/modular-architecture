include (cmake/example/data/integers.cmake)
include (cmake/example/data/strings.cmake)
include (cmake/example/module/generator.cmake)
include (cmake/example/module/reverser.cmake)
include (cmake/example/module/printer.cmake)

add_custom_target(data ALL
	DEPENDS march_data_integers march_data_strings
)

add_custom_target(module ALL
	DEPENDS march_module_generator march_module_reverser march_module_printer
)
