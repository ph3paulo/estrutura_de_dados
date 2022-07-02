#include <iostream>
#include <vector>

using namespace std;
int main() {

  int n;
	cin >> n;
	
  int marker[n];

	int A[n];
	for(int i = 0; i < n; i++){
    cin >> A[i];
    marker[i] = 1;
  }
  

  int m;
	cin >> m;
  
  int B[m];
	for(int i = 0; i < m; i++) cin >> B[i];

  for(int i = 0; i < m; i++){
    for( int z = 0; z < n; z++){
      if(B[i] == A[z]){ 
        A[z] = 0;
        marker[z] = 0;
      }
    }
  }
  
  for(int i =0; i < n; i++){
    if(marker[i] == 1){
      cout << A[i] << " ";
    }
  }
  cout << endl;
}
 