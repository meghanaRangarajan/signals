//rc6
#include <unistd.h>
#include<iostream>
#include<wiringPi.h>

int main()
{
	int pin = 0;
	uint32_t size = 20;
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
        code = 0x00000;
        std::cout<<"key0";
        break;

		case 1:
        code = 0x00001;
        std::cout<<"key1";
        break;

        case 2:
        code = 0x00002;
        std::cout<<"key2";
        break;

        case 3:
        code = 0x00003;
        std::cout<<"key3";
        break;

        case 4:
        code = 0x00004;
        std::cout<<"key4";
        break;

        case 5:
        code = 0x00005;
        std::cout<<"key5";
        break;

        case 6:
        code = 0x00006;
        std::cout<<"key6";
        break;

        case 7:
        code = 0x00007;
        std::cout<<"key7";
        break;

        case 8:
        code = 0x00008;
        std::cout<<"key8";
        break;

        case 9:
        code = 0x00009;
        std::cout<<"key9";
        break; 

        case 10:
        code = 0x00010;
        std::cout<<"vol up";
        break;

        case 11:
        code = 0x00011;
        std::cout<<"vol dowm";
        break;

        case 12:
        code = 0x0000d;
        std::cout<<"mute";
        break;

         case 13:
        code = 0x00020;
        std::cout<<"ch up";
        brea5c

         case 14:
        code = 0x00021;
        std::cout<<"ch down";
        break;

         case 15:
        code = 0x0000c;
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
        std::cout<<"source";
        break; 

        case 37:
        code = 0x00040;
        std::cout<<"options";
        break;   
     
        default :
        std::cout<<"enter correct key code";
        break;

	}

while(1)
{
        digitalWrite(pin,1);
        usleep(2600);
        digitalWrite(pin,0);
        usleep(830);

	uint64_t mask = 0x00001;
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
delay(100);
}
}



