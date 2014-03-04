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
	input.open("C:\\Users\\elmdb\\Desktop\\GitHub\\Real-time-task-2\\FileConverter\\FileConverter\\Debug\\Programs.txt");
	//input.open(fileName);
	if (!input.good()) 
	{
		cout << "file not found." << endl;
		return 0;
	}

	output.open("C:\\Users\\elmdb\\Desktop\\GitHub\\Real-time-task-2\\FileConverter\\FileConverter\\Debug\\ProgramList.h");
	
	//output.open(fileName.replace(fileName.find_last_of("\\"), fileName.size() - fileName.find_last_of("\\"), "ProgramList.h"));
	if (!output.good()) 
	{
		cout << "problem creating ProgramList.h" << endl;
		return 0;
	}
	
	int program = 1; 
	string outputString;
	string programName;
	string readLine;
	std::size_t dotPos = 0;
	cout << "strings defined"<< endl;
	while (std::getline(input, readLine))
	{
		int cycle = 0;
		cout << "line read " + std::to_string(program) + "." << endl;

		if ( readLine.find(std::to_string(program) + ".") != string::npos)
		{
			cout << "finding first ."<< endl;
			cycle = 0;
			
			dotPos = readLine.find(".");
			cout << "dotPos: " + std::to_string(dotPos) << endl;
			programName = readLine.substr(dotPos+1,readLine.size());
			
			while(readLine.find("Complete") == string::npos)
			{
				std::getline(input, readLine);
				cout << "reading line: " + readLine << endl;
				outputString.append(programName + "[" + std::to_string(cycle++) + "].SetData(");
				outputString.append(readLine + "); \n");
			}

			program++;
		}
	}
	input.close();
	
	output << outputString << endl;
	output.close();
	
	cout << "chevron chevron chevron chevron" << endl;

	return 0;
}
