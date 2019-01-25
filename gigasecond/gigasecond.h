#pragma once
#include "boost/date_time/posix_time/posix_time.hpp"

using boost::posix_time::ptime;

namespace gigasecond {
  ptime advance(const ptime &);
}
