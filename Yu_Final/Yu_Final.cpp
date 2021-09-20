#include <iostream>
using namespace std;



class node
{
    public:
    string name;
    int number;
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

void firstfriend (node *&head, node *&last, string name, int number, char gender, int age, int rating)
void addFriend (node *&head, node *&last, string name, int number, char gender, int age, int rating)
void deleteFriend (node *&head, int Num)
void viewFriend (node *&current)
void filterFriend ();


int main()
{
	
	return 0;
}
