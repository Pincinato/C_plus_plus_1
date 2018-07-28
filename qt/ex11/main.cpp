#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <fstream>
using namespace std;

void countString(unordered_multimap<string,int> &myMap,ifstream &in);
void countChar(unordered_multimap<char,int> &myMap,ifstream &in);
void printElements(unordered_multimap<string,int> &myMap);
void printElements(unordered_multimap<char,int> &myMap);

int main()
{
    cout<<endl<<" A solution that has a key and a mapped value was choose. The key is the element to be counted ";
    cout<<"and the mapped value is the frequency of the key."<<endl;
    cout<<"An unordered multimap container to gain in performance. However, to print the result an auxiliar multimap container was used"<<endl;
    unordered_multimap<string,int> myMap;
    unordered_multimap<char,int> myCharMap;
    ifstream in("C:/Users/THP/Desktop/qt/ex11/test.txt");
    cout<<endl<<"text.txt";
    if(!in)
    {
        cout<<endl<<"Open test.txt failed"<<endl;
        return 1;
    }
    cout<<endl<<"----Word----"<<endl;
    countString(myMap,in);
    in.clear();
    in.seekg(0,ios::beg);
    cout<<"----Letters----"<<endl;
    countChar(myCharMap,in);
    ifstream in2("C:/Users/THP/Desktop/qt/ex11/hamlet.txt");
    cout<<endl<<"hamlet.txt"<<endl;
    if(!in2)
    {
        cout<<endl<<"Open hamlet.txt failed";
        return 1;
    }
    cout<<endl<<"----Word----"<<endl;
    countString(myMap,in2);
    in2.clear();
    in2.seekg(0,ios::beg);
    cout<<"----Letters----"<<endl;
    countChar(myCharMap,in2);
    return 0;
}

void printElements(unordered_multimap<string,int> &myMap){

    multimap<int,string> myMapOrdered;
    auto itera=myMap.begin();
    while(itera!=myMap.end()){
        myMapOrdered.insert(make_pair(itera->second,itera->first));
        itera++;
    }
    multimap<int,string>::reverse_iterator it=  myMapOrdered.rbegin();
    int max=0;
    if(myMapOrdered.size()<5) max=myMapOrdered.size();
    else max=5;
    for (int i=0;i<max;i++){
        cout<< it->first <<" "<<it->second << endl;
        ++it;
    }
    return;
}

void printElements(unordered_multimap<char,int> &myMap){

    multimap<int,char> myMapOrdered;
    auto itera=myMap.begin();
    while(itera!=myMap.end()){
        myMapOrdered.insert(make_pair(itera->second,itera->first));
        itera++;
    }
    multimap<int,char>::reverse_iterator it= myMapOrdered.rbegin();
    int max=0;
    if(myMapOrdered.size()<5) max=myMapOrdered.size();
    else max=5;
    for (int i=0;i<max;i++){
        cout<< it->first <<" "<<it->second << endl;
        ++it;
    }
    return;
}

void countString(unordered_multimap<string,int> &myMap,ifstream &in){
    myMap.clear();
    while(in)
    {
     string Input;
     in >> Input;
     if(Input[0]<92) {Input[0]+=32;}
     auto search= myMap.find(Input);
     if(search!=myMap.end()){
        search->second++;
        //cout<<" if "<<search->first<<"   "<<search->second<<endl;
    }
     else{
         if(Input!=""){
            myMap.insert(make_pair(Input,1));
         }
        //cout<<" else  "<<endl;
     }
    }
    printElements(myMap);
    return ;
}

void countChar(unordered_multimap<char,int> &myMap,ifstream &in){
    myMap.clear();
    while(in)
    {
     char Input;
     in >> Input;
     if(Input<92) {Input+=32;}
     auto search= myMap.find(Input);
     if(search!=myMap.end()){
        search->second++;
        //cout<<" if "<<search->first<<"   "<<search->second<<endl;
    }
     else{
         if( (Input!=' ')){
            myMap.insert(make_pair(Input,1));
         }
     }
    }
    printElements(myMap);
    return ;
}

