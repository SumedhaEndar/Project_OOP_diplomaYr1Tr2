#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Reading from a file can also be performed in 
// the same way that we did with cin:

int main () 
{
  string line;
  ifstream myfile ("testing_file_1.txt");
  
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}
