#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "circle.hpp"
#include "mylib.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>

TEST_CASE("AUFGABE 1 - Sort mit Lambda", "[sort_circle]")
{
  
  // auto lambda = [](Circle const& lhs, Circle const& rhs){return lhs < rhs;}

  std::list<Circle> l0(50);
  std::generate(std::begin(l0), std::end(l0), func::gen<Circle, 50>);             
  //l0.sort(lambda)
  l0.sort([](Circle const& lhs, Circle const& rhs){return lhs < rhs;});             // sort mit lambda funktion als Parameter

  REQUIRE(std::is_sorted(std::begin(l0), std::end(l0)));                          
}


TEST_CASE("AUFGABE 2 - Sort mit Funktor", "[sort_circle]")
{
    // lokal definierter und direkt initialisierter Funktor klasse die den klammeroperator implementiert [c++]
  struct  {
    bool operator() (Circle const& a, Circle const& b) const {
      return a < b;
    }
  } loc_less;

  std::list<Circle> l0(50);
  std::generate(std::begin(l0), std::end(l0), func::gen<Circle, 50>);
  l0.sort(loc_less);

  REQUIRE(std::is_sorted(std::begin(l0), std::end(l0)));
}

TEST_CASE("AUFGABE 3 - Add with std::transform", "[transform]")
{
  std::vector<int> v1{1,2,3,4,5};
  std::vector<int> v2{9,8,7,6,5};
  std::vector<int> v3(5);

/*??-- ....including the element pointed by first1 but not the element pointed by last1. ??*/

  std::transform(
      std::begin(v1), std::end(v1), std::begin(v2), std::begin(v3), [](int const lhs, int const rhs){return lhs + rhs;});

//std::cout<<"--------"<<std::endl;
//std::copy (std::begin(v3),std::end(v3),std::ostream_iterator<int>(std::cout, "\n"));     // Ausgabe des Vektors v0
//std::cout<<"--------"<<std::endl;


  REQUIRE(std::all_of(std::begin(v3), std::end(v3),
      [](int const i){ return i == 10; }));
}

TEST_CASE("AUFGABE 4 - std::copy_if", "[copy_if]")
{
  
  std::vector<Circle> v0(20);
  std::vector<Circle> v1(v0.size());

  std::generate(std::begin(v0), std::end(v0), func::gen<Circle, 10>);                                           // Kreise mit zufälligem Radius von 0 bis 50
  auto it = std::copy_if(std::begin(v0), std::end(v0), std::begin(v1), [](Circle const& c){ return c.radius() > 3; });

  v1.resize(std::distance(std::begin(v1), it));                                                                 // Größe von v1 wird verkleinert
  std::copy(v1.begin(), v1.end(), std::ostream_iterator<Circle>(std::cout, "\n"));                              // Ausgabe der Kreise
  REQUIRE(std::all_of(std::begin(v1), std::end(v1), [](Circle const& c){ return c.radius() > 3; }));
}

TEST_CASE("AUFGABE 5 - std::accumulate", "[accumulate]")
{
  
  std::vector<func::Vec3> v(10);
  std::generate(std::begin(v), std::end(v), [](){ return func::Vec3{2,2,2};});

  auto sum1 = std::accumulate(std::begin(v), std::end(v), func::Vec3{0,0,0});                                                              

  auto sum2 = std::accumulate(std::begin(v), std::end(v), func::Vec3{0,0,0}, std::plus<func::Vec3>());                                     
  
  auto sum3 = std::accumulate(std::begin(v), std::end(v), func::Vec3{0,0,0}, [](func::Vec3 const& a, func::Vec3 const& b){return a + b;});

  func::Vec3 res{20,20,20};
  REQUIRE(sum1 == res);
  REQUIRE(sum2 == res);
  REQUIRE(sum3 == res);
}

int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}
