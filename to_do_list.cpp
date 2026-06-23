#include <iostream>
#include <vector>
using namespace std;

class todolist
{
private:
    vector<string> tasks;
    vector<bool> comepletedtask;

public:

    void add_new_task()
    {
        string abcTask;

        cin.ignore();
        cout << "Enter task: ";
        getline(cin, abcTask);

        tasks.push_back(abcTask);
        comepletedtask.push_back(false);

        cout << "Task Added Successfully!\n";
    }

    void displaytasks()
    {
        if(tasks.size() == 0)
        {
            cout << "\n No Tasks Available. \n";
            return;
        }

        cout << "\n TASK LIST \n";

        for(int q = 0; q < tasks.size(); q++)
        {
            cout << q + 1 << ". "
                 << tasks[q]
                 << " [";

            if(comepletedtask[q] == true)
                cout << " Completed";
            else
                cout << " Pending";

            cout << "]\n";
        }
    }

    void finishtask()
    {
        int weirdNum;

        if(tasks.size() == 0)
        {
            cout << "No Tasks Found.\n";
            return;
        }

        displaytasks();

        cout << "\n Enter task number to mark complete: ";
        cin >> weirdNum;

        if(weirdNum >= 1 && weirdNum <= tasks.size())
        {
            comepletedtask[weirdNum - 1] = true;
            cout << " Task Marked Completed!\n";
        }
        else
        {
            cout << " Invalid Task Number.\n";
        }
    }

    void erasetask()
    {
        int xDelete;

        if(tasks.size() == 0)
        {
            cout << "No Tasks To Remove.\n";
            return;
        }

        displaytasks();

        cout << "\n Enter task number to remove: ";
        cin >> xDelete;

        if(xDelete >= 1 && xDelete <= tasks.size())
        {
            tasks.erase(tasks.begin() + (xDelete - 1));
            comepletedtask.erase(comepletedtask.begin() + (xDelete - 1));

            cout << " Task Removed Successfully\n";
        }
        else
        {
            cout << "Invalid Task Number\n";
        }
    }
};

int main()
{
    todolist mylist;

    int choice;

    do
    {
        cout << "\n TO DO LIST MANAGER \n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task Complete\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                mylist.add_new_task();
                break;

            case 2:
                mylist.displaytasks();
                break;

            case 3:
                mylist.finishtask();
                break;

            case 4:
                mylist.erasetask();
                break;

            case 5:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 5);

    return 0;
}