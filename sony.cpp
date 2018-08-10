#include <unistd.h>
#include<iostream>
#include<wiringPi.h>
#include<stdlib.h>

int main()
{
	int pin = 0;
	wiringPiSetup () ;
	pinMode (pin, OUTPUT) ;
	int keycode;
	char function;
	uint64_t code = 0x000;
    uint64_t codec = 0x000;


	std::cout<<"enter the keycode: "<<std::endl;
	std::cin>>keycode;

	switch(keycode)
	{

		case 0:
        std::cout<<"key0";
        code = 0x910;
        
        break;

		case 1:
        code = 0x010;
        std::cout<<"key1";
        break;

        case 2:
        code = 0x810;
        std::cout<<"key2";
        break;

        case 3:
        code = 0x410;
        std::cout<<"key3";
        break;

        case 4:
        code = 0xc10;
        std::cout<<"key4";
        break;

        case 5:
        code = 0x210;
        std::cout<<"key5";
        break;

        case 6:
        code = 0xa10;
        std::cout<<"key6";
        break;

        case 7:
        code = 0x610;
        std::cout<<"key7";
        break;

        case 8:
        code = 0xe10;
        std::cout<<"key8";
        break;

        case 9:
        code = 0x110;
        std::cout<<"key9";
        break; 

        case 10:
        code = 0x490;
        std::cout<<"vol up";
        break;

        case 11:
        code = 0xc90;
        std::cout<<"vol dowm";
        break;

        case 12:
        code = 0x290;
        std::cout<<"mute";
        break;

         case 13:
        code = 0x090;
        std::cout<<"ch up";
        break;

         case 14:
        code = 0x890;
        std::cout<<"ch down";
        break;

         case 15:
        code = 0xa90;
        std::cout<<"power";
        break; 

        case 17:
        codec = 0x62e9;
        std::cout<<"power";
        break; 

        case 18:
        code = 0xc70;
        std::cout<<"exit";
        break; 

        case 21:
        code = 0x2f0;
        std::cout<<"up";
        break; 

        case 22:
        code = 0xaf0;
        std::cout<<"down";
        break; 

        case 23:
        code = 0x2d0;
        std::cout<<"left";
        break; 

        case 24:
        code = 0xcd0;
        std::cout<<"right";
        break; 

        case 25:
        code = 0xa70;
        std::cout<<"OK";
        break; 

        case 26:
        codec = 0x62e9;
        std::cout<<"power";
        break; 

        case 27:
        codec = 0x32e9;
        std::cout<<"power";
        break; 

        case 28:
        codec = 0x72e9;
        std::cout<<"power";
        break; 

        case 29:
        codec = 0x12e9;
        std::cout<<"power";
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
  
	uint32_t size = 12;
	uint64_t code1 = code;
	uint64_t mask = 0x001;
	int i;

    digitalWrite(pin,1);
    usleep(2400);
    digitalWrite(pin,0);
    usleep(550);
	
   
	for(i = 0; i<size ;i++)//to detect the size of the code to be sent
	{
		if((mask & (code1 >> (size-i-1))) == 0)//for logical 0
		{
			digitalWrite(pin,1);
			usleep(550);
			digitalWrite(pin,0);
			usleep(550);
		}
		else// for logical 1
		{       
			digitalWrite(pin,1);
			usleep(1150);
			digitalWrite(pin,0);
			usleep(550);
		}
	}	
delay(500);
}
 if (codec!=0)
 {
    uint32_t size = 16;
    uint64_t code2 = codec;
    uint64_t mask = 0x0001;
    int i;

    digitalWrite(pin,1);
    usleep(2400);
    digitalWrite(pin,0);
    usleep(550);
    
   
    for(i = 0; i<size ;i++)//to detect the size of the code to be sent
    {
        if((mask & (code2 >> (size-i-1))) == 0)//for logical 0
        {
            digitalWrite(pin,1);
            usleep(550);
            digitalWrite(pin,0);
            usleep(550);
        }
        else// for logical 1
        {       
            digitalWrite(pin,1);
            usleep(1150);
            digitalWrite(pin,0);
            usleep(550);
        }
    }   
delay(500);
 }
}
}