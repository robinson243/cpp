#ifndef __JC__TIME__
#define __JC__TIME__

#include <iostream>
#include <cstddef>

namespace jc
{
	class time
	{
	public:
		time(std::size_t h, std::size_t m, std::size_t s);
		time operator+(const time& other) const;
	private:
		std::size_t hours;
		std::size_t minutes;
		std::size_t seconds;
	friend std::ostream& operator<<(std::ostream& os, const time& t);
	
	};

};

#endif