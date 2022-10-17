#include <iostream>
#include <string>
#include <regex>
using namespace std;

class BigDecimal
{
    // Member variables
    string num{"0"};
    size_t size{1};
    char sign{'+'};

public:
    // Constructor to_string
    BigDecimal() = default;

    explicit BigDecimal(int num_param)
    {

        num = to_string(num_param);
        if (num[0] == '+' || num[0] == '-')
        {
            sign = num[0];
            num = num.substr(1);
            size = num.size();
        }
        else
        {
            sign = '+';
            size = num.size();
        }
    }

    explicit BigDecimal(string num_param)
    {
        regex filter("(\\+|-)?[0-9]+");
        if (!regex_match(num_param, filter))
        {
            throw invalid_argument("number");
            // or throw std::out_of_range("month");
        }
        else
        {
            if (num_param[0] == '+' || num_param[0] == '-')
            {
                sign = num_param[0];
                num = num_param.substr(1);
                size = num.size();
            }
            else
            {
                num = num_param;
                sign = '+';
                size = num.size();
            }
        }
    }

    // getter methods

    get_size()
    {
        return size;
    }
    char get_sign()
    {
        return sign;
    }
    string get_num()
    {
        while (num[0] == '0' && num.length() > 1)
        {
            num = num.substr(1);
        }
        return num;
    }

    // Setter methods
    void set_sign(char sign_param)
    {
        sign = sign_param;
    }
    void set_size(int size_param)
    {
        size = size_param;
    }
    void set_num(string num_param)
    {
        num = num_param;
    }

    // Functions (methods)
    void sizeBalance(string &str1, string &str2)
    {
        string zero{"0"};
        while (str1.size() < str2.size())
        {
            str1 = zero + str1;
        }
        while (str1.size() > str2.size())
        {
            str2 = zero + str2;
        }
    }

    string adding_strNums(string &str1, string &str2)
    {
        size_t sz{str1.size() - 1};
        string res;
        int carry{0};
        for (int i = 0; i <= sz; ++i)
        {

            if ((((int)str1[sz - i] - 48) + ((int)str2[sz - i] - 48) + carry) > 9)
            {
                res = to_string(carry + ((int)str1[sz - i] - 48) + ((int)str2[sz - i] - 48) - 10) + res;
                carry = 1;
            }
            else
            {
                res = to_string(carry + ((int)str1[sz - i] - 48) + ((int)str2[sz - i] - 48)) + res;
                carry = 0;
            }
        }
        if (carry == 1)
        {
            res = "1" + res;
        }
        return res;
    }

    string subtract_strNums(string str1, string str2)
    {
        int number1, number2;
        string first_num, second_num, result = "";
        char s = '+';
        for (int i = 0; i < size; i++)
        {
            if ((str1[i] - '0') > (str2[i] - '0'))
            {
                first_num = str1;
                second_num = str2;
                break;
            }
            else if ((str1[i] - '0') < (str2[i] - '0'))
            {
                first_num = str2;
                second_num = str1;
                s = '-';
                break;
            }
        }

        for (int i = size - 1; i > -1; --i)
        {
            number1 = first_num[i] - '0';
            number2 = second_num[i] - '0';
            if (number1 < number2)
            {
                int j = i - 1;
                if (first_num[j] == '0')
                {
                    while (first_num[j] == '0' && j != 0)
                    {
                        --j;
                    }
                    for (int k = j + 1; k < i; ++k)
                    {
                        first_num[k] = '9';
                    }
                }
                first_num[j] = char(((first_num[j] - '0') - 1) + 48);
                number1 += 10;
            }
            result += to_string(number1 - number2);
        }
        if (s == '-')
        {

            result += "-";
            reverse(result.begin(), result.end());
        }
        else
        {
            result += "+";
            reverse(result.begin(), result.end());
        }

        return result;
    }

    bool Is_1stNum_Greater(string str1, string str2)
    {
        for (int i = 0; i < str1.length(); i++)
        {
            if ((str1[i] - '0') > (str2[i] - '0'))
            {
                return 1;
            }
            else if ((str1[i] - '0') < (str2[i] - '0'))
            {
                return 0;
            }
        }
    }
    // operators methods
    BigDecimal operator+(BigDecimal &num2)
    {
        sizeBalance(this->num, num2.num);

        BigDecimal res{"0"};

        if (this->sign == '+' && num2.sign == '+')
        {
            res.sign = '+';
            sizeBalance(this->num, num2.num);
            res.num = adding_strNums(this->num, num2.num);
            cout << res.num << endl;
        }
        else if (this->sign == '-' && num2.sign == '-')
        {
            res.sign = '-';
            sizeBalance(this->num, num2.num);
            res.num = adding_strNums(this->num, num2.num);
            cout << res.num << endl;
        }
        else
        {
            bool x = Is_1stNum_Greater(num, num2.num);
            if (x)
            {
                res.sign = '-';
                res.num = subtract_strNums(num, num2.num);
                res.num = res.num.substr(1);
                res.size = res.num.length();
            }
            else if (!x)
            {
                res.sign = '+';
                res.num = subtract_strNums(num2.num, num);
                res.num = res.num.substr(1);
                res.size = res.num.length();
            }
            else
            {
                res.sign = '+';
                res.num = "0";
                res.size = 1;
            }
        }
        return res;
    }
    BigDecimal operator-(BigDecimal &num2)
    {
        BigDecimal res;
        sizeBalance(num, num2.num);

        if (sign == '+' && num2.sign == '+')
        {

            res.num = subtract_strNums(num, num2.num);
            res.sign = res.num[0];
            res.num = res.num.substr(1);
            res.size = res.num.length();
        }
        else if (sign == '+' && num2.sign == '-')
        {

            res.num = adding_strNums(this->num, num2.num);
            res.sign = '+';
            res.size = res.num.length();
        }
        else if (sign == '-' && num2.sign == '+')
        {
            res.num = adding_strNums(this->num, num2.num);
            res.sign = '-';
            res.size = res.num.length();
        }
        else if (sign == '-' && num2.sign == '-')
        {
            bool x = Is_1stNum_Greater(num, num2.num);

            if (x)
            {
                res.sign = '-';
                res.num = subtract_strNums(num, num2.num);
                res.num = res.num.substr(1);
                res.size = res.num.length();
            }
            else if (!x)
            {
                res.sign = '+';
                res.num = subtract_strNums(num2.num, num);
                res.num = res.num.substr(1);
                res.size = res.num.length();
            }
            else
            {
                res.sign = '+';
                res.num = "0";
                res.size = 1;
            }
        }
        return res;
    }
};

int main()
{

    BigDecimal num1("-23690");
    BigDecimal num2("00690");
    BigDecimal num4(num2 + num1);

    cout << num4.get_sign() << num4.get_num();
    return 0;
}

/*std::cout << "num1 = " << num1 << std::endl;
std::cout << "num2 = " << num2 << estd::ndl;
//Next statement will print 236913578023691357802369135780
std::cout << "num2 + num1 = " << num4 << std::endl;
//Next statement will print -313456789011345678901134567890
std::cout << "num2 - num1 = " << std::num5 << std::endl;
*/