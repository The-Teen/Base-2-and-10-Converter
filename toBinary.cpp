#include <iostream>

int myPow(int base, int exponent){
    int num{1};
    for (int i{0}; i < exponent; i++){
        num *= base;
    }
    
    //std::cout << num << std::endl;
    
    return num;
}

int myLog(int base, int number){
    int num{0};
    for (int i{base}; i <= number; i *= base){
        if ((static_cast<double>(number) / i) >= 1){
            num += 1;}
    }
    
    //std::cout << num << std::endl;
    
    return num;
}

void toBinary(int decimalNum){
    
    if (decimalNum > 255 || decimalNum < 0){
        std::cerr << "Input must be between 0 and 255";
        return;
    }
    
    bool isOdd {false};
    
    if (decimalNum & 1){
        isOdd = true;
        decimalNum -= 1;
    }
    
    
    for (int i{8}; i > 0; i--){
        if ((i - 1 == myLog(2, decimalNum)) && (myLog(2, decimalNum) > 1)){
            std::cout << 1;
            decimalNum = decimalNum - myPow(2, myLog(2, decimalNum));
        } else if (isOdd && (i == 1)){
            std::cout << 1 << std::endl;
        } else {
            std::cout << 0;
        }
    }
};

int main(){
    std::cout << "Enter an integer from 0-255: ";
    int input;
    std::cin >> input;
    toBinary(input);
    return 0;
};