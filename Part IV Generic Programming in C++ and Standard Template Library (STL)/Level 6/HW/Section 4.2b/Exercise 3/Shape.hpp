//Shape.hpp is the header file for the Shape class (hierarchy) with an int type id as its data member

#ifndef SHAPE_HEADER							//If SHAPE_HEADER is not yet defined
#define SHAPE_HEADER							//Define it

#include <stdlib.h>								//Include stdlib for rand() function
#include <sstream>								//Include Point Header
#include <cmath>								//Include cmath for pi functionality
#include <iostream>								//Include iostream for input and output

namespace JoseAponte
{
	namespace CAD
	{

		class Shape
		{
		private:
			int m_id;										//Data member for an id number of type int

		public:
			Shape();										//Default constructor that initializes the id using a random number
			virtual ~Shape() {};							//Destructor

			Shape(const Shape& S);							//Copy constructor that copies the id member.

			Shape& operator = (const Shape& source);		//Assignment operator that copies the id member

			virtual std::string ToString() const;			//ToString() function that returns the id as string
			double ID() const;								//ID() function that retrieves the id of the shape
			virtual void Draw() const = 0;					//Draw() function that's a pure virtual member function
			void Print() const;								//Print() function that calls the ToString() function and sens the results to the cout object
		};
	}
}
#endif