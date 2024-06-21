#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // seeding the random number generator
    
    int randomnumber = rand()% 100 + 1; //this will generate a random number between 1 to 100
    
    int userGuess =0;
    
    cout<<"Hello there!! Welcome to the Number Guessing Game!"<<endl;
    cout<<"_________________________________________________ "<<endl;
    cout<<"Lets see how good your guess can be"<<endl;
    cout<<"I will generate a random number between 1-100 for you."<<endl;
    cout<<"Lets see if you can guess the right number."<<endl;
    
    while(true){
        cout<<"Enter your guess : "<<endl;
        cin>>userGuess;
        
        if(userGuess < randomnumber){
            cout<<"Too low ! try again."<<endl;
        }else if(userGuess > randomnumber){
            cout<<"Too high! try again."<<endl;
        }else{
            cout<<"Congratulations!!! your guess was spot on : "<<randomnumber<<endl;
            break;
        }
    }
    return 0;
}