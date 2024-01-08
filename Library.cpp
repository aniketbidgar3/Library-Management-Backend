#include <bits/stdc++.h>

#include <fstream>
using namespace std;

class library
{

    string id, name, author, search, use, pass, username, password;
    fstream file;

public:
    void addBook();
    void showAll();
    void extractBook();
    void SignUp();
    void Login();

    bool LoggedIn = false;

    void setLoggedIn()
    {
        LoggedIn = true;
    }

} obj;

int main()
{

    char choice;

    while(true){

    cout << "----------------------------------" << endl;
    cout << "1-SignUp" << endl;
    cout << "2-Login" << endl;
    cout << "3-Show All Books" << endl;
    cout << "4-Extract Book" << endl;
    cout << "5-Add books(ADMIN)" << endl;
    cout << "6-Exit" << endl;
    cout << "----------------------------------" << endl;
    cout << "Enter Your Choice :: ";
    cin >> choice;

    switch (choice)
    {

    case '1':
        cin.ignore();
        obj.SignUp();
        break;

    case '2':
        cin.ignore();
        obj.Login();
        break;

    case '3':
        cin.ignore();
        obj.showAll();
        break;
    case '4':
        cin.ignore();
        obj.extractBook();
        break;
    case '5':
        cin.ignore();
        obj.addBook();
        break;
    case '6':
        return 0;
        break;
    default:
        cout << "Invalid Choice...!\n";
    }

    }


    return 0;

}
void library ::addBook()
{
    if (LoggedIn)
    {
        cout << "\nEnter Book ID :: ";
        getline(cin, id);
        cout << "Enter Book Name :: ";
        getline(cin, name);
        cout << "Enter Book's Author name :: ";
        getline(cin, author);

        file.open("bookData.txt", ios ::out | ios ::app);
        file << id << "*" << name << "*" << author << endl;
        file.close();
    }
    else
    {
        cout << "Access Denied. Please log in first\n";
    }
}

void library ::showAll()
{
    if (LoggedIn)
    {

       file.open("bookData.txt", ios::in);
    getline(file, id, '*');
    getline(file, name, '*');
    getline(file, author, '\n');

    cout << "\n\n";
    cout << setw(20) << "Book Id" << setw(30) << "Book Name" << setw(30) << "Author's Name" << endl;
    cout << setfill(' ') << setw(80) << "" << setfill(' ') << endl;

    while (!file.eof()) {
        cout << setw(20) << id << setw(30) << name << setw(30) << author << endl;

        getline(file, id, '*');
        getline(file, name, '*');
        getline(file, author, '\n');
    }
    file.close();
    }
    else
    {
        cout << "Access Denied. Please log in first\n";
    }
}


void library ::extractBook()
{
    if (LoggedIn)
    {

        showAll();
        cout << "Enter Book Id :: ";
        getline(cin, search);

        file.open("bookData.txt", ios ::in);
        getline(file, id, '*');
        getline(file, name, '*');
        getline(file, author, '\n');

        cout << "\n\n";
        cout << "\t\t Book Id \t\t\t Book Name \t\t\t Author's Name" << endl;
        while (!file.eof())
        {
            if (search == id)
            {
                cout << "\t\t " << id << " \t\t\t\t " << name << " \t\t\t " << author << endl;
                cout << "Book Extracted Successfully...!\n";
            }
            getline(file, id, '*');
            getline(file, name, '*');
            getline(file, author, '\n');
        }
        file.close();
    }
    else
    {
        cout << "Access Denied. Please log in first\n";
    }
}
void library::Login()
{
    cout << "Enter Username :: ";
    getline(cin, use);
    cout << "Enter Password :: ";
    getline(cin, pass);

    file.open("Username.txt", ios::in);
    getline(file, username, '*');
    getline(file, password, '\n');

    bool accessGranted = false; // Flag to track access status

    setLoggedIn();

    while (!file.eof())
    {
        if (use == username && pass == password)
        {
            cout << "Access Granted...!\n";
            accessGranted = true;
            break; // Exit the loop when access is granted
        }

        getline(file, username, '*');
        getline(file, password, '\n');
    }

    file.close();

    // Check the access status and display appropriate message
    if (!accessGranted)
    {
        cout << "Access Denied. Invalid username or password\n";
    }
}

void library ::SignUp()
{
    cout << "\nEnter Username:: ";
    getline(cin, username);
    cout << "Enter Password :: ";
    getline(cin, password);

    file.open("Username.txt", ios ::out | ios ::app);
    file << username << "*" << password << endl;
    file.close();
}
