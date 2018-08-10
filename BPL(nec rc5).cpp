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
    

	std::cout<<"enter the keycode: "<<std::endl;
	std::cin>>keycode;

	switch(keycode)
	{

		case 0:
        codec = 0x1000807f;
        code = 0x1c0000ff;
        codex = 0x7ff;
        codea = 0x10EF9B64;
        std::cout<<"key0";
        break;

		case 1:
        codec = 0x1000c03f;
        codex = 0x7fe;
        code = 0x00fd807f;
        codea = 0x10EFA956;
        std::cout<<"key1";
        break;

        case 2:
        codec = 0x100040bf;
        codex = 0x7fd;
        code = 0x1c0040bf;
        codea = 0x10EF9966;
        std::cout<<"key2";
        break;

        case 3:
        codec = 0x1000a05f;
        codex = 0x7fc;
        code = 0x1c00c03f;
        codea = 0x10EFB946;
        std::cout<<"key3";
        break;

        case 4:
        codec = 0x1000e01f;
        codex = 0x7fb;
        code = 0x1c0020df;
        codea = 0x10EF6B94;
        std::cout<<"key4";
        break;

        case 5:
        codec = 0x1000609f;
        codex = 0x7fa;
        code = 0x00fda05f;
        codea = 0x10EF5BA4;
        std::cout<<"key5";
        break;

        case 6:
        codec = 0x1000906f;
        codex = 0x7f9;
        code = 0x1c00609f;
        codea = 0x10EF7B84;
        std::cout<<"key6";
        break;

        case 7:
        codec = 0x1000d02f;
        codex = 0x7f8;
        code = 0x1c00e01f;
        codea = 0x10EF6996;
        std::cout<<"key7";
        break;

        case 8:
        codec = 0x100050af;
        codex = 0x7f7;
        code = 0x1c0010ef;
        codea = 0x10EF59A6;
        std::cout<<"key8";
        break;

        case 9:
        codec = 0x1000f00f;
        codex = 0x7f6;
        code = 0x1c00906f;
        codea = 0x10EF7986;
        std::cout<<"key9";
        break; 

        case 10:
        codex = 0x7ef;
        code = 0x1c006897;
        codec = 0x1000c837;
        codea = 0x10EFC13E;
        
        std::cout<<"vol up";
        break;

        case 11:
        codex = 0x7ee;
        code = 0x1c00e817;
        codec = 0x1000e817;
        codea = 0x10EF619E;
        
        std::cout<<"vol dowm";
        break;

        case 12:
        codex = 0x7f2;
        code = 0x1c0028d7;
        codec = 0x100000ff;
        codea = 0x10EFFB04;
    
        std::cout<<"mute";
        break;

        case 13:
        codec = 0x100048b7;
        codex = 0x7df;
        code = 0x1c0030cf;
        codea = 0x10EF01FE;
        std::cout<<"ch up";
        break;

        case 14:
        codec = 0x10006897;
        codex = 0xfde;
        code = 0x1c00b04f;
        codea = 0x10EF718E;
        std::cout<<"ch down";
        break;

        case 15:
        codex = 0x7f3;
        code = 0x1c0038c7;
        codec = 0x10007887;
        codea = 0x10EFEB14;

        std::cout<<"power";
        break; 

        case 16:
        code = 0x1c0018e7;        
        codex = 0x7da;
        codea = 0x10EFD926;
        break;

        case 17:
        code = 0x1c00926d;
        codec = 0x100008f7;
        codex = 0x7dd;
        std::cout<<"back";
        break;

        case 18:        
        codea = 0x10EF3BC4;
        break;

        case 19:
        codea = 0x10EF2BD4;
        std::cout<<"info";
        break; 

        case 21:       
        codea = 0x10EF49B6;
        std::cout<<"up";
        break; 

        case 22:     
        codea = 0x10EF1BE4;
        std::cout<<"down";
        break; 

        case 23:      
        codea = 0x10EFE916;
        std::cout<<"left";
        break; 

        case 24:        
        codea = 0x10EFF906;
        std::cout<<"right";
        break;

        case 25:        
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
  
    uint32_t size = 32;
    uint64_t mask = 0x0fff0001;
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
    
    uint64_t mask = 0x0001;
    int i;
    int size = 16;
    for(i = 0; i<size ;i++)//to detect the size of the code to be sent
    {
        if((mask & (codex >> i)) == 0)//for logical 0
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



}
}