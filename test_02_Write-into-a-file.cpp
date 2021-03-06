#include <iostream>
#include <fstream>
using namespace std;

/// Writing operations on text files are performed 
//  in the same way we operated with cout:

int main () 
{
  ofstream myfile ("testing_file_1.txt");
  
  if (myfile.is_open())
	{
		myfile << "This is a line.\n";
		myfile << "This is another line.\n";
		myfile << "This is final line.\n";
		myfile.close();
	}
  
  else
	{
		cout << "Unable to open file";
	} 
  
  return 0;
}
