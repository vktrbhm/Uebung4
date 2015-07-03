#ifndef MYLIB_HPP
#define MYLIB_HPP

#include <cstdlib>

namespace func
{
  /**
   * ---------------------------------------------------------------------------
   * ---------------------------------------------------------------------------
   * Aufgabe 4.1
   * ---------------------------------------------------------------------------
   */
   // Generates random Values till V
  template <typename T, int V>    
  T gen() {
    return T(rand() % V);
  }


   /**
   * ---------------------------------------------------------------------------
   * ---------------------------------------------------------------------------
   * Aufgabe 4.2
   * ---------------------------------------------------------------------------
   */
  template <typename T>
  class less
  {
  public:
    bool operator() (T const& a, T const& b) {
      return a < b;
    };
  };

  template <typename T>
  class greater
  {
  public:
    bool operator() (T const& a, T const& b) {
      return a > b;
    };
  };

  /**
   * ---------------------------------------------------------------------------
   * ---------------------------------------------------------------------------
   * Aufgabe 4.5
   * ---------------------------------------------------------------------------
   */
  class Vec3
  {
  public:
    Vec3()
      : x_{}, y_{}, z_{}
    {}
    Vec3(double const& x, double const& y, double const& z)
      : x_{x}, y_{y}, z_{z}
    {}

    friend Vec3 operator+ (Vec3 const& a, Vec3 const& b);
    friend bool operator== (Vec3 const& a, Vec3 const& b);

  private:
    double x_;
    double y_;
    double z_;
  };

  inline Vec3 operator+ (Vec3 const& a, Vec3 const& b) {
    return Vec3{a.x_ + b.x_, a.y_ + b.y_, a.z_ + b.z_};
  }

  inline bool operator== (Vec3 const& a, Vec3 const& b) {
    return a.x_ == b.x_ &&
           a.y_ == b.y_ &&
           a.z_ == b.z_;
  }
}

#endif //MYLIB_HPP