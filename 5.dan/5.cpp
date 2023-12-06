#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(){
    std::string s;
    //prvo dobimo seede
    std::vector<std::pair<long, bool>> vecSemen;
    //line by line
    bool jePrva = true;
    while(getline(std::cin, s)){
        long st = 0;
        int position = 0;
        if(jePrva){
            position = 7;
            jePrva = false;
            while(s[position] != '\0'){
                if(s[position] == ' '){
                    vecSemen.push_back({st, false});
                    st = 0;
                    position++;
                    continue;
                }
                st = st*10 + (s[position] - '0');
                position++;
            }
            vecSemen.push_back({st, false});
        }
        long source,dest,range,count;
        count = 0;
        if(isdigit(s[0]) && !jePrva){
            while(s[position] != '\0'){
                if(s[position] == ' '){
                    if(count == 0)
                        dest = st;
                    else if(count == 1)
                        source = st;
                    count++;
                    st = 0;
                    position++;
                    continue;
                }
                st = st*10 + (s[position] - '0');
                position++;
            }
            range = st;

            //pretvorimo
            for(int i = 0; i < vecSemen.size(); i++){
                //preverimo ce je v source range, ga preslikamo če je
                if(vecSemen[i].first >= source && vecSemen[i].first < source+range && !vecSemen[i].second){
                    long temp = dest - source;
                    vecSemen[i].first += temp;
                    vecSemen[i].second = true;
                }
                //std::cout << vecSemen[i].first << std::endl;
            }
            //std::cout << std::endl;
        }
        if(!isdigit(s[0])){
            for(int i = 0; i < vecSemen.size(); i++)
                vecSemen[i].second = false;
        }
    }
    sort(vecSemen.begin(), vecSemen.end());
    std::cout << vecSemen[0].first << std::endl;
}

/*
seeds: 79 14 55 13

seed-to-soil map:
50 98 2
52 50 48

soil-to-fertilizer map:
0 15 37
37 52 2
39 0 15

fertilizer-to-water map:
49 53 8
0 11 42
42 0 7
57 7 4

water-to-light map:
88 18 7
18 25 70

light-to-temperature map:
45 77 23
81 45 19
68 64 13

temperature-to-humidity map:
0 69 1
1 0 69

humidity-to-location map:
60 56 37
56 93 4
*/