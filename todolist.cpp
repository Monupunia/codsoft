#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

void taskinput(){
	int input;
	cout<<"enter a input:";
	cin>>input;
}

void addTask() {
    string description;
    cout << "Enter a new task: ";
    getline(cin, description);
    Task task = {description, false};
    tasks.push_back(task);
    cout << "Task '" << description << "' added!" << endl;
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
    } else {
        cout << "Your tasks:" << endl;
        for (int i = 0; i < tasks.size(); i++) {
            string status = tasks[i].completed ? "Completed" : "Pending";
            cout << i + 1 << ". " << tasks[i].description << " - " << status << endl;
        }
    }
}

void markTaskAsCompleted() {
    viewTasks();
    int taskNum;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNum;
    taskNum--; // adjust for 0-based indexing
    if (taskNum < 0 || taskNum >= tasks.size()) {
        cout << "Invalid task number." << endl;
    } else {
        tasks[taskNum].completed = true;
        cout << "Task '" << tasks[taskNum].description << "' marked as completed!" << endl;
    }
}

void removeTask() {
    viewTasks();
    int taskNum;
    cout << "Enter the task number to remove: ";
    cin >> taskNum;
    taskNum--; // adjust for 0-based indexing
    if (taskNum < 0 || taskNum >= tasks.size()) {
        cout << "Invalid task number." << endl;
    } else {
        tasks.erase(tasks.begin() + taskNum);
        cout << "Task removed!" << endl;
    }
}

int main() {
    while (true) {
        cout << "\nTo-Do List Manager" << endl;
        cout << "1. Add task" << endl;
        cout << "2. View tasks" << endl;
        cout << "3. Mark task as completed" << endl;
        cout << "4. Remove task" << endl;
        cout << "5. Quit" << endl;
        int choice;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskAsCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid option. Try again!" << endl;
        }
    }

    return 0;
}
