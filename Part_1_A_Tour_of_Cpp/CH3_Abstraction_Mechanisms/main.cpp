#include "Vector.hpp"
#include "Vector_container.hpp"
#include "Complex.hpp"
#include "T_Vector.hpp"
#include "Circle.hpp"
#include "Smiley.hpp"
#include <iostream>
#include <string>
#include <memory>
#include <list>
#include <vector>

void f(complex z)
{
    complex a {2.3}; // construct {2.3,0.0} from 2.3
    complex b {1/a};
    complex c {a+z*complex{1,2.3}};
    // ...
    if (c != b)
        c = -(b/a)+2*b;
}

Vector operator+(const Vector& a, const Vector& b)
{
   if (a.size()!=b.size())
      throw "Vector_size_mismatch{}";
   Vector res(a.size());
   for (int i=0; i!=a.size(); ++i)
      res[i]=a[i]+b[i];
   return res;
}

Vector f()
{
   Vector x(1000);
   Vector y(1000);
   Vector z(1000);
   // ...
   z = x; // we get a copy
   y = std::move(x); // we get a move
   // ...
   return z; // we get a move
}

template<typename Container, typename Value>
Value sum(const Container& c, Value v)
{
   for (auto x : c)
      v+=x;
   return v;
}

void write(const T_Vector<std::string>& vs) // Vector of some strings
{
   for (int i = 0; i!=vs.size(); ++i)
      std::cout << vs[i] << '\n';
}

template<typename T>
class Less_than {
      const T val; // value to compare against
   public:
      Less_than(const T& v) :val(v) { }
      bool operator()(const T& x) const { return x<val; } // call operator
};

template<typename C, typename P>
int count(const C& c, P pred)
{
   int cnt = 0;
   for (const auto& x : c)
      if (pred(x))
         ++cnt;
   return cnt;
}

void f(const std::vector<int>& vec, const std::list<std::string>& lst, int x, const std::string& s)
{
   std::cout << "number of values less than " << x
   << ": " << count(vec,Less_than<int>{x})
   << '\n';
   std::cout << "number of values less than " << s
   << ": " << count(lst,Less_than<std::string>{s})
   << '\n';
}

template<class C, class Oper>
void for_all(C& c, Oper op) // assume that C is a container of pointers
{
   for (auto& x : c)
      op(*x); // pass op() a reference to each element pointed to
}

void user()
{
   std::vector<Shape*> v;
   Circle c(Point(5, 5), 5);
   Smiley s(Point(1, 4), 10);
   v.push_back(&c);
   v.push_back(&s);
   for_all(v,[](Shape& s){ s.draw(); }); // draw all
   for_all(v,[](Shape& s){ s.rotate(45); }); // rotate all 45 degree
}

template<typename T>
void g(T x)
{
   std::cout << x << " ";
}

void func() { } // do nothing

template<typename T, typename... Tail>
void func(T head, Tail... tail)
{
   g(head); // do something to head
   func(tail...); // tr y again with tail
}

int main(){
    /*** 3.2 Classes ***/
    /*** 3.2.1 Concrete Classes ***/
    /*** 3.2.1.1 An Arithmetic Classes ***/

//    complex x(1.1, 2.0);
//    complex y(1.1, 2.0);
//    x += y;
//    std::cout.precision(1);
//    std::cout << std::fixed << x.real() << " " << std::fixed << x.imag() << std::endl;

//    /***  ***/
//    Vector_container v(5);
//    Vector vec(5);
//    v.add(&vec);

//    /*** 3.3.1 Copying Containers ***/

    {
//        Vector original(5);
//        Vector copy = original; // Uses the copy constructor
//        Vector anotherCopy(5);
//        anotherCopy = original; // Uses the copy assignment
    }

    /*** 3.3.2 Moving Containers ***/

    {
       // 'return res' in 'Vector operator+(...) didn't do what the book explain
       // 'return z' in 'Vector f()' didn't do what the book explain
    }

    /*** 3.4.1 Parameterized Types ***/

    {
//      T_Vector<int> vc(200); // vector of 200 characters
//      T_Vector<std::string> vs(5); // vector of 5 strings
//      T_Vector<std::list<int>> vli(45); // vector of 45 lists of integers
//      vs[0] = "hello";
//      write(vs);
      // sum(vc, 1); // error
      // ISSUE: I Could implement the template in the header of the class, NOT the source
    }

    /*** 3.4.2 Function Templates ***/

   {
//      std::vector<int> vector = {1,2,3};
//      std::list<double> list = {1.0, 2.0, 3.0};
//      int a = sum(vector, 1);
//      double b = sum(list, 0.5);
//      std::cout << a << std::endl;
//      std::cout << b << std::endl;
   }

   /*** 3.4.3 Function Objects ***/
   {
//      Less_than<int> lti {42}; // lti(i) will compare i to 42 using < (i<42)
//      Less_than<std::string> lts {"Backus"}; // lts(s) will compare s to "Backus" using < (s<"Backus")
//      bool b1 = lti(50);
//      bool b2 = lts("A");
//      std::cout << b1 << std::endl;
//      std::cout << b2 << std::endl;

      std::vector<int> vec_int {1, 2, 3, 6, 7, 8};
      std::list<std::string> list_str {"Jehad", "Ahmed", "Alghamdi"};
      int c = 5;
      std::string str{"Yousef"};

      f(vec_int, list_str, c, str);

      user(); // similar to f(), but with lambda
   }

   /*** 3.4.4 Variadic Templates ***/
   {
//      std::cout << "first: ";
//      func(1,2.2,"hello");
//      std::cout << "\nsecond: ";
//      func(0.2,'c',"yuck!",0,1,2);
//      std::cout << "\n";
   }

   /*** 3.4.5 Aliases ***/
   {
      // Go back to this section
   }
}
