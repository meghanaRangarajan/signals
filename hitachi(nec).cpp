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
	uint64_t code;

	std::cout<<"enter the keycode: "<<std::endl;
	std::cin>>keycode;

	switch(keycode)
	{

		case 0:
        code = 0x0af530cf;
        std::cout<<"key0";
        break;

		case 1:
        code = 0x0af5b04f;
        std::cout<<"key1";
        break;

        case 2:
        code = 0x0af5708f;
        std::cout<<"key2";
        break;

        case 3:
        code = 0x0af5f00f;
        std::cout<<"key3";
        break;

        case 4:
        code = 0x0af538c7;
        std::cout<<"key4";
        break;

        case 5:
        code = 0x0af5b847;
        std::cout<<"key5";
        break;

        case 6:
        code = 0x0af57887;
        std::cout<<"key6";
        break;

        case 7:
        code = 0x0af5f807;
        std::cout<<"key7";
        break;

        case 8:
        code = 0x0af520df;
        std::cout<<"key8";
        break;

        case 9:
        code = 0x0af5a05f;
        std::cout<<"key9";
        break; 

        case 10:
        code = 0x0af548b7;
        std::cout<<"vol up";
        break;

        case 11:
        code = 0x0af5a857;
        std::cout<<"vol dowm";
        break;

        case 12:
        code = 0x0af5d02f;
        std::cout<<"mute";
        break;

         case 13:
        code = 0x0af59867;
        std::cout<<"ch up";
        break;

         case 14:
        code = 0x0af518e7;
        std::cout<<"ch down";
        break;

         case 15:
        code = 0x0af5e817;
        std::cout<<"power";
        break; 

        case 17:
        code = 0x0af550af;
        std::cout<<"back";
        break;

        case 20:
        code = 0x0af508f7;
        std::cout<<"info";
        break; 

        case 21:
        code = 0x0af50ef1;
        std::cout<<"up";
        break; 

        case 22:
        code = 0x0af58e71;
        std::cout<<"down";
        break; 

        case 23:
        code = 0x0af5ce31;
        std::cout<<"left";
        break; 

        case 24:
        code = 0x0af54eb1;
        std::cout<<"right";
        break;

        case 25:
        code = 0x0af5748b;
        std::cout<<"OK";
        break;

        case 26:
        code = 0x0af532cd;
        std::cout<<"red";
        break;

        case 27:
        code = 0x0af5a25d;
        std::cout<<"green";
        break;

        case 28:
        code = 0x0af5629d;
        std::cout<<"yellow";
        break;

        case 29:
        code = 0x0af5e21d;
        std::cout<<"blue";
        break;

        case 36:
        code = 0x0af5906f;
        std::cout<<"blue";
        break;

        default :
        exit(1);
        std::cout<<"enter correct key code";
        break;

	}
	while(1)
	{
  
	uint32_t size = 32;
	uint64_t codec = code;
	uint64_t mask = 0x00000001;
	int i;

    digitalWrite(pin,1);
    delay(9);
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
}