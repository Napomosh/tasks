project(hello_world)			

set(SOURCE_EXE Task1.cpp)

set(SOURCE_LIB functions.cpp)	

add_library(functions STATIC ${SOURCE_LIB})

add_executable(Task1 ${SOURCE_EXE})

target_link_libraries(Task1 functions)