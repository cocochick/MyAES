#pragma once
#include<string.h>
#include<stdio.h>
#include<cmath>
typedef unsigned char byte;
typedef unsigned int dword;
class aes
{
public:
	aes(byte* c);
	aes(byte* p, byte* c);
	virtual void encrypt();
	virtual void decrypt();
	void log();
	void print_plain();
protected:
	void extend();
	void fill();
	void change_byte();
	void move_line();
	void mix_column();
	void rchange_byte();
	void rmove_line();
	void rmix_column();
	void plus_ck(int i);
	void rplus_ck(int i);
	byte multiple(byte num, byte data);
	byte plain[16];
	byte key[16];
	byte cipher[16];
	dword extended_key[44];
	byte S[16][16];
	byte rS[16][16];
	dword Rcon[10];
};

