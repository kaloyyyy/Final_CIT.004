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
void deleteFriend(node*& head, node*& last, node* cur);
void deleteAFriend(node*& head);
void deleteMany(node*& head);
void filterFriend(node* cur);
void filterByGender(node* cur, char genderInput);

int frCount = 0;

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
			filterFriend(head);
			break;
		case 'c':
			viewFriend(head);
			break;
		case 'd':
			deleteFriend(head, last, head);
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


void deleteFriend(node*& head, node*& last, node* cur)
{
	if (emptyCheck(cur))
	{
		system("CLS");
		cout << "FRIEND LIST EMPTY\n";
	}
	else
	{
		char delButton;
		cout << "a. Delete via name search list\n";
		cout << "b. Delete multiple friends via popularity input\n";
		cin >> delButton;
		switch (delButton)
		{
		case 'a':
			deleteAFriend(head);
			break;
		case 'b':
			deleteMany(head);
			break;
		}
	}
}

void deleteAFriend(node*& head)
{
	string inputName;
	bool searchList = false;
	cout << "Input name of friend you want to delete :(\n";
	cin.ignore();
	getline(cin, inputName);
	node* current = new node;
	node* prev = new node;
	current = head;
	cout << "--------verifying input------\n";
	while (current != NULL)
	{
		if (inputName == current->name)
		{
			searchList = true;
			if (inputName == head->name)
			{
				head = current->nextptr;
			}
			else
			{
				prev->nextptr = current->nextptr;
			}
			cout << "name deleted, please check friends list again\n";
		}
		prev = current;
		current = current->nextptr;
		frCount--;
	}
	if (searchList == false)
	{
		cout << "Error; no friends with user-inputted name\n";
	}
}

void deleteMany(node*& head)
{
	int rateInput;
	bool ratingCheckList = false;
	system("CLS");

	cout << "Enter accurate rating number, program will unfriend people with the same rating\n";
	cin >> rateInput;
	node* current = new node;
	node* prev = new node;
	current = head;
	cout << "Program searching friends with matching popularity rating...\n";
	while (current != NULL)
	{
		if (rateInput == current->popularity)
		{
			if (rateInput == head->popularity)
			{
				head = current->nextptr;
			}
			else
			{
				prev->nextptr = current->nextptr;
			}
			frCount--;
		}
		prev = current;
		current = current->nextptr;
	}
	if (ratingCheckList == false)
	{
		cout << "No friends with user-input popularity matches found\n";
	}
}

void filterFriend(node* cur)
{
	char genderInput;
	int rateInput;
	if (emptyCheck(cur))
	{
		cout << "EMPTY FRIENDS\n";
	}
	else {
		char selection;
		cout << "g. Filter thru gender\n";
		cout << "p. Filter thru popularity\n";
		cin >> selection;
		cin.ignore();
		switch (selection)
		{
		case 'g':
			cout << "input m for male or f for female\n";
			cin >> genderInput;
			cin.ignore();
			filterByGender(cur, genderInput);
			break;
		case 'p':
			cout << "input accurate popularity number\n";
			cin >> rateInput;
			cin.ignore();
			//filterByPopularity(cur,rateInput);
			break;
		}
	}
}

void filterByGender(node* cur, char genderInput)
{
	cout << "Filtering by Gender\n";
	cout << "Loading...\n";
	cout << "results\n";
	while (cur != NULL)
	{
		if (genderInput == cur->gender)
		{
			cout << cur->name << endl;
			cout << cur->age << endl;
			cout << cur->gender << endl;
			cout << cur->popularity << endl << endl;
			cur = cur->nextptr;
		}
		else
		{
			cur = cur->nextptr;
		}
	}
}