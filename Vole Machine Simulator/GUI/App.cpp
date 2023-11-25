#include <wx/wx.h> //elgui
#include <wx/grid.h> //elgrid layout management
#include <fstream> //3shan aftah elfile
#include "Instruction.h" 
#include "Machine.h"
#include <stdlib.h> // 3shan elexit codes
class MachineSimulatorGUI : public Machine, public wxFrame {
protected:
    Machine* Vole;
    wxGrid* memoryGrid = new wxGrid(this, wxID_ANY); 
    wxListBox* registerDisplay = new wxListBox(this, wxID_ANY);
    wxTextCtrl* irDisplay = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
public:
    MachineSimulatorGUI(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(nullptr, wxID_ANY, title, pos, size) {
        Vole = new Machine;
        // memory display
        memoryGrid->CreateGrid(16, 16); // grid for memory cells
        memoryGrid->EnableEditing(false); // Disable editing for memory cells

        // Set content for memory cells
        for (int i = 0; i < 16; ++i) {
            for (int j = 0; j < 16; ++j) {
                wxString cellValue = wxString::Format("%02X", 00);
                memoryGrid->SetCellValue(i, j, cellValue);
            }
        }
        //  register display
        for (int i = 0; i < 16; ++i) {
            registerDisplay->Append("R" + wxString::Format("%X", i) + ": 00"); // Sample content
        }
        memoryGrid->SetDefaultCellAlignment(wxALIGN_CENTER, wxALIGN_CENTER);

        //  control buttons 
        wxButton* runButton = new wxButton(this, wxID_ANY, "Run");
        wxButton* stopButton = new wxButton(this, wxID_ANY, "Fetch");
        wxButton* stepButton = new wxButton(this, wxID_ANY, "Step");
        wxButton* quitButton = new wxButton(this, wxID_ANY, "Quit");
      
        //  load file button and bind an event
        wxButton* loadButton = new wxButton(this, wxID_ANY, "Load File");
        loadButton->Bind(wxEVT_BUTTON, &MachineSimulatorGUI::OnLoadFile, this);
        runButton->Bind(wxEVT_BUTTON, &MachineSimulatorGUI::OnRunButtonClick, this);
        stepButton->Bind(wxEVT_BUTTON, &MachineSimulatorGUI::OnStepClick, this);
        stopButton->Bind(wxEVT_BUTTON, &MachineSimulatorGUI::fetch, this);
        quitButton->Bind(wxEVT_BUTTON, &MachineSimulatorGUI::quit, this);
        // rows
        memoryGrid->SetRowLabelSize(wxGRID_AUTOSIZE);
        memoryGrid->SetColLabelSize(wxGRID_AUTOSIZE);
        for (int i = 0; i < 16; ++i) {
            memoryGrid->SetRowLabelValue(i, wxString::Format("%X", i));
        }
        // cols
        for (int i = 0; i < 16; ++i) {
            memoryGrid->SetColLabelValue(i, wxString::Format("%X", i));
        }
        // Layout management using sizers
        wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);
        wxBoxSizer* leftSizer = new wxBoxSizer(wxVERTICAL);
        wxBoxSizer* rightSizer = new wxBoxSizer(wxVERTICAL);
        leftSizer->Add(memoryGrid, 1, wxEXPAND | wxALL, 10);
        rightSizer->Add(irDisplay, 0, wxEXPAND | wxALL, 5);
        rightSizer->Add(registerDisplay, 1, wxEXPAND | wxALL, 5);
        rightSizer->Add(runButton, 0, wxALIGN_CENTER | wxALL, 5);
        rightSizer->Add(stepButton, 0, wxALIGN_CENTER | wxALL, 5);
        rightSizer->Add(loadButton, 0, wxALIGN_CENTER | wxALL, 5);
        rightSizer->Add(stopButton, 0, wxALIGN_CENTER | wxALL, 5);
        rightSizer->Add(quitButton, 0, wxALIGN_CENTER | wxALL, 5);
        mainSizer->Add(leftSizer, 1, wxEXPAND | wxALL, 10);
        mainSizer->Add(rightSizer, 0, wxEXPAND | wxALL, 10);
        SetSizerAndFit(mainSizer);
    }
    ~MachineSimulatorGUI() {
        delete[] this; //dealloc lelobjects
        Machine::~Machine();
    }
    void quit(wxCommandEvent& event) {
        exit(0);
    }
    void OnRunButtonClick(wxCommandEvent& event) {
        Vole->excute(); // Execute instructions from console version
         updateGUI();
    }
    void fetch(wxCommandEvent& event) {
        wxMessageBox("Files fetched successfully", "Fetch Done", wxOK | wxICON_INFORMATION);
    }
    void updateGUI() {  
        registerDisplay->Clear();
        // Update GUI elements new state
        for (int i = 0; i < 16; ++i) {
            wxString regValue = Vole->reg[i].getValue();
            registerDisplay->Append("R" + wxString::Format("%X", i) + ": " + regValue); 
        }
    }
    void OnStepClick(wxCommandEvent& event) {
        wxString irValue;
        if (Vole->instructions[Vole->step].getCode() != "C000") {
            Vole->excuteOne(Vole->instructions[Vole->step], Vole->step);
            irValue = Vole->instructionReg.getCode();
            irDisplay->SetValue(irValue);
        }
        else {
            irValue = "HALT";
            irDisplay->SetValue(irValue);
        }
        updateGUI();
    }
    void OnLoadFile(wxCommandEvent& event) {
        wxString filePath = wxFileSelector("Choose a file to open"); 
        if (!filePath.empty()) {
            memoryGrid->ClearGrid();
            string filename = filePath.ToStdString();
            ifstream file(filename);
            if (!file.is_open()) {
                wxMessageBox("File not found!", "Error", wxOK | wxICON_ERROR);
                return;
            }
            string line;
            while (std::getline(file, line)) {
                unsigned short x{ 0 };
                if (Instruction(line, Machine::toHex(x)).validateInstruction()) {
                    x++;
                    Vole->instructions.push_back(Instruction(line, Machine::toHex(x)));
                }
                else {
                    wxMessageBox("Instructions failed to load. Please check the format.", "Error", wxOK | wxICON_ERROR); //lw feh instruction ghlat
                    return;
                }
            }
            // Clear existing memory content
            memoryGrid->ClearGrid();
            // generate memory with loaded instructions
            for (size_t i = 0, j = 0, y = 0; i < Vole->instructions.size() * 2; i++, y++, j++) {
                if (y == 16) y = 0;
                string opCode{ Vole->instructions[i / 2].getCode() };
                if (!(j & 1))
                    memoryGrid->SetCellValue(j / 16, y, wxString(opCode.substr(0, 2)));
                else
                    memoryGrid->SetCellValue(j / 16, y, wxString(opCode.substr(2, 2)));
            }
            for (int i = Vole->instructions.size() * 2; i < 256; ++i) {
                int row = i / 16;
                int col = i % 16;
                memoryGrid->SetCellValue(row, col, "00"); //bamla elfady be zeros
            }
            file.close();
        }
    }
};
class MyApp : public wxApp {
public:
    virtual bool OnInit() {
        MachineSimulatorGUI* simulator = new MachineSimulatorGUI("Machine Simulator", wxDefaultPosition, wxSize(800, 700));
        simulator->Show(true);
        return true;
    }
};
wxIMPLEMENT_APP(MyApp);