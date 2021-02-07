#include "Vector.hpp"
#include "Vector_container.hpp"
#include "Complex.hpp"
#include <iostream>
#include <string>
#include <memory>

void f(complex z)
{
    complex a {2.3}; // construct {2.3,0.0} from 2.3
    complex b {1/a};
    complex c {a+z*complex{1,2.3}};
    // ...
    if (c != b)
        c = -(b/a)+2*b;
}

int main(){
    /*** 3.2 Classes ***/
    /*** 3.2.1 Concrete Classes ***/
    /*** 3.2.1.1 An Arithmetic Classes ***/

    complex x(1.1, 2.0);
    complex y(1.1, 2.0);
    x += y;
    std::cout.precision(1);
    std::cout << std::fixed << x.real() << " " << std::fixed << x.imag() << std::endl;

    /***  ***/
    Vector_container v(5);
    Vector vec(5);
    v.add(&vec);

    /*** 3.3.1 Copying Containers ***/

    {
        Vector original(5);
        Vector copy = original; // Uses the copy constructor
        Vector anotherCopy(5);
        anotherCopy = original; // Uses the copy assignment
    }
}
