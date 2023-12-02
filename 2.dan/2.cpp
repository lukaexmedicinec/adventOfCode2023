#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(){
    std::string n;
    int counter = 0;
    long sum = 0;
    while(getline(std::cin, n)){
        counter++;
        int j = 0;
        //prijemo do stevilk
        while(n[j] != ':'){
            j++;
        }
        int green = 0;
        int blue = 0;
        int red = 0;
        bool neGre = false;
        for(int i = j; i < n.length(); i++){
            int temp = 0;
            while(isdigit(n[i])){
                temp = temp*10 + (n[i] - '0');
                i++;
            }
            if(n[i+1] == 'b'){
                if(temp > blue)
                    blue = temp;
            }
            else if(n[i+1] == 'r'){
                if(temp > red)
                    red = temp;
            }
            else if(n[i+1] == 'g'){
                if(temp > green)
                    green = temp;
            }
        }
        if(blue == 0)
            blue++;
        if(red == 0)
            red++;
        if(green == 0)
            green++;
        
        sum+= blue*red*green;

    }
    std::cout << sum << std::endl;
}
/*
r12, g13, b14

Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green
*/