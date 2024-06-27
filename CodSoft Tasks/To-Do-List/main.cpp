#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task{
    string description;
    bool iscompleted;
};

void displayMenu(){
    
    cout<<"1. Add Tasks"<<endl;
    cout<<"2. View Tasks"<<endl;
    cout<<"3. Mark Task as completed"<<endl;
    cout<<"4. Remove Task"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"What do want to do ?"<<endl;
}
void addTask(vector<Task>& tasks){
    cout<<"Enter the task description: "<<endl;
    cin.ignore();
    string description;
    getline(cin, description);
    tasks.push_back({description,false});
    cout<<" New task added "<<endl;
}
void viewTasks(const vector<Task>& tasks){
    if(tasks.empty()){
        cout<<"No tasks to show"<<endl;
        return;
    }
    cout<<"Tasks : "<<endl;
    for(size_t i=0;i< tasks.size(); ++i){
        cout<<i+1<<". "<<tasks[i].description<<" (" << (tasks[i].iscompleted ? "Completed" : "Pending")<<")"<<endl;
    }
}
void markTaskAscompleted(vector<Task>& tasks){
    if(tasks.empty()){
        cout<<"No tasks to mark"<<endl;
        return;
    }
    size_t taskNumber;
    cout<<"Enter the task number you want to mark as completed"<<endl;
    cin>>taskNumber;
    if(taskNumber >= 1 && taskNumber <= tasks.size()){
        tasks[taskNumber - 1].iscompleted = true;
        cout<< "Task marked as completed"<<endl;
    }else{
        cout<<" invalid task number "<<endl;
    }
    
}
void removeTask(vector<Task>& tasks){
    if(tasks.empty()){
        cout<<"No tasks available to remove"<<endl;
        return;
    }
    size_t taskNumber;
    cout<<"Enter the task number you want to remove " <<endl;
    cin>>taskNumber;
    if(taskNumber >=1 && taskNumber <= tasks.size()){
        tasks.erase(tasks.begin() + taskNumber -1);
        cout<<"Task removed"<<endl;
    }else{
        cout<<"Invalid task number"<<endl;
    }
    
}
int main(){
    vector<Task> tasks;
    int choice;
    while(true){
        displayMenu();
        cin>>choice;
        switch(choice){
            case 1:
            addTask(tasks);
            break;
            case 2:
            viewTasks(tasks);
            break;
            case 3:
            markTaskAscompleted(tasks);
            break;
            case 4:
            removeTask(tasks);
            break;
            case 5:
            cout<<"Exit"<<endl;
            return 0;
            default:
            cout<<"Invalid choice ! please try again."<<endl;
            
        }
    }
    return 0;
}