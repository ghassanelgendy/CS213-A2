#include <wx/wx.h> //elgui
#include <wx/grid.h> //elgrid layout management
#include <fstream> //3shan aftah elfile
#include "Instruction.h" 
#include "Machine.h"
#include <stdlib.h> // 3shan elexit codes
#include <wx/hyperlink.h>
//frame github welcredits
class CreditsFrame : public wxFrame {
public:
    CreditsFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(600, 310)) {
        wxInitAllImageHandlers();

        wxPanel* panel = new wxPanel(this, wxID_ANY);
        panel->SetBackgroundColour(wxColour(235, 216, 201));
        wxStaticText* text1 = new wxStaticText(panel, wxID_ANY, "Ghassan Elgendy", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);

        wxBoxSizer* panelSizer1 = new wxBoxSizer(wxVERTICAL);
        panelSizer1->Add(text1, 0, wxALIGN_CENTER | wxALL, 5);

        wxBitmap sourty = wxBitmap(wxT("./ghassan1.jpeg"), wxBITMAP_TYPE_JPEG);
        wxStaticBitmap* image1 = new wxStaticBitmap(panel, wxID_ANY, sourty, wxDefaultPosition, wxDefaultSize, wxALIGN_TOP);
        image1->Bind(wxEVT_LEFT_DOWN, [this](wxMouseEvent& event) {
            wxString url = "https://github.com/ghassanelgendy/";
            if (!wxLaunchDefaultBrowser(url)) {
                wxMessageBox("Failed to open the browser.", "Error", wxOK | wxICON_ERROR, this);
            }
            event.Skip();
            });

        panelSizer1->Add(image1, 1, wxEXPAND);
        panel->SetSizer(panelSizer1);
        panel->Layout();

        wxPanel* panel2 = new wxPanel(this, wxID_ANY);
        panel2->SetBackgroundColour(wxColour(255, 238, 194));
        wxStaticText* text2 = new wxStaticText(panel2, wxID_ANY, "Rowan Ehab", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);

        wxBoxSizer* panelSizer2 = new wxBoxSizer(wxVERTICAL);
        panelSizer2->Add(text2, 0, wxALIGN_CENTER | wxALL, 5);

        wxBitmap souretRowan = wxBitmap(wxT("./rawan.jpeg"), wxBITMAP_TYPE_JPEG);
        wxStaticBitmap* image2 = new wxStaticBitmap(panel2, wxID_ANY, souretRowan, wxDefaultPosition, wxDefaultSize, wxALIGN_TOP);
        image2->Bind(wxEVT_LEFT_DOWN, [this](wxMouseEvent& event) {
            wxString url = "https://github.com/rowanammar";
            if (!wxLaunchDefaultBrowser(url)) {
                wxMessageBox("Failed to open the browser.", "Error", wxOK | wxICON_ERROR, this);
            }
            event.Skip();
            });

        panelSizer2->Add(image2, 1, wxEXPAND);
        panel2->SetSizer(panelSizer2);
        panel2->Layout();

        wxPanel* panel3 = new wxPanel(this, wxID_ANY);
        panel3->SetBackgroundColour(wxColour(252, 254, 253));
        wxStaticText* text3 = new wxStaticText(panel3, wxID_ANY, "Jana Ramadan", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);

        wxBoxSizer* panelSizer3 = new wxBoxSizer(wxVERTICAL);
        panelSizer3->Add(text3, 0, wxALIGN_CENTER | wxALL, 5);

        wxBitmap souretJana = wxBitmap(wxT("./jana.jpeg"), wxBITMAP_TYPE_JPEG);
        wxStaticBitmap* image3 = new wxStaticBitmap(panel3, wxID_ANY, souretJana, wxDefaultPosition, wxDefaultSize, wxALIGN_TOP);
        image3->Bind(wxEVT_LEFT_DOWN, [this](wxMouseEvent& event) {
            wxString url = "https://github.com/janaramadan/";
            if (!wxLaunchDefaultBrowser(url)) {
                wxMessageBox("Failed to open the browser.", "Error", wxOK | wxICON_ERROR, this);
            }
            event.Skip();
            });

        panelSizer3->Add(image3, 1, wxEXPAND);
        panel3->SetSizer(panelSizer3);
        panel3->Layout();

        wxPanel* taht = new wxPanel(this, wxID_ANY);
        taht->SetBackgroundColour(wxColour(171, 171, 171));
        wxStaticText* text4 = new wxStaticText(taht, wxID_ANY, "This project was proudly made in FCAI - CU, under the supervision of Dr. Mohamed Elramly and \n Eng. Rana Abdelkader as part of Assignment 2 in CS213 class.", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);

        wxBoxSizer* tahtSizer= new wxBoxSizer(wxHORIZONTAL);
        tahtSizer->Add(text4, 0, wxALIGN_CENTER | wxALL, 5);
        taht->SetMaxSize(wxSize(600, 400)); // Set maximum size

        taht->SetSizer(tahtSizer);

        taht->Layout();
        wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);
        mainSizer->Add(panel, 1, wxEXPAND);
        mainSizer->Add(panel2, 1, wxEXPAND);
        mainSizer->Add(panel3, 1, wxEXPAND);
        wxBoxSizer* bigestSizer = new wxBoxSizer(wxVERTICAL);
        bigestSizer->Add(mainSizer);
        bigestSizer->Add(taht);


        SetSizer(bigestSizer);
        CentreOnScreen();
    }
};

class InstructionsFrame : public wxFrame {
public:
    InstructionsFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(1000, 350)) {
        wxPanel* panel = new wxPanel(this, wxID_ANY);
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

        wxGrid* instructionsGrid = new wxGrid(panel, wxID_ANY);
        instructionsGrid->CreateGrid(9, 3); // Create a grid with 9 rows and 3 columns

        instructionsGrid->SetColLabelValue(0, "Op-code");
        instructionsGrid->SetColLabelValue(1, "Operand");
        instructionsGrid->SetColLabelValue(2, "Description");
        instructionsGrid->SetColSize(2, 800);
        instructionsGrid->SetRowLabelSize(0); // Disable row labels
        instructionsGrid->SetColLabelSize(30);
        instructionsGrid->SetDefaultCellAlignment(wxALIGN_CENTER, wxALIGN_CENTER);

        // Set default row size for better readability
        instructionsGrid->SetDefaultRowSize(25);

        // Instructions data without examples
        wxString instructionsData[9][3] = {
            {"1", "RXY", "LOAD the register R with the bit pattern found in the memory cell whose address is XY."},
            {"2", "RXY", "LOAD the register R with the bit pattern XY."},
            {"3", "RXY", "STORE the bit pattern found in register R in the memory cell whose address is XY."},
            {"3", "R00", "STORE to location 00, which is a memory mapping for the screen. Writing to 00 is writing to screen."},
            {"4", "0RS", "MOVE the bit pattern found in register R to register S."},
            {"5", "RST", "ADD the bit patterns in registers S and T as though they were two’s complement representations and leave the result in register R."},
            {"6", "RST", "ADD the bit patterns in registers S and T as though they represented values in floating-point notation and leave the floating-point result in register R."},
            {"B", "RXY", "JUMP to the instruction located in the memory cell at address XY if the bit pattern in R is equal to the bit pattern in R0. Otherwise."},
            {"C", "000", "HALT execution."},
        };

        // Populate grid cells with instructions data
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 3; ++col) {
                instructionsGrid->SetCellValue(row, col, instructionsData[row][col]);
            }
        }
        wxBoxSizer* gridSizer = new wxBoxSizer(wxHORIZONTAL);
        gridSizer->Add(instructionsGrid, 1, wxEXPAND | wxALL, 10);
        sizer->Add(gridSizer, 1, wxEXPAND | wxALL, 0); // Add the grid sizer to the main sizer

        // Adding a panel for the text underneath the grid
        wxPanel* textPanel = new wxPanel(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
        wxStaticText* text = new wxStaticText(textPanel, wxID_ANY, "  Instructions must be in the format: 0x1 0x0 0xFF, each separated by a new line in a txt file \n  0x1 0x0 0xFF means load R0 with memory content in location 255d.");
        wxBoxSizer* textSizer = new wxBoxSizer(wxHORIZONTAL);
        textSizer->Add(text, 1, wxALIGN_CENTER_VERTICAL | wxALIGN_CENTER_HORIZONTAL | wxALL, 2);
        textPanel->SetSizer(textSizer);

        sizer->Add(textPanel, 0, wxEXPAND | wxALL, 2); 
        text->SetFocus();
        panel->SetSizer(sizer);
        CentreOnScreen();
    }
};

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

        //Decoder
        


        // Layout management using sizers
        wxBoxSizer* decoder = new wxBoxSizer(wxVERTICAL);
        wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);
        wxBoxSizer* leftSizer = new wxBoxSizer(wxVERTICAL);
        wxBoxSizer* rightSizer = new wxBoxSizer(wxVERTICAL);
        leftSizer->Add(memoryGrid, 0, wxEXPAND | wxALL, 5);
        rightSizer->Add(irDisplay, 0, wxEXPAND | wxALL, 5);
        rightSizer->Add(registerDisplay, 1, wxEXPAND | wxALL, 5);
        rightSizer->Add(runButton, 0, wxALIGN_CENTER | wxALL, 5);
        rightSizer->Add(stepButton, 0, wxALIGN_CENTER | wxALL, 5);
        rightSizer->Add(loadButton, 0, wxALIGN_CENTER | wxALL, 5);
        rightSizer->Add(stopButton, 0, wxALIGN_CENTER | wxALL, 5);
        rightSizer->Add(quitButton, 0, wxALIGN_CENTER | wxALL, 5);
        mainSizer->Add(decoder, 1, wxEXPAND | wxALL, 5);
        mainSizer->Add(leftSizer, 1, wxEXPAND | wxALL, 5);
        mainSizer->Add(rightSizer, 0, wxEXPAND | wxALL, 5);

        loadButton->SetFocus();
        SetSizerAndFit(mainSizer);
        CentreOnScreen();
    }

    ~MachineSimulatorGUI() {
        delete[] this; //dealloc lelobjects
        Machine::~Machine();
    }
    void quit(wxCommandEvent& event) {
        int answer = wxMessageBox("Are you sure you want to quit? :(", "Quit Confirmation", wxYES_NO | wxICON_QUESTION, this);

        if (answer == wxYES) {
            Close(true);
        }
    }
    void OpenRepo(wxCommandEvent& event) {

        int answer = wxMessageBox("You are going to be redirected to github repository", "Redirect Confirmation", wxYES_NO | wxICON_QUESTION, this);

        if (answer == wxYES) {
            wxString url = "https://github.com/ghassanelgendy/CS213-A2/tree/main"; 
            if (!wxLaunchDefaultBrowser(url)) {
                wxMessageBox("Failed to open the browser.", "Error", wxOK | wxICON_ERROR, this);
            }
        }
       
    }
    void OnCreditsMenu(wxCommandEvent& event) {
        //elicon
        wxIcon icon("./icon.ico", wxBITMAP_TYPE_ICO);
        // Create a new instance of the CreditsFrame class (Credits window) when the menu item is clicked
        CreditsFrame* creditsFrame = new CreditsFrame("Credits");
        creditsFrame->SetIcon(icon);

        creditsFrame->Show(true);
    }
    void OnInstructionsMenu(wxCommandEvent& event) {
        // Create a new instance of the InstructionsFrame class (Instructions window) when the menu item is clicked
        InstructionsFrame* instructionsFrame = new InstructionsFrame("Instructions");
        wxIcon icon("./icon.ico", wxBITMAP_TYPE_ICO);
        instructionsFrame->SetIcon(icon);

        instructionsFrame->Show(true);
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
        MachineSimulatorGUI* simulator = new MachineSimulatorGUI("Machine Simulator", wxDefaultPosition, wxSize(900, 700));
        //elicon
        wxIcon icon("./icon.ico", wxBITMAP_TYPE_ICO);
        simulator->SetIcon(icon);
        // menu bar
        wxMenuBar* menuBar = new wxMenuBar;

        // File menu 
        wxMenu* fileMenu = new wxMenu;
        fileMenu->Append(wxID_OPEN, "&Open...", "Opens a file");
        fileMenu->AppendSeparator();
        fileMenu->Append(wxID_EXIT, "E&xit", "Quits the program");
        menuBar->Append(fileMenu, "&File");
        simulator->Bind(wxEVT_MENU, &MachineSimulatorGUI::OnLoadFile, simulator, wxID_OPEN);
        simulator->Bind(wxEVT_MENU, &MachineSimulatorGUI::quit, simulator, wxID_EXIT);
   
        //  Source menu 
        wxMenu* sourceCode = new wxMenu;
        sourceCode->Append(5050, "&Github Repo", "");
        menuBar->Append(sourceCode, "&Source");

        //  Help menu 
        wxMenu* helpMenu = new wxMenu;
        helpMenu->Append(300, "&Instructions", "");
        helpMenu->Append(400, "&Credits", "");
        menuBar->Append(helpMenu, "&Help");


        simulator->SetMenuBar(menuBar);
        simulator->Bind(wxEVT_MENU, &MachineSimulatorGUI::OnCreditsMenu, simulator, 400);
        simulator->Bind(wxEVT_MENU, &MachineSimulatorGUI::OnInstructionsMenu, simulator, 300);
        simulator->Bind(wxEVT_MENU, &MachineSimulatorGUI::OpenRepo, simulator, 5050);

        simulator->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);