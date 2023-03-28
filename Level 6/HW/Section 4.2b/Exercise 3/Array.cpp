//Array source file implements the Array class defined in the 
//array header file

#ifndef Array_cpp
#define Array_cpp

#include "Array.hpp"

namespace JoseAponte
{
	namespace Containers
	{
		template<typename T>
		int Array<T>::def_size = 10;			//Initialise this static in the source file to a value

		template<typename T>
		Array<T>::Array() : arr_size(def_size), m_data(new T[def_size]) {}					//Default constructor that allocates 10 elements w/ Colon Syntax

		template<typename T>
		Array<T>::~Array()					//Destructor that deletes the internal C array
		{
			delete[] m_data;				//Deleting internal C array
		}

		template<typename T>
		Array<T>::Array(const Array<T>& A) : arr_size(A.arr_size), m_data(new T[A.arr_size])			//Copy Constructor w/ Colon Syntax
		{
			int i;								//Declare i for iterations of loop
			for (i = 0; i < arr_size; i++)		//For i = 0 up until the size of the array
			{
				m_data[i] = A.m_data[i];		//Copy the corresponding element
			}
		}

		template<typename T>
		Array<T>::Array(int size) :arr_size(size), m_data(new T[size]) {}			//Constructor with a size argument that allocates the number of elements specified by the size input argument w/ Colon Syntax

		template<typename T>
		Array<T>& Array<T>::operator = (const Array<T>& source)	//Assignment Operator
		{
			if (this != &source)						//Check if the source object is not the same as the this object
			{
				delete[] m_data;						//Delete the old C array
				arr_size = source.arr_size;				//Assign array size
				m_data = new T[source.arr_size];		//Allocate new memory before copying the elements 
				int i;									//Declare i for iterations of assigning loop
				for (i = 0; i < arr_size; i++)			//For 0 <= i < 3
				{
					m_data[i] = source.m_data[i];		//Assign elements
				}
			}
			return *this;
		}

		template<typename T>
		T& Array<T>::operator[](int index)					//Square bracket operator
		{
			if (index >= 0 && index < arr_size)				//When the data index is in bounds
			{
				return m_data[index];						//Return the corresponding element
			}
			else
			{
				throw OutofBoundsException(index);			//Throw OutofBoundsException if the index is out of bounds
			}
		}

		template<typename T>
		const T& Array<T>::operator[](int index) const		//Const version of square bracket operator
		{
			if (index >= 0 && index < arr_size)				//When the data index is in bounds
			{
				return m_data[index];						//Return the corresponding element
			}
			else
			{
				throw OutofBoundsException(index);			//Throw OutofBoundsException if the index is out of bounds
			}
		}

		template<typename T>
		int Array<T>::Size() const							//Size() function that returns the size of the array
		{
			return arr_size;
		}

		template<typename T>
		void Array<T>::SetElement(int& i, T& p)				//SetElement() function that sets an element
		{
			if (i >= 0 && i < arr_size)						//When the data index is in bounds
			{
				m_data[i] = p;								//Set the elements
			}
			else
			{
				throw OutofBoundsException(i);				//Throw OutofBoundsException if the index is out of bounds
			}
		}

		template<typename T>
		T& Array<T>::GetElement(int i) const				//GetElement() function that gets an element
		{
			if (i >= 0 && i < arr_size)						//When the data index is in bounds
			{
				return m_data[i];							//Return the corresponding element
			}
			else
			{
				throw OutofBoundsException(i);				//Throw OutofBoundsException if the index is out of bounds
			}
		}
		template<typename T>
		int Array<T>::DefaultSize()							//Static Getter for default size
		{
			return def_size;
		}

		template<typename T>
		void Array<T>::DefaultSize(int d_size)				//Static Setter for default size
		{
			def_size = d_size;
		}
	}
}
#endif