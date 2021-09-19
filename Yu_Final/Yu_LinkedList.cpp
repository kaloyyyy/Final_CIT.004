#include <iostream>
using namespace std;

class node
{
    public:
    string name;
    int number;
    int data;
    node* next_ptr;
};

int counter = 0;


char menu()
{
	char choice;
	cout << "MENU \n";
	
	
		
	cout << "A. Create" << endl;
	cout << "B. Delete" << endl;
	cout << "C. Display all" << endl;
	cout << "D. Exit" << endl;
	
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

void sorting(node *&head)
{
	int tempNum;
    string tempName;
    node* i;
    node* j;
    for(i=head; i->next_ptr!=NULL;i=i->next_ptr)
    {
        for (j = i->next_ptr; j != NULL; j=j->next_ptr)
        {
            if (i->number > j->number)
            {
                tempNum = i->number;
                tempName = i->name;
                i->number = j->number;
                i->name = j->name;
                j->number = tempNum;
                j->name = tempName;
            }
        }
    }          
}

void firstNode(node *&head, node *&last, int number, string name)
{
	system ("CLS");
    node *temp = new node;
    temp->number = number;
    temp->name = name;
    temp->next_ptr = NULL;
    head = temp;
    last = temp;

}


void addNode(node *&head, node *&last, int number, string name)
{
	system ("CLS");
	if (isEmpty(head))
		firstNode(head, last, number, name);
	else
	{
		node *temp = new node;
	    temp->number = number;
	    temp->name = name;
	    temp->next_ptr = NULL;
	    last->next_ptr = temp;
	    last = temp;
	}
	
	sorting (head);
	system ("CLS");
	cout << "Recorded!" ;
}
void viewNode(node *current)
{
if (isEmpty(current))
        cout << "No Records Found! \n";
    else
    {
        cout << "Current Records: \n";
        while (current != NULL)
        {
            cout << "Number: "<< current->number << endl;
            cout << "Name: "<< current->name << endl;
            current = current->next_ptr;
        }
    }
	
}
void deleteNode(node *&head, int Num)
{
     
    node* traverse = head;
    node* previous = NULL;
     

    if (traverse != NULL && traverse->number == Num)
    {
        head = traverse->next_ptr; 
        delete traverse;            
        return;
    }
 
   
      else
    {
    while (traverse != NULL && traverse->number != Num)
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


int main()
{
	node *head = NULL;
	node *last = NULL;
	int Num;
	char choice;
	int number;
	string name;
	system ("CLS");
	
	do{
		choice = menu();
		
		switch(choice)
		{
			case 'A':
				cout << "Please enter number: ";
				cin >> number;
				
				cin.ignore();
				cout << "Please enter name: ";
				getline(cin, name);
				addNode (head, last, number, name);
				break;
			case 'B':	
		 		cout<<"What number to delete?: ";
		 		cin >> Num;
		 		deleteNode(head, Num);
		 		viewNode(head);
				break;
				
			case 'C':
			system ("CLS");
			viewNode(head);
			break;
			
			
			default: cout << "System exit\n";
		}
	}
	
	while (choice != 'D');
	cout << "Thankyou!";
	return 0;
}
