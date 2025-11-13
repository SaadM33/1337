#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
	Point a( 0.0f, 0.0f );
	Point b( 10.0f, 0.0f );
	Point c( 5.0f, 10.0f );
	
	Point p1( 5.0f, 5.0f );
	Point p2( 0.0f, 0.0f );
	Point p3( 15.0f, 15.0f );
	
	std::cout << "Triangle: A(0,0) B(10,0) C(5,10)" << std::endl;
	std::cout << std::endl;
	
	std::cout << "P1(5,5) inside: " << (bsp(a, b, c, p1) ? "yes" : "no") << std::endl;
	std::cout << "P2(0,0) on vertex: " << (bsp(a, b, c, p2) ? "yes" : "no") << std::endl;
	std::cout << "P3(15,15) outside: " << (bsp(a, b, c, p3) ? "yes" : "no") << std::endl;
	
	return 0;
}
