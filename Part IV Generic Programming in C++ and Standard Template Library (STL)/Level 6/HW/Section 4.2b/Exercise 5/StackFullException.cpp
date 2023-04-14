//StackFullException source file implements the 
//StackFullException derived class from StackException Header File

#include "StackException.hpp"

StackFullException::StackFullException() : StackException() {}			//Default Constructor
StackFullException::~StackFullException() {}							//Destructor

std::string StackFullException::S_GetMessage()							//Overriding S_GetMessage() function
{
	std::stringstream m_string;
	m_string << "Error: Stack is Full";
	return m_string.str();
}