#ifndef COMPLEX_HPP
#define COMPLEX_HPP

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

#endif // COMPLEX_HPP
