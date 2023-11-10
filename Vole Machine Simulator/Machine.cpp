#include "Machine.h"

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
    for (size_t i = 0; i < instructions.size(); i++)
    {
        instructionReg.setInstruction(instructions[i]);
        cout << "IR : " << instructionReg.getInstruction() << endl;
        char regNum{ instructions[i].getOperand()[0] };
        string XY = instructions[i].getOperand().substr(1,2);
        switch (instructions[i].getOpCode()) {
        case('1'):
            cout << "RXY - load R w/ bits from memory XY\n";
            break;
        case('2'):
            cout << "RXY - load R w/ bits XY\n";
            break;
        case('3'):
            if (XY == "00")
                cout << "- DISPLAY\n";
            else
                cout << "RXY - store bits in R in memory address XY\n";
            break;
        case('4'):
            regNum = instructions[i].getOperand()[1];
            cout << "0RS - move bits in register R to register S\n";
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
            cout << "HALT";
            break;
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
        instructions.push_back(Instruction(g));
    }
    cout << "\n---------\n";
    for (size_t i = 0, j = 0; i < instructions.size() * 2; i++, j++)
    {
        string opCode{ instructions[i / 2].getCode() };
        if (!(j & 1))
            memory[j / 16][i].setValue(opCode.substr(0, 2));
        else
            memory[j / 16][i].setValue(opCode.substr(2, 2));
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
