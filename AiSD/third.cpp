
#include <iostream>
using namespace std;

int main(){
    int n;
    int m;
    cin >> n;
    cin >> m;

    int arr [n+2][m+2];
    int res = 0;


    for(int i=0;i<n+2;i++){
        for(int j=0;j<m+2;j++){
            if(i==0 || i == n+1 || j==0 || j == m+1){
                arr[i][j] = 0;
            }
            else{
                arr[i][j] = 1;
            }
        }
    }

    for(int i=0;i<n+2;i++){
        for(int j=0;j<m+2;j++){
            cout << arr[i][j];
        }
        cout << "\n";
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if (arr[i-1][j]==1 && arr[i][j+1]==1){ // и направо и наверх
                res = res + 2;
            }
            else if(arr[i-1][j]==1 && arr[i][j+1]==0){ // можно наверх
                res++;
            }
            else if(arr[i-1][j]==0 && arr[i][j+1]==1){ //можно направо

                res++;
            }
        }
    }

    cout << res;

}