#include <iostream>
#include "boost/date_time/posix_time/posix_time.hpp"

using namespace std;
using namespace boost::posix_time;

namespace gigasecond {
  ptime advance(ptime time){
    return time + seconds(1000000000);
  }
}
