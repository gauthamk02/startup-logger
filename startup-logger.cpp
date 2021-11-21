#include <iostream>  
#include <fstream>
#include <ctime>
#include <sstream>
#include <filesystem>

int main(int argc, char **argv)
{
	size_t startn;
	std::string lastline;
	const std::string filename = "Record.csv";
	time_t rawtime = time(0);
	struct tm * Time = new tm;
	localtime_s(Time, &rawtime);
	
	if (!std::filesystem::exists(filename))
	{
		std::fstream Record;
		Record.open(filename,
			std::ios::app | std::ios::in | std::ios::out);
		Record << "Sl.no,Date,Time\n";

		Record  << "1,"<< Time->tm_mday << "-"
			<< Time->tm_mon + 1 << "-" << (Time->tm_year + 1900)
			<< "," << Time->tm_hour << ":" << Time->tm_min
			<< ":" << Time->tm_sec << "\n";
		Record.close();

		delete Time;
		return 0;
	}


	std::fstream Record;
	Record.open(filename,
		std::ios::app | std::ios::in | std::ios::out);
	if (!Record)
	{
		std::cout << "Unable to open " << filename << std::endl;
		system("pause");

	}

	Record.seekg(-3, std::ios_base::end);

	while (true) 
	{
		char ch;
		Record.get(ch);                        

		if ((int)Record.tellg() <= 1) 
		{   
			std::cout << "Corrupted file " << filename << std::endl;
			system("pause");
			Record.seekg(0);
			break;                
		}
		else if (ch == '\n') 
		{
			break;
		}
		else 
		{                                  
			Record.seekg(-2, std::ios_base::cur);
		}
	}

	Record >> lastline;
	Record.seekg(0, std::ios::end);

	std::stringstream ss(lastline);
	ss >> startn;
	startn++;

	Record << startn << "," << Time->tm_mday << "-"
		<< Time->tm_mon + 1 << "-" << (Time->tm_year + 1900)
		<< "," << Time->tm_hour << ":" << Time->tm_min
		<< ":" << Time->tm_sec << "\n";
	Record.close();
	
	delete Time;
	return 0;
}