#include<iostream>
#include<limits>
#include<stdlib.h>
#include<string>

using namespace std;

class Node
{
public:
	string name;
	int age;
	char gender;
	int PopRating;
	Node* next_ptr;
};

string profile[4] = { "Name: ","Age: ","Gender: ","Popularity Rating: " };

void validateInt();
void filterGender(Node* current);
void filterRating(Node* current);
void viewOneFriend(Node* current);
void delOneFriend(Node*& head);
void delRating(Node*& head);

char menu()
{
	cout << "======================================== \n";
	cout << "-----------Welcome to Konek!------------ \n";
	cout << "========================================" << endl << endl;

	char choice;
	cout << "Choose your choice: \n" << endl;

	cout << "A. Add a Friend \n";
	cout << "B. View a Friend \n";
	cout << "C. Filter Friend List \n";
	cout << "D. Unfriend a Friend \n";
	cout << "E. Exit Program \n";
	cin >> choice;
	return choice;
}

bool isEmpty(Node* head)
{
	if (head == NULL)
	{
		return true;
	}
	else
		return false;
}

void printFriend(Node* current)
{
	cout << profile[0] << current->name << endl;
	cout << profile[1] << current->age << endl;
	cout << profile[2] << current->gender << endl;
	cout << profile[3] << current->PopRating << endl << endl;
}

void firstFriend(Node*& head, Node*& last, string name, int age, char gender, int PopRating)
{
	Node* temp = new Node;
	temp->name = name;
	temp->age = age;
	temp->gender = gender;
	temp->PopRating = PopRating;

	temp->next_ptr = NULL;

	head = temp;
	last = temp;
}

void addFriend(Node*& head, Node*& last, string name, int age, char gender, int PopRating)
{
	if (isEmpty(head))
	{
		firstFriend(head, last, name, age, gender, PopRating);
	}
	else
	{
		Node* temp = new Node;

		temp->name = name;
		temp->age = age;
		temp->gender = gender;
		temp->PopRating = PopRating;

		temp->next_ptr = NULL;
		last->next_ptr = temp;
		last = temp;
	}
}

void validateInt()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void filterFriend(Node* current)
{
	system("CLS");
	if (isEmpty(current))
	{
		cout << "No Friend List\n";
	}
	else
	{
		char sortChoice;
		cout << "A. Sort Friends By Gender\n";
		cout << "B. Sort Friends by Popularity Rating\n";
		cin >> sortChoice;
		switch (sortChoice)
		{
		case 'a':
		case 'A':
			filterGender(current);
			break;

		case 'b':
		case 'B':
			filterRating(current);
			break;
		}
	}
}

void filterGender(Node* current)
{
	char genderFilter;
	bool genderCheck = false;
	string genderPrint = "FEMALE";
	bool genderMatch = false;
	cout << "Enter the Gender you wish to sort \n";
	cin >> genderFilter;
	do {
		if (genderFilter != 'M')
		{
			if (genderFilter != 'F')
			{
				genderCheck = false;
				cout << "Please Enter a Valid Gender (M or F) \n";
				cin >> genderFilter;
			}
			else
			{
				genderCheck = true;
			}
		}
		else
		{
			genderCheck = true;
		}
	} while (genderCheck == false);


	if (genderFilter == 'M')
	{
		genderPrint = "MALE";
	}
	system("CLS");
	cout << "The Following List of Your Friend/s are " << genderPrint << endl << endl;
	while (current != NULL)
	{
		if (genderFilter == current->gender)
		{
			if (genderMatch == false)
				printFriend(current);
			current = current->next_ptr;
			genderMatch = true;
		}
		else
		{
			if (current == NULL)
			{
				if (genderMatch == false)
				{
					cout << "No Results with the Selected Gender \n";
				}
			}
			current = current->next_ptr;
		}
	}
}

void filterRating(Node* current)
{
	int rFilter;
	bool rMatch = false;

	cout << "Enter the Rating you wish to Filter: \n";
	cin >> rFilter;
	do {
		do {
			do {
				if (rFilter < 0)
				{
					validateInt();
					cout << "Please Enter Above 0 Popular Rating  \n";
					cin >> rFilter;
				}
				if (rFilter > 100)
				{
					validateInt();
					cout << "Please Enter Below 100 Popular Rating  \n";
					cin >> rFilter;
				}
				if (cin.fail())
				{
					validateInt();
					cout << "Please Enter Between 0-100 Popularity Rating of your Friend \n";
					cin >> rFilter;
				}
			} while (rFilter > 100);
		} while (cin.fail());
	} while (rFilter < 0);
	system("CLS");

	while (current != NULL)
	{
		if (current->PopRating <= rFilter)
		{
			if (rMatch == false)	cout << "Friends with popularity rating less than or equal to " << rFilter << endl << endl;
			printFriend(current);
			current = current->next_ptr;
			rMatch = true;
		}
		else
		{
			current = current->next_ptr;
			if (current == NULL)
			{
				if (rMatch == false)
				{
					cout << "!No Results Rating " << rFilter << endl;
				}
			}
		}
	}
}

void viewFriend(Node* current)
{
	system("CLS");
	char viewChoice;
	if (isEmpty(current))
	{
		cout << "Your Friend List is Empty! \n";
	}
	else
	{
		cout << "A. View your Friend's Name \n";
		cout << "B. View Friend List \n";
		cin >> viewChoice;
		switch (viewChoice)
		{
		case 'a':
		case 'A':
			system("CLS");
			viewOneFriend(current);
			break;

		case 'b':
		case 'B':
			system("CLS");
			cout << "===Following Friend/s List===\n\n";
			while (current != NULL)
			{
				cout << "------------------------\n";
				printFriend(current);
				current = current->next_ptr;
			}
			break;
		}
	}
}

void viewOneFriend(Node* current)
{
	bool nameMatch = false;
	string viewName;
	cout << "Enter the Friend's Name you Wish to Search: \n";
	cin.ignore();
	getline(cin, viewName);
	cout << "Searching " << viewName << "in your Friend List..." << endl << endl;
	while (current != NULL)
	{
		if (viewName == current->name)
		{
			printFriend(current);
			current = current->next_ptr;
			nameMatch = true;
		}
		else
		{
			current = current->next_ptr;
			if (current == NULL)
			{
				if (nameMatch == false)
				{
					system("CLS");
					cout << "!No Results Found by the Name " << viewName << endl;
				}
			}
		}
	}
}

void deleteFriend(Node*& head, Node* current)

{
	if (isEmpty(current))
	{
		system("CLS");
		cout << "----Friend List is Empty---- \n";
	}
	else
	{
		char delChoice;
		cout << "A. Delete a Friend by Name \n";
		cout << "b. Delete a Friend/s Based on Popularity Rating \n";
		cin >> delChoice;
		switch (delChoice)
		{
		case 'a':
		case 'A':
			delOneFriend(head);
			break;

		case 'b':
		case 'B':
			delRating(head);
			break;
		}
	}
}

void delOneFriend(Node*& head)
{
	string nameDelete;
	bool nameMatch = false;
	system("CLS");

	cout << "Enter the Friend's Name you wish to Delete: \n";
	cin.ignore();
	getline(cin, nameDelete);
	Node* now = new Node;
	Node* prev = new Node;
	now = head;
	cout << "Searching " << nameDelete << "...\n\n";
	while (now != NULL)
	{
		if (nameDelete == now->name)
		{
			nameMatch = true;
			if (nameDelete == head->name)
			{
				head = now->next_ptr;
			}
			else
			{
				prev->next_ptr = now->next_ptr;
			}
			cout << nameDelete << " has now been Unfriended\n\n";
		}
		prev = now;
		now = now->next_ptr;
	}
	if (nameMatch == false)
	{
		cout << "!No Results Found by the Name " << nameDelete << endl;
	}

}

void delRating(Node*& head)
{
	int rDelete;
	bool rMatch = false;
	system("CLS");

	cout << "Enter the Friend's Popularity Rating you wish to Delete: \n";
	cin >> rDelete;

	do {
		do {
			do {
				if (rDelete < 0)
				{
					validateInt();
					cout << "Please Enter Above 0 Popular Rating \n";
					cin >> rDelete;
				}
				if (rDelete > 100)
				{
					validateInt();
					cout << "Please Enter Below 100 Popular Rating \n";
					cin >> rDelete;
				}
				if (cin.fail())
				{
					validateInt();
					cout << "Pleas Enter Between 0-100 Popular Rating of your Friend \n";
					cin >> rDelete;
				}
			} while (rDelete > 100);
		} while (cin.fail());
	} while (rDelete < 0);

	Node* now = new Node;
	Node* prev = new Node;
	now = head;
	cout << "Unfriend with Rating " << rDelete << "...\n\n";
	while (now != NULL)
	{
		if (rDelete == now->PopRating)
		{
			cout << now->name << " has now been Unfriended \n\n";
			if (rDelete == head->PopRating)
			{
				head = now->next_ptr;
			}
			else
			{
				prev->next_ptr = now->next_ptr;
			}
			rMatch = true;
		}
		prev = now;
		now = now->next_ptr;
	}
	if (rMatch == false)
	{
		cout << "!No Results Found by the Rating " << rDelete << endl;
	}
}


int main()
{
	Node* head = NULL;
	Node* last = NULL;
	string name;
	int age = 0;
	char gender = 'x';
	int m, f;
	int PopRating = 0;
	bool genderCheck = true;
	char sortChoice = 'x';
	char choice = 'x';

	do {
		choice = menu();
		switch (choice)
		{
		case 'a':
		case 'A':
			system("CLS");
			cout << "Enter the Friend's Name: \n";
			cin.ignore();
			getline(cin, name);

			cout << "Enter the Age of your Friend " << name << ": \n";
			cin >> age;
			do {
				if (age < 0)
				{
					validateInt();
					cout << "Please Enter a Valid Age of the Friend \n";
					cin >> age;
				}
				do {
					if (cin.fail())
					{
						validateInt();
						cout << "Please Enter a Valid Age of the Friend \n";
						cin >> age;
					}
				} while (cin.fail());
			} while (age < 0);

			cout << "Enter the Gender of your Friend " << name << ": (M or F)\n";
			cin >> gender;
			cin.ignore();
			do {
				if (gender != 'M')
				{
					if (gender != 'F')
					{
						genderCheck = false;
						cout << "Please Enter the Valid Gender \n";
						cin >> gender;
					}
					else
					{
						genderCheck = true;
					}
				}
				else
				{
					genderCheck = true;
				}
			} while (genderCheck == false);

			cout << "Enter the Popular Rating of your Friend " << name << ": (0-100)\n";
			cin >> PopRating;
			do {
				do {
					do {
						if (PopRating < 0)
						{
							validateInt();
							cout << "Please Enter the Valid Popular Rating \n";
							cin >> PopRating;
						}
						if (cin.fail())
						{
							validateInt();
							cout << "Please Enter the Valid Popular Rating \n";
							cin >> PopRating;
						}
					} while (PopRating > 100);
				} while (cin.fail());
			} while (PopRating < 0);

			system("CLS");
			cout << "---Friend " << name << " has been added to your Friend List!---\n\n";
			addFriend(head, last, name, age, gender, PopRating);
			break;

		case 'b':
		case 'B':
			system("CLS");
			viewFriend(head);
			break;

		case 'c':
		case 'C':
			system("CLS");
			filterFriend(head);
			break;

		case 'd':
		case 'D':
			system("CLS");
			deleteFriend(head, head);
		}
	} while (choice != 'E');
	cout << "\nExiting Program... \n";
	cout << "=====Thank you=====";
	return 0;
}