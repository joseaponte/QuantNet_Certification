//IsLess.hpp is the header file that declares the class for IsLess
#ifndef IS_LESS_THAN_HPP
#define IS_LESS_THAN_HPP

class IsLess
{
private:
	double m_val;										//Private data member for value to be checked against

public:
	IsLess();											//Default Constructor
	~IsLess();											//Destructor

	IsLess(double val);									//Constructor with double value parameter
	IsLess(const IsLess& ILT);							//Copy Constructor

	IsLess& operator = (const IsLess& source);			//Assignment operator
	bool operator() (double Ele);						//Overloaded round bracket operator that in this case has the same signature and functionality as the global function created previously

	void Val(double Set);								//Setter for m_val
	double Val() const;									//Getter for m_val
};
#endif