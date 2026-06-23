#include <iostream>
#include <string>
using namespace std;

class book
{
private:
    string book_name;
    string writer;
    string isbn_num;
    bool avl;

public:
    book()
    {
        book_name = "";
        writer = "";
        isbn_num = "";
        avl = true;
    }

    void add_book()
    {
        cin.ignore();
        cout << "Enter Book Title: ";
        getline(cin, book_name);

        cout << "enter Author Name: ";
        getline(cin, writer);

        cout << "enter ISBN number: ";
        getline(cin, isbn_num);

        avl = true;
    }

    void show_books()
    {
        cout << "\ntitle : " << book_name;
        cout << "\nauthor: " << writer;
        cout << "\nISBN  : " << isbn_num;

        if (avl)
            cout << "\nStatus: Available\n";
        else
            cout << "\nStatus: Issued\n";
    }

    string get_title()
    {
        return book_name;
    }

    string get_writer()
    {
        return writer;
    }

    string get_isbn()
    {
        return isbn_num;
    }

    bool isAvailable()
    {
        return avl;
    }

    void issueBook()
    {
        avl = false;
    }

    void returnBook()
    {
        avl = true;
    }
};

class library
{
private:
    book array_book[100];
    int title_book;

public:
    library()
    {
        title_book = 0;
    }

    void addNewBook()
    {
        if (title_book < 100)
        {
            array_book[title_book].add_book();
            title_book++;
            cout << "\nbook Added Successfully \n";
        }
        else
        {
            cout << "\nLibrary Full\n";
        }
    }

    void show_books()
    {
        if (title_book == 0)
        {
            cout << "\nNo Books Found\n";
            return;
        }

        for (int z = 0; z < title_book; z++)
        {
            cout << "\n-------------------";
            array_book[z].show_books();
        }
    }

    void find_book()
    {
        string search_book;
        cin.ignore();

        cout << "enter Title to Search: ";
        getline(cin, search_book);

        bool gotIt = false;

        for (int k = 0; k < title_book; k++)
        {
            if (array_book[k].get_title() == search_book)
            {
                array_book[k].show_books();
                gotIt = true;
            }
        }

        if (!gotIt)
        {
            cout << "\nbook Not Found\n";
        }
    }

    void checkoutBook()
    {
        string findIsbn;
        cin.ignore();

        cout << "Enter ISBN of Book: ";
        getline(cin, findIsbn);

        for (int x = 0; x < title_book; x++)
        {
            if (array_book[x].get_isbn() == findIsbn)
            {
                if (array_book[x].isAvailable())
                {
                    array_book[x].issueBook();
                    cout << "\nbook Issued Successfully!\n";
                }
                else
                {
                    cout << "\nbook Already Issued\n";
                }
                return;
            }
        }

        cout << "\nbook Not Found\n";
    }

    void returnBook()
    {
        string retISBN;
        cin.ignore();

        cout << "enter ISBN of Returning Book: ";
        getline(cin, retISBN);

        for (int j = 0; j < title_book; j++)
        {
            if (array_book[j].get_isbn() == retISBN)
            {
                array_book[j].returnBook();

                int lateDays;
                cout << "Days Late: ";
                cin >> lateDays;

                if (lateDays > 0)
                {
                    int fn = lateDays * 5;
                    cout << "Fine Amount = Rs " << fn << endl;
                }
                else
                {
                    cout << "No Fine\n";
                }

                cout << "Book Returned Successfully\n";
                return;
            }
        }

        cout << "\nBook Not Found \n";
    }
};

int main()
{
    library ob1;
    int op;

    do
    {
        cout << "\n\n LIBRARY MANAGEMENT SYSTEM ";
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Search Book";
        cout << "\n4. Checkout Book";
        cout << "\n5. Return Book";
        cout << "\n6. Exit";
        cout << "\nEnter Choice: ";
        cin >> op;

        switch (op)
        {
        case 1:
            ob1.addNewBook();
            break;

        case 2:
            ob1.show_books();
            break;

        case 3:
            ob1.find_book();
            break;

        case 4:
            ob1.checkoutBook();
            break;

        case 5:
            ob1.returnBook();
            break;

        case 6:
            cout << "\nExiting Program\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (op != 6);

    return 0;
}