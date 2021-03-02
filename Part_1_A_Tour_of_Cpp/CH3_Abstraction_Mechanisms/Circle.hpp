#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Shape.hpp"
#include "Point.hpp"
#include <iostream>

class Circle : public Shape {
   public:
      Circle(Point p, int rr): x{p}, r{rr}{}
      Point center() const { return x; }
      void move(Point to) { x=to; }
      void draw() const
      {
         std::cout << "Draw Circle" << "\n";
      }
      void rotate(int) { std::cout << "Rotate Circle" << "\n"; } // nice simple algorithm
      ~Circle(){}

   private:
      Point x; // center
      int r; // radius
};

#endif // CIRCLE_HPP
