
#include "Point.hpp"

float	area( Point const p1, Point const p2, Point const p3 )
{
	float	result = 0.0f;
	
	result = ( p1.getX().toFloat() * ( p2.getY().toFloat() - p3.getY().toFloat() ) +
			   p2.getX().toFloat() * ( p3.getY().toFloat() - p1.getY().toFloat() ) +
			   p3.getX().toFloat() * ( p1.getY().toFloat() - p2.getY().toFloat() ) ) / 2.0f;
	
	if ( result < 0 )
		result = -result;
	return result;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	a_abc = area( a, b, c );
	
	float	a_abp = area( a, b, point );
	float	a_acp = area( a, c, point );
	float	a_pbc = area( point, b, c );

	float	total_area = a_abp + a_acp + a_pbc;

	if ( total_area == a_abc && a_abp != 0 && a_acp != 0 && a_pbc != 0)
		return true;
	return false;
}
