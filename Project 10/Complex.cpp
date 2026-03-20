//========================================================
// Sam, Harry, Tren
// Complex.cpp
// November 2023
// This file contains the class methods for the
// Complex number class.
//========================================================

#include "Complex.h"
#include <string.h>
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <cstdlib>
using namespace std;

/*========================================================
Default Constructor
Sam Bilus
Creates an instance of the Complex class and sets a and
b to 0 by default.
No parameters
Returns a new instance of the Complex class
========================================================*/
Complex::Complex( void )
{
	a = 0;
	b = 0;
}

//========================================================
// copy constructor
// Harry
// Initializes Rational object to value of c
// PARAMETERS:
// c: a complex number
// RETURN VALUE:
// none
//========================================================
Complex::Complex(const Complex &c)
{
        a = c.a;
        b = c.b;
}

//========================================================
// Complex(a, b) constructor
// Trinity
// Initializes a Complex object with values a and b
// PARAMETERS:
//    double x - the real part of the complex number
//    double y - the imaginary part of the complex number
// RETURN VALUE:
//    none
//========================================================
Complex::Complex(double x, double y /*= 0*/) 
{
	a = x;
	b = y;
}
Complex::~Complex( void )
{
	
}

/*========================================================
setReal
Sam Bilus
Allows the user to manipulate the value of a, the
real number in the a + bi equation.
Parameters:
	r - a double
Returns:
	changes the a value of the Complex to be equal to
	the parameter r
========================================================*/
void Complex::setReal(double r)
{
	a = r;
}

//========================================================
// getReal access method
// Trinity
// Return the real part.
// PARAMETERS:
// none
// RETURN VALUE:
// return real part(double)
//========================================================
double Complex::getReal( void ) const
{
	return a;
}

//========================================================
// setImag
// Trinity
// Sets the imaginary part of a Complex object
// PARAMETERS:
//    double r - the new value for the imaginary part
// RETURN VALUE:
//    none (void function)
//========================================================
void Complex::setImag( double r )
{
	b = r;
}

/*========================================================
getImag
Sam Bilus
Allows the user to access the value of b, the coefficient
of the imaginary number in the a + bi equation
Parameter list-- type and constraints of parameters
Return value-- type and description of the return value
note where calling objects are changed
========================================================*/
double Complex::getImag(void) const
{
	return b;
}

/*========================================================
Assignment Operator
Sam Bilus
Allows assignment of values between complex numbers.
Parameters:
	c - a Complex
Returns:
	sets a equal to the a value of parameter c and b
	to the b value of parameter c
========================================================*/
Complex Complex::operator= (const Complex &c)
{
	a = c.a;
	b = c.b;
	return *this;
}
//========================================================
// addition operators
//========================================================
/*========================================================
Operator + with Complex
Sam Bilus
Supports addition between two complex numbers
Parameters:
	c - a Complex
Returns:
	adds c.a to the value of a, and c.b to the value
	of b, then returns a new Complex with the new
	values
========================================================*/
Complex Complex::operator+ (const Complex &c) const
{
	Complex cem;
	cem.setReal(a + c.getReal());
	cem.setImag(b + c.getImag());
	return cem;
}
//======================================================
// operator+ with int
// Trinity
// Adds an integer to a Complex object, treating the
// integer as a real number
// PARAMETERS:
//    int i - the integer to add to the real part of 
//    the complex number
// RETURN VALUE:
//    Complex - returns a new Complex object with the 
//    integer added to the real part
//======================================================
Complex Complex::operator+ (int i) const 
{
	return Complex(a + i, b);
}

//========================================================
// operator+ with float
// Harry
// c1 = c2 + f
// Will take the components of c2 + f and return them
// to c1.
// PARAMETERS:
// double f: the number to add in
// RETURN VALUE:
// returns sum of *this + f
//========================================================
Complex Complex::operator+ ( double f ) const
{
	Complex ret;
	ret.a = a + f;
	ret.b = b;
	return ret;
}

//========================================================
// subtraction operators
//========================================================
/*========================================================
Operator - with Float
Sam Bilus
Supports subtraction between a Complex and a float
Parameters:
	f - a float
Returns:
	subtracts f from the value of a and returns a 
	new Complex with the new a value and the same b
	value
========================================================*/
Complex Complex::operator- (double f) const
{
	Complex cem;
	cem.setReal(a);
	cem.setImag(b - f);
	return cem;
}

//======================================================
// operator- with int
// Trinity
// Subtracts an integer from a Complex object, treating 
// the integer as a real number
// PARAMETERS:
//    int i - the integer to subtract from the real part 
//    of the complex number
// RETURN VALUE:
//    Complex - returns a new Complex object with the 
//    integer subtracted from the real part
//======================================================
Complex Complex::operator- (int i) const 
{
	return Complex(a - i, b);
}

//========================================================
// operator- with Complex
// c1 = c2 - c3
// Will take the components of c2 + c3 and return them
// to c1.
// PARAMETERS:
// complex object c
// RETURN VALUE:
// returns sum of *this - c
//========================================================
Complex Complex::operator- (const Complex &c ) const
{
	Complex ret;
	ret.a = a - c.a;
	ret.b = b - c.b;
	return ret;
}

//======================================================
// operator-
// c1 = -c2
// Will take the components of c2 and return them
// to c1.
// PARAMETERS:
// const Complex object
// RETURN VALUE:
// returns new Complex object with same value of *this
// except real and imaginary sign  swapped.  
//======================================================
Complex Complex::operator- ( void ) const
{
	Complex ret;
	ret.a = -a;
	ret.b = -b;
	return ret;
}



//========================================================
// multiplication operators
//========================================================
/*========================================================
Operator * with int
Sam Bilus
Supports multiplation between a Complex and an integer
Parameter list:
	i - an int
Return value:
	multiplies both values of Complex by parameter
	i and returns a new Complex with the new values
========================================================*/
Complex Complex::operator* (int i) const
{
	Complex cem;
	cem.setReal(a * i);
	cem.setImag(b * i);
	return cem;
}

//======================================================
// operator* with double
// Trinity
// Multiplies a Complex object by a double, scaling
// both the real and imaginary parts
// PARAMETERS:
//    double f - the factor to multiply the complex
//    number by
// RETURN VALUE:
//    Complex - returns a new Complex object with both 
// the real and imaginary parts scaled by the factor
//======================================================
Complex Complex::operator*(double f) const 
{
	return Complex(a * f, b * f);
}

//========================================================
// operator* with Complex
// c1 = c2 * c3
// Will take the components of c2 * c3 and return them
// to c1.
// PARAMETERS:
// complex object c
// RETURN VALUE:
// returns sum of *this + c
//========================================================
Complex Complex::operator*( const Complex &c ) const
{
	Complex ret;
	ret.a = a*c.a - b*c.b;
	ret.b = a*c.b + b*c.a;
	return ret;
}

//========================================================
// division operators
//========================================================
/*========================================================
Operator / with int
Sam Bilus
Supports division between a Complex and an integer
Parameter list:
	i - an int
Return value:
	divides both values of Complex by parameter i
	and returns a new Complex with the new values
========================================================*/
Complex Complex::operator/ (int i) const
{
	Complex cem;
	cem.setReal(a / i);
	cem.setImag(b / i);
	return cem;
}

//======================================================
// operator/ with Complex
// Trinity
// Divides a Complex object by another Complex object
// PARAMETERS:
//    const Complex &c - a reference to the Complex 
//    object to divide by
// RETURN VALUE:
//    Complex - returns a new Complex object
//======================================================
Complex Complex::operator/ (const Complex &c) const 
{
	double denominator = c.a * c.a + c.b * c.b;
	return Complex((a * c.a + b * c.b) / denominator, (b * c.a - a * c.b) / denominator);
}

//========================================================
// operator/ with double
// c1 = c2 / f
// Will take the components of c2 / f and return them
// to c1.
// PARAMETERS:
// double f: the denominator
// RETURN VALUE:
// returns sum of *this / f
//========================================================
Complex Complex::operator/ ( double f ) const
{
	Complex ret;
	ret.a = a/f;
	ret.b = b/f;
	return ret;
}

/*========================================================
Exponentiation Operator
Sam Bilus
Raises the Complex to an integer power
Parameter list:
	i - an integer
Return value:
	multiplies a Complex by itself a number of times
	equal to parameter i, then returns a new Complex
	with the new values
========================================================*/
Complex Complex::operator^ (int i) const
{
	Complex cem;
	cem.setReal(a);
	cem.setImag(b);
	if(i > 0)
	for(int j = 1; j < i; j++)
	{
		cem = cem * *this;
	}
	if(i < 0)
	for(int j = 1; j < -i; j++)
	{
		cem = cem / *this;
	}
	if(i == 0) return Complex(1, 0);
	return cem;
}
/*========================================================
Conjugation Operator
Sam Bilus
Returns the Complex conjugate
Return value:
	a new Complex equal to the conjugate of the
	Complex
========================================================*/
Complex Complex::operator~ (void) const
{
	Complex cem;
	cem.setReal(a);
	cem.setImag(-b);
	return cem;
}
//========================================================
// abs
// Trinity
// Calculates the absolute value (magnitude) of a Complex
// number
// PARAMETERS:
//    none
// RETURN VALUE:
//    double - the absolute value (magnitude) of the Complex
//    number
//========================================================
double Complex::abs() const
{
	double ret;
	ret = std::sqrt((std::pow(a,2.0) + std::pow(b,2.0)));
	return ret;
}

//========================================================
// equality operator
// Harry
// Returns true if both the real parts and imaginary parts are the same.
// PARAMETERS:
// Complex object c
// RETURN VALUE:
// true if c and *this have same real and imaginary part, false otherwise.
//========================================================
bool Complex::operator== ( const Complex &c ) const
{
    return a == c.a && b == c.b;
}


//========================================================
// inequality operator
//========================================================
bool Complex::operator!= (const Complex &c) const
{ 
	return ( a != c.a) || ( b != c.b);
}

//========================================================
// overload >> for cin
//========================================================
/*std::istream& operator>>(std::istream &is, const Complex &c)
{
	
}*/
//======================================================
// cout << operator overload
// Trinity
// Writes a Complex object to an output stream (e.g., cout)
// PARAMETERS:
//    ostream &os - the output stream to write to
//    const Complex &c - the Complex object to write to 
//    the output stream
// RETURN VALUE:
//    ostream& - a reference to the output stream to 
//    support chaining
// NOTES:
//    - If the imaginary part is zero, only the real 
//      part is printed.
//    - If the real part is zero, only the imaginary
//      part with 'i' is printed.
//    - If the imaginary part is negative, it prints
//      the real part followed by a minus sign, the
//      absolute value of the imaginary part, and 'i'.
//    - Otherwise, it prints the real part followed by
//      a plus sign, the imaginary part, and 'i'.
//======================================================
std::ostream& operator<<(std::ostream &os, const Complex &c)
{
	if (c.b == 0)
	   os << c.a;
	else if (c.a == 0)
	   os << c.b << "i";
	else if (c.b < 0)
	   os << c.a << c.b << "i";
	else
	   os << c.a << "+" << c.b << "i";
	return os;
}

//========================================================
// overload >> for cin
// Overloads the cin istream >> operator to allow
// cin >> c;
// PARAMETERS
// istream &is
// Complex &c
// RETURN VALUE:
// istream is
// Note: if the user only enter 'i' then the imaginary part
// would be set to 1.0
//========================================================
istream &operator>>(istream &is, Complex &c)
{
	c.a = 0.0;
	c.b = 0.0;
	string s;
	is >> s;
	size_t i_spot = s.find('i');
	// check if there is an 'i' character in the string
	if (i_spot == string::npos)
		c.a = stof(s);      // if no, there is no imaginary part in the complex number
	else
	{
        	size_t plus = s.substr(1, s.length() - 1).find('+'); 
        	size_t minus = s.substr(1, s.length() - 1).find('-');
        	// if there is no signs in the number, the number will only have the imaginary part
    		if (plus == string::npos && minus == string::npos)
        	{
            		if (s[i_spot--] == '+' || s.length() == 1)     
            		{
                		c.b = 1.0;
            		}
            		else if (s[i_spot--] == '-')
            		{
            			c.b = -1.0;
            		}
            		else
            		{
                		c.b = stof(s);
            		}
        	}
        	// the number contains both parts
        	else
        	{
            		if (plus != string::npos)
            		{
                		c.a = stof(s.substr(0, plus+1));
                		// check if the input has any number before 'i'
		        if (s[i_spot-1] == '+')
		        {
		            	c.b = 1.0;
		        }
		        else if (s[i_spot-1] == '-')
		        {
		            	c.b = -1.0;
		        }
		        else
		        {
		            	c.b = stof(s.substr(plus + 2, s.length() - plus - 1 - 1));
		        }
		}
		else if (minus != string::npos)
		{
		        c.a = stof(s.substr(0, minus+1));
		        // check if the input has any number before 'i'
		        if (s[i_spot-1] == '+')
		        {
		            c.b = 1.0;
		        }
		        else if (s[i_spot-1] == '-')
		        {
		            c.b = -1.0;
		        }
		        else
		        {
		            c.b = stof(s.substr(minus + 1, s.length() - minus - 1 - 1));

		        }
		    }
		}
	}
	return is;
}
