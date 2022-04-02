#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	string date_in;
	
//	date_in = "1-2-2020";   // substr(4) is year, substr(2,1) is month when length is 8
//	date_in = "11-2-2020";  // substr(5) is year, substr(3,1) is month when length is 9
//	date_in = "1-12-2020";  // substr(5) is year, substr(2,2) is month when length is 9		
	date_in = "11-11-2020"; // substr(6) is year, substr(3,2) is month when length is 10
	
	if(date_in.length() == 8)
	{
		cout << date_in.substr(2,1) << endl;
	}
	
	else if(date_in.length() == 9)
	{
		if(date_in.substr(2,1) == "-")
		{
			cout << date_in.substr(3,1) << endl;
		}
		else
		{
			cout << date_in.substr(2,2) << endl;
		}
		
	}
	
	else if(date_in.length() == 10)
	{
		cout << date_in.substr(3,2) << endl;
	}
	
	
// use stoi to convert string to int
//	cout << 2022 - stoi(dob.substr(6)) << endl;
	
	return 0;
}
