#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	string edu;
	
//	edu = "Diploma in Electronic Engineering";
//	edu = "Bachelor of Electronic Engineering";
	edu = "Bachelor_of_Electronic_Engineering";
	
//	cout << edu.substr(0,7) << endl;
	cout << edu.find("Bachelor") << endl;
	if(edu.find("Bachelor") == 0)
	{
		cout << " yeah" << endl;
	}
//	cout << edu.find("Diploma");
	
	
	string dob;
	
//	dob = "1-2-2000";   // substr(4) when length is 8
//	dob = "11-2-2000";  // substr(5) when length is 9
//	dob = "1-12-2000";  // substr(5) when length is 9		
//	dob = "11-12-2000"; // substr(6) when length is 10
	
//	cout << dob.length() << endl;
//	cout << dob.substr(6) << endl;
	
// use stoi to convert string to int
//	cout << 2022 - stoi(dob.substr(6)) << endl;
	
	return 0;
}
