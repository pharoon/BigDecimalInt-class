#include <iostream>
#include <string>

class BigDecimal {
    //Member variables
    std::string num{0};
    size_t size{1};
    char sign{'+'};
public :
    //Constructor
    BigDecimal() = default;
    BigDecimal(std::string num_param){
        num = num_param;
        sign = num_param[0];
        size = num_param.size();

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


};

int main() {
    std::cout << "hi ^_^" << std::endl;
    return 0;
}
