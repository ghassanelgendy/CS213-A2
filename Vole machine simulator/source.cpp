#include "register.h"
#include "memory.h"
#include "register.cpp"
#include "Memory.cpp"

string toHex(int dec){
    string answer;
    if ( dec < 10){
        answer = to_string(dec);
    }
    else{
        char deff ='A';
        deff += dec - 10;
        answer = deff;
    }
    return answer;

}

int main(){
   Register register1("00","33");

//   register1.setValue("55");
//   cout<< register1.getAddress() << " : " << register1.getValue()<<endl;

   Memory memory1("01","A3");
   memory1.setValue("B4");
//   cout<< memory1.getAddress() << " : " << memory1.getValue()<<endl;


   vector <Register> registry(16);
   short  count = 0;

   for(auto &i : registry){
       i.setAddress('0'+toHex(count++));
       i.setValue("00");
   }
   for(auto i : registry){
      cout << i.getAddress() << ':' << i.getValue()<<endl;
   }
count =0;

    vector<vector<Memory>> memory(16, vector<Memory>(16));

    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            string address = toHex(i) + toHex(j); // Concatenate i and j directly
            memory[i][j].setAddress(address);
            memory[i][j].setValue("00");
        }
    }

    for (const auto &i : memory) {
        for ( auto j : i)
            cout << j.getAddress() << ':' << j.getValue() << "  ";
        cout<<endl;
    }

}