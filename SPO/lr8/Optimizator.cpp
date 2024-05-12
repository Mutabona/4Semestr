#include "Optimizator.h"

vector<vector<string>> Optimizator::Optimize(vector<vector<string>> _objectCode) {
    objectCode = _objectCode;
    for (auto triad : objectCode) {
        if (triad[0] == ":=") {
            if(ProcessAssignment(triad)) {
                ReplaceVariable(triad[1]);
                signOfUse.erase(triad[1]);
            }
        }
        else {
            ProcessOperation(triad);
        }
    }
    return objectCode;
}

void Optimizator::ReplaceVariable(string replaceable) {
    cout<<"Replacing "<< replaceable <<endl;
    string replacing = GetReplacingVariable(replaceable);
    int flag = 0;
    auto toErase = objectCode.begin();
    for (auto triad = objectCode.begin(); triad != objectCode.end(); triad++) {
        if (flag == 0) {
            if ((*triad)[1] == replaceable) {
                toErase = triad;
                flag++;
            }
        } 
        else if (flag == 1) {
            if ((*triad)[1] == replaceable) {
                (*triad)[1] = replacing;
                flag++;
            }
            else if ((*triad)[2] == replaceable) {
                (*triad)[2] = replacing;
                flag++;
                cout<<" Replaced by " << replacing << endl;
            }
        }
        if (flag != 0) {
            if ((*triad)[1][0] == 'T') {
                string str = "";
                for (int i = 0; i < (*triad)[1].size()-1; i++) {
                    str += (*triad)[1][i];
                }
                str += char(int((*triad)[1][(*triad)[1].size()-1]) - 1);
                (*triad)[1] = str;
            } else if ((*triad)[2][0] == 'T') {
                string str = "";
                for (int i = 0; i < (*triad)[2].size()-1; i++) {
                    str += (*triad)[2][i];
                }
                str += char(int((*triad)[2][(*triad)[2].size()-1]) - 1);
                (*triad)[2] = str;
            }
        }
    }
    cout << "Erasing: " << setiosflags(ios::left) << setw(2) << (*toErase)[0] << " " << setw(2) << (*toErase)[1] << " " << setw(2) << (*toErase)[2] << " " << endl;
    objectCode.erase(toErase);
}

void Optimizator::ProcessOperation(vector<string> triad) {
    IncreaseSignOfUse(triad[1]);
    IncreaseSignOfUse(triad[2]);
}

bool Optimizator::ProcessAssignment(vector<string> triad) {
    if (signOfUse.find(triad[1]) != signOfUse.end()) {
        if (signOfUse[triad[1]] == 1) {
            IncreaseSignOfUse(triad[2]);
            return true;
        }
    }
    signOfUse[triad[1]] = 0;
    IncreaseSignOfUse(triad[2]);
    return false;
}

string Optimizator::GetReplacingVariable(string var) {
    cout<<"Finding replacing value"<<endl;
    string replacing;
    auto triad = objectCode.begin();
    for ( ; (*(triad))[1] != var; triad++) {}
    replacing = (*triad)[2];
    cout<<"Founded: "<<replacing<<endl;
    return replacing;
}

void Optimizator::IncreaseSignOfUse(string var) {
    if (signOfUse.find(var) != signOfUse.end()) {
        if (signOfUse[var] != -1) {
            signOfUse[var]++;
        }
    }
    else {
        signOfUse[var] = -1;
    }
}