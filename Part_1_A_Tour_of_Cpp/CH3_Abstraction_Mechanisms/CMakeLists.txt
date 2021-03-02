project(AbstractionMechanisms LANGUAGES CXX)
add_executable(AbstractionMechanisms main.cpp
    Shape.hpp Point.hpp Circle.hpp Smiley.hpp
    Vector.hpp Vector.cpp Vector_container.hpp
    T_Vector.hpp T_Vector.cpp Complex.hpp)
