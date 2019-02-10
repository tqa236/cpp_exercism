#pragma once
#include <boost/date_time/gregorian/gregorian.hpp>

namespace meetup {
    using namespace std;
    class meetup{
    private:
        boost::gregorian::date meeting_date;
    public:
        meetup(boost::gregorian::date meeting_date){
            this.meeting_date = meeting_date;
        }
    }
}
