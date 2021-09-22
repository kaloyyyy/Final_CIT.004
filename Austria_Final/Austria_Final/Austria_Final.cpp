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

void filterFriend(node* current);
void filterGender(node* current, char gfilter);
void filterRating(node* current, int rfilter);

void viewFriend(node* current);
void viewFriendList(node* current);
void viewOneFriend(node* current);

void deleteFriend(node*&head, node*& last, node*current);
void delOneFriend(node*& head);
void delRating(node*& head);


int main()
{
	node* head = NULL;
	node* last = NULL;

	string name;
	int age = 0;
	char gender = 'x';
	int pRating = 0;


	char sortChoice = 'x';
	char choice = 'x';
	do {
		choice = menu();
		switch (choice)
		{
		case 'a':

			cout << "enter your friend's name: \n";
			getline(cin, name);
			cout << "enter " << name << "'s " << "age: \n";
			cin >> age;
			cin.ignore();
			cout << "enter " << name << "'s " << "gender: \n";
			cin >> gender;
			cin.ignore();
			cout << "enter " << name << "'s " << "Popularity Rating: \n";
			cin >> pRating;
			cin.ignore();
			addFriend(head, last, name, age, gender, pRating);
			break;

		case 'b':
			filterFriend(head);
			break;
		case 'c':
			viewFriend(head);
			break;
		case 'd':
			deleteFriend(head,last,head);
		}
	} while (choice != 'e');

	viewFriendList(head);
	return 0;

}

char menu()//main menu
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

bool isEmpty(node* head)//checks if the linkedlist is empty
{
	if (head == NULL)
	{
		cout << "yes\n";
		return true;
	}
	else
		return false;
}

void firstFriend(node*& head, node*& last, string name, int age, char gender, int pRating)//this function is called in addFriend. it is called when the linkedlist is empty
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

void addFriend(node*& head, node*& last, string name, int age, char gender, int pRating)//adds a new friend
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

void viewFriend(node* current)//view friend menu
{
	char viewChoice;
	if (isEmpty(current))
	{
		cout << "your friends list is empty\n";
	}
	else
	{
		cout << "a. view a specific person\n";
		cout << "b. view your friends list\n";
		cin >> viewChoice;
		cin.ignore();
		switch (viewChoice)
		{
		case 'a'://view specific person
			viewOneFriend(current);
			break;
		case 'b':
			viewFriendList(current);
			break;
		}
	}
}

void viewFriendList(node* current)//prints out the friends list
{
	cout << "---Your Friends list---\n";
	while (current != NULL)
	{
		cout << current->name << endl;
		cout << current->age << endl;
		cout << current->gender << endl;
		cout << current->pRating << endl << endl;
		current = current->next_ptr;
	}
}

void viewOneFriend(node* current)
{
	bool nameMatch = false;
	string viewName;
	cout << "enter your friend's complete name you want to view\n";
	getline(cin, viewName);
	while (current != NULL)
	{
		cout << "searching...\n";
		if (viewName == current->name)
		{
			cout << current->name << endl;
			cout << current->age << endl;
			cout << current->gender << endl;
			cout << current->pRating << endl << endl;
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
					cout << "You have no friends with name: " << viewName << endl;
				}
			}
		}
	}
}

void filterFriend(node* current)// the menu for filtering.
{
	char gFilter;
	int rFilter;
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
			cout << "enter the rating you want to filter\n";
			cin >> rFilter;
			cin.ignore();
			filterRating(current, rFilter);
			break;
		}
	}
}

void filterGender(node* current, char gFilter)//gender filter function. it will print all the matching inputted gender.
{
	cout << "gender filter\n";
	bool genderMatch = false;
	while (current != NULL)
	{
		if (gFilter == current->gender)
		{
			cout << current->name << endl;
			cout << current->age << endl;
			cout << current->gender << endl;
			cout << current->pRating << endl << endl;
			current = current->next_ptr;
			genderMatch = true;//once there's a matching gender, this will be true and will not print the prompt below
		}
		else
		{
			current = current->next_ptr;
			if (current == NULL)//if you're at the last node and there are zero matches with the filter, it will run the code below
			{
				if (genderMatch == false)
				{
					cout << "You have no friends with the selected gender\n";
				}
			}
		}
	}
}
void filterRating(node* current, int rFilter)//popularity rating filter function. 
{
	cout << "Popularity rating filter\n";
	bool ratingMatch = false;
	while (current != NULL)
	{
		if (current->pRating <= rFilter)
		{
			cout << current->name << endl;
			cout << current->age << endl;
			cout << current->gender << endl;
			cout << current->pRating << endl << endl;
			current = current->next_ptr;
			ratingMatch = true;//once there's a matching gender, this will be true and will not print the prompt below
		}
		else
		{
			current = current->next_ptr;
			if (current == NULL)//if you're at the last node and there are zero matches with the filter, it will run the code below
			{
				if (ratingMatch == false)
				{
					cout << "You have no friends with the rating equal or below: " << rFilter << endl;
				}
			}
		}
	}
}

void deleteFriend(node*& head, node*& last, node* current)
{
	int rDelete;
	if (isEmpty(current))
		cout << "your friends listis empty\n";
	else
	{
		char delChoice;
		cout << "a. delete a friend by name\n";
		cout << "b. delete friends based on popularity rating\n";
		cin >> delChoice;
		cin.ignore();
		switch (delChoice)
		{
		case'a':
			delOneFriend(head);
			break;
		case'b':
			delRating(head);
			break;
		}
	}

}

void delOneFriend(node*& head)
{
	string nameDelete;
	bool nameMatch = false;
	if (isEmpty(head))
	{
		cout << "your friends listis empty\n";
	}
	else
	{
		cout << "enter your friend's full name you want to delete\n";
		getline(cin, nameDelete);
		node* now = new node;
		node* prev = new node;
		now = head;
		cout << "searching for " << nameDelete << "'s account...\n\n";
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
				cout << nameDelete << " is now removed from your friend list\n";
			}
			prev = now;
			now = now->next_ptr;
		}
		if (nameMatch == false)
		{
			cout << "You have no friends with name: " << nameDelete << endl;
		}
	}	
}

void delRating(node*& head)
{
	int ratingDelete;
	bool ratingMatch = false;
	if (isEmpty(head))
	{
		cout << "your friend list is empty\n";
	}
	else
	{
		cout << "enter your friends' rating you want to unfriend\n";
		cin >> ratingDelete;
		cin.ignore();
		node* now = new node;
		node* prev = new node;
		now = head;
		cout << "searching for friends with a rating of: " <<ratingDelete<< "\n\n";
		while (now != NULL)
		{
			if (ratingDelete == now->pRating)
			{
				if (ratingDelete == head->pRating)
				{
					head = now->next_ptr;
				}
				else
				{
					prev->next_ptr = now->next_ptr;
				}
			}
			prev = now;
			now = now->next_ptr;
		}
		if (ratingMatch == false)
		{
			cout << "you do not have a friend with the popularity rating of: " << ratingDelete << endl;
		}
	}
}