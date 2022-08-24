#include "Text_Preprocessor.h"
#include <string>
#include <vector>

using namespace std;
Text_Preprocessor::Text_Preprocessor(const string &fileName) : file_name(fileName) {}

Text_Preprocessor::~Text_Preprocessor() {
    obj.close();
}

void Text_Preprocessor::preprocess_text() {
    obj.open(file_name);

    string text;
    vector<string>all_data;
    while(obj){
        getline(obj, text);
        all_data.push_back(text);
    }
    vector<string>processed_data;
    for(auto const &to : all_data){
        string final_str;
        for(int i = 0; i < (int)to.size(); i++){
            if((to[i] == ',' ||  to[i] == '.' || to[i] == ';' ||  to[i] == ':') && to[i+1] == ' '){
                i++;
                continue;
            }
            if((to[i] == '?' ||  to[i] == '!' || to[i] == '"') && to[i+1] == ' '){
                i++;
                continue;
            }
            if(to[i] == '"' && to[i-1] == ' '){
                i++;
                continue;
            }
            if(to[i] == 'a' && to[i-1] == ' ' && to[i+1] == ' '){
                i++;
                continue;
            }
            if(to.substr(i, 2) == "an" && to[i+2] == ' ' && to[i-1] == ' '){
                i += 2;
                continue;
            }
            if(to.substr(i, 3) == "the" && to[i+3] == ' ' && to[i-1] == ' ') {
                i+=3;
                continue;
            }
            if(to.substr(i, 2) == "in" && to[i+2] == ' ' && to[i-1] == ' ') {
                i += 2;
                continue;
            }
            if(to.substr(i, 2) == "on" && to[i+2] == ' ' && to[i-1] == ' ') {
                i += 2;
                continue;
            }
            if(to.substr(i, 2) == "at" && to[i+2] == ' ' && to[i-1] == ' ') {
                i += 2;
                continue;
            }
            if(to.substr(i, 5) == "since" && to[i+5] == ' ' && to[i-1] == ' ') {
                i += 5;
                continue;
            }
            if(to.substr(i, 3) == "ago" && to[i+3] == ' ' && to[i-1] == ' ') {
                i += 3;
                continue;
            }
            if(to.substr(i, 6) == "before" && to[i+6] == ' ' && to[i-1] == ' ') {
                i += 6;
                continue;
            }
            if(to.substr(i, 2) == "to" && to[i+2] == ' ' && to[i-1] == ' ') {
                i += 2;
                continue;
            }
            if(to.substr(i, 2) == "by" && to[i+2] == ' ' && to[i-1] == ' ') {
                i += 2;
                continue;
            }
            final_str += tolower(to[i]);
        }
        cout << final_str << "\n";
        processed_data.push_back(final_str);
    }
    processedData = processed_data;
    obj.close();
}

string Text_Preprocessor::search_word(const std::string &word) {
    obj.open(file_name);

    string text;
    vector<string>all_data;
    while(obj){
        getline(obj, text);
        all_data.push_back(text);
    }
    vector<string>processed_data;
    for(auto const &to : all_data) {
        string final_str;
        for (int i = 0; i < (int) to.size(); i++) {
            if(to.substr(i, word.size()) == word && to[i + word.size()] == ' ' && to[i - word.size()] == ' ') {
                cout << to.substr(i, word.size()) << endl;
                return "I Found";
            }final_str += tolower(to[i]);
        }
        processed_data.push_back(final_str);
    }

    obj.close();
    return "Word is not found";
}

