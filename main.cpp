#include <iostream>
#include <string>
#include <regex>
void sizeBalance(std::string &str1, std::string &str2){
    std::string zero{"0"};
    while (str1.size() < str2.size()){
        str1 = zero + str1;
    }
    while (str1.size() > str2.size()){
        str2 = zero + str2;
    }
}

std::string adding_strNums(std::string &str1, std::string &str2){
    size_t sz{str1.size()-1};
    std::string res;
    int carry{0};
    for (int i = 0; i <= sz; ++i){

        if ((((int)str1[sz - i] - 48) + ((int)str2[sz - i] - 48) + carry) > 9){
            res = std::to_string(carry + ( (int) str1[sz - i] - 48) + ((int) str2[sz - i] - 48) - 10) + res ;
            carry = 1;
        }
        else {
            res = std::to_string(carry + ( (int) str1[sz - i] - 48) + ((int) str2[sz - i] - 48)) + res ;
            carry = 0;
        }
    }
    if (carry == 1){
        res = "1" + res;
    }
    return res;
}


class BigDecimal {
    //Member variables
    std::string num{"0"};
    size_t size{1};
    char sign{'+'};

public :
    //Constructor to_string
    BigDecimal() = default;

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
            throw std::invalid_argument("number");
            // or throw std::out_of_range("month");
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
    BigDecimal operator + (BigDecimal num2) {
        BigDecimal res{"0"};

        if (this->sign == '+' && num2.sign == '+'){
            res.sign = '+';
            sizeBalance(this->num, num2.num);
            res.num = adding_strNums(this->num, num2.num);
            std::cout << res.num << std::endl;
        }
        else if (this->sign == '-' && num2.sign == '-') {
            res.sign = '-';
            sizeBalance(this->num, num2.num);
            res.num = adding_strNums(this->num, num2.num);
            std::cout << res.num << std::endl;

        }
        else{
            std::cout << "mlna4 da3wa 4o8l kariem :)" << std::endl;
            std::cout << res.num << std::endl;

        }
        return res;
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
    
       friend ostream &operator<<(ostream &output, BigDecimal &x) {
        output << x.num;
        return output;
    }
    BigDecimal& operator= (const BigDecimal& y)
    {
        num = y.num;
        
    }
       char sgn()
    {
        if(num[0]=='+')
        {
            return '+';
        }
        else if(num[0]=='-')
        {
            return '-';
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
    std::string mmm{"123"},mm{"589999"};
    BigDecimal kkk(mmm);
    std::cout << kkk.get_num() << std::endl;
    std::cout << kkk.get_sign() << std::endl;
    std::cout << kkk.get_size() << std::endl;
 
    BigDecimal num1("123456789012345678901234567890");
    BigDecimal num2("+113456789011345678901134567890");
    BigDecimal num3("-200000000000000000000000000000");
    std::cout << num1.get_num() << std::endl;
    std::cout << num2.get_num() << std::endl;
    std::cout << num3.get_num() << std::endl;
    BigDecimal num4 = num2 + num1;
    std::cout << num4.get_num() << std::endl;
    std::cout << "the end bye ^_^" << std::endl;
    /*std::cout << "num1 = " << num1 << std::endl;
    std::cout << "num2 = " << num2 << estd::ndl;
//Next statement will print 236913578023691357802369135780
    std::cout << "num2 + num1 = " << num4 << std::endl;
//Next statement will print -313456789011345678901134567890
    std::cout << "num2 - num1 = " << std::num5 << std::endl;
*/

}
