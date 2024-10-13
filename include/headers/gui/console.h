#pragma once

#ifndef CONSOLE_H
#define CONSOLE_H

#include "gui_window.h"
#include <vector>

class Console : public GUI_Window {
private:
std::string ProcessCommand(const std::string& command) {
    
    // In-Game Console
    // Enter custom commands here   

    //help
    if (command == "help") {
        return "Hello, World!";

    //exit
    } else if (command == "exit") {
        m_shouldClose = true;
        return "Exiting terminal...";
    }

    //no command was found
    return "Unknown command: " + command; 
}

char inputText[256] = ""; // Buffer for input
std::vector<std::string> commandHistory; // History of commands and outputs

public:
    Console(SDL_Scancode toggleKey=SDL_SCANCODE_GRAVE, SDL_Window* window=nullptr, SDL_Renderer* renderer=nullptr)
    : GUI_Window(toggleKey, window,renderer) {
        commandHistory.push_back("For available commands type: help");

    };

    void Draw() override{
        if(m_shouldClose == false){
        
        GUI_CreateWindow("Console");

        // Display command output
        ImGui::BeginChild("ScrollingRegion", ImVec2(0, -40), true); // Leave room for input
        for (const auto& output : commandHistory) {
            ImGui::Text("%s", output.c_str());
        }
        ImGui::EndChild();

        // Input for new commands
        ImGui::InputText("Type Command", inputText, sizeof(inputText));

        if (ImGui::Button("Enter")) {
            // Handle command submission
            std::string command(inputText);
            commandHistory.push_back(command); // Store command in history

            // Process command and get output (this is where you'd add your command logic)
            std::string output = ProcessCommand(command);
            commandHistory.push_back(output); // Store output in history

            // Clear input text
            inputText[0] = '\0'; 
        }

        GUI_End();
        }
    }
};

#endif // CONSOLE_H