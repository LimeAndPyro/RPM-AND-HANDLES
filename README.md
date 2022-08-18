# IMPORTANT INFO

This program was made from a guide that helped me understand these things better myself 

https://www.unknowncheats.me/forum/programming-for-beginners/267073-coding-hacking-introduction-guide-practical-external-game-hacking.html

This is a older guide so im going to reitterate what is going on here using my own words as well as words from this guide


# What is READ PROCESS MEMORY? 
Lets First go over the required parameters to use this function. More information on this topic can be found here https://docs.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-readprocessmemory

    BOOL WINAPI ReadProcessMemory(
      _In_  HANDLE  hProcess,
      _In_  LPCVOID lpBaseAddress,
      _Out_ LPVOID  lpBuffer,
      _In_  SIZE_T  nSize,
      _Out_ SIZE_T  *lpNumberOfBytesRead
    );

First Lets understand what exactly this function does.
  
  -Here we can see that it requires a HANDLE value.
      
      _In_  HANDLE  hProcess,
      
  # What exactly is a HANDLE?
  A process handle is an integer value that identifies a process to Windows. The Win32 API calls them a "HANDLE".
  
  In dumb words a handle is like a set of numbers that windows assigns on every process, think of it as a key windows uses to organize, identify, and access certain     processes.
  
  # How do we Define and get a HANDLE?
  
  Well Here we use a function known as OPENPROCESS
  
  What is open process?
  
  OpenProcess opens an existing process object running on a local machine.
  
  The syntax looks like this
  
      HANDLE OpenProcess(
        [in] DWORD dwDesiredAccess,
        [in] BOOL  bInheritHandle,
        [in] DWORD dwProcessId
        );
        
  Lets look at this first parameter.
      
        [in] DWORD dwDesiredAccess
        
  dwDesiredAccess is the desired access level to the process object your opening.
  More information on this can be found here {https://docs.microsoft.com/en-us/windows/win32/procthread/process-security-and-access-rights}
  As im not going to list them all out :)
  
  In this program we use *PROCESS_ALL_ACCESS*
  Which you guessed it, gives all access Who would have thought?
  
  So far we have this
        
        HANDLE hofproc = OpenProcess(PROCESS_ALL_ACCESS,
  
  Next parameter we are going to take a look at is a BOOL.
  
        [in] BOOL  bInheritHandle,
        
  obv this is going to either return true or false and if you dont know that you should go learn more programing and come back later.
  
  So what if we return true?
        
        If this value is TRUE, processes created by this process will inherit the handle.
  
  And what about false?
        
        If this value is FALSE, processes do not inherit this handle.
        
 Again more information on this can be found here -> https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-openprocess
 
 So now we can update the parameters we have with this.
 
        HANDLE hofproc = OpenProcess(PROCESS_ALL_ACCESS, false,
        
 Last but not least we have [in] dwProcessId
        
        [in] DWORD dwProcessId
 
 This is the unique process identification number, commonly abbreviated to Process ID or even PID, of the process we want to get an access to.
 *for slow people like me this is numbers that windows assigns to processes to help identify and modify them*
 
 How do we obtain this Process ID thingy?
    
 Well we can find it in task manager
 
 ![xcwu9Jh](https://user-images.githubusercontent.com/98422417/185277827-b30e0f57-27f6-4d6c-8965-91369aa4991a.png)
 
 But to make it easier we also list is out here on the original program
 
        DWORD pid = GetCurrentProcessId();
        std::cout << "Process ID: " << pid << std::endl << std::endl;
 
 If you havent Run the program yet it looks like this
 
 ![FYFVHzs](https://user-images.githubusercontent.com/98422417/185278105-297dab85-cd0d-4c26-9b2b-2382524eb5f4.png)
 
 If your not blind you can see the process ID here
 
 ![paoqiM8](https://user-images.githubusercontent.com/98422417/185278205-b7c4c6e5-181f-413b-a60e-0a92171ebfca.png)
 
 Note this number will be different for all of you!
 
 YAY We Can finally finish this function
    Yours should look something like this
    
        HANDLE hofproc = OpenProcess(PROCESS_ALL_ACCESS, false, PID);
        
 Remember that PID is stored in a DWORD we defined earlier
   
        DWORD pid = GetCurrentProcessId();
        
 Congrats you have succesfully defined your first HANDLE, And im closer to smoking this bowl of weed :)
 
 BUT WAIT
 
 first we need to know to properly error handle your handle just in case it fails to grab the Running PID
 This is really simple like realllllly simple as its just a if check to see if it failed or if the value is NULL, for example 
 
        HANDLE hofproc = OpenProcess(PROCESS_ALL_ACCESS, false, PID);
	if (hofproc != NULL)
    {
        //Do Shit
    }
    
Just remember to properly handle the errors too dont just tuck it under the sheets!
For example.

    HANDLE hofproc = OpenProcess(PROCESS_ALL_ACCESS, false, PID);	
    if (hofproc != NULL)
	{
		//Do Shit
        return EXIT_SUCCESS;
	}
	else
	{
		std::cout << "-------------------HANDLE FAILED TO ATTATCH TO PROCESS------------------------------" << std::endl;
		return EXIT_FAILURE;
	}
Finally for more information on HANDLES visit {https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-openprocess?redirectedfrom=MSDN} and {https://docs.microsoft.com/en-us/windows/win32/rpc/handles}

# Back To RPM (Read Process Memory)

We can now update our parameters alittle bit

	BOOL rpm = ReadProcessMemory(hofproc,
	
Now lets take a look at the next parameter in the function
	
	
	BOOL WINAPI ReadProcessMemory(
      _In_  HANDLE  hProcess,
      _In_  LPCVOID lpBaseAddress,
      _Out_ LPVOID  lpBuffer,
      _In_  SIZE_T  nSize,
      _Out_ SIZE_T  *lpNumberOfBytesRead
    );
    
As we can see here the next parameter is a LPCVOID lpBaseAddress.

So Lets start the next section shall we.

# LPCVOID lpBaseAddress.

Okay at that stage we now have our precious handle that we can use with ReadProcessMemory, let's move on to the second parameter of ReadProcessMemory "_In_ LPCVOID lpBaseAddress".
If you've learned C/C++ with the standard library, don't be afraid of Microsoft variable types, LPCVOID is simply a void* const (LP stands for Long Pointer, C stands for Constant, VOID stands for ... yes, void)
The documentation is rather clear: "A pointer to the base address in the specified process from which to read."

![FYFVHzs](https://user-images.githubusercontent.com/98422417/185282153-6a66edcd-9498-40c5-a218-32e8918a4bef.png)

Again we can see this address in plain site as its wrote right in the program

![gJglBF1](https://user-images.githubusercontent.com/98422417/185282579-289b5bef-463d-4332-ace1-a2b87c9469c6.png)


and if we plop it in there its should look something like this

	BOOL rpm = ReadProcessMemory(hofproc, (LPCVOID)MemAddress,

REMEMBER TO CAST IT compilers no likey when you dont cast

# Back to the Function

Lets take a look at the next parameter.

	BOOL WINAPI ReadProcessMemory(
      _In_  HANDLE  hProcess,
      _In_  LPCVOID lpBaseAddress,
      _Out_ LPVOID  lpBuffer,
      _In_  SIZE_T  nSize,
      _Out_ SIZE_T  *lpNumberOfBytesRead
    );

Says here the next parameter is a _Out_ LPVOID  lpBuffer,.

What exactly is a Buffer?
A "buffer" simply means a place in memory.
think of it as a var that gets the information passed to before reading it kinda like copy and psting from the memory address the value of the variable stored at the particular address.

How do i create a buffer?
Really simple
	
	int readbuffer = 0;

Remember to assign this value as 0, dont worry it will basically be overwritten.
And well thats it for the buffer your code for RPM should look like this now.

	int readbuffer = 0;
		BOOL rpm = ReadProcessMemory(hofproc, (LPCVOID)MemAdd, &readbuffer,

"&" Means address of this variable in memory.


# Back To RPM (Read Process Memory) Again

We are so close!
Lets take yet another look at this function
	
	BOOL WINAPI ReadProcessMemory(
      _In_  HANDLE  hProcess,
      _In_  LPCVOID lpBaseAddress,
      _Out_ LPVOID  lpBuffer,
      _In_  SIZE_T  nSize,
      _Out_ SIZE_T  *lpNumberOfBytesRead
    );
    
Next Parameter we have here is SIZE_T  nSize,
This one is really easy to do as its very simple so i wont be splitting it into its own catagory.
All we are doing is telling the function what the size is of our buffer in this example its a integer so its 4 Bytes so we coullllld define it like this 
		
	ReadProcessMemory(hProcess, (LPCVOID)memoryAddress, &intRead, sizeof(int),
	
But a better and easier way is to define it like this.

	BOOL rpm = ReadProcessMemory(hofproc, (LPCVOID)MemAdd, &readbuffer, sizeof(readbuffer),

So now we have four parameters of the five we are so close and im so glad this guide is long asf and im lazy asf.
Again your code should look something like this now.

	BOOL rpm = ReadProcessMemory(hofproc, (LPCVOID)MemAdd, &readbuffer, sizeof(readbuffer),

Lets take one last look at the parameters needed for this function.

	BOOL WINAPI ReadProcessMemory(
      _In_  HANDLE  hProcess,
      _In_  LPCVOID lpBaseAddress,
      _Out_ LPVOID  lpBuffer,
      _In_  SIZE_T  nSize,
      _Out_ SIZE_T  *lpNumberOfBytesRead
    );
    
The last parameter is _Out_ SIZE_T  *lpNumberOfBytesRead.
This is another really easy one so again i wont make another catagory.
The last parameter, "_Out_ SIZE_T *lpNumberOfBytesRead" allow us to retrieve in a variable of type SIZE_T the number of bytes read, as the function parameter indicates quite clearly.
We could therefore declare a variable SIZE_T named bytesRead initialised to 0 ( SIZE_T bytesRead = 0; ) and give ReadProcessMemory its address (&bytesRead).
This can be useful for error checking for example, however, to keep things simple, since this parameter is optional (as indicated in the documentation), we'll just set it to NULL.

# CONGRAGULATIONS AGAIN

You now know the basics of memory and processes, how to read memory and understanding addresses in memory.

If youve made it this far your code should look something like this minus all the extra Code for the project.

	
	#include <Windows.h>
	#include <iostream>
	#include <sys/types.h>

	using namespace std;

	int main()
	{
		DWORD PID = 0; //buffer for process ID
		cout << "Process ID: ";
		cin >> dec >> PID;//Prompt for id

		//create handle to dummy program
		HANDLE hofproc = OpenProcess(PROCESS_ALL_ACCESS, false, PID);
		if (hofproc != NULL)
		{
			uintptr_t MemAdd = 0x0;
			cout << "MEMORY ADDRESS: ";
			cin >> hex >> MemAdd;//Prompt for address

			int readbuffer = 0;
			BOOL rpm = ReadProcessMemory(hofproc, (LPCVOID)MemAdd, &readbuffer, sizeof(readbuffer), NULL);
			cout << "Memaddress value = " << readbuffer << std::endl;
			std::cout << "PRESS ENTER TO PRINT AGAIN" << std::endl;
			getchar();
			//- Print to console a line of dashes("-") and then let it loop back to the beginning
			std::cout << "-----------------------------------------------------------------------" << std::endl;
			return EXIT_SUCCESS;
		}
		else
		{
			std::cout << "-------------------HANDLE FAILED TO ATTATCH TO PROCESS------------------------------" << std::endl;
			return EXIT_FAILURE;
		}


	}
	
Im getting lazy with this guide so if you havent figured out what you need to do here are the steps in order on what this program is doing.

- Declare a variable of type integer named "intRead" initialised to 0
- Get a handle to our running dummy program (use OpenProcess and check that it succeeded with the checking code that I provided in the lesson, in case of error use the error codes to investigate the reason)
- Read the value of the variable "varInt" in our dummy program and store the result in our variable "intRead" (Use ReadProcessMemory with the handle you got, the memory address shown in the console of our dummy program and don't forget to add the prefix (LPCVOID) to type-cast it so the function doesn't bother you, store the result in our variable "intRead" by using it as a buffer simply by giving its memory address with &intRead, use sizeof(int) for the size, and let the last optional parameter as NULL)
- Print to the console the new value of our variable "intRead" ( cout << "intRead = " << dec << intRead << endl; )
- Print to the console a message "Press ENTER to quit." and pause the execution with either getchar() or system("pause > nul");

Bellow is a gif on how the program works and its output.

![brave_7J0u5689eV](https://user-images.githubusercontent.com/98422417/185287092-73b984e7-4580-449e-9670-cb7282a786f2.gif)



  
 
      
  
      
