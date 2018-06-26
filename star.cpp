#include <iostream>

using namespace std;

int main(){
    int numOfLines, ct;
    cout<<"Enter the number of lines";
    cin>>numOfLines;

    for(int i=numOfLines-1;i>=0;i--){
        ct = numOfLines - i;
        for(int k = i; k>=0; k--) cout<<" ";        
        while(ct!=0){
            cout<<"* ";
            ct--;
        }
        cout<<"\n";
    }
}

/*
G:\Code snippets\c++>star
Enter the number of lines5
     *
    * *
   * * *
  * * * *
 * * * * *

G:\Code snippets\c++>star
Enter the number of lines11
           *
          * *
         * * *
        * * * *
       * * * * *
      * * * * * *
     * * * * * * *
    * * * * * * * *
   * * * * * * * * *
  * * * * * * * * * *
 * * * * * * * * * * *

*/
