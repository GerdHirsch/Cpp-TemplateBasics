cmake_minimum_required(VERSION 3.12)

# project(DynamisationStaticPolymorphism)

# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


set(DYNAMIC_TARGET DynamicPolimorphy)

add_executable( ${DYNAMIC_TARGET} ${CMAKE_SOURCE_DIR}/DynamicVSStaticPolymorphism/src/DemoDynamicPolymorphism.cpp )
target_link_libraries(${DYNAMIC_TARGET} )

set(STATIC_TARGET StaticPolimorphy)

add_executable( ${STATIC_TARGET} ${CMAKE_SOURCE_DIR}/DynamicVSStaticPolymorphism/src/DemoStaticPolymorphism.cpp )
target_link_libraries(${STATIC_TARGET} )

set(DYNAMISED_TARGET DynamisedStaticPolimorphy)

add_executable( ${DYNAMISED_TARGET} ${CMAKE_SOURCE_DIR}/DynamicVSStaticPolymorphism/src/DemoDynamisedStaticPolymorphism.cpp )
target_link_libraries(${DYNAMISED_TARGET} )

set(DYNAMISED_BY_INHERITANCE_TARGET DynamisedStaticPolimorphyByInheritance)

add_executable( ${DYNAMISED_BY_INHERITANCE_TARGET} ${CMAKE_SOURCE_DIR}/DynamicVSStaticPolymorphism/src/DemoDynamisedStaticPolymorphismByInheritance.cpp )
target_link_libraries(${DYNAMISED_BY_INHERITANCE_TARGET} )
