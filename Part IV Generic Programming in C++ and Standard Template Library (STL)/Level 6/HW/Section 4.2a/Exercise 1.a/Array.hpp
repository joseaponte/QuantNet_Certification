//Array.hpp is the header file for the Array class with data members for a dynamic C array of Point objects (Point* m_data) and the size of the array.

#ifndef ARRAY_HEADER		//If ARRAY_HEADER is not yet defined
#define ARRAY_HEADER		//Define it
#include "Point.hpp"		//Include Point Header File
#include "Exceptions.hpp"	//Include Exceptions Header File

namespace JoseAponte
{
	namespace Containers
	{
		template <typename T>
		class Array
		{
		private:
			T* m_data;				//Data member for a dynamic C array of objects
			int arr_size;			//Data member for the size of the array

		public:
			Array();				//Default Constructor
			~Array();				//Destructor

			Array(const Array<T>& A);	//Copy Constructor
			Array(int size);			//Constructor with a size argument

			Array<T>& operator = (const Array<T>& source);	//Assignment Operator
			T& operator [] (int index);						//Square bracket operator
			const T& operator [] (int index) const;			//Const version of square bracket operator

			int Size() const;						//Size function that returns the size of the array
			void SetElement(int& i, T& p);			//SetElement() function that sets an element
			T& GetElement(int i) const;				//GetElement() function that gets an element
		};
	}
}
#ifndef Array_cpp // Must be the same name as in source file #define
#include "Array.cpp"	//This works because the header now includes the source, so if we include the header in main, the source is included too
#endif
#endif