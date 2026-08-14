# Line for expressing minimum required version of CMake
cmake_minimum_required(VERSION 3.20)

# Naming the project
project(CppMathLib)

# Adding a Library target
# add_library(<name> <type> <files...>) → Al compilar obtendremos libmathlib.a
add_library(MathLib STATIC
            src/Vector2.cpp
            src/Vector3.cpp
)

# Adding directories to the library target to make the compiler get to the header files
# target_include_directories(
#            <library_name>
#            <SCOPE>
#            ${CMAKE_CURRENT_SOURCE_DIR}</directory>
#)
target_include_directories(MathLib PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Expressing the C++ version required for the library
#target_compile_features(
#        <target>
#        <scope>
#        <feature>
#)
target_compile_features(MathLib
        PUBLIC
        cxx_std_23)

# Adding executable for Vector2 demo
add_executable(Vector2_demo
        examples/Vector2_demo.cpp
)

# Linking the executable to the library for it to be able to use it
target_link_libraries(Vector2_demo
        PRIVATE
        MathLib)

# Adding executable for Vector3 demo
add_executable(Vector3_demo
        examples/Vector3_demo.cpp
)

# Linking the executable to the library for it to be able to use it
target_link_libraries(Vector3_demo
        PRIVATE
        MathLib)

