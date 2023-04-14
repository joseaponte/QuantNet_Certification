//PerpAmericanOption.cpp is a source file that defines 
//and implements the class for Perpetural American options,
//which represents its solutions

#include "PerpAmericanOption.hpp"

PerpAmericanOption::PerpAmericanOption() : r(0.05), sig(0.2), K(110), b(r), opt_type('C'), und_as("UNKWN") {}
//Default Constructor that initializes the risk-free rate to 0.05, volatility to 0.2, strike price to 110,
//Cost of carry to the risk-free rate, type to call, and underlying asset to unknown

PerpAmericanOption::PerpAmericanOption(const PerpAmericanOption& PAO) : r(PAO.r), sig(PAO.sig), K(PAO.K), b(PAO.b), opt_type(PAO.opt_type), und_as(PAO.und_as) {}
//Copy constructor that copies the risk-free rate, volatiltity, strike price, cost of carry, option type, and name of underlying asset of another perpetual american option

PerpAmericanOption::PerpAmericanOption(const char& Type) : r(0.05), sig(0.2), K(110), b(r), und_as("UNKWN")
{
	{
		if (Type == 'P' || Type == 'C')																//If the user tries a valid input for the type
		{
			opt_type = Type;																		//Allow them to decided the type and set the type to input
		}
		else
		{																							//Otherwise, (if an invalid is tried)
			std::cout << "Invalid type. Setting the type to Call by default." << std::endl;			//Let the user know what's happening
			opt_type = 'C';																			//Set the option type to a call
		}
	}
}
//Constructor that initializes the risk-free rate to 0.05, volatility to 0.2, strike price to 110,
//Cost of carry to the risk-free rate, and underlying asset to unknown
//Very similar to default constructor but this allows user to decide which type
//If an invalid type is attempted, the option is set as a call by default

PerpAmericanOption::PerpAmericanOption(const double& r1, const double& sig1, const double& K1, const char& opt_type1, const std::string& und_as1) : r(r1), sig(sig1), K(K1), b(r1), und_as(und_as1)
{
	{
		if (opt_type1 == 'P' || opt_type1 == 'C')														//If the user tries a valid input for the type
		{
			opt_type = opt_type1;																		//Allow them to decided the type and set the type to input
		}
		else
		{																								//Otherwise, (if an invalid is tried)
			std::cout << "Invalid type. Setting the type to Call by default." << std::endl;				//Let the user know what's happening
			opt_type = 'C';																				//Set the option type to a call
		}
	}
}
//Constructor that allows inititialization of all data members (assuming a valid type is attempted)
//If an invalid type is attempted, the option is set as a call by default

PerpAmericanOption::~PerpAmericanOption() {}												//Destructor

PerpAmericanOption& PerpAmericanOption::operator = (const PerpAmericanOption& source)		//Assignment operator
{

	if (this == &source)						//Prevent self-assignment
	{
		r = source.r;							//Assign risk-free rate to that of source
		sig = source.sig;						//Assign volatility to that of source
		K = source.K;							//Assign strike price to that of source
		b = source.b;							//Assign cost of carry to that of source
		opt_type = source.opt_type;				//Assign option type to that of source
		und_as = source.und_as;					//Assign name of underlying asset to that of source
	}

	return *this;
}

double PerpAmericanOption::Price(const double& val_1) const									//Function that accepts a value for the underlying asset and calculates option price
{
	if (opt_type == 'C')																	//If the option is a call
	{
		double y1 = 0.5 - (b / (sig * sig)) + sqrt((b / (sig * sig) - 0.5) * (b / (sig * sig) - 0.5) + (2 * r) / (sig * sig));
		//Declare, initialize, and calculate a double which equals 0.5-(b/sig^2)+sqrt(((b/sig^2)-(1/2))^2 + 2r/sig^2)
		if (y1 != 1)																		//As long as y1 doesn't equal 1 (prevent dividing by 0)
		{
			return (K / (y1 - 1)) * pow(((y1 - 1) / y1) * (val_1 / K), y1);
			//Return the call price which equals K/(y1-1)*(S(y1-1)/K*y1)^y1
		}
		else
		{	//Otherwise, if y1=1
			return val_1;
			//Return the parameter
		}
	}
	else
	{																						//Otherwise, (if it's a put)
		double y2 = 0.5 - (b / (sig * sig)) - sqrt((b / (sig * sig) - 0.5) * (b / (sig * sig) - 0.5) + (2 * r) / (sig * sig));
		//Declare, initialize, and calculate a double which equals 0.5-(b/sig^2)-sqrt(((b/sig^2)-(1/2))^2 + 2r/sig^2)
		if (y2 != 1)																		//As long as y2 doesn't equal 1 (prevent dividing by 0)
		{
			return (K / (1 - y2)) * pow(((y2 - 1) / y2) * (val_1 / K), y2);
			//Return the put price which equals K/(1-y2)*(S(y2-1)/K*y2)^y2
		}
		else
		{	//Otherwise, if y2=1
			return val_1;
			//Return the parameter
		}
	}
}

double PerpAmericanOption::Delta(const double& value_1) const								//Function that could be used to calculate the Delta of a Perpetual American Function (needed for compatibility with Matrix_Mesh() function
{
	return (NULL);																			//Return Null if this is called, since we don't have a formula
}

double PerpAmericanOption::Gamma(const double& value_2) const								//Function that could be used to calculate the Delta of a Perpetual American Function (needed for compatibility with Matrix_Mesh() function
{
	return (NULL);																			//Return Null if this is called, since we don't have a formula
}

void PerpAmericanOption::Toggle()				//Modifying function that changes type of option
{
	if (opt_type == 'C')						//If the type is a call
		opt_type = 'P';							//Change it to a put
	else
		opt_type = 'C';							//Otherwise (if it's a put) change it to a call
}

void PerpAmericanOption::Carry(const double& b1)				//Function that modifies the cost of carry
{
	b = b1;														//Assign the cost of carry to the parameter
}

//void PerpAmericanOption::Print() const
//{
//	std::cout << und_as << " " << opt_type << ": (" << r << ", " << sig << ", " << K << ", " << b << ")" << std::endl;
	//Prints a description of the option in the form of : "____ (P or C): (r, sig, K, b)"
//}