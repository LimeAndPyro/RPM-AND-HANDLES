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


  
 
      
  
      
