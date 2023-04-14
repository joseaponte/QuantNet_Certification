//Stack.cpp implements the stack class defined in the stack header file
#ifndef Stack_cpp
#define Stack_cpp

#include "Stack.hpp"
#include "StackException.hpp"

namespace JoseAponte
{
	namespace Containers
	{
		template <typename T, int size>
		Stack<T, size>::Stack() : m_array(size), m_current(0) {}									//Default Constructor

		template <typename T, int size>
		Stack<T, size>::~Stack() {}																		//Destructor

		template <typename T, int size>
		Stack<T, size>::Stack(const Stack<T, size>& Stk) : m_array(Stk.m_array), m_current(Stk.m_current) {}	//Copy Constructor
		
		//template <typename T, int size>
		//Stack<T>::Stack(int si) : Arr(Array<T>(si)), m_current(0) {}			//Constructor w/ int parameter
		//remove the constructor with size

		template <typename T, int size>
		Stack<T, size>& Stack<T,size>::operator = (const Stack<T, size>& source)				//Assignment Operator
		{
			if (this != &source)									//Prevent Self Assignemnt
			{
				m_array = source.m_array;							//Assign Array to that of the source
				m_current = source.m_current;						//Assign the current index to that of the source
			}
			return *this;
		}

		template <typename T, int size>
		void Stack<T, size>::Push(T cur_ele)								//A Push() function that stores the element at the current position in the embedded array
		{
			try
			{
				m_array[m_current] = cur_ele;							//Store the element at the current position in the embedded array
				m_current++;										//Increment the current position afterwards
			}
			catch (ArrayException& error)
			{
				throw StackFullException();							//In the catch handler, throw a StackFullException exception
			}
		}

		template <typename T, int size>
		T Stack<T, size>::Pop()											//A Pop() function that decrements the current positionand then returns the element at that position
		{
			try
			{
				--m_current;											//Decrement the current position
				T Pop_Ele = m_array[m_current];
				return Pop_Ele;											//Then return the element at that position
			}
			catch (ArrayException& err)
			{
				m_current = 0;											//Also set the current index back to 0
				throw StackEmptyException();							//In the catch handler, throw a StackFullException exception
			}
		}

		template <typename T, int size>
		int Stack<T, size>::Current() const								//Current() function is a getter that returns the current element numeber (index + 1)(makes it easier to test in main)
		{
			return m_current + 1;
		}

		template <typename T, int size>
		T Stack<T, size>::Element() const									//Element() function is a getter that returns the current element (makes it easier to test in main)
		{
			return m_array[m_current - 1];
		}
	}
}
#endif