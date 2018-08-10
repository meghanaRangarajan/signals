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
    uint64_t codec = 0x00000000;
    uint64_t codex = 0x0000;

	std::cout<<"enter the keycode: "<<std::endl;
	std::cin>>keycode;

	switch(keycode)
	{

		case 0:
        code = 0x20df08f7;
        codec = 0x10ef9b64;
        codex = 0x0fff;
        std::cout<<"key0";
        break;

		case 1:
        codex = 0x0ffe;
        code = 0x20df8877;
        codec = 0x10efa956;
        std::cout<<"key1";
        break;

        case 2:
        codex = 0x0ffd;
        code = 0x20df48b7;
        codec = 0x10ef9966;
        std::cout<<"key2";
        break;

        case 3:
        codex = 0x0ffc;
        code = 0x20dfc837;
        codec = 0x10efb946;
        std::cout<<"key3";
        break;

        case 4:
        codex = 0x0ffb;
        code = 0x20df28d7;
        codec = 0x10ef6b94;
        std::cout<<"key4";
        break;

        case 5:
        codex = 0x0ffa;
        code = 0x20dfa857;
        codec = 0x10ef5ba4;
        std::cout<<"key5";
        break;

        case 6:
        codex = 0x0ff9;
        code = 0x20df6897;
        codec = 0x10ef7b84;
        std::cout<<"key6";
        break;

        case 7:
        codex = 0x0ff8;
        code = 0x20dfe817;
        codec = 0x10ef6996;
        std::cout<<"key7";
        break;

        case 8:
        codex = 0x0ff7;
        code = 0x20df18e7;
        codec = 0x10ef59a6;
        std::cout<<"key8";
        break;

        case 9:
        codex = 0x0ff6;
        code = 0x20df9867;
        codec = 0x10ef7986;
        std::cout<<"key9";
        break; 

        case 10:
        codex = 0x0fef;
        code = 0x20df40bf;
        codec = 0x10efc13e;
        std::cout<<"vol up";
        break;

        case 11:
        codex = 0x0fee;
        code = 0x20dfc03f;
        codec = 0x10ef619e;
        std::cout<<"vol dowm";
        break;

        case 12:
        codex = 0x0ff2;
        code = 0x20df906f;
        codec = 0x10effb04;
        std::cout<<"mute";
        break;

         case 13:
         codex = 0x0fdf;
        code = 0x20df00ff;
        codec = 0x10ef01fe;
        std::cout<<"ch up";
        break;

         case 14:
         codex = 0x0fde;
        code = 0x20df807f;
        codec = 0x10ef718e;
        std::cout<<"ch down";
        break;

        case 15:
         codex = 0x0ff3;
        code = 0x20df10ef;
        codec = 0x10efeb14;
        std::cout<<"power";
        break; 

        case 16:
        codex = 0x0fdb;
        break;

        case 17:
        codex = 0x0fdd;
        code = 0x20df58a7;
        codec = 0x10efbb44;
        std::cout<<"back";
        break;

        case 18:
        codex = 0x0fdd;
        break;

        case 20:
        code = 0x20df55aa;
        std::cout<<"info";
        break; 

        case 21:
        codex = 0x0fe4;
        code = 0x20df02fd;
        codec = 0x10ef49b6;
        std::cout<<"up";
        break; 

        case 22:
        codex = 0x0fe3;
        code = 0x20df827d;
        codec = 0x10ef1be4;
        std::cout<<"down";
        break; 

        case 23:
        codex = 0x0fe5;
        code = 0x20dfe01f;
        codec = 0x10efe916;
        std::cout<<"left";
        break; 

        case 24:
        codex = 0x0fe6;
        code = 0x20df609f;
        codec = 0x10eff906;
        std::cout<<"right";
        break;

        case 25:
        codex = 0x0fda;
        code = 0x20df22dd;
        codec = 0x10efd926;
        std::cout<<"OK";
        break;

        case 26:
        codex = 0x0fc8;
        code = 0x20df4eb1;
        codec = 0x10efcb34;
        std::cout<<"red";
        break;

        case 27:
        codex = 0x0fc9;
        code = 0x20df8e71;
        codec = 0x10ef4bb4;
        std::cout<<"green";
        break;

        case 28:
        codex = 0x0fcd;
        code = 0x20dfc639;
        codec = 0x10ef8b74;
        std::cout<<"yellow";
        break;

        case 29:
        codex = 0x0fcb;
        code = 0x20df8679;
        codec = 0x10ef0bf4;
        std::cout<<"blue";
        break;

        case 36:
        codex = 0x0fc7;
        code = 0x20dfd02f;
        codec = 0x10ef817e;
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
	uint64_t code1 = code;
	uint64_t mask = 0x0fff0001;
	int i;

    digitalWrite(pin,1);
    delay(9);
    digitalWrite(pin,0);
    usleep(4500);
	
   
	for(i = 0; i<size ;i++)//to detect the size of the code to be sent
	{
		if((mask & (code1 >> (size-i-1))) == 0)//for logical 0
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
    uint32_t size = 32;
    uint64_t code2 = codec;
    uint64_t mask = 0x0fff0001;
    int i;

    digitalWrite(pin,1);
    delay(9);
    digitalWrite(pin,0);
    usleep(4500);
    
   
    for(i = 0; i<size ;i++)//to detect the size of the code to be sent
    {
        if((mask & (code2 >> (size-i-1))) == 0)//for logical 0
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

if(codex!=0)
{
    digitalWrite(pin,0);
        usleep(830);
        digitalWrite(pin,1);
        usleep(830);
 
        digitalWrite(pin,0);
        usleep(830);
        digitalWrite(pin,1);
        usleep(830);
    uint64_t code = 0x73d;
    uint64_t mask = 0x001;
    int i;
    for(i = 0; i<size ;i++)//to detect the size of the code to be sent
    {
        if((mask & (code >> i)) == 0)//for logical 0
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
}
}