#include <iostream>
#include "cayley.h"
using namespace std;

const int MAX = 36;
const int ERROR = -1;
const int GOOD = -2;

void print_dashes(int table_size){
  for(int i = 0; i < table_size*2+2; i++){
    cout << "-";
  }
  cout << endl;
}

void read_table(char table[MAX][MAX], int table_size){
  for(int i = 0; i < table_size; i++){
    for(int j = 0; j < table_size; j++){
      cin >> table[i][j];
    }
  }
}

void print_table(char table[MAX][MAX], int table_size){
  cout << " |";
  for(int i = 0; i < table_size; i++){
    cout << table[0][i] << "|";
  }
  cout << endl;
  print_dashes(table_size);
  for(int i = 0; i < table_size; i++){
    cout << table[0][i] << "|";
    for(int j = 0; j < table_size; j++){
      cout << table[i][j] << "|";
    }
    cout << endl;
    print_dashes(table_size);
  }
}

bool is_closed(char table[MAX][MAX], int table_size, char& outlier){
  int fails;
  for(int i = 0; i < table_size; i++){
    for(int j = 0; j < table_size; j++){
      fails = 0;
      for(int k = 0; k < table_size; k++){
	if(table[i][j] != table[0][k]){
	  fails = fails+1;
	  if(fails == table_size){
	    outlier = table[i][j];
	    return false;
	  }
	}
      }
    }
  }
  return true;
}

char helperAssociativity(char table[MAX][MAX], int table_size, char item){
  char numberPosition;
  char arrayFirstLine[table_size];
  for(int i = 0; i < table_size; i++){
    arrayFirstLine[i] = table[0][i];
  }
  for(int i = 0; i < table_size; i++){
    if(item  == arrayFirstLine[i]){
      numberPosition = i;
      return numberPosition;
    }
  }
}

void is_associative(char table[MAX][MAX], int table_size, char& x, char& y, char& z, bool& ans){
  char checkFirstRow;
  char checkFirstColumn;
  char checkSecondRow;
  char checkSecondColumn;
  int counter = 0;
  for(int i = 0; i < table_size; i++){
    for(int j = 0; j < table_size; j++){
      for(int k = 0; k < table_size; k++){
	checkFirstRow = table[i][j];
	checkSecondRow = table[helperAssociativity(table,table_size,checkFirstRow)][k];
        checkFirstColumn = table[j][k];
	checkSecondColumn = table[i][helperAssociativity(table,table_size,checkFirstColumn)];
	if(checkSecondRow == checkSecondColumn){
	  counter = counter + 1;
	  if(counter == table_size*table_size*table_size){
	    ans = true;
	  }
	}
        if(checkSecondRow != checkSecondColumn and ans != false){
	  x = table[0][i];
	  y = table[0][j];
	  z = table[0][k];
	  cout<<"Not associative: "<<"("<<x<<y<<")"<<z<<" != "<<x<<"("<<y<<z<<")"<<endl;
	  ans = false;
	}
      }
    }
  }
}

void has_identity(char table[MAX][MAX], int table_size, char& identity){
  int incorrect = 0;
  identity = table[0][0];
  for(int i = 0; i < table_size; i++){
    if(table[0][i] != table[i][0]){
      incorrect = incorrect + 1;
    }
  }
  if(incorrect > 0 or table_size == 0){
    identity = ERROR;
  }
}

void all_have_inverse(char table[MAX][MAX], int table_size, char& out){
  int counter = 0;
  int wrong = 0;
  char identity = table[0][0];
  for(int i = 0; i < table_size; i++){
    wrong = 0;
    for(int j = 0; j < table_size; j++){
      if(table[i][j] == identity and table[j][i] == identity){
	counter = counter + 1;
	}
      if(table[i][j] != identity){
	wrong = wrong + 1;
	if(wrong == table_size){
	  out = table[0][j];
	  cout << out << endl;
	  return;
	}
      }
    }
  }
  if(counter == table_size or counter == table_size*table_size){
    out = GOOD;
  }
}
