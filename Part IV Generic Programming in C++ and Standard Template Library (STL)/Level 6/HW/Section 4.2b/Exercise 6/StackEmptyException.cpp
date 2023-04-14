//StackEmptyException source file implements the StackEmptyException derived class from StackException Header File

#include "StackException.hpp"

StackEmptyException::StackEmptyException() : StackException() {}			//Default Constructor
StackEmptyException::~StackEmptyException() {}								//Destructor

std::string StackEmptyException::S_GetMessage()								//Overriding S_GetMessage() function
{
	std::stringstream m_string;
	m_string << "Error: Stack is Empty";
	return m_string.str();
}