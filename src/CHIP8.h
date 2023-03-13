#pragma once

#include <array>
#include <string>

constexpr std::array<uint8_t, 80> fontset{
    0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
    0x20, 0x60, 0x20, 0x20, 0x70, // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
    0x90, 0x90, 0xF0, 0x10, 0x10, // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
    0xF0, 0x10, 0x20, 0x40, 0x40, // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90, // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
    0xF0, 0x80, 0x80, 0x80, 0xF0, // C
    0xE0, 0x90, 0x90, 0x90, 0xE0, // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
    0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

class CHIP8 {
public:
    std::array<uint8_t, 2048> graphics{}; // 2048 (64 * 32)
    
    CHIP8();

    auto loadROM(std::string path) -> int;
    auto cycle() -> void;

private:
    uint16_t opcode{0}; // 4 hex numbers
    std::array<uint8_t, 16> registers{}; // 16 general purpose registers
    uint16_t index{0}; // special index register
    uint16_t programCounter{0x200}; // special programCounter register

    uint8_t delayTimer{0};
    uint8_t soundTimer{0};

    std::array<uint8_t, 4096> memory{}; // 4096 byte array (64 * 64)
    std::array<uint16_t, 16> stack{}; // keep track of stack of addresses
    uint16_t sp{0}; // stack pointer, the current thing on the stack (can be u4)

    std::array<uint16_t, 16> keys{}; // what keys are being pressed

    auto incrementPC() -> void;
};