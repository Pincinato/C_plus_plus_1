#include <iostream>
 #include <vector>
 int main()
 {
 using namespace std;

 vector<int> vect;
 for (int i=0; i < 6; i++)
 {
 vect.push_back(i);
 }
 int i=0;
 vector<int>::const_iterator it; // read􀀀only i t e r a t o r
 it = vect.begin(); // assign i t to the s t a r t of the vec tor
 while (it != vect.end()) // whi le not at end
 {
 cout << *it << " "; // p r i n t value i t point s to
 ++it; // and i t e r a t e to the next element
 ++i;
 }
 --it;
 --i;
 cout <<vect[i]<< endl; // Output : 0 1 2 3 4 5
}
