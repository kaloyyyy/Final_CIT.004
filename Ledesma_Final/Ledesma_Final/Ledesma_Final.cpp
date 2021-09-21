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
void viewFriend(node* cur);
void viewAll(node* cur);
void viewOne(node* cur);
void deleteFriend(node*& head, string name);
//void deleteAFriend(node*& head);//


int main()
{
	node* head = NULL;
	node* last = NULL;
	string name;
	int age;
	char gender;
	int popularity;
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
		case 'c':
			viewFriend(head);
			break;
		case 'd':
			cin >> name;
			deleteFriend(head, name);
			break;
		}
	} while (choice != 'e');

	//viewFriend(head);//
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
		return true;
	}
	else
		return false;
}

void firstFriend(node*& head, node*& last, string name, int age, char gender, int popularity)////addFriend will use this function when head is null
{
	node* temporary = new node;
	temporary->name = name;
	temporary->age = age;
	temporary->gender = gender;
	temporary->popularity = popularity;

	temporary->nextptr = NULL;

	head = temporary;
	last = temporary;
}

void addFriend(node*& head, node*& last, string name, int age, char gender, int popularity)
{
	if (emptyCheck(head))
	{
		firstFriend(head, last, name, age, gender, popularity);
	}
	else
	{
		node* temporary = new node;

		temporary->name = name;
		temporary->age = age;
		temporary->gender = gender;
		temporary->popularity = popularity;

		temporary->nextptr = NULL;
		last->nextptr = temporary;
		last = temporary;
	}
}

void viewFriend(node* cur)
{
	char selection;
	if (emptyCheck(cur))
	{
		cout << "EMPTY FRIEND LIST\n";
	}
	else {
		cout << "s. Specific view\n";
		cout << "a. All friends view\n";
		cin >> selection;
		cin.ignore();
		switch (selection)
		{
		case 's':
			viewOne(cur);
			break;
		case 'a':
			viewAll(cur);
			break;
		}
	}
}

void viewOne(node* cur)
{
	string inputName;
	bool foundIt = false;
	cout << "INPUT NAME OF FRIEND U WISH TO SEE\n";
	getline(cin, inputName);
	while (cur != NULL)
	{
		cout << "---...---\n";
		if (inputName == cur->name)
		{
			cout << cur->name << endl;
			cout << cur->age << endl;
			cout << cur->gender << endl;
			cout << cur->popularity << endl << endl;
			cur = cur->nextptr;
			foundIt = true;
		}
		else
		{
			cur = cur->nextptr;
			if (cur == NULL) {
				if (foundIt == false)
				{
					cout << "no friend with that name found";
				}
			}
		}
	}
}

void viewAll(node* cur)
{
	cout << "--Friends---\n";
	while (cur != NULL)
	{
		cout << cur->name << endl;
		cout << cur->age << endl;
		cout << cur->gender << endl;
		cout << cur->popularity << endl << endl;
		cur = cur->nextptr;
	}
}


void deleteFriend(node*& head, string name)//wrong
{
	node* tmp = head;
	while (head->name == name)
	{
		head = head->nextptr;
	}
	while (tmp->nextptr != NULL)
	{
		if (tmp->nextptr->name == name)
		{
			tmp->nextptr = tmp->nextptr->nextptr;
		}
		else
		{
			tmp = tmp->nextptr;
		}
	}
}

/*void deleteAFriend(node*& head)
{
	string inputName;
	cout << "Input name of friend you want to delete :(\n";
	getline(cin, inputName);
	while (head != NULL)
	{
		if (inputName == head->name)
		{
			node* current = new node;
			node* previous = new node;
			current = head;
			previous = current;
			current = current->nextptr;
			previous->nextptr = current->nextptr;
		}
	}
}
*/