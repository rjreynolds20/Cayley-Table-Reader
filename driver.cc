#include <iostream>
#include "cayley.h"
using namespace std;

int main(){
  const int MAX = 36;
  const int ERROR = -1;
  const int GOOD = -2;
  char table[MAX][MAX];
  int table_size;
  char outlier = ' ';
  bool ans;
  char x;
  char y;
  char z;
  char out;
  char identity;
  cin >> table_size;
  read_table(table, table_size);
  if(is_closed(table,table_size,outlier)){
    is_associative(table, table_size, x, y, z, ans);
    if(ans == true){
      has_identity(table, table_size, identity);
      if(identity != ERROR){
	all_have_inverse(table, table_size, out);
	if(out == GOOD){
	  cout << "It is a cayley table! The identity element is: " << identity << endl;
	}
	else{
	  cout<<"This is not a cayley table, not every element has an inverse."<<endl;
	}
      }
      else{
	cout<<"This is not a cayley table, there is no identity."<<endl;
      }
    }
  }
  else{
    cout << "Not a cayley table because it is not closed, outlier was: " << outlier << endl;
  }
}
