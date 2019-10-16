#pragma once
#include <boost/date_time/gregorian/gregorian.hpp>

namespace meetup {
using Date = boost::gregorian::date;
using Month = boost::gregorian::greg_month;
using Year = short unsigned int;
using Days = boost::gregorian::days;

class scheduler {
 private:
  Date meeting_date;

 public:
  scheduler(Month month, Year year);
  Date monteenth() const;
  Date tuesteenth() const;
  Date wednesteenth() const;
  Date thursteenth() const;
  Date friteenth() const;
  Date saturteenth() const;
  Date sunteenth() const;
};
}  // namespace meetup
