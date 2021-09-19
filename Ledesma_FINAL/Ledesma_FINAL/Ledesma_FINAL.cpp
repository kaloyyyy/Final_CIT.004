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
	int popularity;
	node* nextptr;
};


char menu();
bool emptyCheck(node* head);
void firstFriend(node*& head, node*& last, string name, int age, char gender, int popularity);
void addFriend(node*& head, node*& last, string name, int age, char gender, int popularity);

int main()
{
	node* head = NULL;
	node* last = NULL;
	string name;
	int age;
	char gender;
	int pRating;
	char choice;
	string eyf = "enter your friend's ";
	do {
		choice = menu();
		switch (choice)
		{
		case 'a':
			cout << "The program will prompt subsequent texts, please follow instructions for adding\n";
			cout << "name: \n";
			getline(cin, name);
			cout << "age: \n";
			cin >> age;
			cin.ignore();
			cout << "gender: \n";
			cin >> gender;
			cin.ignore();
			cout << "Popularity Rating: \n";
			cin >> popularity;
			cin.ignore();
			addFriend(head, last, name, age, gender, popularity);
			break;

		case 'b':
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

bool emptyCheck(node* head)
{
	if (head == NULL)
	{
		cout << "Empty: you have not added any friends\n";
		return true;
	}
	else
		return false;
}

void firstFriend(node*& head, node*& last, string name, int age, char gender, int popularity)////addFriend will use this function when head is null
{
	node* temporary = new node;
	temp->name = name;
	temp->age = age;
	temp->gender = gender;
	temp->popularity = popularity;

	temp->next_ptr = NULL;

	head = temp;
	last = temp;
}

void addFriend(node*& head, node*& last, string name, int age, char gender, int popularity)
{
	if (isEmpty(head))
	{
		firstFriend(head, last, name, age, gender, popularity);
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

