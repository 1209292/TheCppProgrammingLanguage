#include <iostream>
#include <complex>
#include <vector>
#include <sstream>

using namespace std;

extern void structDemo();

double sum(const vector<double>&);

void complexInCpp();

void InitializationResolvedAtCompileTime();

void fAndConstExpr();
constexpr double square(double x) { return x*x; } // evaluated at compile time

class Vector {
    public:
        Vector(int s){
            if(s == -1){
                std::stringstream ss;
                ss << s;
                throw std::length_error{"Unable to construct Vector of length " + ss.str()};
            }
            elem = new double[s];
            sz = s;
        }
        double& operator[](int i) {  // element access: subscripting
            if(i < 0 || i >= size()){
                std::stringstream ss;
                ss << i;
                throw std::out_of_range("Index " + ss.str() + " is out of range");
            }
            return elem[i];
        }

        int size() { return sz; }
    private:
        double* elem; // pointer to the elements
        int sz; // the number of elements
};

double read_and_sum(int s)
{
    Vector v(s); // make a vector of s elements
    for (int i=0; i!=v.size(); ++i)
        cin>>v[i]; // read into elements
    double sum = 0;
    for (int i=0; i!=v.size(); ++i)
        sum+=v[i]; // take the sum of the elements
    return sum;
}

enum class Color { red, blue, green };
enum class Traffic_light { green, yellow, red , };

Traffic_light& operator++(Traffic_light& t) // prefix increment: ++
{
    switch (t) {
    case Traffic_light::green: return t=Traffic_light::yellow;
    case Traffic_light::yellow: return t=Traffic_light::red;
    case Traffic_light::red: return t=Traffic_light::green;
    }
}

namespace mySpace{
double read_and_sum(int s);
}
double mySpace::read_and_sum(int s){
    double result = 0;
    for(int i = 0; i < s; i++){
        double temp = 0;
        cin >> temp;
        result += temp;
    }
    return result;
}

enum PlainEnum { red, blue, green };

int main()
{
    // complex

    complexInCpp();

    // resolve Initialization at compile time

    InitializationResolvedAtCompileTime();

    // const and constexp

    //constAndConstExpr();

    /**** 2.3 User Defined Types ***/

    /*** 2.3.1 Structures ***/

    structDemo();

    /*** 2.3.2 Classes ***/

    int x = 5;
//    read_and_sum(x); // reads x number from user and sum them

    Vector v(5);
    v[0] = 55; // how does this one works? //TOKNOW

    /*** 2.3.3 Enumerations ***/

    Color col = Color::red;
    Traffic_light light = Traffic_light::red;

//    Color x = red; // error : which red?
//    Color y = Traffic_light::red; // error : that red is not a Color
    Color z = Color::red; // OK
//    int i = Color::red; // error : Color ::red is not an int
//    Color c = 2; // error : 2 is not a Color

    Traffic_light tl = Traffic_light::red;
    ++tl; // for this to work, you must implement the operator++() yourself
//    t++; // error

    PlainEnum cc = red;
//    PlainEnum ccc = 2; // error : no int->PlainEnum conversion
    int num = PlainEnum::red; // OK : PlainEnum->int conversion

    /*** Namespaces 2.4.2 ***/

//    read_and_sum(5); // this function is in the global namespace
//    double sum = mySpace::read_and_sum(5); // this function is in mySpace

    /*** 2.4.3 Error Handling ***/

    /*** 2.4.3.1 Exceptions ***/
    try {
        Vector vv(5);
        vv[10] = 5;
    } catch (std::length_error e) {
        cout << e.what() << endl;
    } catch (std::out_of_range e){
        cout << e.what() << endl;
    } catch (std::bad_alloc e){
        // if the 'new' can't find memory to allocate, it throws this exception
    }

    /***  2.4.3.3 Static Assert ***/

    // static_assert report error at compile-time
    static_assert (4 <= sizeof(int), "Integers are too small");
    const int a = 5;
    //static_assert (a == 4, "Not right");
    return 0;
}

double sum(const vector<double>&){

}


void complexInCpp()
{

    //  complex

    double d1 = 2.3;
    double d2 {2.3};
    complex<double> z = 1; // a complex number with double-precision floating-point scalars
    complex<double> z2 {d1,d2};
    complex<double> z3 = {1,2}; // the = is optional with { ... }
}

void InitializationResolvedAtCompileTime(){

    /*
     *  resolve Initialization at compile time
    */

    int i1 = 7.2; // i1 becomes 7
//    int i2 {7.2}; // error : floating-point to integer conversion
//    int i3 = {7.2}; // error : floating-point to integer conversion (the = is redundant)

}

void constAndConstExpr(){

    const int dmv = 17; // dmv is a named constant
    int var = 17; // var is not a constant
    constexpr double max1 = 1.4 * square(dmv); // OK if square(17) is a constant expression
//    constexpr double max2 = 1.4 * square(var); // error : var is not a constant expression
    const double max3 = 1.4 * square(var); // OK, may be evaluated at run time

    vector<double> vec {1.2, 3.4, 4.5}; // v is not a constant
    const double s1 = sum(vec); // OK: evaluated at run time
//    constexpr double s2 = sum(v); // error : sum(v) not constant expression

}
