#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std; 

struct TodoList{
    string description; 
    string dueDate; 
    string status;
};

void addTask(vector<TodoList> &todo);
void removeTask(vector<TodoList> &todo, const string &name);
void viewTasks(vector<TodoList> &todo);
void updateStatus(vector<TodoList> &todo);

int main(){

    vector<TodoList> todo; 
    int choice; 
    string nameToRemove; 

    do {
        cout << "Todo" << endl;
        cout << "1. Add new task" << endl; 
        cout << "2. Remove a task" << endl; 
        cout << "3. View tasks" << endl;
        cout << "4. Update Status" << endl;
        cout << "5. Exit" << endl; 
        cin >> choice;

        switch (choice)
        {
        case 1:
            addTask(todo);
            break;
        case 2: 
            cout << "Enter the name of the task to remove: ";
            cin >> nameToRemove;
            removeTask(todo,nameToRemove);
            break;
        case 3: 
            viewTasks(todo);
            break;
        case 4:
            updateStatus(todo);
            break;
        case 5: 
            cout << "Goodbye!";
        
        default:
            cout << "Invalid choice";
            break;
        }
    }while (choice < 9);

}

void addTask(vector<TodoList> &todo){
    TodoList newTodo; 
    cout << "\n Enter task name: "; 
    cin.ignore();
    getline(cin, newTodo.description);

    cout << "\n Enter due date: ";
    getline(cin, newTodo.dueDate);

    todo.push_back(newTodo);

    cout << "Todo added successfully";
};

void removeTask(vector<TodoList> &todo, const string &name){
    for (auto t = todo.begin(); t < todo.end(); ++t){
        if (t->description == name){
            todo.erase(t);
            cout << "Task" << name << "has been deleted" << endl;
        }
    }
    cout << "Task" << name << "not found" << endl; 
}



void viewTasks(vector<TodoList> &todo){
    for (const TodoList &t : todo){
        cout << "Description: " << t.description << endl;
        cout << "Due date: "<< t.dueDate << endl;
        cout << "Status: "<< t.status << endl;
    }
};

void updateStatus(vector<TodoList> &todo){
    string taskToUpdte; 
    cout << "Enter the name of the task to update: "; 
    cin >> taskToUpdte;

    for (TodoList &t: todo){
        if (t.description == taskToUpdte){
            string statusName;
            cout << "Update the status of the task" << endl; 
            cin >> statusName;

            if (statusName == "Completed"){
                t.status = statusName;
            }else if (statusName == "Uncompleted"){
                t.status = statusName;
            }
        }else{
            cout << "No tasks foudn with this name: " << taskToUpdte << endl;
        }
    }
}

