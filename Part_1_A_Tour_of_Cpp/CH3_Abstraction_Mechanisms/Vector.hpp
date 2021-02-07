#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

class Vector {
    private:
        double* elem;
        int sz;
    public:
        Vector(int s) :elem{new double[s]}, sz{s}
        {
            for (int i=0; i!=s; ++i) elem[i]=0;
        }

        ~Vector() { delete[] elem; std::cout << "Vector destructor" << std::endl;}
        Vector(const Vector& a) // copy constrsuctor
            :elem{new double[a.sz]}, // allocate space for elements
              sz{a.sz}
        {
            for (int i=0; i!=sz; ++i) // copy elements
                elem[i] = a.elem[i];
        }

        Vector& operator=(const Vector& a) // copy assignment
        {
            double* p = new double[a.sz];
            for (int i=0; i!=a.sz; ++i)
                p[i] = a.elem[i];
            delete[] elem; // delete old elements
            elem = p;
            sz = a.sz;
            return *this;
        }

        Vector(Vector&& a): // move constructor
           elem{a.elem}, // grap the elements' from a
           sz{a.sz}
        {
           std::cout << "move const." << std::endl;
           a.elem = nullptr; // now a has no elements
           a.sz;
        }

        Vector& operator=(Vector&& a){ // move assignment
           elem = {a.elem};
           sz = {a.sz};
           a.elem = nullptr;
           a.sz = 0;
           std::cout << "move oper." << std::endl;
        }
        double& operator[](int i) { return elem[i];}
        int size() const { return sz;}
};

#endif // VECTOR_HPP
