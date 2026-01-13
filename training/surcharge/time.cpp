#include "time.hpp"

namespace jc
{
	time::time(std::size_t h, std::size_t m, std::size_t s): hours(h), minutes(m) , seconds(s) {};

	time time::operator+(const time& other) const
	{
		return time{hours + other.hours, minutes + other.minutes, seconds + other.seconds};
	}

	std::ostream& operator<<(std::ostream& os, const time& t)
	{
		os << t.hours << ":" << t.minutes << ":" << t.seconds;
		return os; 
	}
}
