#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Task {
public:
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(string description) {
        Task task(description);
        tasks.push_back(task);
        cout << "Task '" << description << "' added." << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks." << endl;
        } else {
            cout << "Tasks:" << endl;
            for (int i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << tasks[i].description << " - " << (tasks[i].completed ? "Completed" : "Pending") << endl;
            }
        }
    }

    void markTaskCompleted(int index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            cout << "Task '" << tasks[index - 1].description << "' marked as completed." << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    void removeTask(int index) {
        if (index >= 1 && index <= tasks.size()) {
            cout << "Task '" << tasks[index - 1].description << "' removed." << endl;
            tasks.erase(tasks.begin() + index - 1);
        } else {
            cout << "Invalid task number." << endl;
        }
    }
};

int main() {
    ToDoList todoList;

    while (true) {
        cout << "\nTODO LIST MANAGER" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string taskDescription;
                cout << "Enter task description: ";
                cin.ignore(); // Ignore the newline character from the previous input
                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: {
                int taskIndex;
                cout << "Enter task number to mark as completed: ";
                cin >> taskIndex;
                todoList.markTaskCompleted(taskIndex);
                break;
            }
            case 4: {
                int taskIndex;
                cout << "Enter task number to remove: ";
                cin >> taskIndex;
                todoList.removeTask(taskIndex);
                break;
            }
            case 5:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 5." << endl;
        }
    }

    return 0;
}
