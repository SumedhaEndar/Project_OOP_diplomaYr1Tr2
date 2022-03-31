#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct Employee
{
	int ID;
	string Name;
};


int main() 
{
	Employee Emp[2];
	
	ifstream myfile ("testing_file_2.txt");
	
	if (myfile.is_open())
	{
		for(int i=0; i<2; i++)
		{
			myfile >> Emp[i].ID >> Emp[i].Name;
		}
		
		myfile.close();
		
		cout << "Name : " << Emp[1].Name << "  " << " ID : " << Emp[1].ID << endl;
	}
	
	else
	{
		cout << "Unable to open file"; 
	}
	
	return 0;
}
