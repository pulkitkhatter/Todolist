#include <iostream>
#include <string>
#include "19ToDo.h"



using namespace std;

bool addToList(string description, int priority, string dueDate);
bool getNextItem(MyToDo &mytodo);
bool getByPriority(MyToDo matches[100], int search);
void printToDo();

int main()
{
	int choice = 0;
	char nextmove = 'y';


	while (nextmove = 'y')
	{
		cout << "This will keep of the things you need to do!" << endl;
		cout << "What would you like to do?" << endl;
		cout << "1. Add to my to do list" << endl;
		cout << "2. Display the next item in my list" << endl;
		cout << "3. Search for activites of a certain priority" << endl;
		cout << "4. Print out my whole list" << endl;

		cin >> choice;

		if (choice == 1)
		{
			string description;
			int priority;
			string dueDate;


			cout << "what is the description of the activity?" << endl;
			cin.ignore();
			getline(cin, description);
			cout << "how urgent is this? rank 1-5. 1 for not really important, 5 for very important" << endl;
			cin >> priority;
			cout << "when is the due date? is day/month format" << endl;
			cin >> dueDate;

			addToList(description, priority, dueDate);
		}
		else if (choice == 2)
		{

			MyToDo y;

			getNextItem(y);

		
			cout <<"Description: " << y.description << endl;
			cout << "Priority :" << y.priority << endl;
			cout << "Due Date :" << y.dueDate << endl;
			

		}
		else if (choice == 3)
		{
			struct MyToDo matches[100];
			int search = 0;

			cout << "Enter a priority level to search for 1-5" << endl;
			cin >> search;

			getByPriority(&matches[100], search);
			for (int i = 0; i < 10; i++)
			{
				cout << "Description: " << matches[i].description << endl;
				cout << "Priority : " << matches[i].priority << endl;
				cout << "Due Date : " << matches[i].dueDate << endl;
			}
		}
		else if (choice == 4)
		{

			printToDo();
		}
		else
		{
			cout << "That was an incorrect choice!" << endl;
		}
		cout << "would you like to keep playing? y for YES" << endl;
		cin >> nextmove;

	}

	cout << "Good job keeping yourself on schedule!" << endl;
	return 0;
}