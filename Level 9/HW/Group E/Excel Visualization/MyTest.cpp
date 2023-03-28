//Group F is a project that builds onto the project from Group 
//A&B except, this time, the output is produced in Excel

#include "GlobalTemplate.hpp"
#include "UtilitiesDJD/VectorsAndMatrices/Vector.cpp"
#include "UtilitiesDJD/ExcelDriver/ExcelDriverLite.hpp"
#include "UtilitiesDJD/Geometry/Range.cpp"
#include "UtilitiesDJD/ExceptionClasses/DatasimException.hpp"

int main()
{
	EuropeanOption Batch1(0.08, 0.30, 65, 0.25, 'C', "Batch 1");								//Declare and initialize a European Option with T=0.25,K=65,sig=0.30,r=0.08
	std::vector<double> MyVectorCall = Mesh(Batch1, 55, 65, 1, 'O');							//Initialize a vector for the values of the call for values of the underlying asset between 55 and 65 in increments of 1
	Batch1.Toggle();																			//Initialize a vector for the values of the put for values of the underlying asset between 55 and 65 in increments of 1
	std::vector<double> MyVectorPut = Mesh(Batch1, 55, 65, 1, 'O');								//Print values of the option for values of the underlying asset between 59 and 61 in increments of 0.3
	std::vector<double> Underlying_Values = { 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65 };
	//Initialize a vector of doubles for the values of the underlying assets [55,65] in increments of 1

	try
	{
		printOneExcel(Underlying_Values, MyVectorPut, string("UA v P"), string("Under"), string("Put"), string("Prices"));
	}
	catch (DatasimException& e)																	//Catch datasim exceptions
	{
		e.print();																				//Handle it by calling the print() function
	}
	catch (...)																					//Handle everything else by printing "Ooops"
	{
		std::cout << "Ooops" << std::endl;
	}

	return 0;
}