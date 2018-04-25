/*
    ICS 51, Lab #3

    --------------------------------------------------------------------

    IMPORTATNT NOTES:

    - This lab has five parts. The description of each part is given below.

    - Noramally, the compiler adds the prologue/epilogue code for the callee. However, when the 
    __declspec(naked) attribute is used, it is the programmer's responsibility to write the 
    prologue/epilogue code. In this lab you need to write prologue/epilogue code sections only 
    for the functions that have been declared with the naked attribute, namely:

       + findMinIndex
       + isPalindrome
       + performOperation
       + gcd

    - You cannot define any local variable in the C code. If you need additional variables in your
    assembly code, you have to allocate space for them in the prologue of the function. 

    - You are not allowed to change anything in this file except for adding your assembly code 
    between the lines marked with "YOUR CODE STARTS HERE" and "YOUR CODE ENDS HERE".

    - This lab has to be done individually.

    - Remember to fill in your name, student ID below.

    - Submit ONLY your completed lab3.c for grading.
*/

char *yourName = "Calvin Lui";
char *yourStudentID = "84152100";

#define RANDOMIZE_CALLEE_REGISTERS __asm mov ebx, 0xAFAFAFAF \
                                   __asm mov esi, 0xAFAFAFAF \
                                   __asm mov edi, 0xAFAFAFAF 
#define RANDOMIZE_CALLER_REGISTERS __asm mov eax, 0xAFAFAFAF \
                                   __asm mov ecx, 0xAFAFAFAF \
                                   __asm mov edx, 0xAFAFAFAF

/***********************************************************************************************

    PART 1: Change Letter Case

    You are given a string (null-terminated array of characters) that may contain numbers,
    upper and lower case letters, punctuations symbols, etc. Implement a function to convert all
    uppercase letters to lowercase and vice versa.
    For example "ThisIsTheFinalLabOf51" should be converted to "tHISiStHEfINALlABoF51".
    The string should be modifed in place. There is no explicit output for this function.

    Tips:

    - Note that each element of the arrays is a char (1 byte). You can NOT use a 32-bit register
    to read/write from/to a memory location. Instead you should use the 8-bit version of the x86
    general-purpose registers.

    - The link to the ASCII codes is here: http://www.asciitable.com/

************************************************************************************************/
void changeCase(char *string) {

    RANDOMIZE_CALLEE_REGISTERS
    RANDOMIZE_CALLER_REGISTERS

    __asm
    {
        // YOUR CODE STARTS HERE
		mov eax, string
		mov esi,0

		string_loop:
		mov bl, byte ptr[eax + esi*1]
		cmp bl,0
		je end

		// capital range is 65 - 90 inclusive and lowercase is 97 - 122
		cmp bl,65
		jge letter_range

		// if its smaller than move on to next letter
		jmp next_letter
		
		//if ascii value is outside range of 65 - 122 go to next letter
		letter_range:
		cmp bl,122
		jg next_letter

		cmp bl, 90
		jle upper
		cmp bl,97
		jge lower
		jmp next_letter

		
		lower:
		sub bl,32
		mov byte ptr[eax + esi*1],bl
		jmp next_letter

		upper:
		add bl,32
		mov byte ptr[eax+esi*1],bl


		next_letter:
		add esi,1
		jmp string_loop

		//inc esi
		mov string,eax
		end:
        // YOUR CODE ENDS HERE
    }
}

/***********************************************************************************************

    PART 2: Selection Sort

    Selection sort is an in-place comparison sort algorithm that works by dividing the input list 
    into two parts: the sublist of items already sorted, which is built up from left to right of 
    the list, and the sublist of items remaining to be sorted that occupy the rest of the list. 
    Initially, the sorted sublist is empty and the unsorted sublist is the entire input list. 
    The algorithm proceeds by finding the smallest element in the unsorted sublist, exchanging it 
    with the leftmost unsorted element (putting it in sorted order), and moving the sublist 
    boundaries one element to the right. To learn more, read: 
    https://en.wikipedia.org/wiki/Selection_sort#Example

    Our implementation here uses a function called "findMinIndex" to find the index of smallest
    element between ith index and jth index of the array. The function "selectionSort" uses
    this function to find the smallest number and exchanges it with the leftmost unsorted element
    in each iteration. You need to implement the behavior of both functions in x86 assembly.

************************************************************************************************/
__declspec(naked) 
int findMinIndex (int integer_array[], int i, int j)
{

// C code to be converted to x86 assembly
/*
    int iMin = i;
    // test against elements after i and before j to find the smallest 
    for ( i ; i < j; i++) {
        // if this element is less, then it is the new minimum   
        if (integer_array[i] < integer_array[iMin]) {
            // found new minimum; remember its index 
            iMin = i;
        }
    }

    return iMin;
*/

    RANDOMIZE_CALLER_REGISTERS

		__asm
	{
		// YOUR CODE STARTS HERE
		push ebp
		mov ebp,esp

		push edi
		push esi
		push ebx
		mov eax, [ebp + 8]
		mov edx, [ebp + 12]
		mov ecx, [ebp + 16]
		mov ebx,edx

		min_loop:
		cmp edx, ecx
		jge min_end
		mov edi, [eax + ebx * 4]
		mov esi,[eax + edx*4]


		cmp esi,edi
		jge arr_next
		mov ebx, edx
		arr_next:
		add edx,1
		jmp min_loop
		
		min_end:
		mov eax,ebx
		pop ebx
		pop esi
		pop edi
		mov esp,ebp
		pop ebp
		
        // YOUR CODE ENDS HERE
        ret
    }

}

void selectionSort (int integer_array[], int array_size)
{

// C code to be converted to x86 assembly
/*  
    int j;
    int iMin;
    int temp;

    // advance the position through the entire array //
    // (could do j < n-1 because single element is also min element) //
    for (j = 0; j < array_size-1; j++) {

        // find the index of min element in the unsorted a[j .. n-1] //
        iMin = findMinIndex (integer_array, j, array_size);
 
        if(iMin != j) { // swap values
            temp = integer_array[iMin];
            integer_array[iMin] = integer_array [j];
            integer_array[j] = temp;    
        }
    }
*/

    RANDOMIZE_CALLEE_REGISTERS
    RANDOMIZE_CALLER_REGISTERS

    __asm
    {
        // YOUR CODE STARTS HERE
		mov edx, array_size
		sub edx, 1
		mov esi, integer_array
		mov edi,0

		for_loop:
		cmp edi, edx
		jge sort_end

		push eax
		push ecx
		push edx

		mov ebx,array_size
		push ebx
		push edi
		push esi

		call findMinIndex
		mov ebx,eax
		add esp, 12
		pop edx
		pop ecx
		pop eax
		cmp ebx,edi
		je within
		mov ecx, [esi + edi * 4]
		mov eax, [esi + ebx*4]
		xor eax, ecx
		xor ecx, eax
		xor eax, ecx
		mov [esi + 4* ebx],eax
		mov [esi + 4*edi],ecx
		within:
		add edi,1
		jmp for_loop


		sort_end:

        // YOUR CODE ENDS HERE
    }

}

/***********************************************************************************************

    PART 3: Palindrome

    Given a string, complete the implementation of the recursive function isPalindrome() to check 
    if the string is palindrome or not. A string is said to be palindrome if reverse of the 
    string is same as string. For example, �abba� is palindrome, but �abbc� is not palindrome.

************************************************************************************************/
__declspec(naked)
int isPalindrome(char *input_string, int left_index, int right_index)
{

// C code to be converted to x86 assembly
/*
    // Input Validation
    if (NULL == input_string || left_index < 0 || right_index < 0){
        return -1;
    }
    // Recursion termination condition
    if (left_index >= right_index)
        return 1;
    if (input_string[left_index] == input_string[right_index]){
        return isPalindrome(input_string, left_index + 1, right_index - 1);
    }
    return -1;
*/

    RANDOMIZE_CALLER_REGISTERS

    __asm
    {
        // YOUR CODE STARTS HERE
		push ebp
		mov ebp,esp

		push edi
		push esi
		push ebx

		mov eax,[ebp + 8] //right index
		mov ebx,[ebp + 12]//left index
		mov ecx,input_string//input string
		
		cmp eax,0
		jl not_pali
		cmp ebx, 0
		jl not_pali
		cmp ecx,0x00000000
		jl not_pali

		cmp ebx,eax
		jl check_match
		mov eax,1
		jmp end_pali

		check_match:
		cmp ebx,edx
		jne not_pali
		pop ebx
		dec eax
		inc ebx
		push ecx
		push ebx
		push eax
		call isPalindrome
		pop eax
		pop ebx
		pop	ecx
		mov eax,1
		jmp end_pali

		



		not_pali:
		mov eax,-1

		end_pali:
		pop ebx
		pop esi
		pop edi
		mov esp,ebp
		pop ebp


        // YOUR CODE ENDS HERE
        ret
    }
}

/***********************************************************************************************

    PART 4: Vector Operation

    The vectorOperations function gets as parameters 4 arrays of the same length and
    the number of elements in those arrays. 

    For each pair of elements in first_array and second_array, it calls performOperation
    and stores the returned result in the same index of output_array.

    output_array[index] = performOperation(operation_array[index], first_array[index], second_array[index]).

    You also need to implement the body of performOperation function according to the provided
    C code.
  
************************************************************************************************/
__declspec(naked) 
int performOperation (int operation, int first, int second)
{

// C code to be converted to x86 assembly
/*
    if (operation==0) 
        return first - second;
    else if (operation==1)
        return first + second;
    else if (operation==2)
        return (first < second)? first : second;
    else if (operation==3)
        return (first > second)? first : second;
    else
        return first;
*/

    RANDOMIZE_CALLER_REGISTERS

    __asm
    {
        // YOUR CODE STARTS HERE
		push ebp
		mov ebp,esp
		sub esp,4

		push edi
		push esi
		push ebx

		mov ebx,[ebp+8]
		mov ecx,[ebp+12]
		mov edx,[ebp+16]
		
		cmp ebx,0
		je zero
		cmp ebx,1
		je one
		cmp ebx,2
		je two
		cmp ebx,3
		je three
		jmp other

		zero:
		mov [ebp-4],ecx
		sub [ebp-4],edx
		mov eax,[ebp-4]
		jmp done

		one:
		mov[ebp - 4], ecx
		add[ebp - 4], edx
		mov eax, [ebp - 4]
		jmp done

		two:
		cmp ecx,edx
		jge two_comp
		mov eax,ecx
		jmp done
		two_comp:
		mov eax,edx
		jmp done

		three:
		cmp ecx,edx
		jle three_comp
		mov eax,ecx
		jmp done
		three_comp:
		mov eax,edx
		jmp done

		other:
		mov eax,ecx
		done:
		pop ebx
		pop esi
		pop edi
		add esp,4

		mov esp,ebp
		pop ebp
        // YOUR CODE ENDS HERE
        ret
    }
}

void vectorOperations (int number_of_elements, int *first_array, int *second_array, 
                       int *operation_array, int *output_array)
{
// C code to be converted to x86 assembly
/*
    int i;
    for (i=0; i<number_of_elements; i++)
    {
        output_array[i] = performOperation(operation_array[i], first_array[i], second_array[i]);
    }
*/

    RANDOMIZE_CALLEE_REGISTERS
    RANDOMIZE_CALLER_REGISTERS

    __asm 
    {
        // YOUR CODE STARTS HERE
		mov edi,output_array
		mov esi,0
		mov eax, number_of_elements

		vector_loop:
		cmp esi, eax
		jge end_vector

		push eax
		push ecx
		push edx

		mov eax,second_array
		mov eax, [eax + esi*4]
		mov ebx, first_array
		mov ebx,[ebx + esi*4]
		mov ecx, operation_array
		mov ecx, [ecx + esi*4]

		push eax
		push ebx
		push ecx

		call performOperation

		add esp, 12

		mov [edi + esi*4], eax

		pop edx
		pop ecx
		pop eax

		add esi,1
		jmp vector_loop
	end_vector:
		mov output_array, edi





        // YOUR CODE ENDS HERE
    }
}

/***********************************************************************************************

    PART 5: Dijkstra's Algorithm to calculate GCD.

    Implement a recursive function in assembly that calculates the greatest common divisor of 
    two unsigned integers.

    Given two unsigned integers n and m, we can define GCD(m , n) as:

           GCD(m , n) = n                       ,    if (m % n) == 0
           GCD(m , n) = GCD(n , m % n)          ,    if (m % n) >  0

************************************************************************************************/
__declspec(naked) 
unsigned int gcd(unsigned int m, unsigned int n) {

// C code to be converted to x86 assembly
/*
    if ((m % n) == 0)
        return n;
    else
        return gcd(n, m % n);


    RANDOMIZE_CALLER_REGISTERS
    */
    __asm
    {
        //YOUR CODE STARTS HERE
		
		push ebp
		mov ebp,esp

		push esi
		push edi
		push ebx

		mov edx,0
		mov eax, [ebp+8]
		mov ebx, [ebp+12]
		cmp ebx,0
		je finish
		idiv ebx
		cmp edx,0
		jge recurse
		mov eax, n
		//jmp finish

		recurse:
		mov ebx,[ebp+12]
		push edx
		push ebx
		call gcd
		pop ebx
		pop edx
		jmp finish

		finish:
		pop ebx
		pop edi
		pop edx

		mov esp,ebp
		pop ebp
		
        //YOUR CODE ENDS HERE
        ret
    }
}