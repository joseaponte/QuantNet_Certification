//EuropeanOption.cpp is a source file that defines and 
//implements the class for European (plain) options,
//which represents solutions to European Options

#include "EuropeanOption.hpp"

EuropeanOption::EuropeanOption() : r(0.05), sig(0.2), K(110), T(0.5), b(r), opt_type('C'), und_as("UNKWN") {}
//Default Constructor that initializes the risk-free rate to 0.05, volatility to 0.2, strike price to 110,
//Time to maturity of 0.5, cost of carry to the risk-free rate, type to call, and underlying asset to unknown

EuropeanOption::EuropeanOption(const EuropeanOption& EO) : r(EO.r), sig(EO.sig), K(EO.K), T(EO.T), b(EO.b), opt_type(EO.opt_type), und_as(EO.und_as) {}
//Copy constructor that copies the risk-free rate, volatiltity, strike price, time to maturity, cost of carry, option type, and name of underlying asset of another european option

EuropeanOption::EuropeanOption(const char& Type) : r(0.05), sig(0.2), K(110), T(0.5), b(r), und_as("UNKWN")
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
//Time to maturity to 0.5, cost of carry to the risk-free rate, and underlying asset to unknown
//Very similar to default constructor but this allows user to decide which type
//If an invalid type is attempted, the option is set to a call by default

EuropeanOption::EuropeanOption(const double& r1, const double& sig1, const double& K1, const double& T1, const char& opt_type1, const std::string& und_as1) : r(r1), sig(sig1), K(K1), T(T1), b(r1), und_as(und_as1)
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
//If an invalid type is attempted, the option is set to a call by default

EuropeanOption::~EuropeanOption() {}											//Destructor

EuropeanOption& EuropeanOption::operator = (const EuropeanOption& source)		//Assignment operator
{

	if (this == &source)						//Prevent self-assignment
	{
		r = source.r;							//Assign risk-free rate to that of source
		sig = source.sig;						//Assign volatility to that of source
		K = source.K;							//Assign strike price to that of source
		T = source.T;							//Assign time to maturity to that of source
		b = source.b;							//Assign cost of carry to that of source
		opt_type = source.opt_type;				//Assign option type to that of source
		und_as = source.und_as;					//Assign name of underlying asset to that of source
	}

	return *this;
}

double EuropeanOption::Price(const double& val_1) const
{
	double d1 = (log(val_1 / K) + (b + (sig * sig) * 0.5) * T) / (sig * sqrt(T));
	//Declare and initialize a double for a conditional probability
	double d2 = d1 - (sig * sqrt(T));
	//Declare and initialize a double for the probability that the option expires in the money
	boost::math::normal_distribution<> N(0.0, 1.0);
	//Declare and initialize a standard normal distribution from boost library

	if (opt_type == 'C')					//If option type is call
	{
		return (val_1 * exp((b - r) * T) * cdf(N, d1)) - (K * exp(-r * T) * cdf(N, d2));
	}	//Return price which equals Se^((b-r)T)*N(d1)-(Ke^(-rT) * N(d2))
	else
	{										//Otherwise, (if it's a put)
		return (K * exp(-r * T) * cdf(N, -d2) - val_1 * exp((b - r) * T) * cdf(N, -d1));
	}	//Return price which equals Ke^(-rT) * N(-d2)-Se^(b-r)*N(-d1)
}

double EuropeanOption::PCP_Price(const double& val_2) const			//Put-Call Parity pricing function which returns the value of the opposite type (put price for a call, call price for a put)
{
	if (opt_type == 'C')											//If the option is a call
	{
		return (this->Price(val_2) + K * exp(-r * T) - val_2);		//Return corresponding put price P=C+Ke^(-rT)-S
	}
	else
	{																//Otherwise, (if it's a put)
		return (this->Price(val_2) + val_2 - K * exp(-r * T));		//Return corresponding call price C=P+S-Ke^(-rT)//Otherwise, (if it's a put (originally a call))
	}
}

void EuropeanOption::PCP_Check(const double& val_3) const										//Function that checks whether a set of prices satisfy PCP
{
	if (opt_type == 'C')																		//If the option is a call
	{
		if ((this->Price(val_3) + K * exp(-r * T)) == (this->PCP_Price(val_3) + val_3))			//If C+Ke^(-rT)=P+S
		{
			std::cout << "Put-Call Parity passed." << std::endl;								//Print "Put-Call Parity passed."
		}
		else
		{																						//Otherwise (if they don't equal)
			std::cout << "Put-Call Parity failed." << std::endl;								//Print "Put-Call Parity failed."
		}
	}
	else
	{																							//Otherwise, (If the option is a put)
		if ((this->Price(val_3) + val_3) == (this->PCP_Price(val_3) + K * exp(-r * T)))			//If P+S=C+Ke^(-rT)
		{
			std::cout << "Put-Call Parity passed." << std::endl;								//Print "Put-Call Parity passed."
		}
		else
		{																						//Otherwise (if they don't equal)
			std::cout << "Put-Call Parity failed." << std::endl;								//Print "Put-Call Parity failed."
		}
	}
}
double EuropeanOption::Delta(const double& value_1) const							//Function that calculates delta (option's value sensititivity to underlying asset price)
{
	double d1 = (log(value_1 / K) + (b + (sig * sig) * 0.5) * T) / (sig * sqrt(T));
	//Declare and initialize a double for a conditional probability
	boost::math::normal_distribution<> N(0.0, 1.0);
	//Declare and initialize a standard normal distribution from boost library
	if (opt_type == 'C')					//If the option is a call
	{
		return (exp((b - r) * T) * cdf(N, d1));
	}	//Return the delta which equals e^((b-r)T)*N(d1) (Should be between 0 and 1)
	else
	{
		//Otherwise, (if the option is a put)
		return -(exp((b - r) * T) * cdf(N, -d1));
	}	//Return the delta which equals -e^((b-r)T)*N(-d1) (Should be between -1 and 0)
}

double EuropeanOption::Gamma(const double& value_2) const							//Function that calculates gamma (rate of change of an option's delta)
{
	double d1 = (log(value_2 / K) + (b + (sig * sig) * 0.5) * T) / (sig * sqrt(T));
	//Declare and initialize a double for a conditional probability
	boost::math::normal_distribution<> N(0.0, 1.0);
	//Declare and initialize a standard normal distribution from boost library

	return (pdf(N, d1) * exp((b - r) * T) / (value_2 * sig * sqrt(T)));
	//Return gamma which equals (n(d1)e^(b-r)*T)/(S*sig*sqrt(T))
}

double EuropeanOption::Approx_Delta(const double& value_3, const double& h_1) const		//Function that approximates Delta using numerical methods
{
	if (h_1 != 0)																		//Prevent dividing by zero
	{
		return (Price(value_3 + h_1) - Price(value_3 - h_1)) / (2 * h_1);				//Return (V(S+h)-V(S-h))/2h
	}
	else
	{																					//Otherwise
		std::cout << "Invalid step size." << std::endl;									//Tell the user that the step size is invalid
	}
}

double EuropeanOption::Approx_Gamma(const double& value_4, const double& h_2) const		//Function that approximates the Gamma using numerical methods
{
	if (h_2 != 0)																		//Prevent dividing by zero
	{
		return (Price(value_4 + h_2) - 2 * Price(value_4) + Price(value_4 - h_2)) / (h_2 * h_2);	//Return (V(S+h)-2V(S)+V(S-h))/(h^2)
	}
	else
	{
		std::cout << "Invalid step size." << std::endl;									//Tell the user that the step size is invalid
	}
}

//void EuropeanOption::Print() const				//Function that prints description of option (For flexibility, can easily be commented out if it's decided we don't want public accessibility)
//{
//	std::cout << und_as << " " << opt_type << ": (" << r << ", " << sig << ", " << K << ", " << T << ", " << b << ")" << std::endl;
//}	//Prints a description of the option in the form of : "____ (P or C): (r, sig, K, T, b)"

void EuropeanOption::Toggle()					//Modifying function that changes type of option
{
	if (opt_type == 'C')						//If the type is a call
		opt_type = 'P';							//Change it to a put
	else
		opt_type = 'C';							//Otherwise (if it's a put) change it to a call
}

void EuropeanOption::Carry(const double& b1)					//Function that modifies the cost of carry
{
	b = b1;														//Assign the cost of carry to the parameter
}