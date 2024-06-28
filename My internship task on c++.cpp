/*Build a console-based to-do list application.
 Users should be able to add tasks, mark them as
 completed, and view their current tasks*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Task {
private:
    string name; // Task name
    string description; // Task description
    string dueDate; // Task due date
    bool completed; // Task completion status

public:
    Task(const string& name, const string& description,
         const string& dueDate)
        : name(name)
        , description(description)
        , dueDate(dueDate)
        , completed(false)
    {
    }
    string getName() const { return name; }
    string getDescription() const { return description; }
    string getDueDate() const { return dueDate; }
    bool isCompleted() const { return completed; }
    void setName(const string& name) { this->name = name; }
    void setDescription(const string& description)
    {
        this->description = description;
    }
    void setDueDate(const string& dueDate)
    {
        this->dueDate = dueDate;
    }

    void markCompleted() { completed = true; }
    void displayTask() const
    {
        cout << name << " ("
             << (completed ? "Completed" : "Pending")
             << ") - Due: " << dueDate << endl
             << "   Description: " << description << endl;
    }
};
class ToDoList {
private:
    vector<Task> tasks; 
    public:
    void displayMenu()
    {
        cout
            << "\n---------- To-Do List Menu -----------\n";
        cout << "1. Add Task\n";
        cout << "3. Display Tasks\n";
        cout << "4. Mark Task as Completed\n";
    
    }
    void addTask()
    {
        string name, description, dueDate;
        cout << "Enter task name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter task description: ";
        getline(cin, description);
        cout << "Enter task due date (YYYY-MM-DD): ";
        getline(cin, dueDate);

        tasks.emplace_back(name, description, dueDate);
        cout << "Task added successfully!" << endl;
    }
    void markTaskCompleted()
    {
        if (tasks.empty()) {
            cout << "No tasks to mark as completed!"
                 << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].getName()
                 << endl;
        }
        cout << "Enter the task number to mark as "
                "completed: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].markCompleted();
            cout << "Task marked as completed!" << endl;
        }
        else {
            cout << "Invalid task number!" << endl;
        }
    }


    // Display all tasks
    void displayTasks()
    {
        if (tasks.empty()) {
            cout << "No tasks to display!" << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            tasks[i].displayTask();
        }
    }

    void run()
    {
        int choice;
        do {
            displayMenu();
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
            case 1:
                addTask();
                break;
           
            case 3:
                displayTasks();
                break;
            case 4:
                markTaskCompleted();
                break;
            default:
                cout << "Invalid choice. Please try again!"
                     << endl;
            }
        } while (choice != 6);
    }
};
int main()
{
   
    ToDoList toDoList;
    toDoList.run();
    return 0;
}
