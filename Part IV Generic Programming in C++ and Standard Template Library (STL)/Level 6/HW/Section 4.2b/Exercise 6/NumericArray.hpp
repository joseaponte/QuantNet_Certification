//NumericArray.hpp is the header file for the Numeric Array class, which will be derived form the Array class

#ifndef NUMERIC_ARRAY_HEADER
#define NUMERIC_ARRAY_HEADER
#include "Array.hpp"
#include "Exceptions.hpp"

namespace JoseAponte
{
	namespace Containers
	{
		template <typename T>
		class NumericArray : public Array<T>
		{
		public:
			NumericArray();										//Default Constructor
			~NumericArray();									//Destructor

			NumericArray(const NumericArray<T>& NA);			//Copy Constructor
			NumericArray(int sz);								//Constructor with size argument

			NumericArray<T>& operator = (const NumericArray<T>& source);		//Assignment operator
			NumericArray<T> operator * (double scale) const;					//An operator * to scale the elements of the numeric array by a factor
			NumericArray<T> operator + (const NumericArray<T>& na) const;		//An operator + to add the elements of two numeric arrays

			double DotProduct(const NumericArray<T>& num_arr);					//A function to calculate the dot product of two arrays
		};
	}
}
#ifndef NUMERIC_ARRAY_CPP
#include "NumericArray.cpp"
#endif
#endif
