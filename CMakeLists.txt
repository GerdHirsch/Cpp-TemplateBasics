cmake_minimum_required(VERSION 3.12)

project(TemplateBasics)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()

# Add subdirs
# add_subdirectory(ext/googletest)
# add_subdirectory(external)
add_subdirectory(DynamicVSStaticPolymorphism)
