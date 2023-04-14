//IsLess.cpp is the source file that defines the class for IsLess

#include "IsLess.hpp"

IsLess::IsLess() : m_val(6.2) {}							//Default Constructor
IsLess::~IsLess() {}										//Destructor

IsLess::IsLess(double val) : m_val(val) {}					//Constructor with double value parameter
IsLess::IsLess(const IsLess& ILT) : m_val(ILT.m_val) {}		//Copy Constructor

IsLess& IsLess::operator = (const IsLess& source)			//Assignment operator
{
	if (this != &source)									//Prevent self-assignment
	{
		m_val = source.m_val;								//Assign m_val to that of its source
	}

	return *this;
}
bool IsLess::operator()(double Ele)							//Overloaded round bracket operator that in this case has the same signature and functionality as the global function created previously
{
	return Ele < m_val;										//Return elements with value less than m_val
}

void IsLess::Val(double Set_num)							//Setter for m_val
{
		m_val = Set_num;									//Set m_val equal to parameter
}
double IsLess::Val() const									//Getter for m_val
{
		return m_val;										//Return m_val
}