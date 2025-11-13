
#include <iostream>
#include "Point.hpp"


Point::Point( void ): _x(0) , _y(0)
{
}

Point::Point( const float x, const float y ): _x(x) , _y(y)
{
}

Point::Point( const Point &src ): _x(src._x), _y(src._y)
{
}

Point	&Point::operator=( const Point &rhs )
{
	(void)rhs;
	return *this;
}