//NumericArray source file implements the NumericArray class 
//defined in the header file

#ifndef NUMERIC_ARRAY_CPP
#define NUMERIC_ARRAY_CPP

#include "NumericArray.hpp"

namespace JoseAponte
{
	namespace Containers
	{
		template<typename T>
		NumericArray<T>::NumericArray() :Array<T>() {}								//Default Constructor

		template<typename T>
		NumericArray<T>::~NumericArray() {}											//Destructor

		template<typename T>
		NumericArray<T>::NumericArray(const NumericArray<T>& NA) : Array<T>(NA) {}	//Copy Constructor w/ Colon Syntax

		template<typename T>
		NumericArray<T>::NumericArray(int sz) : Array<T>(sz) {}						//Constructor with a size argument

		template<typename T>
		NumericArray<T>& NumericArray<T>::operator=(const NumericArray<T>& source)		//Assignment Operator
		{
			if (this != &source)							//Prevent self-assignment
			{
				Array<T>::operator = (source);				//Call the base class where appropriate
			}

			return *this;
		}

		template<typename T>
		NumericArray<T> NumericArray<T>::operator * (double scale) const		//Scale array by a factor operator
		{
			NumericArray<T> Scaled_NA((*this).Size());								//Using inherited Size() function to get size parameter
			for (int i = 0; i < (*this).Size(); i++)								//For 0<=i<size of numeric array
			{
				Scaled_NA[i] = (*this)[i] * scale;									//Scale each element
			}

			return Scaled_NA;
		}

		template<typename T>
		NumericArray<T> NumericArray<T>:: operator + (const NumericArray<T>& na) const		//Add two Numeric Arrays Operator
		{
			NumericArray<T> Added_NA((*this).Size());										//Declaring a Numeric Array for the result
			if ((*this).Size() == na.Size())											//If Sizes are equal
			{
				for (int i = 0; i < (*this).Size(); i++)								//For 0<=i<size of NA
				{
					Added_NA[i] = (*this)[i] + na[i];									//Add the corresponding elements of the two NA's together
				}

				return Added_NA;
			}
			else
			{
				throw NA_Exception();													//Throw an exception if the two arrays have not the same size
			}
		}

		template<typename T>
		double NumericArray<T>::DotProduct(const NumericArray<T>& num_arr)					//A function to calculate the dot product
		{
			double dot = 0;																	//Initialize a double 'dot' = 0

			if ((*this).Size() == num_arr.Size())											//If sizes are equal
			{
				for (int i = 0; i < (*this).Size(); i++)									//For 0<=i<size
				{
					dot = dot + (*this)[i] * num_arr[i];									//Add the product of the corresponding elements to the sum
				}

				return dot;
			}
			else
			{
				throw NA_Exception();														//Throw an exception if the two arrays have not the same size
			}
		}
	}
}
#endif