//xiomi

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
        case 10:
        code = 0x404015ea;
        std::cout<<"vol up";
        break;

        case 11:
        code = 0x40401ce3;
        std::cout<<"vol dowm";
        break;

        case 12:
        code = 0x4040bf40;
        std::cout<<"mute";
        break;

         case 15:
        code = 0x40400af5;
        std::cout<<"power";
        break; 

        case 17:
        code = 0x404037c8;
        std::cout<<"back";
        break;

        case 19:
        code = 0x404040bf;
        std::cout<<"back";
        break; 

        case 21:
        code = 0x40400bf4;
        std::cout<<"up";
        break; 

        case 22:
        code = 0x40400ef1;
        std::cout<<"down";
        break; 

        case 23:
        code = 0x404010ef;
        std::cout<<"left";
        break; 

        case 24:
        code = 0x404011ee;
        std::cout<<"right";
        break;

        case 25:
        code = 0x40400df2;
        std::cout<<"OK";
        break;

        case 36:
        code = 0x404016e9;
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
	uint64_t mask = 0x00000001;
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
}



