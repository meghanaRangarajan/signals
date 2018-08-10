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
	uint64_t code = 0x00000000;
    uint64_t codec = 0x0000;


	std::cout<<"enter the keycode: "<<std::endl;
	std::cin>>keycode;

	switch(keycode)
	{
        case 10:
        code = 0x10ef00ff;
        codec = 0xf2f0d0;
        std::cout<<"vol up";
        break;

        case 11:
        code = 0x10ef20df;
        codec = 0xf2e0d1;
        std::cout<<"vol dowm";
        break;

        case 12:
        code = 0x10efd02f;
        codec = 0xf3f0c0;
        std::cout<<"mute";
        break;

         case 15:
         codec = 0xf2a0d5;
        code = 0x10efa05f;
        std::cout<<"power";
        break; 

        case 16:
        codec = 0xff400b;
        std::cout<<"select";
        break; 

        case 21:
        codec = 0xf590a6;
        code = 0x10ef609f;
        std::cout<<"up";
        break; 

        case 22:
        codec = 0xf580a7;
        code = 0x10efe01f;
        std::cout<<"down";
        break; 

        case 23:
        codec = 0xf560a9;
        code = 0x10ef827d;
        std::cout<<"left";
        break; 

        case 24:
        codec = 0xf570a8;
        code = 0x10efc23d;
        std::cout<<"right";
        break;

        case 25:
        codec = 0xff400b;
        code = 0x10ef42bd;
        std::cout<<"OK";
        break;

        case 36:
        codec = 0xfa305c;
        code =0x10ef02fd;
        std::cout<<"blue";
        break;

        default :
        exit(1);
        std::cout<<"enter correct key code";
        break;

	}
	while(1)
	{
        if(code!=0)
        {
  
	uint32_t size = 32;
	uint64_t codec = code;
	uint64_t mask = 0x00000001;
	int i;

    digitalWrite(pin,1);
    usleep(9000);
    digitalWrite(pin,0);
    usleep(4500);
	
   
	for(i = 0; i<size ;i++)//to detect the size of the code to be sent
	{
		if((mask & (codec >> (size-i-1))) == 0)//for logical 0
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

if(codec!=0)
{
    uint32_t size = 24;
    uint64_t mask = 0x000001;
    int i;

    digitalWrite(pin,1);
    delay(4);
    digitalWrite(pin,0);
    delay(4);
    
   
    for(i = 0; i<size ;i++)//to detect the size of the code to be sent
    {
        if((mask & (codec >> (size-i-1))) == 0)//for logical 0
        {
            digitalWrite(pin,1);
            usleep(500);
            digitalWrite(pin,0);
            delay(1);
        }
        else// for logical 1
        {       
            digitalWrite(pin,1);
            usleep(500);
            digitalWrite(pin,0);
            delay(2);
        }
    }   
delay(100);
}
}
}