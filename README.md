#IMPORTANT INFO

This program was made from a guide that helped me understand these things better myself 

https://www.unknowncheats.me/forum/programming-for-beginners/267073-coding-hacking-introduction-guide-practical-external-game-hacking.html

This is a older guide so im going to reitterate what is going on here using my own words as well as words from this guide


#What is READ PROCESS MEMORY? 
Okay, so let's go over the parameters one by one, here's the prototype so you don't have to switch back and forth on MSDN while reading.
BOOL WINAPI ReadProcessMemory(
  _In_  HANDLE  hProcess,
  _In_  LPCVOID lpBaseAddress,
  _Out_ LPVOID  lpBuffer,
  _In_  SIZE_T  nSize,
  _Out_ SIZE_T  *lpNumberOfBytesRead
);
