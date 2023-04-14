//Stack.cpp implements the stack class defined in the stack header file
#ifndef Stack_cpp
#define Stack_cpp

#include "Stack.hpp"

namespace JoseAponte
{
	namespace Containers
	{
		template <typename T>
		Stack<T>::Stack() : Arr(Array<T>()), m_current(0) {}				//Default Constructor

		template <typename T>
		Stack<T>::~Stack() {}												//Destructor

		template <typename T>
		Stack<T>::Stack(const Stack<T>& Stk) : Arr(Stk.Arr), m_current(Stk.m_current) {}	//Copy Constructor

		template <typename T>
		Stack<T>::Stack(int si) : Arr(Array<T>(si)),m_current(0) {}			//Constructor w/ int parameter

		template <typename T>
		Stack<T>& Stack<T>::operator = (const Stack<T>& source)				//Assignment Operator
		{
			if (this != &source)									//Prevent Self Assignemnt
			{
				Arr = source.Arr;									//Assign Array to that of the source
				m_current = source.m_current;						//Assign the current index to that of the source
			}
			return *this;
		}

		template <typename T>
		void Stack<T>::Push(T cur_ele)								//A Push() function that stores the element at the current position in the embedded array
		{
			Arr[m_current] = cur_ele;								//Store the element at the current position in the embedded array
			m_current++;											//Increment the current position afterwards
		}

		template <typename T>
		T Stack<T>::Pop()											//A Pop() function that decrements the current positionand then returns the element at that position
		{
			--m_current;											//Decrement the current position
			T Pop_Ele = Arr[m_current];
			return Pop_Ele;											//Then return the element at that position
		}

		template <typename T>
		int Stack<T>::Current() const								//Current() function is a getter that returns the current element number (index + 1) (makes it easier to test in main)
		{
			return m_current + 1;
		}

		template <typename T>
		T Stack<T>::Element() const									//Element() function is a getter that returns the current element (makes it easier to test in main)
		{
			return Arr[m_current - 1];
		}
	}
}
#endif