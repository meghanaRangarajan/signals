//rc6
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
	uint64_t code = 0x00000;
    uint64_t codec = 0x00000;

	std::cout<<"enter the keycode: "<<std::endl;
	std::cin>>keycode;

	switch(keycode)
	{

		case 0:
        code = 0x00000;
        codec = 0x0fff;
        std::cout<<"key0";
        break;

		case 1:
        code = 0x00001;
        codec = 0x0ffe;
        std::cout<<"key1";
        break;

        case 2:
        code = 0x00002;
        codec = 0x0ffd;
        std::cout<<"key2";
        break;

        case 3:
        code = 0x00003;
        codec = 0x0ffc;
        std::cout<<"key3";
        break;

        case 4:
        code = 0x00004;
        codec = 0x0ffb;
        std::cout<<"key4";
        break;

        case 5:
        code = 0x00005;
        codec = 0x0ffa;
        std::cout<<"key5";
        break;

        case 6:
        code = 0x00006;
        codec = 0x0ff9;
        std::cout<<"key6";
        break;

        case 7:
        code = 0x00007;
        codec = 0x0ff8;
        std::cout<<"key7";
        break;

        case 8:
        code = 0x00008;
        codec = 0x0ff7;
        std::cout<<"key8";
        break;

        case 9:
        code = 0x00009;
        codec = 0x0ff6;
        std::cout<<"key9";
        break; 

        case 10:
        code = 0x00010;
        codec = 0x0fef;
        std::cout<<"vol up";
        break;

        case 11:
        code = 0x00011;
        codec = 0x0fee;
        std::cout<<"vol dowm";
        break;

        case 12:
        code = 0x0000d;
        codec = 0x0fe4;
        std::cout<<"mute";
        break;

         case 13:
        code = 0x00020;
        codec = 0x0fdf;
        std::cout<<"ch up";
        break;

         case 14:
        code = 0x00021;
        codec = 0x0fde;
        std::cout<<"ch down";
        break;

         case 15:
        code = 0x0000c;
        codec = 0x0ff3;
        std::cout<<"power";
        break; 

        case 16:
        code = 0x0005c;
        std::cout<<"select";
        break; 

        case 17:
        code = 0x0000a;
        std::cout<<"back";
        break; 

        case 26:
        code = 0x0006d;
        std::cout<<"red";
        break; 

        case 29:
        code = 0x00070;
        std::cout<<"blue";
        break;

        case 27:
        code = 0x0006e;
        std::cout<<"green";
        break; 

        case 28:
        code = 0x0006f;
        std::cout<<"yellow";
        break; 

        case 21:
        code = 0x00058;
        std::cout<<"up";
        break; 

        case 22:
        code = 0x00059;
        std::cout<<"down";
        break; 

        case 23:
        code = 0x0005a;
        std::cout<<"left";
        break; 

        case 24:
        code = 0x0005b;
        std::cout<<"right";
        break; 

        case 25:
        code = 0x0005c;
        std::cout<<"OK";
        break; 

        case 20:
        code = 0x0000f;
        std::cout<<"info";
        break;

        case 36:
        code = 0x00038;
        codec = 0x0fc7;
        std::cout<<"source";
        break; 

        case 37:
        code = 0x00040;
        std::cout<<"options";
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
        digitalWrite(pin,1);
        usleep(2600);
        digitalWrite(pin,0);
        usleep(830);

	uint64_t mask = 0x00001;
	int size = 20;
int i;
int a;
int logic;
	for(i = 0; i<size ;i++)//to detect the size of the code to be sent
	{
		a = (size-i-1);
		if(a != 16)
{
		if((mask & (code >>(size-i-1))) == 0)//for logical 0
		{
			digitalWrite(pin,0);
        		usleep(380);
        		digitalWrite(pin,1);
        		usleep(380);
			
		}
		else// for logical 1
		{    
			digitalWrite(pin,1);
        		usleep(380);
        		digitalWrite(pin,0);
        		usleep(380);
		}
}
		
		else
{
		if((mask & (code >>(size-i-1))) == 0)//for logical 0
		{
			digitalWrite(pin,0);
        		usleep(830);
        		digitalWrite(pin,1);
        		usleep(830);
			
		}
		else// for logical 1
		{    
			digitalWrite(pin,1);
        		usleep(830);
        		digitalWrite(pin,0);
        		usleep(830);
		}
}
	}
digitalWrite(pin,0);
delay(89);
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
        int size = 16;
    uint64_t mask = 0x0001;
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
delay(89);
}
}
}
