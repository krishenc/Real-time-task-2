#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

bool fstreamGood(const fstream &, const string);
bool ifstreamGood(const ifstream &, const string);
bool ofstreamGood(const ofstream &, const string);

bool fstreamGood(const fstream &stream, const string fileName)
{
	if (!stream.good()) 
	{
		std::cout << "file " + fileName + " not found." << endl;
		std::cout << "press any button to continue..." << endl;
		std::cin.ignore();
		return false;
	}
	else
	{
		return true;
	}
}
bool ifstreamGood(const ifstream &stream, const string fileName)
{
	if (!stream.good()) 
	{
		std::cout << "file " + fileName + " not found." << endl;
		std::cout << "press any button to continue..." << endl;
		std::cin.ignore();
		return false;
	}
	else
	{
		return true;
	}
}
bool ofstreamGood(const ofstream &stream, const string fileName)
{
	if (!stream.good()) 
	{
		std::cout << "file " + fileName + " not found." << endl;
		std::cout << "press any button to continue..." << endl;
		std::cin.ignore();
		return false;
	}
	else
	{
		return true;
	}
}

int main(int argc, char* argv[])
{
	ifstream programtxt;
	ifstream programh_in;
	ifstream programcpp_in;
	ofstream programh_out;
	ofstream programcpp_out;

	string fileName;
	string readLine;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// count the number of programs
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	// open program.txt for reading
	fileName = "programs.txt";
	programtxt.open(fileName);
	if (!ifstreamGood(programtxt, fileName)) return 0;

	// count the number of program declarations in the file
	cout << "Counting number of programs in programs.txt" << endl;
	int programCount = 0;
	while (std::getline(programtxt, readLine))
	{
		if ( readLine.find(std::to_string(programCount+1) + ":") != string::npos)
		{
			programCount++;
		}
	}
	cout << "Found " + std::to_string(programCount) + " programs." << endl;
	programtxt.close();

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// write the #define MaxPrograms in Program.h
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	// open program.h for reading
	fileName = "program.h";
	programh_in.open(fileName);
	if (!ifstreamGood(programh_in, fileName)) return 0;

	// write to temp string, but with line replacement
	cout << "Replacing #define MaxPrograms..." << endl;
	string strProgramh;
	while (std::getline(programh_in, readLine))
	{
		if ( readLine.find("#define MaxPrograms") != string::npos)
		{
			readLine = "#define MaxPrograms " + std::to_string(programCount);
		}
		strProgramh.append(readLine + "\n");
	}

	cout << strProgramh << endl;

	// close and reopen program.h for writing
	programh_in.close();
	fileName = "programNew.h";
	programh_out.open(fileName);
	if (!ofstreamGood(programh_out, fileName)) return 0;
	programh_out << strProgramh << endl;
	programh_out.close();
	
	remove("programOld.h");
	rename("program.h", "programOld.h");
	rename("programNew.h", "program.h");

	// ~~~~~~~~~~~~~~~~~~~
	// write programs.cpp
	// ~~~~~~~~~~~~~~~~~~~
	
	// open program.txt for reading
	fileName = "programs.txt";
	programtxt.open(fileName);
	if (!ifstreamGood(programtxt, fileName)) return 0;

	// build constructor function definition from txt file
	cout << "building new constructor function..." << endl;
	string constructorFunction;
	int program = 0;
	while(std::getline(programtxt, readLine))
	{
		int cycle = 0;
		// look for new program definition i.e. 1:ColourWash
		if ( readLine.find(std::to_string(program+1) + ":") != string::npos)
		{
			program++;
			cycle = 0;
			// look for final cycle definition
			while(readLine.find("Complete") == string::npos)
			{
				std::getline(programtxt, readLine);
				constructorFunction.append("\tPrograms[" + std::to_string(program) + "][" + std::to_string(cycle++) + "]");
				constructorFunction.append(" = WashCycle(" + readLine + "); \n");
			}
		}
	}
	cout << "Constructor function contents:" << endl;
	cout << constructorFunction << endl;

	// open program.cpp for reading
	fileName = "program.cpp";
	programcpp_in.open(fileName);
	if (!ifstreamGood(programcpp_in, fileName)) return 0;

	// append file to temporary string until we find Program::Program()
	string strProgramcpp;
	while (std::getline(programcpp_in, readLine))
	{
		if ( readLine.find("Program::Program()") != string::npos)
		{
			strProgramcpp.append("Program::Program()\n");
			strProgramcpp.append("{\n");
			strProgramcpp.append(constructorFunction);
			strProgramcpp.append("}\n");
			break;
		}
		strProgramcpp.append(readLine + "\n");
	}

	programcpp_in.close();
	fileName = "programNew.cpp";
	programcpp_out.open(fileName);
	if (!ofstreamGood(programcpp_out, fileName)) return 0;
	programcpp_out << strProgramcpp << endl;
	programcpp_out.close();
	
	remove("programOld.cpp");
	rename("program.cpp", "programOld.cpp");
	rename("programNew.cpp", "program.cpp");

	std::cout << "press any button to continue..." << endl;
	std::cin.ignore();




	/* OLD CODE
	int program = 1;
	string outputString;
	string tempProgramArray;
	string programName;
	std::size_t dotPos = 0;
	std::cout << "strings defined"<< endl;
	outputString.append("//This file is created automatically from the programs.txt\n\n");
	outputString.append("class ProgramData\n"
		"{ \n"
		"	private:\n" 
		"		int Status;\n" 
		"		int Time;\n" 
		"		int Speed;\n\n" 
		
		"	public:\n" 
		"		ProgramData();\n" 
		"		void SetData(int, int, int);\n" 
		"};\n\n"
	);

	
	// go back to beginning of file
	//input.seekg(0);
	input.close();
	input.open("Programs.txt");
	std::cout << "Back to start of input file" << endl;

	while (std::getline(input, readLine))
	{
		int cycle = 0;
		std::cout << "line read " + std::to_string(program) + "." << endl;

		if ( readLine.find(std::to_string(program) + ".") != string::npos)
		{
			std::cout << "finding first ."<< endl;
			cycle = 0;
			
			dotPos = readLine.find(".");
			std::cout << "dotPos: " + std::to_string(dotPos) << endl;
			programName = readLine.substr(dotPos+1,readLine.size());
			tempProgramArray = "";

			
			
			while(readLine.find("Complete") == string::npos)
			{
				std::getline(input, readLine);
				std::cout << "reading line: " + readLine << endl;
				tempProgramArray.append(programName + "[" + std::to_string(cycle++) + "].SetData(");
				tempProgramArray.append(readLine + "); \n");
			}

			outputString.append("//" + programName + " is defined below\n");

			outputString.append(programName + " = new ProgramData[" + std::to_string(cycle) + "]; \n");
			
			outputString.append(tempProgramArray);

			outputString.append("ProgramArray[" +  std::to_string(program-1) + "] = " + programName + "*; \n\n");
			program++;
		}
	}
	outputString.append("#define NumberofPrograms " + std::to_string(program-1));
	input.close();
	
	output << outputString << endl;
	output.close();
	
	std::cout << "press any button to continue..." << endl;
	std::cin.ignore();
	*/
	return 0;
}

