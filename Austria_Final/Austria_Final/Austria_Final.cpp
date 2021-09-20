#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

class node
{
public:
	string name;
	int age;
	char gender;
	int pRating;
	node* next_ptr;
};


char menu();
bool isEmpty(node* head);

void firstFriend(node*& head, node*& last, string name, int age, char gender, int pRating);
void addFriend(node*& head, node*& last, string name, int age, char gender, int pRating);

void viewFriend(node* current);
void deleteFriend();

void filterFriend(node* current, char gFilter, int rFilter);
void filterGender(node* current, char gfilter);

int main()
{
	node* head = NULL;
	node* last = NULL;

	string name;
	int age = 0;
	char gFilter = 'x';
	int rFilter = 100;
	char gender = 'x';
	int pRating = 0;


	char sortChoice = 'x';
	char choice = 'x';
	string eyf = "enter your friend's ";
	do {
		choice = menu();
		switch (choice)
		{
		case 'a':
			cout << eyf<< "name: \n";
			getline(cin, name);
			cout << eyf<<"age: \n";
			cin >> age;
			cin.ignore();
			cout << eyf << "gender: \n";
			cin >> gender;
			cin.ignore();
			cout << eyf << "Popularity Rating: \n";
			cin >> pRating;
			cin.ignore();
			addFriend(head, last, name, age, gender, pRating);
			break;

		case 'b':
			filterFriend(head, gFilter, rFilter);
			break;
		case 'c':
			viewFriend(head);
			break;
		}
	} while (choice != 'e');

	viewFriend(head);
	return 0;

}

char menu()
{
	char choice;
	cout << "a. add a friend\n";
	cout << "b. filter friends list\n";
	cout << "c. view friend\n";
	cout << "d. unfriend someone\n";
	cout << "e. close the program\n";
	cin >> choice;
	cin.ignore();
	return choice;
}

bool isEmpty(node* head)
{
	if (head == NULL)
	{
		cout << "yes\n";
		return true;
	}
	else
		return false;
}

void firstFriend(node*& head, node*& last, string name, int age, char gender, int pRating)
{
	node* temp = new node;

	temp->name = name;
	temp->age = age;
	temp->gender = gender;
	temp->pRating = pRating;

	temp->next_ptr = NULL;

	head = temp;
	last = temp;
}

void addFriend(node*& head, node*& last, string name, int age, char gender, int pRating)
{
	if (isEmpty(head))
	{
		firstFriend(head, last, name, age, gender, pRating);
	}
	else
	{
		node* temp = new node;

		temp->name = name;
		temp->age = age;
		temp->gender = gender;
		temp->pRating = pRating;

		temp->next_ptr = NULL;
		last->next_ptr = temp;
		last = temp;
	}

}

void viewFriend(node* current)
{
	if (isEmpty(current))
		cout << "---Your friends list is empty---\n";
	else
	{
		cout << "Your\n";
		while (current != NULL)
		{
			cout << current->name << endl;
			cout << current->age << endl;
			cout << current->gender << endl;
			cout << current->pRating << endl << endl;
			current = current->next_ptr;
		}
	}
}

void filterFriend(node* current, char gFilter, int rFilter)
{
	if (isEmpty(current))
	{
		cout << "your friends list is empty\n";
	}
	else
	{
		char sortChoice;
		cout << "a. sort friends by gender\n";
		cout << "b. sort friends by popularity rating\n";
		cin >> sortChoice;
		cin.ignore();
		switch (sortChoice)
		{
		case 'a':
			cout << "enter the gender you want to sort\n";
			cin >> gFilter;
			cin.ignore();
			filterGender(current, gFilter);
			break;
		case 'b':
			break;
		}
	}
}

void filterGender(node* current, char gFilter)
{
	cout << "gender filter\n";
	while (current != NULL)
	{
		if (gFilter == current->gender)
		{
			cout << current->name << endl;
			cout << current->age << endl;
			cout << current->gender << endl;
			cout << current->pRating << endl << endl;
			current = current->next_ptr;
		}
		else
		{
			current = current->next_ptr;
		}
	}

}