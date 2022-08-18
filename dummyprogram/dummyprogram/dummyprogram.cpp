
#include <Windows.h>
#include <iostream>
#include <sys/types.h>


int main()
{
    DWORD pid = GetCurrentProcessId();
    //- Declare a variable named varInt of type integer equal to 123456
    int varInt = 123456;
    //- Declare a variable named varString of type string with the text "DefaultString" (C++ only, ignore if writing in C)
    char varString[] = "DefaultString";
    //- Declare an array of char named arrChar of size 128 with the text "Long char array right there ->" (you can put the size in a declared constant)
    char arrChar[128] = "Long char array right there ->";
    //- Declare a pointer to integer named ptr2int pointing to varInt
    int* ptr2int = &varInt;
    //- Declare a pointer to pointer to int named ptr2ptr pointing to ptr2int
    int** ptr2ptr = &ptr2int;
    //- Declare a pointer to pointer to pointer to int named ptr2ptr2 pointing to ptr2ptr
    int*** ptr2ptr2 = &ptr2ptr;

    //Once this is done you will create an infinite loop in which you will:
    while (true)
    {
        //-Print to console "Process ID: " followed by the process ID of the program using the Windows API function GetCurrentProcessId() (Therefore, don't forget to #include <Windows.h> !!)
        std::cout << "Process ID: " << pid << std::endl << std::endl;
        //- Print to console "varInt (0x[ADDRESS OR THE VARIABLE]) = [VALUE OF THE VARIABLE]" (Remember that you can get the address of a variable by prefixing it by "&")
        std::cout << "varInt -> " << "(0x" << &varInt << ")" << " = " << varInt << std::endl;
        //- Same thing for varStringand varChar
        std::cout << "varString -> " << "(0x" << &varString << ")" << " = " << varString << std::endl;
        std::cout << "arrChar[128] -> " << "(0x" << &arrChar << ")" << " = " << arrChar << std::endl << std::endl;
        //- Same thing for our 3 pointers, print for example "ptr2int (0x[ADDRESS OF THE POINTER]) = 0x[ADDRESS POINTED])
        std::cout << "ptr2int -> " << "(0x" << &ptr2int << ")" << " = 0x" << ptr2int << std::endl;
        std::cout << "ptr2ptr -> " << "(0x" << &ptr2ptr << ")" << " = 0x" << ptr2ptr << std::endl;
        std::cout << "ptr2ptr2 -> " << "(0x" << &ptr2ptr2 << ")" << " = 0x" << ptr2ptr2 << std::endl << std::endl;
        //- Print to console "Press ENTER to print again."
        std::cout << "PRESS ENTER TO PRINT AGAIN" << std::endl;
        //- Put something to pause, you can either use getchar() or system("pause > nul")
        getchar();
        //- Print to console a line of dashes("-") and then let it loop back to the beginning
        std::cout << "-----------------------------------------------------------------------" << std::endl;
    }
}


