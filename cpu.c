#include "globals.h"

const enum f_Functions
{
    LD_DELAYTIMER_GET = 0x07, LD_KEYPAD_STORE = 0x0A, LD_DELAY_SET = 0x15,
    LD_SOUND = 0x18, ADD_I = 0x1E, LD_FONT = 0x29,
    LD_BCD = 0x33, LD_STORE_REGISTER_MEM = 0x55,
    LD_READ_REGISTER_MEM = 0x65

};

typedef void(*FunctionPointer) (void);

void (*ChipOpCodes[46]) ();
void (*ChipArith[9]) ();
void (*ChipKeypadFuncs[10]) ();


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

void cpu_SNE_REGISTER()
{
    
}

void cpu_LOAD_IREG_VALUE()
{
    
}

void cpu_JMP_V0_VALUE()
{
}

void cpu_RAND()
{
    
}

void cpu_DRAW_SPRITE()
{
    
}


void cpu_KEYPAD()
{
    ChipKeypadFuncs[(chipReg.operand.WORD & 0x000F)]();
}

void cpu_SKIP_IF_KEY()
{
    
}

void cpu_SKIP_NOT_KEY()
{
    
}

void cpu_REG_KEYPAD_MISC ()
{
    
}

void (*ChipOpCodes[46]) () = 
{
    cpu_MISC, cpu_JUMP, cpu_CALL, cpu_SE_REGISTER_VALUE, cpu_SNE_REGISTER_VALUE,
    cpu_SE_REGISTER, cpu_LOAD, cpu_ADD_REGISTER_VALUE, cpu_ARITHMETIC,
    cpu_SNE_REGISTER, cpu_LOAD_IREG_VALUE, cpu_JMP_V0_VALUE, cpu_RAND,
    cpu_DRAW_SPRITE, cpu_KEYPAD, cpu_REG_KEYPAD_MISC
};


void (*ChipArith[9]) () =
{
    cpu_MOV_VY_VX, cpu_OR_VX_VY, cpu_AND_VX_VY, cpu_XOR_VX_VY, cpu_ADD_VX_VY,
    cpu_SUB_VX_VY, cpu_SHIFT_RIGHT_VX_VY, cpu_SUBN_VX_VY, cpu_SHIFT_LEFT_VX_VY
};

void (*ChipKeypadFuncs[10]) () =
{
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, cpu_SKIP_IF_KEY,
    cpu_SKIP_NOT_KEY
    
};
