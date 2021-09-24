
#include<iostream>
#include<stdlib.h>//for system("CLS");
#include<string>//for getline for string;
#include<limits>//for limit in cin.ignore
using namespace std;



class node
{
public:
	string name;
	char gender;
	int age;
	int rating;
	node* next_ptr;
};

char menu()
{
	char choice;
	cout << "MENU \n";



	cout << "A. Add Friend" << endl;
	cout << "B. Unfriend" << endl;
	cout << "C. Friend List" << endl;
	cout << "D. Filter Friends" << endl;
	cout << "E. Exit" << endl;

	cout << "select option\n";
	cin >> choice;

	return choice;
}

bool isEmpty(node* head)
{
	{
		if (head == NULL)
			return true;
		else
			return false;
	}

}

void firstfriend(node*& head, node*& last, string name, char gender, int age, int rating)
{
	node* temp = new node;
	temp->name = name;
	temp->gender = gender;
	temp->age = age;
	temp->rating = rating;
	temp->next_ptr = NULL;
	head = temp;
	last = temp;

}
void addFriend(node*& head, node*& last, string name, char gender, int age, int rating)
{
	if (isEmpty(head))
	{

		firstfriend(head, last, name, gender, age, rating);
	}
	else
	{
		node* temp = new node;
		temp->name = name;
		temp->gender = gender;
		temp->age = age;
		temp->rating = rating;
		temp->next_ptr = NULL;
		last->next_ptr = temp;
		last = temp;
	}

	system("CLS");
	cout << "Recorded! \n";
}

void deleteSpecFriend(node*& head)
{
	bool nameMatch = false;
	string deleteFriend;
	cin.ignore();
	cout << "Enter name of friend you wish to unfriend \n";
	getline(cin, deleteFriend);
	node* temp = head;
	node* previous = NULL;
	if (temp != NULL && temp->name == deleteFriend)
	{
		head = temp->next_ptr;
		delete temp;



	}
	else
	{
		while (temp != NULL && temp->name != deleteFriend)
		{
			previous = temp;
			temp = temp->next_ptr;
		}
		if (temp == NULL)
			return;

		previous->next_ptr = temp->next_ptr;

		delete temp;
	}

}

void deleteRating(node*& head)
{
	bool rateMatch = false;
	int rateDelete;
	cout << "Enter Popularity rating of friend that you wish you want to delete: \n";
	cin >> rateDelete;
	node* temp = head;
	node* previous = NULL;
	if (temp != NULL && temp->rating == rateDelete)
	{
		head = temp->next_ptr;
		delete temp;



	}
	else
	{
		while (temp != NULL && temp->rating != rateDelete)
		{
			previous = temp;
			temp = temp->next_ptr;
		}
		if (temp == NULL)
			return;

		previous->next_ptr = temp->next_ptr;

		delete temp;
	}

}


void deleteFriend(node*& head, node*& last, node* current)
{
	char Delselect;
	if (isEmpty(current))
	{
		cout << "No friends on friends list! \n";
	}
	else
	{
		char Delselect;
		cout << "Delete by: \n";
		cout << "A. Name \n";
		cout << "B. Popularity Rating \n";
		cin >> Delselect;
		switch (Delselect)
		{
		case 'A':
			deleteSpecFriend(head);
			break;

		case 'B':
			deleteRating(head);
			break;

		}
	}
}


void viewAllFriends(node* current)
{
	system("CLS");
	cout << "Current Records: \n";
	while (current != NULL)
	{
		cout << "Name: " << current->name << endl;
		cout << "Gender: " << current->gender << endl;
		cout << "Age: " << current->age << endl;
		cout << "Popularity Rating: " << current->rating << endl;
		current = current->next_ptr;
	}
}
void viewSpecFriend(node* current)
{
	bool nameMatch = false;
	string searchFriend;
	cout << "Enter name of friend\n";
	cin.ignore();
	getline(cin, searchFriend);
	system("CLS");
	cout << "friend list: \n";
	while (current != NULL)
	{
		if (searchFriend == current->name)
		{
			cout << current->name << endl;
			cout << current->gender << endl;
			cout << current->age << endl;
			cout << current->rating << endl << endl;
			current = current->next_ptr;
			searchFriend = true;
		}
		if (current != NULL)current->next_ptr;
		if (current == NULL)
		{
			if (nameMatch == false)
			{
				system("CLS");
				cout << "No results for: " << searchFriend << endl;
			}
		}

	}

}

void viewFriend(node* current)
{
	system("CLS");
	char select;
	if (isEmpty(current))
	{
		cout << "No friends on friends list! \n";
	}
	else
	{
		cout << "A. Show a person \n";
		cout << "B. Show All list \n";
		cin >> select;
		switch (select)
		{
		case 'A':
			viewSpecFriend(current);
			break;

		case 'B':
			viewAllFriends(current);
			break;

		}


	}
}



void genderFilter(node* current)
{
	system("CLS");
	char sortbygender;
	bool genderMatch = false;
	cout << "Enter gender: \n";
	cin >> sortbygender;
	system("CLS");
	while (current != NULL)
	{
		cout << "friend list: \n";
		if (sortbygender == current->gender)
		{

			cout << current->name << endl;
			cout << current->gender << endl;
			cout << current->age << endl;
			cout << current->rating << endl << endl;
			current = current->next_ptr;
			genderMatch = true;
		}
		else
		{
			current = current->next_ptr;
			if (current == NULL)
			{
				if (genderMatch == false)
				{
					cout << "No results for: " << sortbygender << endl;
				}
			}
			current = current->next_ptr;
		}
	}
}


void ratingFilter(node* current)
{
	system("CLS");
	int sortbyrating;
	bool rateMatch = false;
	cout << "Enter Popularity Rating: \n";
	cin >> sortbyrating;
	while (current != NULL)
	{
		if (current->rating <= sortbyrating)
		{
			if (rateMatch == false)
				cout << "friend list: \n";
			cout << current->name << endl;
			cout << current->gender << endl;
			cout << current->age << endl;
			cout << current->rating << endl << endl;
			current = current->next_ptr;
			sortbyrating = true;
		}
		else
		{
			current = current->next_ptr;
			if (current == NULL)
			{
				if (rateMatch == false)
				{
					cout << "No results for: " << sortbyrating << endl;
				}
			}
		}
	}
}


void filterFriend(node* current)
{
	system("CLS");
	if (isEmpty(current))
		cout << "No friends on friends list! \n";
	else {
		char filselect;
		cout << "Sort by: \n";
		cout << "A. Gender \n";
		cout << "B. Popularity \n";
		cin >> filselect;
		cin.ignore();
		switch (filselect)
		{
		case 'A':
			genderFilter(current);
			break;

		case 'B':
			ratingFilter(current);
			break;
		}

	}

}



int main()
{
	node* head = NULL;
	node* last = NULL;
	char gender;
	char choice;
	string name;
	int m, f;
	int age = 0;
	int rating = 0;
	system("CLS");

	do {
		choice = menu();
		switch (choice)
		{
		case 'A':

			cin.ignore();
			cout << "Please enter name: ";
			getline(cin, name);

			cout << "Please enter gender: ";
			cin >> gender;
			if (gender == 'M' || gender == 'F');
			else {

				cout << "invalid gender. Please input m (M) or f (F) \n ";
				continue;
			}

			cout << "Please enter age: ";
			cin >> age;
			do
			{
				if (age < 1)
				{
					cout << "Invalid age please input again!";
					cin >> age;
				}
			} while (age < 0);


			cout << "Please enter Popularity Rating from 1-100: ";
			cin >> rating;

			do
			{
				if (rating < 0)
				{
					cout << "Invalid popularity rating please input again!";
					cin >> rating;
				}
				if (rating > 100)
				{
					cout << "Invalid popularity rating please input again!";
					cin >> rating;

				}
			} while (rating > 100 || rating < 0);

			addFriend(head, last, name, gender, age, rating);
			break;

		case 'B':
			deleteFriend(head, last, head);
			break;


		case 'C':
			viewFriend(head);
			break;

		case 'D':
			filterFriend(head);
			break;


		default: cout << "System exit\n";
		}
	}

	while (choice != 'E');
	cout << "Thankyou!";
	return 0;
}
