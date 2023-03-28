//OutOfBoundsException source file implements the OutOfBoundsException class defined in the Exceptions header file
//It's a derived class of the base ArrayException Class

#include "Exceptions.hpp"

OutofBoundsException::OutofBoundsException() : ArrayException(), m_index() {}						//Default Constructor
OutofBoundsException::OutofBoundsException(int m_index) : ArrayException(), m_index(m_index) {}		//Constructor with an int as argument that indicates the erroneous array index and stores it in a data member
OutofBoundsException::~OutofBoundsException() {}													//Destructor

std::string OutofBoundsException::GetMessage()				//Overriding GetMessage() function
{
	std::stringstream m_string;								//Using a std::stringstream object and the standard stream operators to create the string
	m_string << "The given index is out of bounds.";		//Let the implementation return a message string saying the given index is out of bounds.
	return m_string.str();
}