#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(){
    std::string s;
    std::vector<long> time;
    std::vector<long> dist;
    bool jePrva = true;
    while(getline(std::cin, s)){
        int position = 0;
        while(!isdigit(s[position]))
            position++;
        
        long st = 0;
        if(jePrva){
            jePrva = false;
            while(s[position] != '\0'){
                if(s[position] == ' '){
                    time.push_back(st);
                    //std::cout << st << " ";
                    while(!isdigit(s[position]))
                        position++;
                    st = 0;
                    continue;
                }
                st = st*10 + (s[position] - '0');
                position++;
            }
            //std::cout << st << " ";
            time.push_back(st);
            //std::cout << time.size() <<std::endl;
        }
        else{
        while(s[position] != '\0'){
                if(s[position] == ' '){
                    dist.push_back(st);
                    //std::cout << st << " ";
                    while(!isdigit(s[position]))
                        position++;
                    st = 0;
                    continue;
                }
                st = st*10 + (s[position] - '0');
                position++;
        }
        //std::cout << st << " ";
        dist.push_back(st);
        //std::cout << dist.size() << std::endl;
        }
    }
    long rez = 1;
    for(long i = 0; i < time.size(); i++){
        long count = 0;
        for(long j = 1; j < time[i]; j++){
            long speed = j;
            long remainingTime = time[i] - j;
            long distance = speed * remainingTime;
            if(distance > dist[i])
                count++;
        }
        rez *= count;
    }
    std::cout << rez << std::endl;
}