#include <iostream>
#include <bitset>

// use std::bitset::test() to check the digit in the numbers position and then multiple it by
// 2 raised to that position

// decimal to binary cnverter and vice versa

int myPow(int base, int exponent){
    int num{1};
    for (int i{0}; i < exponent; i++){
        num *= base;
    }
    
    //std::cout << num << std::endl;
    
    return num;
}

int toDecimal(std::bitset<8> binaryNum){
    int decimalNum {0};
    int start{0};
    
    for (int i{7 /*1 less than size of "binaryNum" bitset*/}; i > 0; i--){
        if (binaryNum.test(i)){
            start = i;
            break;
        }
    }
    
    for (int i {0}; i <= start; i++){
        decimalNum += (binaryNum.test(i) * myPow(2, i));
    }
    
    return decimalNum;
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

std::bitset<8> toBinary(int decimalNum){
    std::bitset<8> binaryNum;
    
    if (decimalNum & 1){
        binaryNum.set(0);
        decimalNum -= 1;
    }
    
    int dif;
    do {
        dif = decimalNum - myPow(2, myLog(2, decimalNum));
        binaryNum.set(myLog(2, decimalNum));
        decimalNum = dif;
        
    } while (dif > 0);

    return binaryNum;
}

void clear_screen(){
    system("clear");
}

int main(){
    std::cout << "Options: \n\t1.) Convert binary to decimal\n\t2.) Convert decimal to binary\n\nWhat would you like to do? ";
    int choice;
    std::cin >> choice;
    clear_screen();

    if (choice == 1){
        std::cout << "Enter a binary number: ";
        std::bitset<8> inputBinaryNum;
        std::cin >> inputBinaryNum;
	std::cout << toDecimal(inputBinaryNum) << std::endl;
    } else if (choice == 2) {
        std::cout << "Enter a decimal number: ";
        int inputDecimalNum;
        std::cin >> inputDecimalNum;
	    std::bitset<8> binNum {toBinary(inputDecimalNum)};
	
	    int start;
        for (int i{binNum.size() - 1}; ; i--){
            if (binNum.test(i)){
                start = i;
                break;
            }
        }

        for (int i{start};i >= 0; i--){
            std::cout << binNum.test(i);
        }

        std::cout << std::endl;

    } else {
        std::cout << "Invalid option." << std::endl;
    }
    
    return 0;
}
