#ifndef VECTOR_CONTAINER_HPP
#define VECTOR_CONTAINER_HPP

#include "Container.hpp"
#include <iostream>

class Vector_container : public Container {
    private:
        Vector v;
        Vector* vv;
    public:
        Vector_container(int s) : v(s) { } // Vector of s elements
        ~Vector_container() {
            // Note that the member destructor (˜Vector()) is implicitly invoked by its class’s destructor (˜Vector_container()).
            std::cout << "Vector_container destructor" << std::endl;
            delete vv;
        }
        double& operator[](int i) { return v[i]; }
        int size() const { return v.size(); }
        void add(Vector* vv) { Vector_container::vv = vv; }
};

#endif // VECTOR_CONTAINER_HPP
