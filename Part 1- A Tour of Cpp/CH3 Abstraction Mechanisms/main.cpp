#include <iostream>
#include <string>
#include <memory>

class complex {
        double re, im; // representation: two doubles
    public:
        complex(double r, double i) :re{r}, im{i} {} // construct complex from two scalars
        complex(double r) :re{r}, im{0} {} // construct complex from one scalar
        complex() :re{0}, im{0} {} // default complex: {0,0}
        double real() const { return re; }
        void real(double d) { re=d; }
        double imag() const { return im; }
        void imag(double d) { im=d; }
        complex& operator+=(complex z) { re+=z.re; im+=z.im; return *this; } // add to re and im
        // and return the result
        complex& operator-=(complex z) { re-=z.re; im-=z.im; return *this; }
        complex& operator*=(complex z) { re*=z.re; im*=z.im; return *this; }
        complex& operator/=(complex z) { re/=z.re; im/=z.im; return *this; }
};

complex operator+(complex a, complex b) { return a+=b; }
complex operator-(complex a, complex b) { return a-=b; }
complex operator-(complex a) { return {-a.real(), -a.imag()}; } // unar y minus
complex operator*(complex a, complex b) { return a*=b; }
complex operator/(complex a, complex b) { return a/=b; }

bool operator==(complex a, complex b) // equal
{
    return a.real()==b.real() && a.imag()==b.imag();
}
bool operator!=(complex a, complex b) // not equal
{
    return !(a==b);
}



class Container {
    public:
        virtual double& operator[](int) = 0;
        virtual int size() const = 0;
        virtual ~Container() {}
};

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
            :elem{new double[sz]}, // allocate space for elements
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
        double& operator[](int i) { return elem[i];}
        int size() const { return sz;}
};

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
