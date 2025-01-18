#pragma once

#include <cstdint>
#include <random>


//chip 8 uses a 60hz clock for both CPU and sound


const int MEMORY_SIZE = 4096;
//registers, v0-ve, vf is used for the carry flag
const int REGISTER_COUNT = 16;
//16 level stack with a pointer
const int STACK_SIZE = 16;
//the display uses XOR mode
const int DISPLAY_HEIGHT = 32;
const int DISPLAY_WIDTH = 64;
//hex keyboard
const int KEYPAD_SIZE = 16;

class Chip8
{
public:
	Chip8();
	void LoadROM(char const* filename);
	void Cycle();

	uint8_t keypad[KEYPAD_SIZE]{};
	uint32_t video[DISPLAY_WIDTH * DISPLAY_HEIGHT]{};
private:
    void Table0();
	void Table8();
	void TableE();
	void TableF();

	// nothing, empty, souless, dark
	void OP_NULL();

	// clear the display
	void OP_00E0();

	// return from a subroutine
	void OP_00EE();

	// jump to an address
	void OP_1nnn();

	// call the subroutine at nnn
	void OP_2nnn();

	// Skip next instruction if Vx == kk
	void OP_3xkk();

	// Skip next instruction if Vx != kk
	void OP_4xkk();

	// Skip next instruction if Vx = Vy.
	void OP_5xy0();

	// set Vx == Kk
	void OP_6xkk();

	// Set Vx = Vx + kk.
	void OP_7xkk();

	// Set Vx = Vy.
	void OP_8xy0();

	// Set Vx = Vx OR Vy.
	void OP_8xy1();

	// Set Vx = Vx AND Vy.
	void OP_8xy2();

	// Set Vx = Vx XOR Vy.
	void OP_8xy3();

	// Set Vx = Vx + Vy, set VF = carry.
	void OP_8xy4();

	// Set Vx = Vx - Vy, set VF = NOT borrow.
	void OP_8xy5();

	// Set Vx = Vx SHR 1.
	void OP_8xy6();

	// Set Vx = Vy - Vx, set VF = NOT borrow.
	void OP_8xy7();

	// Set Vx = Vx SHL 1.
	void OP_8xyE();

	// Skip next instruction if Vx != Vy.
	void OP_9xy0();

	// Set I = nnn.
	void OP_Annn();

	// Jump to location nnn + V0.
	void OP_Bnnn();

	// Set Vx = random byte AND kk.
	void OP_Cxkk();

	// Display n-byte sprite starting at memory location I at (Vx, Vy), set VF = collision.
	void OP_Dxyn();

	// Skip next instruction if key with the value of Vx is pressed.
	void OP_Ex9E();

	// Skip next instruction if key with the value of Vx is not pressed
	void OP_ExA1();

	// Set Vx = delay timer value.
	void OP_Fx07();

	// Wait for a key press, store the value of the key in Vx.
	void OP_Fx0A();

	// Set delay timer = Vx.
	void OP_Fx15();

	// Set sound timer = Vx.
	void OP_Fx18();

	// Set I = I + Vx.
	void OP_Fx1E();

	// Set I = location of sprite for digit Vx.
	void OP_Fx29();

	// Store BCD representation of Vx in memory locations I, I+1, and I+2.
	void OP_Fx33();

	// Store registers V0 through Vx in memory starting at location I.
	void OP_Fx55();

	// Read registers V0 through Vx from memory starting at location I.
	void OP_Fx65();

	//creates a memory array with the amount of memory avaliable
	uint8_t memory[MEMORY_SIZE]{};

	//creates an array with 16 registers
	uint8_t registers[REGISTER_COUNT]{};

	uint16_t index{};
	//parogram counter
	uint16_t pc{};
	//cpu clock speed 60hz
	uint8_t delayTimer{};
	//sound clock speed 60hz
	uint8_t soundTimer{};
	//creates a stack with 16 levels
	uint16_t stack[STACK_SIZE]{};
	//creates an array called stack pointer
	uint8_t sp{};
	//opcode = operation code
	uint16_t opcode{};

	std::default_random_engine randGen;
	std::uniform_int_distribution<uint8_t> randByte;

	typedef void (Chip8::*Chip8Func)();
	Chip8Func table[0xF + 1];
	Chip8Func table0[0xE + 1];
	Chip8Func table8[0xE + 1];
	Chip8Func tableE[0xE + 1];
	Chip8Func tableF[0x65 + 1];
};