#if !defined(GLOBALS_H)
/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Casey Muratori $
   $Notice: (C) Copyright 2015 by Molly Rocket, Inc. All Rights Reserved. $
   ======================================================================== */

#define GLOBALS_H

#include <SDL.h>

//*******************************************************Defines************/

#define MEM_SIZE 0x1000
#define SP_START 0x252   // Where does the Stack pointer start?
#define ROM_LOAD 0x200


#define CPU_CLEAR_SCREEN 0xE0
#define CPU_RET 0xEE

typedef void(*FunctionPointer) (void);

void (*ChipOpCodes[46]) ();
void (*ChipArith[9]) ();

void cpu_MISC()
{
    if (chipReg.operand.BYTE.low == CPU_CLEAR_SCREEN)
    {
        
    } else if (chipReg.operand.BYTE.low == CPU_RET) {

    } else {
        // Invalid opcode.
    }
}

void cpu_JUMP()
{
    
}

void cpu_CALL()
{
    
}

void cpu_SE_REGISTER_VALUE()
{
    
}

void cpu_SNE_REGISTER_VALUE()
{
}

void cpu_SE_REGISTER()
{
    
}

void cpu_LOAD()
{
    
}

void cpu_ADD_REGISTER_VALUE()
{
    
}

void cpu_ARITHMETIC()
{
    // Do lookup in arithmetic function table
    ChipArith[(chipReg.operand.WORD & 0x000F)] ();

}

void cpu_MOV_VY_VX()
{
    
}

// NOTE: ORs VX and VY
// IMPORTANT: Result stored in VX.
void cpu_OR_VX_VY()
{
    
}

void cpu_AND_VX_VY()
{
}

void cpu_XOR_VX_VY()
{
}

void cpu_ADD_VX_VY()
{
}

void cpu_SUB_VX_VY()
{
    
}

void cpu_SHIFT_RIGHT_VX_VY()
{
    
}

void cpu_SUBN_VX_VY()
{
}

void cpu_SHIFT_LEFT_VX_VY()
{
    
}

void (*ChipOpCodes[46]) () = 
{
    cpu_MISC, cpu_JUMP, cpu_CALL, cpu_SE_REGISTER_VALUE, cpu_SNE_REGISTER_VALUE,
    cpu_SE_REGISTER, cpu_LOAD, cpu_ADD_REGISTER_VALUE, cpu_ARITHMETIC
};


void (*ChipArith[9]) () =
{
    cpu_MOV_VY_VX, cpu_OR_VX_VY, cpu_AND_VX_VY, cpu_XOR_VX_VY, cpu_ADD_VX_VY,
    cpu_SUB_VX_VY, cpu_SHIFT_RIGHT_VX_VY, cpu_SUBN_VX_VY, cpu_SHIFT_LEFT_VX_VY
};

#endif
