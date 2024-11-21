add_custom_target(data ALL
	DEPENDS march_data_integers march_data_strings
)

add_custom_target(module ALL
	DEPENDS march_module_generator march_module_reverser 
)
