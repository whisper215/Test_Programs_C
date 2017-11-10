#include <stdio.h>
#include <stdlib.h>


#include <Windows.h>

VOID startup(LPCTSTR lpApplicationName)
{
    // additional information
    STARTUPINFO si;     
    PROCESS_INFORMATION pi;

    // set the size of the structures
    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );

    printf("startup called, %s\n", lpApplicationName);

    // start the program up
    CreateProcess( lpApplicationName,   // the path
            //argv[1],        // Command line
            NULL,        // Command line
            NULL,           // Process handle not inheritable
            NULL,           // Thread handle not inheritable
            FALSE,          // Set handle inheritance to FALSE
            0,              // No creation flags
            NULL,           // Use parent's environment block
            NULL,           // Use parent's starting directory 
            &si,            // Pointer to STARTUPINFO structure
            &pi             // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
            );

    printf("result = %s\n", GetCommandLine());

    // Close process and thread handles. 
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );
}

int main()
{
    printf("main start.\n");

    //system("pwd.exe");

    //startup("pwd.exe");

    startup("D:\\Program Files (x86)\\LinuxCommand\\coreutils-5.3.0-bin\\bin\\pwd.exe");

    printf("main end\n");

    getchar();

    return 0;
}
