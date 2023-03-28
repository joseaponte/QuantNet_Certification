//Stack.hpp is the header file for the Stack Class which will
// use the Array class as a data member

#ifndef STACK_HPP
#define STACK_HPP
#include "Array.hpp"

namespace JoseAponte
{
	namespace Containers
	{
		template <typename T>
		class Stack
		{
		private:
			int m_current;										//A data member for the current index in the array	
			Array<T> Arr;										//Use the Array class as a data member

		public:
			Stack();											//Default Constructor
			~Stack();											//Destructor

			Stack(const Stack<T>& Stk);							//Copy Constructor
			Stack(int si);										//Constructor w/ an int parameter

			Stack<T>& operator = (const Stack<T>& source);		//Assignment Operator

			void Push(T cur_ele);								//Push() function that stores the element at the current position in the embedded array
			T Pop();											//Pop() function that decrements the current position and then returns the element at that position

			int Current() const;								//Getter function for current index
			T Element() const;									//Getter function for current element
		};
	}
}
#ifndef Stack_cpp
#include "Stack.cpp"
#endif
#endif