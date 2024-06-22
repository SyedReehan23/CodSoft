#include <iostream>
using namespace std;
int main() {
    double num1,num2;
    char operation;
    double result;
    
    cout<<"Enter the first number : "<<endl;
    cin>>num1;
    
    cout<<"Enter the second number : "<<endl;
    cin>>num2;
    
    cout<<"choose the operation you want (+,-,*,/) : "<<endl;
    cin>>operation;
    
    switch(operation){
        case'+':
        result=num1 + num2;
        cout<<"Result : "<< num1 << "+" << num2 << "=" << result <<endl;
        break;
        
      case'-':
      result=num1-num2;
      cout<<"Result : "<< num1 << "-" << num2 << "=" << result <<endl;
      break;
      
      case'*':
      result=num1*num2;
      cout<<"Result : "<< num1 << "*" << num2 << "=" << result <<endl;
      break;
      
      case'/':
      if(num2 != 0){
      result=num1/num2;
      cout<<"Result : "<< num1 << "/" << num2 << "=" << result <<endl;
      }else{
          cout<< " Cannot divide by 0 "<<endl;
      }
      break;
      
      default:
      cout<<"Invalid operation"<<endl;
      break;
    }
    return 0;
}
