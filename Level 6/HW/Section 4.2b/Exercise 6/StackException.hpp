//StackException.hpp implements the StackException class, StackFullException class, and StackEmptyException class
#ifndef STACK_EXCEPTION_HEADER
#define STACK_EXCEPTION_HEADER

#include <sstream>

class StackException
{
public:
	StackException();							//Default Constructor
	virtual ~StackException();					//Destructor

	virtual std::string S_GetMessage() = 0;		//Abstract S_GetMessage() that returns a std::string
};

class StackFullException : public StackException
{
public:
	StackFullException();						//Default Constructor
	~StackFullException();						//Destructor

	std::string S_GetMessage();					//Overriding S_GetMessage() function
};

class StackEmptyException : public StackException
{
public:
	StackEmptyException();						//Default Constructor
	~StackEmptyException();						//Destructor

	std::string S_GetMessage();					//Overriding S_GetMessage() function
};

#endif