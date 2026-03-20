//===========================================
// Tren Meckel & Jiamin Liu
// 25 January 2024
// prisonEscape.cpp
// Python code translated to C++ that determines if
// Dr. Kretchmar escapes prison or not by avoiding
// lights. It takes input data about the spotlight cycle
// from user and the attempted escape time. The prisoner 
// escapes successfully if there are no spot lights
//==========================================

#include <iostream>

bool is_light_on( int t, int ontime, int offtime)
{
	int timeCycle = ontime + offtime;
	return (t % timeCycle) < ontime;
}

//===========================================
// string_escape
// This function checks from the lightcycle whether the 
// the light(s) is on when Dr. Kretchmar attempts to escape
// Parameters:
//	t1_on: the length of time the first security light stays on
//	t1_off: the length of time the first security light stays off
//	t2_on: the length of time the second security light stays on
//	t2_off: the length of time the second security light stays off
//	t_escape: the time in minutes after midnight when Dr. K escape
//Return Value:
//	whether Dr. Kretchmar escapes or gets caught
//===========================================

std::string escape_attempt( int t1_on, int t1_off, int t2_on, int t2_off, int t_escape)
{
	bool light1_on = is_light_on( t_escape, t1_on, t1_off);
	bool light2_on = is_light_on( t_escape, t2_on, t2_off);
	
	if (t1_on >= 1450 or t2_on >= 1450)
	{	return "CAUGHT" ; }
	else
	{	if (!light1_on && !light2_on) 
		{	return "ESCAPE"; }
		else 
		{	return "CAUGHT"; }
	}
}

int main( void )
{
// input
	int t1_on, t1_off, t2_on, t2_off, t_escape;
	std::cin >> t1_on;
	std::cin >> t1_off;
	std::cin >> t2_on;
	std::cin >> t2_off;
	std::cin >> t_escape;
	
// output 
	std::string result = escape_attempt(t1_on, t1_off, t2_on, t2_off, t_escape);
	std::cout << result << std::ends; 
	
	return 0;
}

