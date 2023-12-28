#ifndef FINITE_STATE_MACHINE_H
#define FINITE_STATE_MACHINE_H
#include <string>
#include <vector>
#include <iostream>

template  <class Type>
class FiniteStateMachine {
    public:
        FiniteStateMachine(int states_, std:: vector <std::vector <Type>> alphabet_, int state_, 
        std:: vector <int> final_state_, std::vector <std::vector <int>>  transition_) {
            states = states_;
            alphabet = alphabet_;
            state = state_;
            final_state = final_state_;
            transition = transition_;
        }

        bool check_str(std::vector<Type> str) {
            int state_now = state;
            std::vector <Type> str_now;
            int ind;
            for (int i = 0; i < str.size(); ++i) {
                str_now.push_back(str[i]);
                ind = alphabet_ind(str_now);
                if (ind >= 0) {
                    str_now.clear();
                    state_now = transition[state_now][ind];
                }
            }
            if (str_now.empty()) {
                for (auto st : final_state) {
                    if (st == state_now) return 1;
                }
            }
            return 0;
        }

    private:
        int states; 
        std:: vector<std::vector <Type>> alphabet; 
        int state; 
        std:: vector <int> final_state; 
        std:: vector <std::vector <int>>  transition;

        bool equivalent_to(std::vector<Type> a, std::vector<Type> b) {
            if (a.size() != b.size()) return 0;
            for (int i = 0; i < a.size(); ++i) {
                if (a[i] != b[i]) return 0;
            }
            return 1;
        }

        int alphabet_ind(std::vector<Type> str) {
            for (int k = 0; k < alphabet.size(); ++k) { 
                if (equivalent_to(str, alphabet[k])) return k;
            }
            return -1;
        }
};

#endif // FINITE_STATE_MACHINE_H
