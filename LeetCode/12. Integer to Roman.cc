class Solution {
public:
    string intToRoman(int num) {
        struct data_t { int value; char const* numeral; };
        static data_t const data[] = { 1000, "M", 900, "CM", 500, "D", 400, "CD",
        100, "C", 90, "XC", 50, "L", 40, "XL",
        10, "X", 9, "IX", 5, "V", 4, "IV",
        1, "I", 0, NULL };

        string result = "";
        for(data_t const* curr = data; curr->value > 0; ++curr)
            while(num >= curr->value)
            {
                result += curr->numeral;
                num -= curr->value;
            }
        return result;
    }
};