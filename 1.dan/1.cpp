#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const int velikostAbecede = 26;
using namespace std;

class Node {
    public:
    Node* children[velikostAbecede];
    pair<int, int> pomembnostVrstniRed;//pomembnost in indekst vrstnegaReda
    bool koncnaBeseda;
    string beseda;

    //konstruktor
    Node (){
        koncnaBeseda = false;
        for(int i = 0; i < velikostAbecede; i++){
            children[i] = nullptr;
        }
        pomembnostVrstniRed = {-1, -1};
    }
};
class autoCompleteTrie {
    private:
    Node* root;
    public:
    autoCompleteTrie(){
        root = new Node();
    }

    void insert(string beseda, int pomembnost, int indeks){
        Node* current = root;
        for(int i = 0; i < beseda.length(); i++){
            int crka = beseda[i] - 'a';
            if(current->children[crka] == nullptr){
                current->children[crka] = new Node();
            }
            //current->children[crka]->beseda = current->children[crka]->beseda.append(current->beseda);
            if(current->children[crka]->pomembnostVrstniRed.first > pomembnost){

            }

            else
                current->children[crka]->pomembnostVrstniRed = {pomembnost, indeks};
            current = current->children[crka];
        }
        current->koncnaBeseda = true;
    }

    int search(string beseda){
        Node* current = root;
        for(int i = 0; i < beseda.length(); i++){
            int crka = beseda[i] - 'a';
            if(current->children[crka] == nullptr){
                return 0;
            }
            current = current->children[crka];
        }
        return current->pomembnostVrstniRed.second;
    }
    int modifiedSearch(string n, int indeks){
        Node* current = root;
        for(int i = indeks; i < n.length(); i++){
            if(current->koncnaBeseda || isdigit(n[i]))
                break;
            int crka = n[i] - 'a';
            if(current->children[crka] == nullptr)
                return -1;
            current = current->children[crka];
        }
        if(current->koncnaBeseda)
            return current->pomembnostVrstniRed.first;
        else
            return -1;
    }

};
int main(){
   std::string n;
   int sum = 0;
   autoCompleteTrie trie;
   trie.insert("one", 1,1);
   trie.insert("two", 2,2);
   trie.insert("three", 3,3);
   trie.insert("four", 4,4);
   trie.insert("five", 5,5);
   trie.insert("six", 6,6);
   trie.insert("seven", 7,7);
   trie.insert("eight", 8,8);
   trie.insert("nine", 9,9);

   while(std::cin >> n){
    int prvi = 0;
    int drugi = 0;
    bool samEnaStevilka = true;
    int temp = 0;
        for(int i = 0; i < n.length(); i++){
            if(!isdigit(n[i])){
                temp = trie.modifiedSearch(n, i);
                if(temp > 0 && prvi == 0){
                    prvi = temp;
                }
                else if(temp > 0){
                    drugi = temp;
                    samEnaStevilka = false;
                }
            }
            if(isdigit(n[i]) && prvi == 0){
                prvi = n[i] - '0';
            }
            else if(isdigit(n[i])){
                drugi = n[i] - '0';
                samEnaStevilka = false;
            }
                
        }
        if(samEnaStevilka)
            drugi = prvi;
        sum += (prvi*10 + drugi);
        //std::cout << (prvi*10 + drugi) << std::endl;
   }
   std::cout << sum << std::endl;
}