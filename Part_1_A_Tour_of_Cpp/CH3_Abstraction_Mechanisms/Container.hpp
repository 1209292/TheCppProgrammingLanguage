#ifndef CONTAINER_HPP
#define CONTAINER_HPP

class Container {
    public:
        virtual double& operator[](int) = 0;
        virtual int size() const = 0;
        virtual ~Container() {}
};

#endif // CONTAINER_HPP
