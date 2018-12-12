#ifndef _MYARRAY_H
#define _MYARRAY_H

#define delete 1
#define search 0


/*initial an array with size (elements) having value -1*/
void array_init(int * arr, int size); 

/*push a new value to the array with size of array: size */
void array_push(int * arr, int val, int size); 

/*find value val inside the array
if val was found, return 1 else 0
action act = delete, make array in that position = -1 
act = search, do nothing*/
int array_search(int *arr, int size, int val, int act); 

/*print all elements of array*/
void array_print(int *arr, int size); 

/*return a string of an integer
for example: 155 -> "155", return in array b*/
void conv_alpha(char *b, int val); 

/*remove the first letter of a string
return the last integer
for example: "N155" -> 155 */
int conv_int(char * arr); 

/*return a string of an integer with prefix N
for example: 155 -> N155*/
void conv_alphaN(char *b, int val); 

#endif 