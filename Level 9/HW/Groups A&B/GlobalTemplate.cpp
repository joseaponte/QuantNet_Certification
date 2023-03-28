//GlobalTemplate.cpp is the source file that defines 
//and implements global template functions for the Group A,B project

#ifndef GLOBAL_TEMPLATE_CPP							//Need to use this method in source file for templates
#define GLOBAL_TEMPLATE_CPP							//So define this if it hasn't yet been defined

#include "PerpAmericanOption.hpp"					//Include PerpAmericanOption header file
#include <typeinfo>									//Include typeinfo header file (for type checking)

//Defining global function that produces a mesh array of doubles separated by a mesh size h
template <typename T>
std::vector<double> Mesh(const T& Opt, const double& start_val, const double& end_val, const double& h_3, const char& which_type)
{
	std::vector<double> mesh_vec;										//Declare the vector to be returned
	if (which_type == 'O')												//If asking for changes in the price (made it O for price of option to differentiate from put's 'P')
	{
		for (double d = start_val; d <= end_val; d += h_3)				//For values between the start and end value (inclusive)
		{
			mesh_vec.push_back(Opt.Price(d));							//New element = Price of option at start value + step size * iteration number
		}
	}
	else if (which_type == 'D')											//If asking for changes in the delta
	{
		for (double d = start_val; d <= end_val; d += h_3)				//For values between the start and end value (inclusive)
		{
			mesh_vec.push_back(Opt.Delta(d));							//New element = Delta of option at start value + step size * iteration number
		}
	}
	else
	{																	//Otherwise, assume asking for changes in gamma

		for (double d = start_val; d <= end_val; d += h_3)				//For values between the start and end value (inclusive)
		{
			mesh_vec.push_back(Opt.Gamma(d));							//New element = Gamma of option at start value + step size * iteration number
		}
	}

	return mesh_vec;													//Return the vector
}

//Defining function that calculates prices, gammas, or deltas of an option based on varying underlying asset prices and another parameter
template <typename T>
std::vector<std::vector<double> > Matrix_Mesh(T& OP, const char& mem, const double& start_value, const double& end_value, const double& strt, const double& nd, const double& val_h, const double& para_h, const char& which_typ)
{
	std::vector<double> Inner_Vec;													//Declaring a vector of doubles that stores values of an option depending on underlying asset's price
	std::vector<std::vector<double> > Mesh_Mat;										//Declaring a matrix (vector of vectors) that stores values of an option depending on a parameter and the underlying asset's price
	if (mem == 'T' && typeid(OP).name() != typeid(PerpAmericanOption).name())		//If the member trying to be accessed is time to maturity and the object isn't a PerpAmericanObject
	{
		double tmp = OP.T;															//Store the time to maturity in a temporary double
		for (double d_2 = strt; d_2 <= nd; d_2 += para_h)							//For the given bounds
		{
			OP.T = d_2;																//Change the time to maturity to some value based on the parameters
			Inner_Vec = Mesh(OP, start_value, end_value, val_h, which_typ);			//Initialize a vector to be pushed by into the other vector of vectors using the Mesh() function
			Mesh_Mat.push_back(Inner_Vec);											//Push that vector back into the vector of vectors
		}
		OP.T = tmp;																	//Return time to maturity to its original value
	}
	else if (mem == 'r')															//If the member trying to be accessed is the risk-free rate
	{
		double tmp = OP.r;															//Store the risk-free rate in a temporary double
		for (double d_2 = strt; d_2 <= nd; d_2 += para_h)							//For the given bounds
		{
			OP.r = d_2;																//Change the risk-free rate to some value based on the parameters
			Inner_Vec = Mesh(OP, start_value, end_value, val_h, which_typ);			//Initialize a vector to be pushed by into the other vector of vectors using the Mesh() function
			Mesh_Mat.push_back(Inner_Vec);											//Push that vector back into the vector of vectors
		}
		OP.r = tmp;																	//Return the risk-free rate to its original value
	}
	else if (mem == 'V')															//If the member trying to be accessed is the volatility
	{
		double tmp = OP.sig;														//Store the volatility in a temporary double
		for (double d_2 = strt; d_2 <= nd; d_2 += para_h)							//For the given bounds
		{
			OP.sig = d_2;															//Change the volatility to some value based on the parameters
			Inner_Vec = Mesh(OP, start_value, end_value, val_h, which_typ);			//Initialize a vector to be pushed by into the other vector of vectors using the Mesh() function
			Mesh_Mat.push_back(Inner_Vec);											//Push that vector back into the vector of vectors
		}
		OP.sig = tmp;																//Return the volatility to its original value
	}
	else if (mem == 'b')															//If the member trying to be accessed is cost of carry
	{
		double tmp = OP.b;															//Store the cost of carry in a temporary double
		for (double d_2 = strt; d_2 <= nd; d_2 += para_h)							//For the given bounds
		{
			OP.b = d_2;																//Change the cost of carry to some value based on the parameters
			Inner_Vec = Mesh(OP, start_value, end_value, val_h, which_typ);			//Initialize a vector to be pushed by into the other vector of vectors using the Mesh() function
			Mesh_Mat.push_back(Inner_Vec);											//Push that vector back into the vector of vectors
		}
		OP.b = tmp;																	//Return the cost of carry to its original value
	}
	else																			//Otherwise, assume the strike price is tring to be accessed
	{
		double tmp = OP.K;															//Store the strike price in a temporary double
		for (double d_2 = strt; d_2 <= nd; d_2 += para_h)							//For the given bounds
		{
			OP.K = d_2;																//Change the strike price to a some value based on the parameters
			Inner_Vec = Mesh(OP, start_value, end_value, val_h, which_typ);			//Initialize a vector to be pushed by into the other vector of vectors using the Mesh() function
			Mesh_Mat.push_back(Inner_Vec);											//Push that vector back into the vector of vectors
		}
		OP.K = tmp;																	//Return strike price to its original value
	}
	return Mesh_Mat;																//Retrun the matrix/vector of vectors of doubles
}
#endif // !GLOBAL_TEMPLATE_CPP