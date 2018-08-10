//vu

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
    uint64_t codea = 0x00000000;
    uint64_t codeb = 0x000000;

	std::cout<<"enter the keycode: "<<std::endl;
	std::cin>>keycode;

	switch(keycode)
	{

		case 0:
        code = 0x00fd00ff;
        codex = 0x00fd00ff;
        codea = 0x10EF9B64;
        std::cout<<"key0";
        break;

		case 1:
        codex = 0x00fd807f;
        code = 0x00fd807f;
        codea = 0x10EFA956;
        std::cout<<"key1";
        break;

        case 2:
        codex = 0x00fd40bf;
        code = 0x00fd40bf;
        codea = 0x10EF9966;
        std::cout<<"key2";
        break;

        case 3:
        codex = 0x00fdc03f;
        code = 0x00fdc03f;
        codea = 0x10EFB946;
        std::cout<<"key3";
        break;

        case 4:
        codex = 0x00fd20df;
        code = 0x00fd20df;
        codea = 0x10EF6B94;
        std::cout<<"key4";
        break;

        case 5:
        codex = 0x00fda05f;
        code = 0x00fda05f;
        codea = 0x10EF5BA4;
        std::cout<<"key5";
        break;

        case 6:
        codex = 0x00fd609f;
        code = 0x00fd609f;
        codea = 0x10EF7B84;
        std::cout<<"key6";
        break;

        case 7:
        codex = 0x00fde01f;
        code = 0x00fde01f;
        codea = 0x10EF6996;
        std::cout<<"key7";
        break;

        case 8:
        codex = 0x00fd10ef;
        code = 0x00fd10ef;
        codea = 0x10EF59A6;
        std::cout<<"key8";
        break;

        case 9:
        codex = 0x00fd906f;
        code = 0x00fd906f;
        codea = 0x10EF7986;
        std::cout<<"key9";
        break; 

        case 10:
        codex = 0x00fd18e7;
        code = 0x00fd22dd;
        codec = 0x0fef;
        codea = 0x10EFC13E;
        codeb = 0x12fed0;
        std::cout<<"vol up";
        break;

        case 11:
        codex = 0x00fd9867;
        code = 0x00fdc23d;
        codec = 0x0fee;
        codea = 0x10EF619E;
        codeb = 0x12eed1;
        std::cout<<"vol dowm";
        break;

        case 12:
        codex = 0x00fd52ad;
        code = 0x00fd708f;
        codec = 0x0ff2;
        codea = 0x10EFFB04;
        codeb = 0x13fec0;
        std::cout<<"mute";
        break;

         case 13:
        codex = 0x00fd6897;
        code = 0x00fd52ad;
        codea = 0x10EF01FE;
        std::cout<<"ch up";
        break;

         case 14:
        codex = 0x00fde817;
        code = 0x00fdd22d;
        codea = 0x10EF718E;
        std::cout<<"ch down";
        break;

        case 15:
        codex = 0x00fdb04f;
        code = 0x00fdb04f;
        codec = 0x0ff3;
        codea = 0x10EFEB14;
        codeb = 0x12aed5;
        std::cout<<"power";
        break; 

        case 16:
        codec = 0x0fda;
        codex = 0x00fdf00f;
        codea = 0x10EFD926;
        break;

        case 17:
        codec = 0x0fdd;
        codex = 0x00fdd02f;
        std::cout<<"back";
        break;

        case 18:
        codec = 0x0fe0;
        codex = 0x00fdd02f;
        codea = 0x10EF3BC4;
        break;

        case 19:
        code = 0x00fd28d7;
        codex = 0x00fdd22d;
        codea = 0x10EF2BD4;
        std::cout<<"info";
        break; 

        case 21:
        codex = 0x00fd6897;
        code = 0x00fd6897;
        codec = 0x0fd0;
        codea = 0x10EF49B6;
        std::cout<<"up";
        break; 

        case 22:
        codex = 0x00fde817;
        code = 0x00fde817;
        codec = 0x0fcf;
        codea = 0x10EF1BE4;
        std::cout<<"down";
        break; 

        case 23:
        codex = 0x00fd9867;
        code = 0x00fd9867;
        codec = 0x0fce;
        codea = 0x10EFE916;
        std::cout<<"left";
        break; 

        case 24:
        codex = 0x00fd18e7;
        code = 0x00fd18e7;
        codec = 0x0fcc;
        codea = 0x10EFF906;
        std::cout<<"right";
        break;

        case 25:
        codex = 0x00fda857;
        code = 0x00fda857;
        codec = 0x0fe4;
        codea = 0x10EFD926;
        std::cout<<"OK";
        break;

        case 26:
        codea = 0x10EFCB34; 
        std::cout<<"red";
        break;

        case 27:
        codea = 0x10EF4BB4;    
        std::cout<<"green";
        break;

        case 28:               
        codea = 0x10EF8B74;
        std::cout<<"yellow";
        break;

        case 29:         
        codea = 0x10EF0BF4;
        std::cout<<"blue";
        break;

        case 36:
        codex = 0x00fd48b7;
        code = 0x00fd48b7;
        codec = 0x0fc7;
        codea = 0x10EFC33C;
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
	uint64_t mask = 0x0fff0001;
	int i;

    digitalWrite(pin,1);
    delay(9);
    digitalWrite(pin,0);
    usleep(4500);
	
   
	for(i = 0; i<size ;i++)//to detect the size of the code to be sent
	{
		if((mask & (code >> (size-i-1))) == 0)//for logical 0
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
    digitalWrite(pin,0);
        usleep(830);
        digitalWrite(pin,1);
        usleep(830);
 
        digitalWrite(pin,0);
        usleep(830);
        digitalWrite(pin,1);
        usleep(830);
    
    uint64_t mask = 0x0001;
    int i;
    int size = 16;
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

if(codea!=0)
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
        if((mask & (codea >> (size-i-1))) == 0)//for logical 0
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

if(codeb!=0)
{
	uint32_t size = 24;
	uint64_t mask = 0x00000001;
	int i;

    digitalWrite(pin,1);
    delay(4);
    digitalWrite(pin,0);
    delay(4);
	
   
	for(i = 0; i<size ;i++)//to detect the size of the code to be sent
	{
		if((mask & (codeb >> (size-i-1))) == 0)//for logical 0
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