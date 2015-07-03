#include "circle.hpp"
#include <cmath>

Circle::Circle()
  : radius_{0.0}
{}

Circle::Circle(double const radius)
  : radius_{radius}
{}

Circle::~Circle(){}

double Circle::radius() const {
  return radius_;
}

bool operator< (Circle const& p1, Circle const& p2) {
  return p1.radius() < p2.radius();
}
bool operator> (Circle const& p1, Circle const& p2) {
  return p1.radius() > p2.radius();
}
bool operator== (Circle const& p1, Circle const& p2) {
  return p1.radius() == p2.radius();
}
std::ostream& operator<<(std::ostream& os, Circle const& c) {
  os << "Circle{ \"radius\":" << c.radius() << " }";
     
  return os;
}