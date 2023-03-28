//NAExceptions source file implements the 
//NAException class defined in the header file

#include "Exceptions.hpp"

NA_Exception::NA_Exception() :ArrayException() {}		//Default Constructor

NA_Exception::~NA_Exception() {}						//Destructor

std::string NA_Exception::GetMessage()
{
	std::stringstream m_string;										//Using a std::stringstream object and the standard stream operators to create the string
	m_string << "The sizes of the numeric arrays are unequal.";		//Let the implementation return a message string saying sizes of arrays are unequal
	return m_string.str();
}