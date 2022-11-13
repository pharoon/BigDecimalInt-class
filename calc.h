#include <string>
using namespace std;
class BigDecimal{
    std::string num{"0"};
    size_t size{1};
    char sign{'+'};

    public:
    explicit BigDecimal(int num_param);
    explicit BigDecimal(std::string num_param);

    //functions
    void sizeBalance(string &str1, string &str2);
    string adding_strNums(string &str1, string &str2);
    string subtract_strNums(string str1, string str2);
    bool Is_1stNum_Greater(string str1, string str2);

    //getters
     char sign_();
     int size_();

    // operators methods
    BigDecimal operator+(BigDecimal num2);
    BigDecimal operator-(BigDecimal &num2);
    bool operator<(const BigDecimal &dec2);
    bool operator>(BigDecimal &dec2);
    bool operator==(BigDecimal a);
    friend ostream &operator<<(std::ostream &output, BigDecimal &x);

};
