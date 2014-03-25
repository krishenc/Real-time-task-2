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
		cout << "file " + fileName + " not found." << endl;
		cout << "press any button to continue..." << endl;
		cin.ignore();
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
		cout << "file " + fileName + " not found." << endl;
		cout << "press any button to continue..." << endl;
		cin.ignore();
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
		cout << "file " + fileName + " not found." << endl;
		cout << "press any button to continue..." << endl;
		cin.ignore();
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
	while (getline(programtxt, readLine))
	{
		if ( readLine.find(to_string(programCount+1) + ":") != string::npos)
		{
			programCount++;
		}
	}
	cout << "Found " + to_string(programCount) + " programs." << endl;
	
	// go back to begenning of file
	programtxt.clear();
	programtxt.seekg(0,ios::beg);

	// figure out what the maximum number of cycles is for any program
	int cycleCount = 0;
	int program = 0;
	while (getline(programtxt, readLine))
	{
		int cycle = 0;
		if ( readLine.find(to_string(program+1) + ":") != string::npos)
		{
			program++;
			cycle = 0;
			while(readLine.find("Complete") == string::npos)
			{
				getline(programtxt, readLine);
				cycle++;
			}
			if (cycle > cycleCount) cycleCount = cycle;
		}
	}
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
	while (getline(programh_in, readLine))
	{
		if ( readLine.find("#define MaxPrograms") != string::npos)
		{
			readLine = "#define MaxPrograms " + to_string(programCount);
		}
		if ( readLine.find("#define MaxCycles") != string::npos)
		{
			readLine = "#define MaxCycles " + to_string(cycleCount);
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
	program = 0;
	while(getline(programtxt, readLine))
	{
		int cycle = 0;
		// look for new program definition i.e. 1:ColourWash
		if ( readLine.find(to_string(program+1) + ":") != string::npos)
		{
			program++;
			cycle = 0;
			// look for final cycle definition
			while(readLine.find("Complete") == string::npos)
			{
				getline(programtxt, readLine);
				constructorFunction.append("\tPrograms[" + to_string(program-1) + "][" + to_string(cycle++) + "]");
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
	while (getline(programcpp_in, readLine))
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

	cout << "press any button to continue..." << endl;
	cin.ignore();




	/* OLD CODE
	int program = 1;
	string outputString;
	string tempProgramArray;
	string programName;
	size_t dotPos = 0;
	cout << "strings defined"<< endl;
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
	cout << "Back to start of input file" << endl;

	while (getline(input, readLine))
	{
		int cycle = 0;
		cout << "line read " + to_string(program) + "." << endl;

		if ( readLine.find(to_string(program) + ".") != string::npos)
		{
			cout << "finding first ."<< endl;
			cycle = 0;
			
			dotPos = readLine.find(".");
			cout << "dotPos: " + to_string(dotPos) << endl;
			programName = readLine.substr(dotPos+1,readLine.size());
			tempProgramArray = "";

			
			
			while(readLine.find("Complete") == string::npos)
			{
				getline(input, readLine);
				cout << "reading line: " + readLine << endl;
				tempProgramArray.append(programName + "[" + to_string(cycle++) + "].SetData(");
				tempProgramArray.append(readLine + "); \n");
			}

			outputString.append("//" + programName + " is defined below\n");

			outputString.append(programName + " = new ProgramData[" + to_string(cycle) + "]; \n");
			
			outputString.append(tempProgramArray);

			outputString.append("ProgramArray[" +  to_string(program-1) + "] = " + programName + "*; \n\n");
			program++;
		}
	}
	outputString.append("#define NumberofPrograms " + to_string(program-1));
	input.close();
	
	output << outputString << endl;
	output.close();
	
	cout << "press any button to continue..." << endl;
	cin.ignore();
	*/
	return 0;
}

