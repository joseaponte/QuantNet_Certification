//Exercise 5.1.2 asks us to perform the following tasks while working with Tuples from boost
//Create a typedef for a Person tuple that contains a name, age and length,
//Create a function that prints the person tuple using the get<T>() member functions to retrieve the data.
//Create a few person tuple instances and print them.
//And increment the age of one of the persons.

#include "boost/tuple/tuple.hpp"		//Include boost tuple header file
#include <iostream>						//Include iostream header file
#include <iomanip>						//Include input output manipulation header file
#include <string>						//Include string header file
#include "boost/tuple/tuple_io.hpp"		//Include boost tuple input output header file

using namespace std;

//Create a typedef for a Person tuple that contains a name, age and length,
typedef boost::tuple<string, int, double> Person;

//Declaring a function that prints the person tuple
void Print(const Person& indiv);

int main()
{
	//Create a few person tuple instances
	Person John(string("John"), 45, 5.9);				//Defining a person named John who's 45 and 5.9 units long
	Person Eric(string("Eric"), 25, 6.2);				//Defining a person named Eric who's 25 and 6.2 units long
	Person Bob(string("Bob"), 19, 5.5);					//Defining a person named Bob who's 19 and 5.5 units long
	Person Ellie(string("Ellie"), 29, 5.6);				//Defining a person named Ellie who's 29 and 5.6 units long
	Person Mary(string("Mary"), 62, 5.8);				//Defining a person named Mary who's 62 and 5.8 units long
	
	//Print them
	Print(John);								//Print description of John
	Print(Eric);								//Print description of Eric
	Print(Bob);									//Print description of Robert
	Print(Ellie);								//Print description of Ellie
	Print(Mary);								//Print description of Mary

	cout << "==========================================================" << endl;
	cout << "One birthday later for Ellie: " << endl;
	//Increment the age of one of the persons (using the get<T>() function since it returns a reference to the value)
	Ellie.get<1>()++;		//Increment Ellie's age
	Print(Ellie);			//Print the description of Ellie again
	return 0;
}

//Defining a function that prints the person tuple
void Print(const Person& indiv)
{
	cout << "Name: " << left << setw(5) << indiv.get<0>() << " / Age: " << setw(2) << indiv.get<1>() << " / Length: " << setw(2) << indiv.get<2>() << endl;
	//setw() and left just set the width and formatting to make the output look nicer (can easily change the 5 to something else if longer names were used
	//Using the get<T>() member functions the retrieve the data
}