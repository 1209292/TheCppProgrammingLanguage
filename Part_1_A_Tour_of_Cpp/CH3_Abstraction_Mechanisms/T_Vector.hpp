#ifndef T_VECTOR_HPP
#define T_VECTOR_HPP

template<typename T>
class T_Vector
{
   public:
      T_Vector(int s){ // constructor: establish invariant, acquire resources
         if ( s < 0) throw "Negative_size{}";
         elem = new T[s];
         sz = s;
      }
      ~T_Vector()
      {
         delete[] elem;
      }

      T& operator[](int i)
      {
            if(i < 0 || size() <= i)
            {
               throw "Out of range";
            }
            elem[i] = i;
            return elem[i];
      }

      const T& operator[](int i) const
      {
            if(i < 0 || size() <= i)
            {
               throw "Out of range";
            }
            return elem[i];
      }

      int size() const { return sz; }

   private:
      T* elem; // elem points to an array of sz elements of type T
      int sz;


};

#endif // T_VECTOR_HPP
