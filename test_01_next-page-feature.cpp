#include<iostream>
#include<iomanip>
#include <conio.h>

using namespace std;

class Page
{
	private:
		int menu;
		
	public:
		Page()
		{
			cout << " " << endl;
			cout << "\t\t TL3L Group 4 Sdn Bhd" << endl;
			cout << " ******************************************************" << endl;
			cout << " [1] Register New Employee(s) " << endl;
			cout << " [2] Search Employee Details " << endl;
			cout << " [3] Update Contact Number " << endl;
			cout << " [4] Update Employees' Details " << endl;
			cout << " [5] Calculate Employees' Salary " << endl;
			cout << " [6] Fire Employees' Salary " << endl;
			cout << " [7] End Program " << endl;
			cout << " ******************************************************" << endl;
		}
		
		void setMenu(int m)
		{
			menu = m;
		}
		
		void display()
		{
			if(menu == 1)
			{
				cout << " " << endl;
				cout << "\t\t Register New Employee(s)" << endl;
				cout << " ******************************************************" << endl;
			}
			
			else if(menu == 2)
			{
				cout << " " << endl;
				cout << "\t\t Search Employee's Details" << endl;
				cout << " ******************************************************" << endl;
			}
			
			else if(menu == 3)
			{
				cout << " " << endl;
				cout << "\t\t Update Contact Number" << endl;
				cout << " ******************************************************" << endl;
			}
			
			else if(menu == 4)
			{
				cout << " " << endl;
				cout << "\t\t Update Employees' Details" << endl;
				cout << " ******************************************************" << endl;
			}
			
			else if(menu == 5)
			{
				cout << " " << endl;
				cout << "\t\t Calculate Employees' Salary" << endl;
				cout << " ******************************************************" << endl;
			}
			
			else if(menu == 6)
			{
				cout << " " << endl;
				cout << "\t\t Fire Employee(s)" << endl;
				cout << " ******************************************************" << endl;
			}
		}
};



int main()
{
	Page *page;
	
	
	int menu_selection = 0;
	
	do
	{
		page = new Page;
		
		cout << " Enter Menu Selection : ";
		cin >> menu_selection;
		
		system("cls");
		page->setMenu(menu_selection);
		page->display();
		
		
		
		if(menu_selection == 7)
		{
			cout << " Thank you for using this Program"; 
		}
		else
		{
			cout << " Press Space to the Home Page";
		}
		
		getch();
		system("cls");
		
		delete page;
			
	} while(menu_selection != 7);	
	
	
	return 0;
}
