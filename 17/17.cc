#include <bits/stdc++.h>

using namespace std;

class NumberConvert
{
public:
    static std::string toEnglish(std::size_t number);
private:
    NumberConvert() = delete;
    static std::string convertEnglish(std::size_t number);
    static const std::vector<std::string> EnglishWords[3];
};

const std::vector<std::string> NumberConvert::EnglishWords[3] = 
{
    {
        "Zero", 
        "One", 
        "Two", 
        "Three", 
        "Four", 
        "Five", 
        "Six", 
        "Seven", 
        "Eight", 
        "Nine",
        "Ten",
        "Eleven",
        "Twelve", 
        "Thirteen", 
        "Fourteen", 
        "Fifteen", 
        "Sixteen", 
        "Seventeen", 
        "Eighteen", 
        "Nineteen" 
    },
    {
         "", 
         "", 
         "Twenty",
         "Thirty",
         "Forty", 
         "Fifty", 
         "Sixty", 
         "Seventy", 
         "Eighty", 
         "Ninety",
         "Hundred"
    },
    {
        "", 
        " Thousand", 
        " Million", 
        " Billion", 
        " Trillion"
    },
};

std::string NumberConvert::toEnglish(std::size_t number)
{
    if (number == 0) 
    {
        return EnglishWords[0][number];
    }
    std::string words;
    for (int thousands = 0; number; ++thousands, number /= 1000)
    {
        int chunk = number % 1000;
        if (chunk) {
            words = NumberConvert::convertEnglish(chunk) 
                + NumberConvert::EnglishWords[2][thousands] 
                + (words.size() ? " " : "") 
                + words;
        }
    }
    return words;
}

std::string NumberConvert::convertEnglish(std::size_t number)
{
    if (number == 0)
        return "";
    int hundreds = number / 100;
    number %= 100;   // just keep last two digits
    std::string words;

    if (hundreds) {
        words = NumberConvert::EnglishWords[0][hundreds] 
            + " " + NumberConvert::EnglishWords[1][10] 
            + (number ? " " : "");
    }
    if (number == 0) {
        return words;
    }
    if (number < 20) {
        return words + NumberConvert::EnglishWords[0][number];
    }
    int tens = number / 10;
    int units = number % 10;
    if (tens) {
        words += NumberConvert::EnglishWords[1][tens];
    }
    if (units) {
        words += (tens ? " " : "") + NumberConvert::EnglishWords[0][units];
    }
    return words;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    long long n;
    cin >> n;
    cout << NumberConvert::toEnglish(n) << endl;
  }
}