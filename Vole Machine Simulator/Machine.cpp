#include "Machine.h"
//toDec(XY[1] variable
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
    cout << "Excuting\n---------\n";
    for (size_t i = 0; i < instructions.size(); i++)
    {
        instructionReg.setInstruction(instructions[i]);
        cout << "IR : " << instructionReg.getInstruction() << endl;
        char regNum{ instructions[i].getOperand()[0] };
        string XY = instructions[i].getOperand().substr(1,2);
        switch (instructions[i].getOpCode()) {
        case('1'):
            reg[ toDec(regNum)].setValue(memory[toDec(XY[0])][toDec(XY[1])].getValue());
            break;
        case('2'):
            reg[ toDec(regNum)].setValue(XY);
            break;
        case('3'):
            if (XY == "00") {
                memory[0][0].setValue(reg[toDec(regNum)].getValue());
                cout << "- DISPLAY\n";
                cout<< memory[0][0].getValue()<<endl;
            }
            else
                memory[toDec(XY[0])][toDec(XY[1])].setValue(reg[toDec(regNum)].getValue());
            break;
        case('4'):
            reg[toDec(XY[1])].setValue(reg[toDec(XY[0])].getValue());
            break;
        case('5'):
            cout << "RST - add bits in register S and register T and put it in R ( two’s complement representations )\n";
            break;
        case('6'):
            cout << "RST - add bits in register S and register T and put it in R\n";
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
        string answer;
        if (dec < 10) {
            answer = to_string(dec);
        }
        else {
            char deff = 'A';
            deff += dec - 10;
            answer = deff;
        }
        return answer;
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
void Machine::loadInstructions(string filename)
{
    string f = filename + ".txt";
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
int Machine::toDec(char x) {
    int result = x-'0';
    if (result<=9){
        return result;
    }
    else
        return result-7;

}
