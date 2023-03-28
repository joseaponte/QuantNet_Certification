//Shape source file implements the Shape class (hierarchy) defined in the header file

#include"Shape.hpp"

using namespace std;

namespace JoseAponte
{
	namespace CAD
	{
		Shape::Shape() :m_id(rand()) {}								//Default constructor that initializes the id using a random number
		//Using the rand() function from the “stdlib.h” header file
	
		Shape::~Shape()												//Destructor
		{
			cout << "Shape Destructor Called." << endl;				//Printing some text in the destructor of Shape to test deletion of base class
		}

		Shape::Shape(const Shape& S) : m_id(S.m_id) {}				//Copy constructor that copies the id member.

		Shape& Shape::operator=(const Shape& source)				//Assignment operator that copies the id member
		{
			if (&source != this)									//Self-Assignment Prevention
			{
				m_id = source.m_id;									//Copying id member
			}
			return *this;
		}

		std::string Shape::ToString() const							//ToString() function that returns the id as string
		{
			std::stringstream m_string;								//Using a std::stringstream object and the standard stream operators to create the string
			m_string << "ID: " << m_id;								//Output in the form of "ID: ___”
			return m_string.str();
		}
		double Shape::ID() const									//ID() function that retrieves the id of the shape
		{
			return m_id;
		}
	}
}