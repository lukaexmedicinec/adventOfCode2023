#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


long preveriKvadrat(std::vector<std::vector<char>>&, int, int);
long vrniInt (std::vector<std::vector<char>>&, int, int);
int main(){
    char c;
    std::vector<std::vector<char>> res;
    std::vector<char> tempRow;
    int counVrstic = 0;
    bool jePrvi = true;
    while((c = getchar()) != EOF){
        if(c == '\n'){
            tempRow.push_back('.');
            tempRow.insert(tempRow.begin(), '.');
            if(jePrvi){
                std::vector<char> temp(tempRow.size(), '.');
                res.push_back(temp);
            }
            res.push_back(tempRow);
            counVrstic++;
            tempRow.clear();
            jePrvi = false;
            continue;
        }
        else
            tempRow.push_back(c);
    }
    tempRow.push_back('.');
    tempRow.insert(tempRow.begin(), '.');
    res.push_back(tempRow);
    std::vector<char> temp(tempRow.size(), '.');
    res.push_back(temp);
    long sum = 0;
    for(int i = 1; i < res.size(); i++){
        for(int j = 1; j < res[i].size();j++){
            if(res[i][j] != '.' && !isdigit(res[i][j])){
                //preverimo kvadrat okol
                sum += preveriKvadrat(res, i, j);
                //sum += preveriKvadrat(res, i, j);
            }
        }
    }


    // for(int i = 0; i < res.size(); i++){
    //     for(int j = 0; j < res[i].size(); j++){
    //         std::cout << res[i][j];
    //     }
    //     std::cout << std::endl;
    // }
    std::cout << sum << std::endl;
}
long preveriKvadrat(std::vector<std::vector<char>>& res, int a, int b){
    long sum = 0;
    for(int i = a-1; i <= a+1; i++){
        for(int j = b -1; j <= b+1; j++){
            if(isdigit(res[i][j]))
                sum += vrniInt(res, i, j);
                
        }
    }
    return sum;
}
long vrniInt (std::vector<std::vector<char>>& res, int a, int b){
    while(isdigit(res[a][b])){
        b--;
    }
    b++;
    char stevilo[10] = "";
    int counter = 0;
    while(isdigit(res[a][b])){
        stevilo[counter] = res[a][b];
        res[a][b] = '.';
        counter++;
        b++;
    }

    return std::stoi(stevilo);
}
/*
467..114..
...*......
..35..633.
......#...
617*......
.....+.58.
..592.....
......755.
...$.*....
.664.598..
*/