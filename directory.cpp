#include <iostream>
#include <map>
#include <string>

using namespace std;

int countLongest(string directory){
    
    map<int, string> dir;
    
    string max;
    int current = 0;
    
    //bool ext = false;
    
    bool space = true;
    int spaceCount = 0;
    
    int subStart = 0;
    int subCount = 0;

    for(int i = 0; i < directory.length(); i++){    
        if(space == true){
            if(directory.at(i) == ' ')
                spaceCount++;
            else{
                space = false;
                subStart = i;
                subCount = 1;
            }
        }
        else if(directory.at(i) == '\n'){
            
            current = spaceCount;
            if(spaceCount != 0){
                dir[spaceCount] = dir[spaceCount-1] + "\\" + directory.substr(subStart, subCount);
                cout << spaceCount << " at " << dir[spaceCount] << endl;
            }
            else{
                dir[spaceCount] = "\\" + directory.substr(subStart, subCount);
                cout << spaceCount << " at " << dir[spaceCount] << endl;
            }
            spaceCount = 0;
            space = true;
        }
        else if(directory.at(i) == '.'){
            if((i+5) < directory.length()){
                if(directory.at(i+1) == 'g' && directory.at(i+2) == 'i' && directory.at(i+3) == 'f'){
                    if(directory.at(i+4) == '\n' || directory.at(i+4) == '\0'){
                        string compare = dir[spaceCount-1] + '\\' + directory.substr(subStart, subCount + 4);
                        if(max.length() < compare.length()){
                            max = compare;
                        }
                        while(directory.at(i) != '\n' && directory.at(i) != '\0')
                            i++;
                        space = true;
                        spaceCount = 0;
                    }
                    else{
                        space = true;
                        spaceCount = 0;
                        while(directory.at(i) != '\n' && directory.at(i) != '\0')
                            i++;
                    }
                }
                else if(directory.at(i+1) == 'p' && directory.at(i+2) == 'n' && directory.at(i+3) == 'g'){
                    if(directory.at(i+4) == '\n' || directory.at(i+4) == '\0'){
                        string compare = dir[spaceCount-1] + '\\' + directory.substr(subStart, subCount + 4);
                        if(max.length() < compare.length()){
                            max = compare;
                        }
                        while(directory.at(i) != '\n' && directory.at(i) != '\0')
                            i++;
                        space = true;
                        spaceCount = 0;
                    }
                    else{
                        space = true;
                        spaceCount = 0;
                        while(directory.at(i) != '\n' && directory.at(i) != '\0')
                            i++;
                    }
                }
                else if(directory.at(i+1) == 'j' && directory.at(i+2) == 'p' && directory.at(i+3) == 'e' && directory.at(i+4) == 'g'){
                    if(directory.at(i+5) == '\n' || directory.at(i+5) == '\0'){
                        string compare = dir[spaceCount-1] + '\\' + directory.substr(subStart, subCount + 5);
                        if(max.length() < compare.length()){
                            max = compare;
                        }
                        while(directory.at(i) != '\n' && directory.at(i) != '\0')
                            i++;
                        space = true;
                        spaceCount = 0;
                    }
                    else{
                        space = true;
                        spaceCount = 0;
                        while(directory.at(i) != '\n' && directory.at(i) != '\0')
                            i++;
                    }
                }
                else{
                    space = true;
                    spaceCount = 0;
                    while(directory.at(i) != '\n' && directory.at(i) != '\0')
                        i++;
                }
            }
            else if((i+4) < directory.length()){
                if(directory.at(i+1) == 'g' && directory.at(i+2) == 'i' && directory.at(i+3) == 'f'){
                    if(directory.at(i+4) == '\n' || directory.at(i+4) == '\0'){
                        string compare = dir[spaceCount-1] + '\\' + directory.substr(subStart, subCount + 4);
                        if(max.length() < compare.length()){
                            max = compare;
                        }
                        while(directory.at(i) != '\n' && directory.at(i) != '\0')
                            i++;
                        space = true;
                        space = 0;
                    }
                    else{
                        space = true;
                        spaceCount = 0;
                        while(directory.at(i) != '\n' && directory.at(i) != '\0')
                            i++;
                    }
                }
                else if(directory.at(i+1) == 'p' && directory.at(i+2) == 'n' && directory.at(i+3) == 'g'){
                    if(directory.at(i+4) == '\n' || directory.at(i+4) == '\0'){
                        string compare = dir[spaceCount-1] + '\\' + directory.substr(subStart, subCount + 4);
                        if(max.length() < compare.length()){
                            max = compare;
                        }
                        while(directory.at(i) != '\n' && directory.at(i) != '\0')
                            i++;
                        space = true;
                        spaceCount = 0;
                    }
                    else{
                        space = true;
                        spaceCount = 0;
                        while(directory.at(i) != '\n' && directory.at(i) != '\0')
                            i++;
                    }
                }
                else{
                    space = true;
                    spaceCount = 0;
                    while(directory.at(i) != '\n' && directory.at(i) != '\0')
                        i++;
                }
            }
            else{
                i = directory.length();
            }
        }
        else{
            subCount++;
        }
    }
    
    cout << "behold: " << max << endl;
    
    return max.length();
}

int main(void){
 
    string directory("dir1\n dir2\n  txt.gif\n  dir3\n   x.txt\n  dir4\n   dir5\n    abc.jpeg\n    dir6\n     abcdefg.jpeg\n    dir7\n     cba.png\n   dir8\n dir9\n  hello.zip\ndir10\n a.out");
    
    cout << directory << endl;
    
    cout << countLongest(directory) << endl;    
    return 0;
}