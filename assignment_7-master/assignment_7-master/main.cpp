#include "Text_Preprocessor.h"
#include <thread>
#include <fstream>
#include <mutex>
using namespace std;

int main() {
    Text_Preprocessor *text = new Text_Preprocessor("../Task_1.txt");

    text->preprocess_text();
    string word;
    cin>>word;
    cout << text->search_word(word);




    /*
     * ******************************************************************************************************
     * ******************************************************************************************************
     * ******************************************************************************************************
     */

    fstream obj;
    obj.open("../Task_2.txt");
    string str;
    float sum = 0;
    int amount = 0;
    vector<float>nums;

    while(getline(obj, str)) {
        amount++;
        float cur = stof(str);
        nums.push_back(cur);
        sum += cur;
    }

    float average = sum / (amount * 1.0);

    mutex mu;
    auto toFile = [&mu](const vector<float>&numbers, float avg) {
        mu.lock();
        ofstream str1("../Thread_1.txt");
        ofstream str2("../Thread_2.txt");
        for(auto to : numbers){
            if(to > avg){
                str1 << to_string(to)<<"\n";
            }
            if(to < avg){
                str2 << to_string(to)<<"\n";
            }
        }
        str1.close();
        str2.close();
        mu.unlock();
    };

    auto th_test = [](const vector<float>&numbers, float avg) {
        ofstream str3("../example.txt");
        for(auto to : numbers){
            if(to < avg){
                str3 << to_string(to)<<"\n";
            }
        }
        str3.close();
    };

    thread th(toFile, nums, average);
    thread th2(th_test, nums, average);

    th.join();
    th2.join();

    delete text;
}
