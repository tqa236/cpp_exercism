#pragma once
#include <boost/date_time/gregorian/gregorian.hpp>

namespace meetup {
// typedef scheduler boost::gregorian::date;
class meetup {
 private:
  boost::gregorian::date meeting_date;

 public:
  explicit meetup(boost::gregorian::date meeting_date) {
    this->meeting_date = meeting_date;
  }
};
}  // namespace meetup
