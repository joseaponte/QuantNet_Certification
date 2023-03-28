//Exceptions header file, which implements both of the 
//exception classes in a single header, for simplicity

#ifndef EXCEPTIONS_HPP		//If not yet defined
#define EXCEPTIONS_HPP		//Define the term (avoid multiple inclusions)
#include <sstream>

class ArrayException
{
public:
	ArrayException();						//Default Constructor
	virtual ~ArrayException();				//Destructor

	virtual std::string GetMessage() = 0;	//Abstract GetMessage() function that returns a std::string
};

class OutofBoundsException : public ArrayException
{
private:
	int m_index;						//Private member data for index of array
public:
	OutofBoundsException();				//Default Constructor
	OutofBoundsException(int m_index);	//Constructor with an int as argument that indicates the erroneous array index and stores it in a data member
	~OutofBoundsException();			//Destructor

	std::string GetMessage();			//Overriding GetMessage() function

};

class NA_Exception : public ArrayException
{
public:
	NA_Exception();					//Default Constructor
	~NA_Exception();				//Destructor

	std::string GetMessage();		//Overriding GetMessage()
};

#endif