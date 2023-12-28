#include "finite-state machine.h"
using namespace std;

int main() {
    int states = 4; 
    vector <vector <char>> alphabetint = {{'a'}, {'b'}}; 
    int state = 2; 
    vector <int> final_state = {0, 1}; 
    vector <vector <int>>  transitions = {{3, 1}, {0, 3}, {0, 1}, {3, 3}};
    vector<char> list1 = {'b', 'b', 'a'};
    vector<char> list2 = {'a', 'b', 'a', 'a', 'b'};
    vector<char> list3 = {'b', 'a', 'b', 'a'};
    
    FiniteStateMachine<char> FiniteStateMachineChar(states, alphabetint, state, final_state, transitions);
    cout << FiniteStateMachineChar.check_str(list1) << endl;
    cout << FiniteStateMachineChar.check_str(list2) << endl;
    cout << FiniteStateMachineChar.check_str(list3) << endl;
}
