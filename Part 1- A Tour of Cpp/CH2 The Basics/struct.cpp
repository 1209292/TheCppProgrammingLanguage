#include <iostream>

using namespace std;

struct VectorStruct {
        int sz; // number of elements
        double* elem; // pointer to elements
};

void vector_init(VectorStruct& v, int s)
{
    v.elem = new double[s]; // allocate an array of s doubles
    v.sz = s;
}

double read_and_sum_struct(int s)
// read s integers from cin and return their sum; s is assumed to be positive
{
    VectorStruct v;
    vector_init(v,s); // allocate s elements for v
    for (int i=0; i!=s; ++i)
        cin>>v.elem[i]; // read into elements
    double sum = 0;
    for (int i=0; i!=s; ++i)
        sum+=v.elem[i]; // take the sum of the elements
    return sum;
}

void structDemo(){

}
