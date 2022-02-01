// trying out reget in c++ wiht regex library
#include<iostream>
#include<regex>
#include<string>

int main(int argc,char * argv[]){
    // this is regex constructor which takes regex as constructor argument, we can't assign any values to it directly
    std::regex expression("[0-9]+");
    // this smatch object will stores the matched string values
    std::smatch match;
    // created String which contains array elements where regex should pick only the numberic values
    std::string arrInString = {"23,54,6,7,54,3,7,8,"};
    // regex_search (original_string,matcher_object,regex); thisfunction takes in arguments and matches the values
    std::vector<int> match_values;
    while (regex_search(arrInString,match,expression)){
        for (std::string s : match){
            match_values.push_back(stoi(s)); 
        }
        arrInString = match.suffix().str();
    }
    std::cout << "str value : " << arrInString << std::endl;
    
    for (int i = 0; i < match_values.size(); i+=1){
        std::cout << match_values.at(i) << std::endl;
    }
}
