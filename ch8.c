#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <windows.h>
#include "globals.h"

bool loadRom(const char *filename)
{
    bool Result = false;
    printf("Loading: %s\n", filename);

    FILE *file = fopen(filename, "rb");

    if(file == NULL)
    {
        Result = false;
        return Result;
    }

    // Check file size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    printf("Filesize: %d\n", (int)fileSize);

    // Rewind file to begininning
    rewind(file);

    // Create a buffer for the file contents to go in
    char *Buffer = (char *)malloc(sizeof(char) * fileSize);

    // Check to make sure buffer allocation didn't fail
    if (Buffer == NULL)
    {
        fputs("Memory error. Something's fucked?", stderr);
        return false;
    }
    
    size_t fileRead = fread(Buffer, 1, fileSize, file);

    if(fileRead != fileSize)
    {
        fputs("File reading error.", stderr);
        return false;
    }

    // Make sure we have enough memory
    // first 512 vytes reserved
    if(fileRead > (4096 - 512))
    {
        printf("File too big. gah.\n");
        return false;
    }

    unsigned int i = 0;

    while(i < fileRead)
    {
        chipMem[i+0x200] = (byte)Buffer[i];
        i++;
    }
    
    Result = true;
    fclose(file);
    return Result;
}

void fetchInstr()
{
    WORD opcode = chipMem[chipReg.pc.WORD] << 8 | chipMem[chipReg.pc.WORD + 1];
    chipReg.operand.WORD = (WORD)opcode;
}

void execInstr()
{
    
}

void init()
{
    
    chipMem = mainChip.memory;
    chipReg = mainChip.regs;
    chipReg.pc.WORD = (unsigned int)0x200;  // PC always starts here
    chipReg.operand.WORD = 0;
    chipReg.sp.WORD = 0;

    int i = 0;
    while (i < 79)
    {
        chipMem[i] = fontset[i];
        i++;
    }
}

int main(int argc, char *argv[])
{
    init();

    if(argc < 2)
    {
        printf("Usage: ch8.exe chip8application\n\n");
        return 1;
    }

    // LOAD ROM

    if(!loadRom(argv[1]))
    {
        printf("file cant be loaded\n");
        return 1;
    }

    
    SDL_Window *window;
    //The surface contained by the window
    SDL_Surface* ScreenSurface = NULL;

    SDL_Init(SDL_INIT_VIDEO);


    window = SDL_CreateWindow(
        "An SDL2 Window",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        SDL_WINDOW_OPENGL
                              );
    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    ScreenSurface = SDL_GetWindowSurface(window);

    //Main loop flag
    bool quit = false;
    //Event handler
    SDL_Event e;

    while(!quit)
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT || e.key.keysym.sym == SDLK_q)
            {
                quit = true;
            }
            else if( e.type == SDL_KEYDOWN ) {
                switch( e.key.keysym.sym ) {
                    default:
                        break;
                }
            }
        }

        // Dispatch events

        // Cycle

        fetchInstr();
        
        // Call function to parse opcode
        execInstr();


        // Draw
        
    }

    SDL_DestroyWindow(window);
    window = NULL;
    SDL_Quit();
    return 0;
}

