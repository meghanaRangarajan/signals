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
        code = 0x414242BD;
        std::cout<<"key0";
        break;

        case 1:
        code = 0x420241FD;
        std::cout<<"key1";
        break;

        case 2:
        code = 0x410242FD;
        std::cout<<"key2";
        break;

        case 3:
        code = 0x430240FD;
        std::cout<<"key3";
        break;

        case 4:
        code = 0x4082437D;
        std::cout<<"key4";
        break;

        case 5:
        code = 0x4282417D;
        std::cout<<"key5";
        break;

        case 6:
        code = 0x4182427D;
        std::cout<<"key6";
        break;

        case 7:
        code = 0x4382407D;
        std::cout<<"key7";
        break;

        case 8:
        code = 0x404243BD;
        std::cout<<"key8";
        break;

        case 9:
        code = 0x424241BD;
        std::cout<<"key9";
        break; 

        case 10:
        code = 0x40A2435D;
        std::cout<<"vol up";
        break;

        case 11:
        code = 0x42A2415D;
        std::cout<<"vol dowm";
        break;

        case 12:
        code = 0x43A2405D;
        std::cout<<"mute";
        break;

         case 13:
        code = 0x422241DD;
        std::cout<<"ch up";
        break;

         case 14:
        code = 0x412242DD;
        std::cout<<"ch down";
        break;

         case 15:
        code = 0x41A2425D;
        std::cout<<"power";
        break; 

         case 16:
        code = 0x412A42D5;
        std::cout<<"power";
        break; 

        case 17:
        code = 0x0392406d;
        std::cout<<"back";
        break;

        case 18:
        code = 0x42BE4141;
        std::cout<<"back";
        break; 

        case 21:
        code = 0x43AA4055;
        std::cout<<"up";
        break; 

        case 22:
        code = 0x401243ED;
        std::cout<<"down";
        break; 

        case 23:
        code = 0x43AE4051;
        std::cout<<"left";
        break; 

        case 24:
        code = 0x406E4391;
        std::cout<<"right";
        break;

        case 25:
        code = 0x412A42D5;
        std::cout<<"OK";
        break;

        case 26:
        code = 0x404A43B5;
        std::cout<<"red";
        break;

        case 27:
        code = 0x424A41B5;
        std::cout<<"green";
        break;

        case 28:
        code = 0x414A42B5;
        std::cout<<"yellow";
        break;

        case 29:
        code = 0x434A40B5;
        std::cout<<"blue";
        break;

        case 36:
        code = 0x432240DD;
        std::cout<<"blue";
        break;

        default :
        exit(1);
        std::cout<<"enter correct key code";
        break;

    }

while(1)
{
	uint64_t mask = 0x00000001;
    int i;
    int size = 32;
		if((mask & (code >>(size-i-1))) == 0)//for logical 0
		{
			digitalWrite(pin,0);
        		usleep(300);
        		digitalWrite(pin,1);
        		usleep(650);
			
		}
		else// for logical 1
		{    
			digitalWrite(pin,1);
        		usleep(300);
        		digitalWrite(pin,0);
        		usleep(1650);
		}

delay(100);
}
}



