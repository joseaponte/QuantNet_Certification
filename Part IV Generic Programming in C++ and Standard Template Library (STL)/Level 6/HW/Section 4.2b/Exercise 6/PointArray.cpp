//PointArray source file implements the PointArray class defined in the header file

#include "PointArray.hpp"

namespace JoseAponte
{
	namespace Containers
	{
		PointArray::PointArray() : Array<Point>() {}								//Default Constructor
		PointArray::~PointArray() {}												//Destructor

		PointArray::PointArray(int siz) : Array<Point>(siz) {}						//Constructor with size parameter
		PointArray::PointArray(const PointArray& PA) : Array<Point>(PA) {}			//Copy Constructor

		PointArray& PointArray::operator=(const PointArray& source)					//Assignment Operator
		{
			if (this != &source)													//Prevent Self Assignment
			{
				Array<Point>::operator = (source);									//Call the base class where appropriate
			}

			return *this;
		}

		double PointArray::Length() const											//Add a Length() function that returns the total length between the points in the array
		{
			double len = 0;															//Initialize the value of length to 0
			for (int i = 1; i < (*this).Size(); i++)								//For 0<=i<PointArray's Size
			{
				len = len + (*this)[i].Distance((*this)[i - 1]);					//Add the length between this element and the previous one
			}
			return len;
		}
	}
}