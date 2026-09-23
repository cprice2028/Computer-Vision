
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc , char*argv[])

{
    ifstream fin;
    vector<int> v;
    int val;
    string fname;
    cout<<"Filename: "<<flush;
    cin>>fname;
    fin.open(fname+".txt");
    int min1=0;
    int min2=1;
    while(fin>>val){
        v.push_back(val);
    }
    while (v.size()>1){
        cout<<"[";
        int min1 = 0;
        int min2 = 1;
        if (v[min1] > v[min2]) {
            swap(min1, min2);
        }
        for (int i =2 ;i<v.size();i++){
            if(v.at(min1)>v.at(i)){
                min2=min1;
                min1=i;
            }
            else if(v.at(min2)>v.at(i)){
                min2=i;
            }
        }
        for (int i = 0; i < v.size(); i++) {
            if (i ==0)
                cout<<v[i];
            else
                cout << ", " << v[i];
        }
        cout<<"]"<<endl;
        cout<<endl;
        int total = v.at(min1)+v.at(min2);

        if (min1>min2){
            v.erase(v.begin()+min1);
            v.erase(v.begin()+min2);
        }
        else {
            v.erase(v.begin()+min2);
            v.erase(v.begin()+min1);
        }
        v.push_back(total);
    }
    cout<<"["<<v[0]<<"]"<<endl;

return 0;
}    

/*
SUMMATIVE
• repeat until there is only one (1) element in the vector
o find the two (2) smallest values and calculate their sum
o remove those two values from the vector
o add their sum to the vector as a new value
o thus, the size of the vector has decreased by one
o but, the total sum of all values in the vector is unchanged
• at each step you should display the entire contents, as in the demo
Copy-paste the output of three runs:
<numsA>
<numsB>
<numsC>
END    
*/