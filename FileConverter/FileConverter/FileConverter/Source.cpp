#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	ifstream input;
	ofstream output;
	
	string fileName = string(argv[0]);

	// open input file
	input.open("Programs.txt");
	//input.open(fileName);
	if (!input.good()) 
	{
		std::cout << "file not found." << endl;
		std::cout << "press any button to continue..." << endl;
		std::cin.ignore();
		return 0;
	}

	output.open("ProgramList.h");
	
	//output.open(fileName.replace(fileName.find_last_of("\\"), fileName.size() - fileName.find_last_of("\\"), "ProgramList.h"));
	if (!output.good()) 
	{
		std::cout << "problem creating ProgramList.h" << endl;
		return 0;
	}
	
	int program = 1; 
	string outputString;
	string tempProgramArray;
	string programName;
	string readLine;
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

	// count number of programs in file
	int programCount = 1;
	while (std::getline(input, readLine))
	{
		if ( readLine.find(std::to_string(programCount) + ".") != string::npos)
		{
			programCount++;
		}
	}
	outputString.append("ProgramArray = new int[" + std::to_string(programCount-1) + "]; \n\n");
	std::cout << "Number of programs: " + std::to_string(programCount) << endl;
	
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

	return 0;
}
