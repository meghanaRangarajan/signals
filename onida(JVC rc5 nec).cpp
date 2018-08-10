#include<stdlib.h>
#include <unistd.h>
#include<iostream>
#include<wiringPi.h>

int main()
{
	int pin = 0;	
	wiringPiSetup () ;
    pinMode (pin, OUTPUT) ;
    int keycode;
	char function;
	uint64_t code = 0x0000;
	uint64_t codec = 0x0000;
	uint64_t codex = 0x00000000;

	std::cout<<"enter the keycode: "<<std::endl;
	std::cin>>keycode;

	switch(keycode)
	{

		case 0:
        code = 0xc004;
        codec = 0x0fff;
        codex = 0x00fe58a7;
        std::cout<<"key0";
        break;

		case 1:
		codec = 0x0ffe;
        code = 0xc084;
        codex = 0x00fe708f;
        std::cout<<"key1";
        break;

        case 2:
        codex = 0x00fe609f;
        codec = 0x0ffd;
        code = 0xc044;
        std::cout<<"key2";
        break;

        case 3:
        codex = 0x00fef00f;
        code = 0xc0c4;
        codec = 0x0ffc;
        std::cout<<"key3";
        break;

        case 4:
        codex = 0x00fe48b7;
        codec = 0x0ffb;
        code = 0xc024;
        std::cout<<"key4";
        break;

        case 5:
        codex = 0x00fee01f;
        codec = 0x0ffa;
        code = 0xc0a4;
        std::cout<<"key5";
        break;

        case 6:
        codex = 0x00fec837;
        codec = 0x0ff9;
        code = 0xc064;
        std::cout<<"key6";
        break;

        case 7:
        codex = 0x00fe6897;
        codec = 0x0ff8;
        code = 0xc0e4;
        std::cout<<"key7";
        break;

        case 8:
        codex = 0x00fe40bf;
        codec = 0x0ff7;
        code = 0xc014;
        std::cout<<"key8";
        break;

        case 9:
        codex = 0x00fee817;
        codec = 0x0ff6;
        code = 0xc094;
        std::cout<<"key9";
        break; 

        case 10:
        code = 0xc078;
        codec = 0x0fef;
        codex = 0x00fef807;
        std::cout<<"vol up";
        break;

        case 11:
        code = 0xc0f8;
        codec = 0x0fee;
        codex = 0x00fefa05;
        std::cout<<"vol dowm";
        break;

        case 12:
        codex = 0x00fed02f;
        code = 0xc038;
        codec = 0x0ff2;
        std::cout<<"mute";
        break;

         case 13:
        code = 0xc098;
        codec = 0x0fdf;
        codex = 0x00fe7a85;
        std::cout<<"ch up";
        break;

         case 14:
        code = 0xc018;
        codec = 0x0fde;;
        codex = 0x00fe6a95;
        std::cout<<"ch down";
        break;

         case 15:
         codex = 0x00fe50af;
        code = 0xc0e8;
        codec = 0x0ff3;
        std::cout<<"power";
        break; 

        case 16:
        codex = 0x00fec03f;
        codec = 0x0fc1;
        std::cout<<"back";
        break;

        case 17:
        code = 0xc067;
        codex = 0x00fed827;
        codec = 0x0fdd;
        std::cout<<"red";
        break;

        case 18:
        codex = 0x00feea15;
        codec = 0x0fdd;
        std::cout<<"red";
        break;

        case 19:
        code = 0xc05e;
        std::cout<<"back";
        break;

        case 21:
        codex = 0x00fe7a85;
        code = 0xc03e;
        codec = 0x400401005253;
        std::cout<<"up";
        break; 

        case 22:
        codex = 0x00fe6a95;
        code = 0xc0de;
        codec = 0x40040100d2d3;
        std::cout<<"down";
        break; 

        case 23:
        codex = 0x00feda25;
        code = 0xc0da;
        codec = 0x400401007273;
        std::cout<<"left";
        break; 

        case 24:
        codex = 0x00fe1ae5;
        code = 0xc05a;
        codec = 0x40040100f2f3;
        std::cout<<"right";
        break;

        case 25:
        codex = 0x00fe5aa5;
        code = 0xf72b;
        codec = 0x0fda;
        std::cout<<"OK";
        break;

        case 26:
        codec = 0x0fc8;
        std::cout<<"red";
        break;

        case 27:
        codec = 0x0fc9;
        std::cout<<"green";
        break;

        case 28:
        codec = 0x0fcd;
        std::cout<<"yellow";
        break;

        case 29:
        codec = 0x0fcb;
        std::cout<<"blue";
        break;

        case 36:
        codex = 0x7070f00f;
        code = 0xc088;
        codec = 0x0fc7;
        std::cout<<"blue";
        break;

        default :
        exit(1);
        std::cout<<"enter correct key code";
        break;

	}

	while(1)
	{
		if (code!=0)
		{
			digitalWrite(pin,1);
    usleep(8400);
    digitalWrite(pin,0);
    usleep(4200);
	uint64_t mask = 0x0001;
	uint32_t size = 16;
	int i;
	uint64_t code3 = code;
	for(i = 0; i<size ;i++)//to detect the size of the code to be sent
	{
		if(((mask & (code3 >> (size-i-1))) == 0))//for logical 0
		{
			digitalWrite(pin,1);
			usleep(460);
			digitalWrite(pin,0);
			usleep(460);
		}
		else// for logical 1
		{       
			digitalWrite(pin,1);
			usleep(460);
			digitalWrite(pin,0);
			usleep(1500);
		}
	}
delay(89);
		}

		if (codec!=0)
		{
			digitalWrite(pin,0);
        usleep(830);
        digitalWrite(pin,1);
        usleep(830);
 
        digitalWrite(pin,0);
        usleep(830);
        digitalWrite(pin,1);
        usleep(830);
    uint64_t mask = 0x0001;
    int size = 16;
    int i;
    for(i = 0; i<size ;i++)//to detect the size of the code to be sent
    {
        if((mask & (codec >> i)) == 0)//for logical 0
        {
            digitalWrite(pin,1);
            usleep(830);
            digitalWrite(pin,0);
            usleep(830);
        }
        else// for logical 1
        {       
            digitalWrite(pin,0);
            usleep(830);
            digitalWrite(pin,1);
            usleep(830);
        }
    }
delay(100);
		}

		if(codex!=0)
		{
			uint32_t size = 32;
	uint64_t mask = 0x00000001;
	int i;

    digitalWrite(pin,1);
    delay(9);
    digitalWrite(pin,0);
    usleep(4500);
	
   
	for(i = 0; i<size ;i++)//to detect the size of the code to be sent
	{
		if((mask & (codex >> (size-i-1))) == 0)//for logical 0
		{
			digitalWrite(pin,1);
			usleep(500);
			digitalWrite(pin,0);
			usleep(500);
		}
		else// for logical 1
		{       
			digitalWrite(pin,1);
			usleep(500);
			digitalWrite(pin,0);
			usleep(1620);
		}
	}	
delay(100);
		}
	}

}