#include "meetup.h"

namespace meetup {
// using boost::gregorian::day_of_week;

scheduler::scheduler(Month month, Year year)
    : meeting_date(year, month, 13), year(year), month(month) {}

Date scheduler::monteenth() const {
  return meeting_date + Days((8 - meeting_date.day_of_week()) % 7);
}

Date scheduler::tuesteenth() const {
  return meeting_date + Days((9 - meeting_date.day_of_week()) % 7);
}

Date scheduler::wednesteenth() const {
  return meeting_date + Days((10 - meeting_date.day_of_week()) % 7);
}

Date scheduler::thursteenth() const {
  return meeting_date + Days((11 - meeting_date.day_of_week()) % 7);
}

Date scheduler::friteenth() const {
  return meeting_date + Days((12 - meeting_date.day_of_week()) % 7);
}

Date scheduler::saturteenth() const {
  return meeting_date + Days((13 - meeting_date.day_of_week()) % 7);
}

Date scheduler::sunteenth() const {
  return meeting_date + Days((14 - meeting_date.day_of_week()) % 7);
}

Date scheduler::first_monday() const {
  const Date first_day{year, month, 1};
  return first_day + Days((8 - first_day.day_of_week()) % 7);
}

}  // namespace meetup
