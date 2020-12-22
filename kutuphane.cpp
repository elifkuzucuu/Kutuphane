#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <sstream>



using namespace std;
//User Class
int size = 0;
class User {
private:
	void createUser(User a);
	int checkUser(User a);
	void deleteUser(User a);
public:
	friend class File;
	string userName;
	string userPassword;
	string userID;
	User(string uN, string uId, string uP)
	{
		userName = uN;
		userID = uId;
		userPassword = uP;

	}
};

//Book CLass
class Book {
private:
	void addBook(Book a);
	void deleteBook(string a);
	void displayAllBooks();
	void sortAllBooks();

public:
	friend class File;

	string bookName;
	string authorName;
	string ISBN;
	int pageNumber;
	int publishYear;
	string keyWords;
	Book(string bN, string aN, string IS, int pN, int pY, string kW)
	{

		bookName = bN;
		authorName = aN;
		ISBN = IS;
		pageNumber = pN;
		publishYear = pY;
		keyWords = kW;
	}
};

class File {

public:
	void addB(Book a)
	{
		a.addBook(a);
	}
	void deleteB(string b, Book a)
	{
		a.deleteBook(b);
	}
	int checkU(User a)
	{
		return a.checkUser(a);

	}
	void displayBooks(Book a)
	{
		a.displayAllBooks();
	}
	void sortBooks(Book a)
	{
		a.sortAllBooks();
	}
	void deleteU(User a)
	{
		a.deleteUser(a);
	}
	void createU(User a)
	{
		a.createUser(a);
	}
};
struct year {

	int pyear;
	Book* pr;

};
void Book::addBook(Book a)
{
	string s;
	ofstream file;
	file.open("Books.txt", ios::app);
	file << a.bookName << " " << a.authorName << " " << a.ISBN << " " << a.pageNumber <<" "<<"-" << a.publishYear << " " << a.keyWords<<endl;

	file.close();

}
void Book::deleteBook(string a)
{
	int counter = 0, i = 0, j = 0, mcounter = 0;
	ifstream file;
	file.open("Books.txt");
	string line;
	string nline = "*";

	while (!file.eof())
	{
		getline(file, line);
	
		i = 0;
		while (1)
		{
			if (line[i] == '\0')
				break;


			if (line[i] == a[j])
			{

				counter++;
				if (counter == 9)
					mcounter = counter;

				j++;



			}
			else
			{
				j = 0;
				counter = 0;
			}

			i++;


		}
	


		if (mcounter == a.length())
		{

			nline = line;

		}

		mcounter = 0;

	}
	file.close();
	if(nline == "*")
	cout<<"No books found."<<endl;
	ofstream file1;
	ifstream file2;
	file2.open("Books.txt");
	file1.open("Temp.txt");
	while (!file2.eof())
	{
		getline(file2, line);

		if (line != nline)
			file1 << line << "\n";

	}
	file1.close();
	file2.close();

	ifstream main;
	ofstream file3;
	file3.open("Books.txt");
	main.open("Temp.txt");

	while (!main.eof())
	{
		getline(main, line);

		file3 << line << "\n";

	}

	file3.close();
	main.close();

}
void Book::displayAllBooks()
{
	string s;
	int i = 0;
	ifstream file;
	file.open("Books.txt");
	while (!file.eof())
	{
		getline(file, s);
		if(s[0]== '\0')
		continue;
		
		i=0;
		while(s[i] != '\0')
		{ 
		if(s[i] != '-')
		cout << s[i];
		i++;
		}
	cout<<endl;

	}
	file.close();
cout<<endl;

}
void User::createUser(User a) {

	string s;
	s = a.userID;
	ofstream file5;
	file5.open("Users.txt", ios::app);
	file5 << s << " " << a.userName << " " << a.userPassword << endl;
	file5.close();
	cout<<"New user is created!"<<endl;
}

int User::checkUser(User a) {

	ifstream file;
	file.open("Users.txt");
	string satir;
	int offset;
	int i = 0;
	
	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, satir);
			if ((offset = satir.find(a.userID, 0)) != string::npos) {
				return 1;
			}
			
		}
		return 0;
		file.close();
	}
	


	

}
void Book::sortAllBooks() {
	int* array, year = 0, i = 0, j = 0;
	int bookcounter = 0;
	array = (int*)malloc(bookcounter * sizeof(int));
	ifstream oku;

	string str;
	oku.open("Books.txt");

	while (!oku.eof())
	{	
		
		getline(oku, str);
		bookcounter++;

	}

	oku.close();

	ifstream temp;
	temp.open("Books.txt");


	while (!temp.eof())
	{
		getline(temp, str);
		i = 0;
		
		while (1)
		{
			if (str[i] == '\0')
				break;

			if (str[i] == '-')
			{

				year = (str[i + 1] - '0') * 1000 + (str[i + 2] - '0') * 100 + (str[i + 3] - '0') * 10 + (str[i + 4] - '0') * 1;

			}

			i++;

		}
		array[j] = year;
		year = 0;
		j++;
	}

	
	


	int g;
	temp.close();

	
	for (j = 0; j < bookcounter - 1; j++)
	{
		for (i = 0; i < bookcounter - 1; i++)
		{
			if (array[i + 1] < array[i])
			{
				g = array[i];
				array[i] = array[i + 1];
				array[i + 1] = g;
			}

		}
	}
	
	

	
	stringstream ss;
	int offset;
	
	
	ifstream temp3;
	int yearco = 0, k = 0, bol = 1000, son, m, t = 0, yedek;
	string str1, str2;
	
	string satir;
	for(i=0;i<bookcounter;i++)
	{
		stringstream ss;
		ss<<array[i];
		ss>>str1;
		yearco = 0;
		
		
	temp3.open("Books.txt");
	if (temp3.is_open())
	{
		while (!temp3.eof()) 
		{
			getline(temp3, satir);
			
			if ((offset = satir.find(str1, 0)) != string::npos) 
			{
				yearco = 1;
				
			}
			
			if(yearco == 1)
			{
			cout<<satir<<endl;
			yearco = 0;
			}
		}
			
	temp3.close();
	
	}
	
	

	}
		
		

cout<<endl;

	



}



User getUser(User a)
{
	ofstream ilk;
	ilk.open("Users.txt", ios :: app);
	string name, password, id;
	cout << "User Name: ";
	getline(cin, name);
	a.userName = name;
	cout << "Password: ";
	getline(cin, password);
	a.userPassword = password;
	cout << "User Id: ";
	getline(cin, id);
	a.userID = id;
	
	ilk.close();
	

	return a;

}


int main()
{
	int size = 0;
	year* array = new year[size];
	Book in("a", "a", "a", 6, 66, "a");
	User a("a", "a", "a");
	User b("a", "a", "a");
	string id;
	File knk;
	int intid = 1000;
	string name, password, deneme;
	string letter;
	char s = ',';
	a = getUser(a);

	//user check
	if (!knk.checkU(a))
	{
		cout << "No users found. Create User" << endl << "Please enter your user Id to create new user" << endl;
		cin >> id; cin.ignore();
		b.userID = id;
		cout << endl << "Please enter your user name" << endl;
		cin >> name; cin.ignore();
		b.userName = name;
		cout << endl << "Please enter your password" << endl;
		cin >> password; cin.ignore();
		b.userPassword = password;
		knk.createU(b);
		getUser(a);

	}
	
	

	while(1)
	{
	cout << "Press A to insert a book" << endl << "Press D to delete a book" << endl << "Press S to sort all books (date)" << endl << "Press X to display all books" << endl << "Press Q to exit" << endl;
	getline(cin, letter);
	
	if(letter == "q" || letter == "Q")
	break;

	if (letter == "a" || letter == "A")
	{
		cout << "Enter the information of the book." << endl;
		cout << "Book Name: ";
		getline(cin, in.bookName); cout << endl;
		cout << "Author Name: "; getline(cin, in.authorName); cout << endl;
		cout << "ISBN: "; getline(cin, in.ISBN); cout << endl;
		cout << "Page Number: "; cin >> in.pageNumber; cin.ignore(); cout << endl;
		cout << "Publish Year: "; cin >> in.publishYear; cin.ignore(); cout << endl;
		array[size].pyear = in.publishYear;
		cout << "Category: "; getline(cin, in.keyWords); cout << endl;
		array[size].pr = &in;
		size++;
		knk.addB(in);

	}
	if (letter == "x" || letter == "X")
		knk.displayBooks(in);
	if (letter == "d" || letter == "D")
	{
		cout << "Enter the ISBN of the book" << endl;
		getline(cin, deneme);
		knk.deleteB(deneme, in);
	}

	if (letter == "s" || letter == "S")
		knk.sortBooks(in);


	}


	delete(array);

















}
