#include <iostream>
#include <fstream>
using namespace std;

#define MAXBOOKS 1000

void insertAt (int loc, string ob, string* books);
void printMyBooks (string* books);

void read(string filename, string* books){
	ifstream fin(filename);
	int index = 0;
	while(!fin.eof()){
		getline(fin, books[index++]);
	}
}

int exponentialSearch(string* books, string searchBook){
	int index = 1;
	while (books[index-1] < searchBook && index < MAXBOOKS){
		index = index*2;
		//		cout << "index: " << index << endl;
	}

	int first = 0;
	int last = index;
	int mid;
	bool found = false;

	while (first <= last && !found){
		mid = (first + last)/2;

		if (books[mid] == searchBook){
			found = true;
		}
		else if (books[mid] > searchBook){
			last = mid -1;
		}
		else{
			first = mid +1;
		}
	}
	if (found){
		return mid;
	}
	else {
		return -1;
	}

}


void addBook(string* books, string aBook){
	int count = 0;
	int index = 1;
	int mid;
	bool found = false;

	while (books[index-1] < aBook && index < MAXBOOKS){
		index = index*2;

		//		cout << "index: " << index << endl;
	}

	int first = 0;
	int last = index;


	while (first <= last && !found){
		count ++;
		mid = (first + last)/2;

		if (aBook < books [0]){
			found = true;
			mid = 0;
			//insertAt (0, aBook, books);
		}
//		else if (aBook > books[last]){
//			found = true;
//			mid = last;
//		}
		else if (books[mid] == aBook){
			cout << "Book already in list" << endl;
			return;
			//found = true;
		}
		else if(aBook > books [mid] &&  aBook < books[mid+1]){
			found = true;
		}
		else if (books[mid] > aBook){
			last = mid -1;
		}
		else{
			first = mid +1;
		}
	}
	if (found){
		insertAt(mid, aBook, books);
	}
	else {
//		cout << "could not insert: " << mid << " index: "<< index << " count: " << count << endl;
//		cout << books[count+2] << endl;
		insertAt(count+2, aBook, books);
	}

}

void addBooks(string* newbooks, string* books){
	for (int i = 0; i < 4; i++){
		addBook(books, newbooks[i]);
	}
}

int main() {
	string* books = new string[MAXBOOKS];
	read("src//books.txt", books);
	string* newBooks = new string [MAXBOOKS];
	read("src//newbooks.txt", newBooks);

	//cout << books << endl;
	string searchBook = "The Lord of the Rings";
	cout << "ExponentialSearch: " << searchBook << " : ";
	cout << exponentialSearch(books, searchBook) << endl;

	string addThisBook = "ABCs";
	addBook(books, addThisBook);
	cout << "addBook: " << addThisBook << " : " << books[0] << endl;

	string addThisBook2 = "The Joy Luck Club";
	addBook(books, addThisBook2);
	cout << "addBook: " << addThisBook2 << " : " << books[5] << endl;
	cout << endl;

	cout << "After adding books: " << endl;
	printMyBooks(books);

	cout << "New books to be added: " << endl;
	printMyBooks(newBooks);

	addBooks(newBooks, books);

	/**************************************
	 * TODO: Implement your code here:
	 * 1. Take user input - search string
	 * 2. Search for the book using exponentialSearch
	 * 3. Take user input to add book to the list
	 * 4. Add the book using addBook
	 **************************************/
	cout << "After all operations" << endl;
	printMyBooks(books);
	delete [] books;
	return 0;
}

void insertAt (int loc, string ob, string* books){
	if (loc < 0 || loc >= MAXBOOKS){
		cout << "ERROR: The location for the to-be inserted item is out of range" << endl;
	}
	else {
		string *temp = new string [MAXBOOKS];
		if (loc == 0){
			temp [0] = ob;
			for (int i = loc+1; i < 20; i++){
				temp [i] = books [i-1];
			}
		}
		else{
			for (int i = 0; i < loc; i++){
				temp [i] = books [i];
			}
			temp [loc] = ob;
			for (int i = loc+1; i < 25; i++){
				temp [i] = books [i-1];
			}
		}
		delete [] books;
		books = temp;
	}

	string *temp2 = new string [MAXBOOKS];

	for (int i = 0; i < loc; i++){
		temp2 [i] = books [i];
	}

	for (int i = loc; i < 25; i++){
		temp2 [i] = books [i];
	}

	delete [] books;
	books = temp2;

}

void printMyBooks (string* books){
	for (int i = 0; i< 15; i++){
		cout << books[i] << endl;
	}
}
