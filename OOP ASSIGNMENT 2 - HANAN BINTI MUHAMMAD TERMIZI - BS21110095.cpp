#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

	char *author = new char[20];
	char *title = new char[20];
	char *publisher = new char[20];
	float *price = new float;
	int *stock = new int;

	
	void feeddata();
	void editdata();
	void showdata();
	int search(char[],char[]);
	void buybook();
	


void feeddata()	{
	cin.ignore();
	cout<<"\nEnter Author Name: ";      cin.getline(author,20);
	cout<<"Enter Title Name: ";       cin.getline(title,20);
	cout<<"Enter Publisher Name: ";   cin.getline(publisher,20);
	cout<<"Enter Price: ";            cin>>*price;
	cout<<"Enter Stock Position: ";   cin>>*stock;   
	
}

void editdata()	{
	
	cout<<"\nEnter Author Name: ";      cin.getline(author,20);
	cout<<"Enter Title Name: ";       cin.getline(title,20);
	cout<<"Enter Publisher Name: ";   cin.getline(publisher,20);
	cout<<"Enter Price: ";            cin>>*price;
	cout<<"Enter Stock Position: ";   cin>>*stock;   
	
}

void showdata()	{
	cout<<"\nAuthor Name: "<<author;
	cout<<"\nTitle Name: "<<title;
	cout<<"\nPublisher Name: "<<publisher;
	cout<<"\nPrice: "<<*price;
	cout<<"\nStock Position: "<<*stock;   
	
}

int search(char tbuy[20],char abuy[20] )	{
	if(strcmp(tbuy,title)==0 && strcmp(abuy,author)==0)
		return 1;
	else return 0;
		
}

void buybook()	{
	int count;
	cout<<"\nEnter Number Of Books to buy: ";
	cin>>count;
	if(count<=*stock)	{
		*stock=*stock-count;
		cout<<"\nBooks Bought Sucessfully";
		cout<<"\nAmount: RM. "<<(*price)*count;
	}
	else
		cout<<"\nRequired Copies not in Stock";
}

int main()	{
	int i=0,r,t,choice;
	char titlebuy[20],authorbuy[20];
	while(1)	{
		cout<<"\n\n\t\tMENU"
		<<"\n1. Entry of New Book"
		<<"\n2. Buy Book"
		<<"\n3. Search For Book"
		<<"\n4. Edit Details Of Book"
		<<"\n5. Exit"
		<<"\n\nEnter your Choice: ";
		cin>>choice;
		
		switch(choice)	{
			
			// Entry of new book
			case 1:	
				feeddata();
				i++;	break;
			
			// Buy book	
			case 2: cin.ignore();
				cout<<"\nEnter Title Of Book: "; cin.getline(titlebuy,20);
				cout<<"Enter Author Of Book: ";  cin.getline(authorbuy,20);
				
				buybook();
				
				break;
			
			// Search for book	
			case 3: cin.ignore();
				cout<<"\nEnter Title Of Book: "; cin.getline(titlebuy,20);
				cout<<"Enter Author Of Book: ";  cin.getline(authorbuy,20);
				search(titlebuy,authorbuy);
				showdata();
				
				break;
				
			// Edit details of book	
			case 4: cin.ignore();	
				cout<<"\nEnter Title Of Book: "; cin.getline(titlebuy,20);
				cout<<"Enter Author Of Book: ";  cin.getline(authorbuy,20);
			 	
			 	editdata();
		
				break;
			
			// Exit
			case 5: exit(0);
			default: cout<<"\nInvalid Choice Entered";
			
		}
	}
	
	
	
	
	return 0;
}
