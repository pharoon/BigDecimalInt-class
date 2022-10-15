#include <iostream>
#include <string>
#include <regex>
using namespace std;

class BigDecimal {
    //Member variables
    std::string num{"0"};
    size_t size{1};
    char sign{'+'};

public :
    //Constructor to_string
    //BigDecimal() = default;

    explicit BigDecimal(int num_param){

        num = std::to_string(num_param);
        if (num[0] == '+' || num[0] == '-') {
            sign = num[0];
            num = num.substr(1);
            size = num.size();
        }
        else{
            sign = '+';
            size = num.size();
        }
    }

    explicit BigDecimal(std::string num_param){
        std::regex filter("(\\+|-)?[0-9]+");
        if (!std::regex_match(num_param,filter)) {
            // throws error if the input is invalid (to make it a real BigDecimal class) 
            throw std::invalid_argument("number");
            
        }
        else{
            if (num_param[0] == '+' || num_param[0] == '-') {
                num = num_param.substr(1);
                sign = num_param[0];
                size = num.size();
            } else {
                num = num_param;
                sign = '+';
                size = num.size();
            }
        }
    }

    //Functions (methods)


    //getter methods
    size_t get_size(){
        return size;
    }
    char get_sign(){
        return sign;
    }
    std::string get_num(){
        return num;
    }


    //Setter methods
    void set_sign(char sign_param){
        sign = sign_param;
    }
    void set_size(int size_param){
        size = size_param;
    }
    void set_num(std::string num_param){
        num = num_param;
    }

    //operators methods
    
   friend ostream &operator<<(ostream &output, BigDecimal &x) {
        output << x.num;
        return output;
    }
    
     bool operator>(BigDecimal &dec2) {
        if (dec2.num[0] == '-' && num[0] == '+') { 
            return true; 
        } else if (num[0] == '-' && dec2.num[0] == '+') {
            return false;
        } else if (num[0] == '+' && dec2.num[0] == '+') {
            if (num.length() < dec2.num.length()) {
                return false;
            }
            for (int i = 0; i < num.length(); i++) {
                if (num[i] > dec2.num[i]) {
                    return true;
                } else {
                    return false;
                }
            }
        } else if (num[0] == '-' && dec2.num[0] == '-') {
            if (num.length() < dec2.num.length()) {
                return true;
            }
            for (int i = 0; i < num.length(); i++) {
                if (num[i] < dec2.num[i]) {
                    return true;
                } else {
                    return false;
                }
            }
        }
    }
     int sgn()
    {
        if(num[0]=='+')
        {
            return 1;
        }
        else if(num[0]=='-')
        {
            return 0;
        }
    }
    int sze()
    {
        return num.length();
    } 
    
    bool operator==(BigDecimal a)
    {
        for (int i = 0; i < num.length(); ++i) {
            if (num == a.num) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }

};

int main() {
    std::cout << "hi ^_^" << std::endl;
    int m {+123};
    std::string mmm{"+123"};
    BigDecimal kkk(mmm);
    std::cout << kkk.get_num() << std::endl;
    std::cout << kkk.get_sign() << std::endl;
    std::cout << kkk.get_size() << std::endl;
    std::cout << "end of main bye ^_^" << std::endl;

    return 0;
}
