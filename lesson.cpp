#include <iostream>
#include <cstdlib>
//#include <cstring>

int magic_number;		//extern int magic_number;
static int magic_number2 = 1;

int main(int argc, const char** argv) { 

	magic_number = 42;

// 1.Create and initialize variables of traversed data types
	printf("\nVariables\n");

	char 	var_char		= 'A';			
	int 	var_int			= 0xFFFF;
	short 	var_short		= 0xFFFF;
	long 	var_long		= 0xFFFFFFFF;
	
	printf("\tvar_char = %c\n\tvar_int = 0x%.4X\n\tvar_short = 0x%.4X\n\tvar_long = 0x%.8X\n", 
		 var_char, var_int, var_short, var_long);

	//-------
	unsigned int 	var_uint 	= 0xFFFF;
	unsigned short 	var_ushort 	= 0xFFFF;
	unsigned long 	var_ulong 	= 0xFFFFFFFF;
	
	printf("\n\tvar_uint = 0x%.4X\n\tvar_ushort = 0x%.4X\n\tvar_ulong = 0x%.8X\n", 
		  var_uint, var_ushort, var_ulong);

	//-------			  
	float  f_PI = 3.141592;
	double d_PI = 3.141592653589793;

    printf("\n\tfloat  PI = %1.6f\n\tdouble PI = %1.15f\n", f_PI, d_PI);






// 2. Create an enumeration with possible variants of symbols 
//    for playing tic-tac-toe
    enum ttt_cell_state {free, cross, zero};






// 3. Create an array capable of containing the values of such
//    an enumeration and initialize it.
    int tic_tac_toe_array [3] [3] = {0};

    // verification
    printf("\nVerification array tic_tac_toe\n");
    tic_tac_toe_array [0] [0] = ttt_cell_state::cross;
    tic_tac_toe_array [2] [2] = ttt_cell_state::zero;

    for (int i=0; i<3; i++){
		printf("\t%d %d %d\n", tic_tac_toe_array [i] [0], 
			tic_tac_toe_array [i] [1], tic_tac_toe_array [i] [2]);
    }





// 4. Create a data structure "Field for the game of tic-tac-toe" 
//    and provide it with all the necessary (in your opinion) properties
    struct ttt {
    	char Player0_name[16];
    	char Player1_name[16];
    	int ttt_game_field [3] [3];
       // int game_step;		// can be parsed - ttt_game_field
        int who_goes_first;
    };
	
 




// 5. Create a union and structure with bit flags indicating 
//    what type of value is currently contained in the union

union var_int {
    struct {
        unsigned char var0 : 4;
        unsigned char var1 : 4;
        unsigned char var2 : 4;
        unsigned char var3 : 4;
    } nibble;
    struct {
        unsigned char var_1_0;
        unsigned char var_3_2;
    } bytes;
    unsigned int word;
};
typedef union var_int var_all;



// verification
printf("\nUnion / Struct / Bit Field\n");

var_all var_union_str_b;

var_union_str_b.word = 0xABCD;		// union initialization

printf("\tstruct(Bit Field): var3=0x%01X,", var_union_str_b.nibble.var3);  
printf(" var2=0x%01X,", var_union_str_b.nibble.var2);  
printf(" var1=0x%01X,", var_union_str_b.nibble.var1);  
printf(" var0=0x%01X\n", var_union_str_b.nibble.var0);

printf("\tstruct:            var_3_2=0x%02X,", var_union_str_b.bytes.var_3_2);
printf(" var_1_0=0x%02X\n", var_union_str_b.bytes.var_1_0);

printf("\tunion:             word(int)=0x%04X\n", var_union_str_b.word);


    return 0; 
}
