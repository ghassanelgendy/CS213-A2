#include "Machine.h"
#include <bitset>
#include <sstream>

Machine::Machine() 
{
    ///generating registery of 16
    short  count = 0;
    for (auto& i : reg) {
        i.setAddress('0' + toHex(count++));
        i.setValue("00");
    }

    count = 0;
    ///generating memory of 16 * 16
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            string address = toHex(i) + toHex(j); // Concatenate i and j directly
            memory[i][j].setAddress(address);
            memory[i][j].setValue("00");
        }
    }
}

void Machine::excute() 
{
    cout << "\t\t==================================[Excuting]==================================\n";
    for (size_t i = 0; i < instructions.size(); i++)
    {
        cout << "\n=====[Step " << i + 1<<"]===== \n\n";
        string XY{ instructions[i].getOperand().substr(1, 2) }; //XY
        unsigned short R{ toDec(instructions[i].getOperand()[0]) }, //Register num
            X{toDec(XY[0])}, Y{ toDec(XY[1]) }; //X,Y as numbers
            string s,t;
            int S,T;
        ///Displaying current Instruction
        instructionReg.setInstruction(instructions[i]);
        cout << "IR : " << instructionReg.getInstruction() << endl;
        switch (instructions[i].getOpCode()) {
        case('1'):
            reg[R].setValue(memory[X][Y].getValue());
            break;
        case('2'):
            reg[R].setValue(XY);
            break;
        case('3'):
            if (XY == "00") {
                memory[0][0].setValue(reg[R].getValue());
                cout << "\n{{DISPLAY :"<< memory[0][0].getValue() <<"}}\n";
            }
            else
                memory[X][Y].setValue(reg[R].getValue());
            break;
        case('4'):
            reg[Y].setValue(reg[X].getValue());
            break;
        case('5'):
            s = reg[X].getValue();
            t  = reg[Y].getValue();
            S = toDec(s) ,  T = toDec(t);
            s= int_to_binary(S); t = int_to_binary(T);
           reg[R].setValue(binaryToHex(addBinary(s,t)));
            break;
        case('6'):
            cout << "RST - add bits in register S and register T and put it in R\n";
//            int s = toDec(reg[XY[0]].getValue()) ;
            break;
        case('B'):
            cout << "RXY - if bits in R == bits in register 0, jump to memory address XY\n";
            break;
        case('C'):
            return;
        default:
            cout << "Wrong opcode\n";
        }
    }
}

string Machine::toHex(int dec)
{
    string result;
    if (dec < 10) {
        result += static_cast<char>('0' + dec);
    }
    else {
        // If the decimal number is 10 or greater, convert to hexadecimal
        while (dec > 0) {
            int remainder = dec % 16;
            if (remainder < 10) {
                result = static_cast<char>('0' + remainder) + result;
            }
            else {
                result = static_cast<char>('A' + remainder - 10) + result;
            }
            dec /= 16;
        }
    }
    return result;
}

void Machine::print()
{
    cout << "Registery: \n\n";
    for (auto i : reg) {
        cout << i.getAddress() << " : " << i.getValue() << endl;
    }
    cout <<"\nMemory: \n\n";
    for (const auto& i : memory) {
        for (auto j : i)
            cout << j.getAddress() << ':' << j.getValue() << "  ";
        cout << endl;
    }
}

//load instructions from file to memory
void Machine::loadInstructions()
{
    cout << "\t\t=============================[Loading File]=============================\n";
    cout << "Enter Filename: ";
    string f;
    cin >> f;
    f = f + ".txt";
    string g;
    ifstream file(f);
    if (file.fail()) {
        cout << f << " is not found!\n";
        return;
    }
    else
    cout << f << " is opened\n";
    while (getline(file, g)) {
        if (Instruction(g).validateInstruction()) {
            instructions.push_back(Instruction(g));
        }
        else {
            cout << "Instructions failed to load, Please make sure of the format!\n";
            exit(500);
        }
    }
    cout << "---------\n";

    for (size_t i = 0, j = 0 , y=0; i < instructions.size() * 2; i++,y++, j++)
    {
        if (y==16)
            y=0;
        string opCode{ instructions[i / 2].getCode() };
        if (!(j & 1))
            memory[j / 16][y].setValue(opCode.substr(0, 2));
        else
            memory[j / 16][y].setValue(opCode.substr(2, 2));
    }
}

void Machine::clear()
{
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            memory[i][j].clearMemory();
        }
    }
    for (auto& i : reg) {
        i.clearReg();
    }
}

unsigned short Machine::toDec(string& hexString) {
    int result = 0;

    for (char x : hexString) {
        if (isdigit(x)) {
            result = result * 16 + (x - '0');
        }
        else if (isxdigit(x)) {
            if (isupper(x)) {
                result = result * 16 + (x - 'A' + 10);
            }
            else {
                result = result * 16 + (x - 'a' + 10);
            }
        }
    }
    return result;
}

unsigned short Machine::toDec(char& hexChar) {
    int result = hexChar - '0';
    if (result <= 9) {
        return result;
    }
    else
        return result - 7;
} //overriding toDec

long Machine::binary_to_int(string Binary_num){
    long ans{0};
    for (int i = 0; i < (int)Binary_num.size(); ++i) if(Binary_num[i] == '1') ans+=(1 << (Binary_num.size() - i - 1));
    return ans;
}
string Machine::int_to_binary(long long num){
    string binary_num{""};
    while(num>=1){
        if((num&1)) binary_num="1"+binary_num;
        else binary_num="0"+binary_num;
        num/=2;
    }
    while (binary_num.size() < 8) {
        binary_num = "0" + binary_num;
    }
    return binary_num;
}
string Machine::addBinary(string a, string b) {
    bitset<8> bitsetA(a);
    bitset<8> bitsetB(b);
    bitset<8> result = bitsetA.to_ulong() + bitsetB.to_ulong();

    return result.to_string();
}

string Machine::binaryToHex(const string& binaryString) {
    bitset<32> bitset(binaryString);
    unsigned long long decimalValue = bitset.to_ullong();
    ostringstream stream;
    stream << hex << decimalValue;
    return stream.str();
}
