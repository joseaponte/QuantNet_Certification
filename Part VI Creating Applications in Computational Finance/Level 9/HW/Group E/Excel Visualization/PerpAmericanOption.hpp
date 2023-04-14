//PerpAmericanOption.hpp is a header file that declares 
//the class for Perpetural American options,
//which is a class that represents solutions to
// Perpetual American options.

#ifndef PERP_AMERICAN_OPTION_HPP							//Avoid multiple inclusions by not allowing
#define PERP_AMERICAN_OPTION_HPP							//PERP_AMERICAN_OPTION_HPP to be defined more than once

#include "Global.hpp"

class PerpAmericanOption
{
private:
	double r;			//Private data member for the risk-free interest rate
	double sig;			//Private data member for the underlying asset's volatiltiy (sigma) 
	double K;			//Private data member for the option's strike price
	double b;			//Private data member for the cost of carry
	double T = (NULL);	//Private data member for the time to maturity (Nulll since there isn't one for Perpetual American Options, but necessay for Matrix_Mesh() function)

	char opt_type;			//Private data member for the option type (call or put)
	std::string und_as;		//Private date member for the name of underlying asset

public:
	//Constructors and Destructor:
	PerpAmericanOption();												//Default constructor
	PerpAmericanOption(const PerpAmericanOption& PAO);					//Copy constructor
	PerpAmericanOption(const char& Type);								//Specified type constructor
	PerpAmericanOption(const double& r1, const double& sig1, const double& K1, const char& opt_type1, const std::string& und_as1);
	//Constructor that allows inititialization of all data members (discluding cost of carry, which will be assigned the same value as risk-free rate)
	virtual ~PerpAmericanOption();										//Destructor

	//Operators:
	PerpAmericanOption& operator = (const PerpAmericanOption& source);		//Assignment Operator	

	//Pricing Function:
	double Price(const double& val_1) const;								//Function that accepts a value for the underlying asset and calculates option price

	//Sensitivity Functions:
	double Delta(const double& value_1) const;								//Function that calculates delta (option's value sensititivity to underlying asset price)
	double Gamma(const double& value_2) const;								//Function that calculates gamma (rate of change of an option's delta)

	//Modifier Functions:
	void Toggle();											//Change option type (call to put or put to call)
	void Carry(const double& b1);							//Function that modifies the cost of carry

	//Print/Description Function:
	//void Print() const;									//Function that prints description of option (For flexibility, can easily be commented out if it's decided we don't want public accessibilty)

	//Friend Function:
	template <typename T>
	friend std::vector<std::vector<double> > Matrix_Mesh(T& EUR, const char& mem, const double& start_value, const double& end_value, const double& strt, const double& nd, const double& val_h, const double& para_h, const char& which_typ);
	//Function that calculates prices, gammas, or deltas of an option based on varying underlying asset prices and another parameter
};

#endif