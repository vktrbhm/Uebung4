#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <iostream>

class Circle
{
public:
  Circle();
  Circle(double const radius);
  ~Circle();

  double radius() const;
  

  friend bool operator<(Circle const& c1, Circle const& c2);
  friend bool operator>(Circle const& c1, Circle const& c2);
  friend bool operator==(Circle const& c1, Circle const& c2);
  friend std::ostream& operator<<(std::ostream& os, Circle const& c);

private:
  double radius_;

  
};

#endif // CIRCLE_HPP