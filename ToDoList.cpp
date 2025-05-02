#include<iostream>
#include<string>
using namespace std;

const int maxtask= 100;

class Task {
public:
    string add;
    bool completed;
    Task() : add(""), completed(false) {}
    Task(string desc) : add(desc), completed(false) {}
    void markCompleted() {
	 completed = true; 
	 }
    void display(int index) {
        cout << index + 1 << ". " << (completed ? "[?] " : "") << add << endl;
    }
};

class ToDoList {
private:
    Task tasks[maxtask];
    int taskCount;
public:
    ToDoList() : taskCount(0) {}
    
    void addTask() {
        if (taskCount >= maxtask) {
            cout << "Task List Is Full! Cannot Add More Tasks."<<endl;
            return;
        }
        cout << "Enter Task : ";
        cin.ignore();
        getline(cin, tasks[taskCount].add);
        tasks[taskCount].completed = false;
        taskCount++;
        cout <<endl <<"Task Added Successfully!"<<endl<<"....................."<<endl;
    }
    
    void viewTasks() {
        if (taskCount == 0) {
            cout <<endl<< "No Tasks Available."<<endl;
            return;
        }
        cout <<endl<< "To-Do List:"<<endl;
        for (int i = 0; i < taskCount; i++) {
            tasks[i].display(i);
        }
    }
    
    void completeTask() {
        if (taskCount == 0) {
            cout <<endl<< "No Tasks Available To Complete."<<endl;
            return;
        }
        viewTasks();
        int num;
        cout <<endl<< "Enter Task Number To Complete: ";
        cin >> num;
        if (num > 0 && num <= taskCount) {
            tasks[num - 1].markCompleted();
            cout <<endl<< "Task Marked As Completed!"<<endl;
        } else {
            cout <<endl<< "Invalid Task Number!<<endl";
        }
    }
    
    void removeTask() {
        if (taskCount == 0) {
            cout <<endl<< "No Tasks Available To Delete."<<endl;
            return;
        }
        viewTasks();
        int num;
        cout <<endl<< "Enter Task Number To Delete: ";
        cin >> num;
        if (num > 0 && num <= taskCount) {
            for (int i = num - 1; i < taskCount - 1; i++) {
                tasks[i] = tasks[i + 1];
            }
            taskCount--;
            cout <<endl<< "Task Deleted Successfully!"<<endl<<"...................."<<endl;
        } else {
            cout <<endl<< "Invalid Task Number!<,endl";
        }
    }
};

int main() {
    ToDoList todo;
    int choice;
    do {
    	cout<<endl<<"...................."<<endl;
        cout << "To-Do List Menu:"<<endl;
        cout << "1. Add Task"<<endl;
        cout << "2. View Tasks"<<endl;
        cout << "3. Mark Task As Completed"<<endl;
        cout << "4. Remove Task"<<endl;
        cout << "5. Exit"<<endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            todo.addTask();
            break;
        case 2:
            todo.viewTasks();
            break;
        case 3:
            todo.completeTask();
            break;
        case 4:
            todo.removeTask();
            break;
        case 5:
            cout <<endl<<"Exiting The ToDoList"<<endl;
            break;
        default:
            cout <<endl<< "Invalid Choice! Try Again."<<endl;
            break;
        }
    } while (choice != 5);
    return 0;
}

