//Group A&B is a collective project that asks us to 
//create a robust, efficient, and concise program
//That performs fucntionality for option pricing, greeks, 
//and matrix pricing

#include "GlobalTemplate.hpp"

int main()
{
	EuropeanOption Batch1(0.045, 0.43, 122, 1.65, 'P', "Batch1");
	Batch1.Carry(0);
	std::cout << Batch1.Price(102) << std::endl;
	std::cout << Batch1.Delta(102) << std::endl;
	std::cout << Batch1.Gamma(102) << std::endl;


	return 0;
}