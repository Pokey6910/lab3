#include "finite-state machine.h"
using namespace std;

int main() {
    int states = 2; 
    vector <vector <int>> alphabetint = {{1, 2, 3}, {1, 1}, {2, 2}}; 
    int state = 1; 
    int final_state = 0; 
    vector <vector <int>>  transitions = {{0, 0, 1}, {1, 0, 0}};
    vector<int> list = {1, 2, 3, 2, 2, 1, 1};
    FiniteStateMachine<int> FiniteStateMachineInt(states, alphabetint, state, final_state, transitions);
    cout << FiniteStateMachineInt.check_str(list) << endl;


    vector <vector <char>> alphabetchar = {{'h', 'e', 'l', 'l', 'o'}, {'a', 'a'}, {'b', 'b'}}; 
    transitions = {{0, 0, 1}, {1, 0, 0}};
    vector <char> listchar = {'h', 'e', 'l', 'l', 'o', 'a', 'a', 'b', 'b'};
    FiniteStateMachine<char> FiniteStateMachineChar(states, alphabetchar, state, final_state, transitions);
    cout << FiniteStateMachineChar.check_str(listchar) << endl;

}