#include <iostream>
#include <string>
#include <stack>
// sample from chatGPT
// In this implementation, the Editor class is the receiver and is responsible for performing the copy, paste, and undo
//https://refactoring.guru/design-patterns/command/cpp/example
class Editor {
public:
    Editor() : text_() {}
    
    void copy(int start, int end) {
        copied_text_ = text_.substr(start, end - start);
        std::cout << "Copied text: " << copied_text_ << std::endl;
    }
    
    void paste(int position) {
        text_.insert(position, copied_text_);
        std::cout << "Pasted text: " << copied_text_ << std::endl;
    }
    
    void undo() {
        if (!history_.empty()) {
            text_ = history_.top();
            history_.pop();
            std::cout << "Undo: " << text_ << std::endl;
        }
    }
    
    void setText(const std::string& text) {
        text_ = text;
    }
    
    std::string getText() const {
        return text_;
    }
    
private:
    std::string text_;
    std::string copied_text_;
    std::stack<std::string> history_;
};

class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class CopyCommand : public Command {
public:
    CopyCommand(Editor& editor, int start, int end)
        : editor_(editor), start_(start), end_(end) {}
    
    void execute() override {
        editor_.copy(start_, end_);
    }
    
    void undo() override {}
    
private:
    Editor& editor_;
    int start_;
    int end_;
};

class PasteCommand : public Command {
public:
    PasteCommand(Editor& editor, int position)
        : editor_(editor), position_(position) {}
    
    void execute() override {
        editor_.paste(position_);
    }
    
    void undo() override {
        editor_.setText(editor_.getText().erase(position_, copied_text_.length()));
    }
    
private:
    Editor& editor_;
    int position_;
    std::string copied_text_;
};

class UndoCommand : public Command {
public:
    UndoCommand(Editor& editor) : editor_(editor) {}
    
    void execute() override {
        editor_.undo();
    }
    
    void undo() override {}
    
private:
    Editor& editor_;
};

class Invoker {
public:
    void setCommand(Command* command) {
        command_ = command;
    }
    
    void executeCommand() {
        command_->execute();
        history_.push(command_);
    }
    
    void undo() {
        if (!history_.empty()) {
            Command* command = history_.top();
            command->undo();
            history_.pop();
        }
    }
    
private:
    Command* command_;
    std::stack<Command*> history_;
};

int main() {
    Editor editor;
    editor.setText("The quick brown fox jumps over the lazy dog.");
    
    Invoker invoker;
    
    // Copy "quick brown fox"
    Command* copy_cmd = new CopyCommand(editor, 4, 17);
    invoker.setCommand(copy_cmd);
    invoker.executeCommand();
    
    // Paste at position 20
    Command* paste_cmd = new PasteCommand(editor, 20);
    invoker.setCommand(paste_cmd);
    invoker.executeCommand();
    
    // Undo the paste command
    invoker.undo();
    
    // Undo the copy command
    invoker.undo();
    
    delete copy_cmd;
    delete paste_cmd;
    
    return 0;
}
