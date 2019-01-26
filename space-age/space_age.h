#pragma once
#include <string>

namespace space_age {
  using namespace std;
  class space_age{
    private:
      long age;
    public:
      space_age(long p_age){
        age = p_age;
      };
      long seconds() const;
      double on_planet(string const &) const;
      double on_earth() const;
      double on_mercury() const;
      double on_venus() const;
      double on_mars() const;
      double on_jupiter() const;
      double on_saturn() const;
      double on_uranus() const;
      double on_neptune() const;

  };
}
