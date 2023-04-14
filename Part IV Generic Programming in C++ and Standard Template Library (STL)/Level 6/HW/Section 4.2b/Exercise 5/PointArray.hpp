//PointArray.hpp is the header file for the Point Array class, 
//which will be derived form the Array class

#ifndef POINT_ARRAY_HPP
#define POINT_ARRAY_HPP

#include "Array.hpp"
#include "Point.hpp"

using namespace JoseAponte::CAD;

namespace JoseAponte {
	namespace Containers {
		class PointArray : public Array<Point>
		{
		public:
			PointArray();										//Default Constructor
			~PointArray();										//Destructor

			PointArray(int siz);								//Constructor w/ Size parameter
			PointArray(const PointArray& PA);					//Copy Constructor

			PointArray& operator = (const PointArray& source);	//Assignment operator

			double Length();									//Add a Length() function that returns the total length between the points in the array
		};
	}
}

#endif
