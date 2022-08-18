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
  
  OpenProcess opens an existion process object running on a local machine.
  
  The syntax looks like this
  
      HANDLE OpenProcess(
        [in] DWORD dwDesiredAccess,
        [in] BOOL  bInheritHandle,
        [in] DWORD dwProcessId
        );
      

 
      
  
      
