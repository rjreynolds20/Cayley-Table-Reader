const int MAX = 36;
const int ERROR = -1;
const int GOOD = -2;

//PRE: int table_size where table_size must be greater than 0 but less than or equal to 36. 
//POST: This function prints a line of dashes and creates a new line. Used to separate lines of the
//cayley table specifically when put together with the print_table() function.
void print_dashes(int table_size);

//PRE: Pass a two dimensional array called table and int table_size where table size must be greater 
//than zero but less than or equal to 36.
//POST: This function reads the table. It reads in n² (where n = table_size) numbers into the array 
//table. These are the n rows of the table. 
void read_table(char table[MAX][MAX], int table_size);

//PRE: Pass a two dimensional array called table and int table_size where table_size must be greater 
//than zero but less than or equal to 36.
//POST: This function prints table as a cayley table of size table_size. It should be printed as 
//presented in the examples above. It should have row and column boundaries. 
void print_table(char table[MAX][MAX], int table_size);

//PRE: Pass a two dimensional array called table and int table_size where table_size must be greater 
//than zero but less than or equal to 36. Also passes char outlier which must be set as an empty 
//string.
//POST: This function is meant to verify the closure axiom. It should return true if and only if the 
//table stored in table is closed i.e. every operation gives an element in the group. If the group 
//isn't closed, then outlier should be set to a character in the table that doesn't belong. MAX is a 
//constant integer that is set to 36 (the number of allowed characters). It should be declared in 
//cayley.h. 
bool is_closed(char table[MAX][MAX], int table_size, char& outlier);

//PRE: Pass a two dimensional array called table and int table_size must be greater than zero but less
//than or equal to 36. Also passes char item.
//POST: This function returns the position of item in an array of the first line of a cayley table.
char helperAssociativity(char table[MAX][MAX], int table_size, char item);

//PRE: Pass a two dimensional array called table and int table_size where table_size must be greater 
//than zero but less than or equal to 36. Also passes char x, char y, and char z where all must be 
//set as empty string. Bool ans is an undecided bool that will change through execution of the function.
//POST: This function is meant to verify the associativity axiom. It should set ans to true if and 
//only if the table's operation is associative. If it isn't it should set x, y, and z to elements 
//that violate associativity. They should be set such that (xy)z != x(yz).
void is_associative(char table[MAX][MAX], int table_size, char& x, char& y, char& z, bool& ans);

//PRE: Pass a two dimensional array called table and int table_size where table_size must be greater 
//than zero but less than or equal to 36. Also passes char identity which will be set to the identity 
//of the cayley table through the execution of the function.
//POST: This function is meant to verify the identity element axiom. It should set identity to the 
//integer constant ERROR (Should be declared in cayley.h and set to -1) if the table has no identity 
//element. Otherwise, identity is set to an identity element in the table. 
void has_identity(char table[MAX][MAX], int table_size, char& identity);

//PRE: Pass a two dimensional array called table and int table_size where table_size must be greater 
//than zero but less than or equal to 36. Also passes char out where out must be set to an empty 
//string.
//POST: This function is meant to verify the inverse element axiom. It should set out to the integer 
//constant GOOD (Should be declared in cayley.h and set to -2.) if every element in the group has an 
//inverse. Otherwise, out out should be set to an element in the table without an inverse. 
void all_have_inverse(char table[MAX][MAX], int table_size, char& out);
