//nec

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
        code = 0xe0e08877;
        std::cout<<"key0";
        break;

		case 1:
        code = 0xe0e020df;
        std::cout<<"key1";
        break;

        case 2:
        code = 0xe0e08877;
        std::cout<<"key2";
        break;

        case 3:
        code = 0xe0e0609f;
        std::cout<<"key3";
        break;

        case 4:
        code = 0xe0e010ef;
        std::cout<<"key4";
        break;

        case 5:
        code = 0xe0e010ef;
        std::cout<<"key5";
        break;

        case 6:
        code = 0xe0e050af;
        std::cout<<"key6";
        break;

        case 7:
        code = 0xe0e030cf;
        std::cout<<"key7";
        break;

        case 8:
        code = 0xe0e0b04f;
        std::cout<<"key8";
        break;

        case 9:
        code = 0xe0e0708f;
        std::cout<<"key9";
        break; 

        case 10:
        code = 0xe0e0e01f;
        std::cout<<"vol up";
        break;

        case 11:
        code = 0xe0e0d02f;
        std::cout<<"vol dowm";
        break;

        case 12:
        code = 0xe0e0f00f;
        std::cout<<"mute";
        break;

         case 13:
        code = 0xe0e048b7;
        std::cout<<"ch up";
        break;

         case 14:
        code = 0xe0e008f7;
        std::cout<<"ch down";
        break;

         case 15:
        code = 0xe0e040bf;
        std::cout<<"power";
        break; 

        case 16:
        code = 0xe0e016e9;
        std::cout<<"select";
        break; 

        case 17:
        code = 0xe0e01ae5;
        std::cout<<"back";
        break;

        case 19:
        code = 0xe0e058a7;
        std::cout<<"menu";
        break; 

        case 20:
        code = 0xe0e0f807;
        std::cout<<"info";
        break; 

        case 21:
        code = 0xe0e006f9;
        std::cout<<"up";
        break; 

        case 22:
        code = 0xe0e08679;
        std::cout<<"down";
        break; 

        case 23:
        code = 0xe0e0a659;
        std::cout<<"left";
        break; 

        case 24:
        code = 0xe0e046b9;
        std::cout<<"right";
        break;

        case 25:
        code = 0xe0e016e9;
        std::cout<<"OK";
        break;

        case 26:
        code = 0xe0e036c9;
        std::cout<<"red";
        break;

        case 27:
        code = 0xe0e028d7;
        std::cout<<"green";
        break;

        case 28:
        code = 0xe0e0a857;
        std::cout<<"yellow";
        break;

        case 29:
        code = 0xe0e06897;
        std::cout<<"blue";
        break;

        default :
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
delay(100)
}
}