#include <map>
#include <string>
#include "space_age.h"

using namespace std;

namespace space_age {
  map<string, double> year_length =
  {
    { "earth", 1.0}, { "mercury", 0.2408467},
    { "venus", 0.61519726}, { "mars", 1.8808158},
    { "jupiter", 11.862615}, { "saturn", 29.447498},
    { "uranus", 84.016846}, { "neptune", 164.79132}
  };
  long space_age::seconds() const{
    return age;
  }
  double space_age::on_planet(string const & name) const{
    return age/ (31557600.0 * year_length[name]);
  }
  double space_age::on_earth() const{
    return space_age::on_planet("earth");
  }
  double space_age::on_mercury() const{
    return space_age::on_planet("mercury");
  }
  double space_age::on_venus() const{
    return space_age::on_planet("venus");
  }
  double space_age::on_mars() const{
    return space_age::on_planet("mars");
  }
  double space_age::on_jupiter() const{
    return space_age::on_planet("jupiter");
  }
  double space_age::on_saturn() const{
    return space_age::on_planet("saturn");
  }
  double space_age::on_uranus() const{
    return space_age::on_planet("uranus");
  }
  double space_age::on_neptune() const{
    return space_age::on_planet("neptune");
  }
}
