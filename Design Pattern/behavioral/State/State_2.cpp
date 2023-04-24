#include <iostream>
using namespace std;

class State {
public:
    virtual void doAction() = 0;
};

class StartState : public State {
public:
    void doAction() {
        cout << "Player is in start state" << endl;
    }
};

class StopState : public State {
public:
    void doAction() {
        cout << "Player is in stop state" << endl;
    }
};

class Context {
private:
    State* state;

public:
    Context() {
        state = nullptr;
    }

    void setState(State* newState) {
        state = newState;
    }

    State* getState() {
        return state;
    }
};

int main() {
    Context context;

    StartState startState;
    StopState stopState;

    context.setState(&startState);
    context.getState()->doAction();

    context.setState(&stopState);
    context.getState()->doAction();

    return 0;
}
