#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

class Vector {
    private:
        double* elem;
        int sz;
    public:
        Vector(int s);
        ~Vector();

        Vector(const Vector& a); // copy constrsuctor
        Vector& operator=(const Vector& a); // copy assignment

        Vector(Vector&& a); // move constructor
        Vector& operator=(Vector&& a); // move assignment

        double& operator[](int i) const;
        int size() const;
};

#endif // VECTOR_HPP
