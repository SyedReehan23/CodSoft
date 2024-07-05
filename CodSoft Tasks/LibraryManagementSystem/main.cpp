#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <ctime>

using namespace std;

struct Book{
    string title;
    string author;
    string ISBN;
    bool isAvailable;
};

struct Borrower{
    string name;
    string borrowedISBN;
    time_t borrowDate;
};


vector<Book>books;
unordered_map<string, Borrower>borrowers;

void displayMenu(){
    cout<<"1.Add Book\n"
        <<"2.Search Book\n"
        <<"3.Checkout Book\n"
        <<"4.Return Book\n"
        <<"5.Exit\n"
        <<"Enter your choice : ";
}

void addBook(){
    Book book;
    cout<<"Enter Title: "<<endl;
    cin.ignore();
    getline(cin, book.title);
    cout<<"Enter author: "<<endl;
    getline(cin, book.author);
    cout<<"Enter ISBN:"<<endl;
    getline(cin, book.ISBN);
    book.isAvailable =true;
    books.push_back(book);
    cout<<"Book added succesfully"<<endl;
}
void searchBook(){
    string query;
    cout<<"Enter the title or the author or the ISBN of the book you want"<<endl;
    cin.ignore();
    getline(cin,query);
for(const auto&book : books){
    if(book.title == query || book.author == query || book.ISBN == query){
        cout<< "Title: "<<book.title<<", Author: "<<book.author<<", ISBN: " <<book.ISBN<<", Available: "<<(book.isAvailable? "yes" : "No")<<endl;
        
    }
}

}

void checkoutBook(){
    string isbn, borrowerName;
    cout<<"Enter ISBN of the book you want to checkout: "<<endl;
    cin.ignore();
    getline(cin, isbn);
    for(auto& book : books){
        if (book.ISBN == isbn && book.isAvailable){
            cout<<"Enter borrower's name: "<<endl;
            getline(cin, borrowerName);
            book.isAvailable =false;
            Borrower borrower = {borrowerName, isbn, time(0)};
            borrowers[isbn] = borrower;
            cout<< "Book chechked out successfully! "<<endl;
            return;
        }
    }
    cout<<"Book not available"<<endl;
}

void returnBook(){
    string isbn;
    cout<<"Enter ISBN of the book to return: "<<endl;
    cin.ignore();
    getline(cin, isbn);
    auto it = borrowers.find(isbn);
    if(it != borrowers.end()){
        for(auto& book : books){
            if(book.ISBN == isbn){
                book.isAvailable=true;
                time_t currentTime= time(0);
                double diff = difftime(currentTime, it->second.borrowDate);
                int days = diff / (60 * 60 * 24);
                if(days>14){
                    double fine= (days - 14)* 0.5;
                    cout<<"Book returned late. Fine: $"<<fine<<endl;
                }else{
                    cout<<"Book returned on time. No fine"<<endl;
                }
                borrowers.erase(it);
                return;
            }
        }
}
cout<< "Invalid ISBN or book was not checked out!"<<endl;
}

int main() {
    int choice;
    while(true){
        
    displayMenu();
    cin>>choice;
    switch(choice){
        case 1:addBook();
        break;
        case 2:searchBook();
        break;
        case 3:checkoutBook();
        break;
        case 4:returnBook();
        break;
        case 5: cout<<"Exit"<<endl;
        return 0;
        default:
        cout<<"Invalid choice! try again."<<endl;
    }
}
return 0;

}
