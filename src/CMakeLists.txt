target_sources(app PRIVATE
    ${SOURCE_DIR}/main.c)

target_compile_options(app PRIVATE -save-temps=obj)

set_target_properties(app PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${BINARY_DIR}")