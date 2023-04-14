//EuropeanOption.hpp is a header file that declares the 
//class for European (plain) options,
//which is a class that represents  solutions to European options.

#ifndef EuropeanOption_hpp							//Avoid multiple inclusions by not allowing
#define EuropeanOption_hpp							//EuropeanOption_hpp to be defined more than once

#include <string>									//Include string header file
#include <boost/math/distributions/normal.hpp>		//Include boost normal distrubitions header file
#include <cmath>									//Inclde cmath header file
#include <iostream>									//Include iostream header file
#include <vector>									//Include vector header file

class EuropeanOption
{
private:
	double r;		//Private data member for the risk-free interest rate
	double sig;		//Private data member for the underlying asset's volatiltiy (sigma) 
	double K;		//Private data member for the strike price
	double T;		//Private data member for the expiry time/time to maturity
	double b;		//Private data member for the cost of carry

	char opt_type;			//Private data member for the option type (call or put)
	std::string und_as;		//Private date member for the name of underlying asset

public:
	//Constructors and Destructor:
	EuropeanOption();												//Default constructor
	EuropeanOption(const EuropeanOption& EO);						//Copy constructor
	EuropeanOption(const char& Type);								//Specified type constructor
	EuropeanOption(const double& r1, const double& sig1, const double& K1, const double& T1, const char& opt_type1, const std::string& und_as1);
	//Constructor that allows inititialization of all data members (discluding cost of carry, which will be assigned the same value as risk-free rate)
	virtual ~EuropeanOption();										//Destructor

	//Operators:
	EuropeanOption& operator = (const EuropeanOption& source);		//Assignment Operator	

	//Pricing Functions:
	double Price(const double& val_1) const;					//Function that accepts a value for the underlying asset and calculates option price
	double PCP_Price(const double& val_2) const;				//Function that calculates the price of an option based on generic put-call parity
	void PCP_Check(const double& val_3) const;					//Function that checks whether set of prices satisfy Put-Call Parity

	//Sensitivity Functions:
	double Delta(const double& value_1) const;								//Function that calculates delta (option's value sensititivity to underlying asset price)
	double Gamma(const double& value_2) const;								//Function that calculates gamma (rate of change of an option's delta)
	double Approx_Delta(const double& value_3, const double& h_1) const;	//Function that approximates the delta of an option using numerical methods
	double Approx_Gamma(const double& value_4, const double& h_2) const;	//function that approximates the gamma of an option using numerical methods

	//Modifier Functions:
	void Toggle();											//Change option type (call to put or put to call)
	void Carry(const double& b1);							//Function that modifies the cost of carry

	//Print/Description Function:
	//void Print() const;										//Function that prints description of option (For flexibility, can easily be commented out if it's decided we don't want public accessibility)

	//Friend Function:
	template <typename T>
	friend std::vector<std::vector<double> > Matrix_Mesh(T& EUR, const char& mem, const double& start_value, const double& end_value, const double& strt, const double& nd, const double& val_h, const double& para_h, const char& which_typ);
	//Function that calculates prices, gammas, or deltas of an option based on varying underlying asset prices and another parameter
};

#endif