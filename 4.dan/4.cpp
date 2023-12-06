#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define velikost 191
int main(){
    int a;
    int sum = 0;
    int zaporednaSt = 1;
    std::string s;
    std::vector<int> kolko(velikost, 1);
    while(getline(std::cin, s)){
            std::vector<bool> res(100, false);
        //for(int i = 0; i < kolko[zaporednaSt]; i++){
            // std::cout << zaporednaSt << " ";
            s.append(" ");
            s.append("\n");
            int j = 0;
            while(s[j] != ':'){
                j++;
            }
            j+=2; // s tem smo na prvi stevki
            int st = 0;
            while(s[j] != '|'){
                if(s[j] == ' ')
                    s[j] = '0';
                st += (s[j++] - '0');
                st += st*10 + (s[j] - '0');
                j+=2;
                res[st] = true;
                st = 0;
            }
            j+=2;
            int checker = 0;
            while(s[j] != '\n'){
                if(s[j] == ' ')
                    s[j] = '0';
                st += (s[j++] - '0');
                st += st*10 + (s[j]- '0');
                j+=2;
                if(res[st])
                    checker++;
                st = 0;
            }
            //std::cout<<zaporednaSt << "ima" << checker << std::endl;
            for(int k = zaporednaSt+1; k <= zaporednaSt + checker && k <= velikost; k++){
                    // std::cout << "stevilki" << k << "+1" << std::endl;
                    kolko[k] += kolko[zaporednaSt];
                    //std::cout << "srecki st " << k << "pristejem " << kolko[zaporednaSt] << "zdaj ima" <<  kolko[k]<< std::endl;
                }
                
            res.clear();
            // std::cout << "sum do zdaj je " << sum << std::endl;
        //}
        zaporednaSt++;
    }
    for(int i = 1; i < velikost; i++){
        //std::cout << " srecka " << i << "ima" << kolko[i ]<< std::endl;
        sum += kolko[i];
    }
    std::cout << sum << std::endl;
}

/*
Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53
Card 2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19
Card 3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1
Card 4: 41 92 73 84 69 | 59 84 76 51 58  5 54 83
Card 5: 87 83 26 28 32 | 88 30 70 12 93 22 82 36
Card 6: 31 18 13 56 72 | 74 77 10 23 35 67 36 11
*/