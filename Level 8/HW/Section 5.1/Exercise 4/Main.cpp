//Exercise 5.1.4 asks us to simulate dice throwing using functionality in Random library by creating a discrete uniform random number generator whose outcomes are in the closed range [1, 6]

#include <iostream>
#include <map>
#include "boost/random.hpp"

using namespace std;

int main()
{
	// Throwing dice.
	// Mersenne Twister.
	boost::random::mt19937 myRng;

	// Set the seed.
	myRng.seed(static_cast<boost::uint32_t> (std::time(0)));

	// Uniform in range [1,6]
	boost::random::uniform_int_distribution<int> six(1, 6);

	//We now create a map that holds the frequency of each outcome :
	map<int, long> statistics;		// Structure to hold outcome + frequencies
	int outcome;					// Current outcome

	//A typical outcome is generated as follows :
	outcome = six(myRng);
	//This will generate a number in the range [1,6]

	long tri_num;					//Declaring a long int for a number of trials
	cout << "How many trials?  ";
	cin >> tri_num;					//Allowing user to decide number of trials
	cout << endl;

	for (int i = 0; i < 6; i++)		//For 0<=i<6
	{
		statistics[i] = 0;			//Initialize each element of the map to 0
	}

	for (int i = 1; i < tri_num + 1; i++)	//For 0<=i<tri_num
	{
		outcome = six(myRng);				//Simulate a dice roll
		if (outcome == 1)					//If the outcome is one
		{
			statistics[0] ++;				//Increment the first element
		}
		else if (outcome == 2)				//If the outcome is two
		{
			statistics[1] ++;				//Increment the second element
		}
		else if (outcome == 3)				//If the outcome is threee
		{
			statistics[2] ++;				//Increment the third element
		}
		else if (outcome == 4)				//If the outcome is four
		{
			statistics[3] ++;				//Increment the fourth element
		}
		else if (outcome == 5)				//If the outcome is five
		{
			statistics[4] ++;				//Increment the fifth element
		}
		else
		{
			statistics[5] ++;				//If the outcome is 6, increment the sixth element
		}
	}

	for (int i = 0; i < 6; i++)				//Print the results
	{
		double per = statistics[i] * 100.0 / tri_num;
		cout << "Trial " << i + 1 << " has " << per << "% outcomes" << endl;
	}

	//Output should look like:
	//	How many trials? 1000000
	// 
	//	Trial 1 has 16.6677 % outcomes
	//	Trial 2 has 16.6551 % outcomes
	//	Trial 3 has 16.6881 % outcomes
	//	Trial 4 has 16.7103 % outcomes
	//	Trial 5 has 16.6273 % outcomes
	//	Trial 6 has 16.6515 % outcomes

	return 0;
}