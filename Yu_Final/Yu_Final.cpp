#include <iostream>

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

void firstfriend (node *&head, node *&last, string name,  char gender, int age, int rating)
{
    node *temp = new node;
    temp->name = name;
    temp->gender = gender;
    temp->age = age;
    temp->rating = rating;
    temp->next_ptr = NULL;
    head = temp;
    last = temp;

}
void addFriend (node *&head, node *&last, string name, char gender, int age, int rating)
{
	if (isEmpty(head))
	{
	
		firstfriend(head, last, name, gender, age, rating);
	}
	else
	{
		node *temp = new node;
	    temp->name = name;
	    temp->gender = gender;
	    temp->age = age;
	    temp->rating = rating;
	    temp->next_ptr = NULL;
	    last->next_ptr = temp;
	    last = temp;
	}
	
	system ("CLS");
	cout << "Recorded!" ;
}
void deleteFriend (node *&head, string Name)
{
	node* traverse = head;
    node* previous = NULL;
     

    if (traverse != NULL && traverse->name == Name)
    {
        head = traverse->next_ptr; 
        delete traverse;            
        return;
    }
 
   
      else
    {
    while (traverse != NULL && traverse->name != Name)
    {
        previous = traverse;
        traverse = traverse->next_ptr;
    }
 
    
    if (traverse == NULL)
        return;
 
  
    previous->next_ptr = traverse->next_ptr;
 
    
    delete traverse;
    }
}


void viewAllFriends (node *current)
{
	cout << "Current Records: \n";
        while (current != NULL)
        {
            cout << "Name: "<< current->name << endl;
            cout << "Gender: "<< current->gender << endl;
            cout << "Age: "<< current->age << endl;
             cout << "Popularity Rating: "<< current->rating << endl;
            current = current->next_ptr;
        }
}
void viewSpecFriend (node* current)
{
	bool nameMatch = false;
	string searchFriend;
	cin.ignore();
	cout << "Enter name of friend\n";
	getline(cin, searchFriend);
	while (current != NULL)
	{
		cout << "friend list: \n";
		if (searchFriend == current->name)
		{
			cout << current->name << endl;
			cout << current->gender << endl;
			cout << current->age << endl;
			cout << current->rating << endl << endl;
			current = current->next_ptr;
			searchFriend = true;
			
		}
		else
		{
			current = current->next_ptr;
			if (current == NULL)
			{
				if (nameMatch == false)
				{
					cout << "No results for: " << searchFriend <<endl;
				}
			}
		}
	}
	
}

void viewFriend (node *&current)
{
	char select;
	if (isEmpty(current))
        cout << "No friends on friends list! \n";
    else
    {
        cout << "A. Show a person \n";
        cout << "B. Show All list \n";
        cin >> select;
        switch (select)
        {
        	case 'A': 
        			viewSpecFriend (current);
        			break;
        			
        	case 'B':
        			viewAllFriends (current);
        			break;
        		
		}
        
        
    }
}



void genderFilter (node *&current)
{
	char sortbygender;
	bool genderMatch = false;
	cout << "Enter gender: \n";
	cin >> sortbygender;
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
						cout << "No results for: " << sortbygender <<endl;
					}
				}
				current = current->next_ptr;
			}
		}
}


void ratingFilter (node *&current)
{
	int sortbyrating;
	bool rateMatch = false;
	cin.ignore();
	cout << "Enter Popularity Rating: \n";
	cin >> sortbyrating;
	while (current != NULL)
	{
		cout << "friend list: \n";
		if (sortbyrating == current->rating)
		{
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
						cout << "No results for: " << sortbyrating <<endl;
					}
				}
		}
	}
}


void filterFriend (node *current)
{
	if (isEmpty(current))
        cout << "No friends on friends list! \n";
    else{
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
	node *head = NULL;
	node *last = NULL;
	char gender;
	string Name;
	char choice;
	string name;
	int m, f;
	int age = 0;
	int rating = 0;
	system ("CLS");
	
	do{
		choice = menu();
		
		switch(choice)
		{
			case 'A':
				
				cin.ignore();
				cout << "Please enter name: ";
				getline(cin, name);
				
				cout << "Please enter gender: ";
				cin >> gender;
				if (gender == 'm' || gender == 'M' || gender == 'f' || gender == 'F');
				else{
					
				cout << "invalid gender. Please input m (M) or f (F) \n ";
				continue;
		}
				
				cout << "Please enter age: ";
				cin >> age;
	
				cout << "Please enter Popularity Rating: ";
				cin >> rating;
			
				addFriend (head, last, name, gender, age, rating);
				break;
				
			case 'B':
				cin >> Name;
				deleteFriend (head, Name);
			    viewFriend (head);
			    break;
			    
			    
			case 'C':
				viewFriend (head);
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
