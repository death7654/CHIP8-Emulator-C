unsigned short opcode;
//memory
unsigned char memory[4096];
//registers, v0-ve, vf is used for the carry flag
unsigned register_[16];
//index counter
unsigned short index;
//program counter
unsigned short program_counter;

/*
Memory Map
0x000 - 0x1ff //the interpreter
0x050-0x0a0 //font
0x200-0xfff //program space
*/

//display 64 long, 32 tall, also monocromatic
//the display uses XOR mode
unsigned char gfx[64*32];

//chip 8 uses a 60hz clock for both CPU and sound
unsigned char delay_timer;
unsigned char sound_timer;

//16 level stack with a pointer
unsigned short stack[16];
unsigned short stack_pointer;

//hex keyboard
unsigned char key[16];

