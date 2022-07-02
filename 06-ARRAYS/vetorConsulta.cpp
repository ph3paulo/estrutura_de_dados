#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main() {

  int n;
	cin >> n;
	
	string A[n];
	for(int i = 0; i < n; i++) cin >> A[i];

  int m;
	cin >> m;
	
	string B[m];
	for(int i = 0; i < m; i++) cin >> B[i];

  int mark=0;

  for(int i = 0; i < m; i++){
    for( int z = 0; z < n; z++){
      if(B[i] == A[z]) mark++;
    }
    cout << mark;
    if(i < (m - 1)) cout << " ";
    if(i == m -1) cout << endl;
    mark = 0;
    
  }
}