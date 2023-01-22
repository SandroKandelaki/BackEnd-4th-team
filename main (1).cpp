#include <iostream>
  
using namespace std; 


int main()  {
string roman;
while(true){
    cin>>roman;
    
if (roman == "I"){
    cout<<1;
}else if(roman == "V"){
    cout<<5;
}else if(roman == "X"){
    cout<<10;
}else if(roman == "L"){
    cout<<50;
    
}else if(roman =="C"){
    cout<<100;
};

if(roman == "EXIT"){
    break;
}
}



return 0;
}