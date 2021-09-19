#include <iostream>
using namespace std;
 
int main()
{
    char Number;
 	int arr[7], average=0;
 	int i, j, temp, desc;
 	
 	cout << "1. Ascending \n" "2. Descending \n";
	cin >> Number;
	
		switch(Number) {
	case '1': cout << "Enter 7 numbers \n";
		for(i=0; i<7; i++)
    {
        cin>>arr[i];
    }
    for(i=0; i<7; i++)
    {
        for(j=i+1; j<7; j++)
        {
           
            if(arr[j] < arr[i])
            {
                temp = arr[i];
                arr
				[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
   
    cout<<"The numbers of the array is sorted ascending order:"<<endl;
    for(i=0; i<7; i++)
    {
        cout<<arr[i]<<endl;
 
 	for (int i=0;i<7;i++)
	 {
     average=average+arr[i];
     cout<<arr[i];
 	}
	 cout <<"  Average = "<<average;
 
	 {
     if(average%2==0)
     {
         cout<<" The average is even number\n"<<endl;
     }
     else
     {
         cout<<" The average is odd number\n"<<endl;
     }
    }
}
	break;

	case '2': cout << "Enter 7 numbers \n";
	 cout<<" ";
	 for (i = 0; i < 7; ++i)
    cin>>arr[i];
   
    for (i = 0; i < 7; ++i)
    {
        for (j = i + 1; j < 7; ++j)
        {
            if (arr[i] < arr[j])
            {
                desc = arr[i];
                arr[i] = arr[j];
                arr[j] = desc;
            }
        }
    }
    cout<<"\n Numbers in Descending Order : \n";
    for (i = 0; i < 7; ++i)
    {
        cout<<" ";
        cout<<arr[i];
        cout<<"\n";
    }
    break;
}
	return 0;
}
 
