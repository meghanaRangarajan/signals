
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
	uint64_t code = 0x000000000000;
	uint64_t codec = 0x000000000000;
	uint64_t codex = 0x00000000;

	std::cout<<"enter the keycode: "<<std::endl;
	std::cin>>keycode;

	switch(keycode)
	{

		case 0:
        code = 0x400401009899;
        codec = 0x400401009899;
        std::cout<<"key0";
        break;

		case 1:
		codec = 0x400401000809;
        code = 0x400401000809;
        std::cout<<"key1";
        break;

        case 2:
        codec = 0x400401008889;
        code = 0x400401008889;
        std::cout<<"key2";
        break;

        case 3:
        code = 0x400401004849;
        codec = 0x400401004849;
        std::cout<<"key3";
        break;

        case 4:
        codec = 0x40040100c8c9;
        code = 0x40040100c8c9;
        std::cout<<"key4";
        break;

        case 5:
        codec = 0x400401002829;
        code = 0x400401002829;
        std::cout<<"key5";
        break;

        case 6:
        codec = 0x40040100a8a9;
        code = 0x40040100a8a9;
        std::cout<<"key6";
        break;

        case 7:
        codec = 0x400401006869;
        code = 0x400401006869;
        std::cout<<"key7";
        break;

        case 8:
        codec = 0x40040100e8e9;
        code = 0x40040100e8e9;
        std::cout<<"key8";
        break;

        case 9:
        codec = 0x400401001819;
        code = 0x400401001819;
        std::cout<<"key9";
        break; 

        case 10:
        code = 0x400401000405;
        codec = 0x400401000405;
        codex = 0x707028d7;
        std::cout<<"vol up";
        break;

        case 11:
        code = 0x400401008485;
        codec = 0x400401008485;
        codex = 0x7070a857;
        std::cout<<"vol dowm";
        break;

        case 12:
        codex = 0x7070b04f;
        code = 0x400401004c4d;
        codec = 0x400401004c4d;
        std::cout<<"mute";
        break;

         case 13:
        code = 0x400401002c2d;
        codec = 0x400401002c2d;
        std::cout<<"ch up";
        break;

         case 14:
        code = 0x40040100acad;
        codec = 0x40040100acad;
        std::cout<<"ch down";
        break;

         case 15:
         codex = 0x707030cf;
        code = 0x40040100bcbd;
        codec = 0x40040100bcbd;
        std::cout<<"power";
        break; 

        case 16:
        codex = 0x707058a7;
        code = 0x400401009293;
        std::cout<<"back";
        break;

        case 17:
        codex = 0x7070d02f;
        codec = 0x400401002b2a;
        std::cout<<"red";
        break;

        case 18:
        codex = 0x7070ad52;
        codec = 0x40040100cbca;
        std::cout<<"red";
        break;

        case 19:
        code = 0x400401004a4b;
        std::cout<<"back";
        break;

        case 21:
        codex = 0x707042bd;
        code = 0x400401002c2d;
        codec = 0x400401005253;
        std::cout<<"up";
        break; 

        case 22:
        codex = 0x7070c23d;
        code = 0x40040100acad;
        codec = 0x40040100d2d3;
        std::cout<<"down";
        break; 

        case 23:
        codex = 0x707022dd;
        code = 0x400401008485;
        codec = 0x400401007273;
        std::cout<<"left";
        break; 

        case 24:
        codex = 0x7070a25d;
        code = 0x400401000405;
        codec = 0x40040100f2f3;
        std::cout<<"right";
        break;

        case 25:
        codex = 0x7070629d;
        code = 0x400401003839;
        codec = 0x400401009293;
        std::cout<<"OK";
        break;

        case 26:
        codec = 0x400401000e0f;
        std::cout<<"red";
        break;

        case 27:
        codec = 0x400401008e8f;
        std::cout<<"green";
        break;

        case 28:
        codec = 0x400401004e4f;
        std::cout<<"yellow";
        break;

        case 29:
        codec = 0x40040100cecf;
        std::cout<<"blue";
        break;

        case 36:
        codex = 0x7070f00f;
        code = 0x40040100a0a1;
        codec = 0x40040100a0a1;
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
		uint32_t size = 48;
        digitalWrite(pin,1);
        usleep(3360);
        digitalWrite(pin,0);
        usleep(3360);

	uint64_t mask = 0x000000000001;
	int i;
	for(i = 0; i<size ;i++)//to detect the size of the code to be sent
	{
		if((mask & (code >> i)) == 0)//for logical 0
		{
			digitalWrite(pin,1);
			usleep(800);
			digitalWrite(pin,0);
			usleep(800);
		}
		else// for logical 1
		{       
			digitalWrite(pin,1);
			usleep(800);
			digitalWrite(pin,0);
			usleep(2500);
		}
	}
delay(89);
}

if(codec!=0)
	{
		uint32_t size = 48;
        digitalWrite(pin,1);
        usleep(3360);
        digitalWrite(pin,0);
        usleep(3360);

	uint64_t mask = 0x000000000001;
	int i;
	for(i = 0; i<size ;i++)//to detect the size of the code to be sent
	{
		if((mask & (codec >> i)) == 0)//for logical 0
		{
			digitalWrite(pin,1);
			usleep(800);
			digitalWrite(pin,0);
			usleep(800);
		}
		else// for logical 1
		{       
			digitalWrite(pin,1);
			usleep(800);
			digitalWrite(pin,0);
			usleep(2500);
		}
	}
delay(89);
}

if(codex!=0)
{
	uint32_t size = 32;
	uint64_t code1 = codex;
	uint64_t mask = 0x00000001;
	int i;

    digitalWrite(pin,1);
    usleep(4500);
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
delay(89);
}
}
}


