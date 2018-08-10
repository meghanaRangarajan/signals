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
        code = 0x40bf28d7;
        std::cout<<"key0";
        break;

		case 1:
        code = 0x40bf807f;
        std::cout<<"key1";
        break;

        case 2:
        code = 0x40bf40bf;
        std::cout<<"key2";
        break;

        case 3:
        code = 0x40bfc03f;
        std::cout<<"key3";
        break;

        case 4:
        code = 0x40bf20df;
        std::cout<<"key4";
        break;

        case 5:
        code = 0x40bfa05f;
        std::cout<<"key5";
        break;

        case 6:
        code = 0x40bf609f;
        std::cout<<"key6";
        break;

        case 7:
        code = 0x40bfe01f;
        std::cout<<"key7";
        break;

        case 8:
        code = 0x40bf10ef;
        std::cout<<"key8";
        break;

        case 9:
        code = 0x40bf906f;
        std::cout<<"key9";
        break; 

        case 10:
        codex = 0x7070c837;
        code = 0x40bf58a7;
        codec = 0x00fe7887;
        codea = 0x61a030cf;
        
        std::cout<<"vol up";
        break;

        case 11:
        codex = 0x707048b7;
        code = 0x00fefa05;
        codec = 0x00fefa05;
        codea = 0x61a0b04f;
        
        std::cout<<"vol dowm";
        break;

        case 12:
        codex = 0x707028d7;
        code = 0x40bf08f7;
        codec = 0x00fed02f;
        codea = 0x61a0708f;
    
        std::cout<<"mute";
        break;

        case 13:
        code = 0x40bfd827;
        std::cout<<"ch up";
        break;

        case 14:
        code = 0x40bff807;
        std::cout<<"ch down";
        break;

        case 15:
        codex = 0x7070d02f;
        code = 0x40bf48b7;
        codec = 0x00fe50af;
        codea = 0x61a0f00f;

        std::cout<<"power";
        break; 

        case 16:
        code = 0x40bfc837;        
        break;

        case 17:
        code = 0x40bf708f;
        std::cout<<"back";
        break;

        case 18:     
        code = 0x40bf42bd;   
        break;

        case 21: 
        codex = 0x70708877;
        codec=  0x00fe50af;     
        codea = 0x61a042bd;
        std::cout<<"up";
        break; 

        case 22: 
        codex = 0x707008f7;
        codec=  0x00fe6a95; 
        codea = 0x61a0c23d;
        std::cout<<"down";
        break; 

        case 23:      
        codex = 0x707048b7;
        codec=  0x00feda25; 
        codea = 0x61a06897;
        std::cout<<"left";
        break; 

        case 24:     
        codex = 0x7070c837;   
        codec=  0x00fe1ae5; 
        codea = 0x61a0a857;
        std::cout<<"right";
        break;

        case 25:        
        codec=  0x00fe5aa5; 
        codea = 0x61a018e7;
        std::cout<<"OK";
        break;

        case 36:      
        codex = 0x7070f00f;
        codec = 0x00feca35;
        codea = 0x61a0b847;
        code = 0x40bf28d7;
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
  
    uint32_t size = 32;
    uint64_t mask = 0x0fff0001;
    int i;

    digitalWrite(pin,1);
    usleep(4500);
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
}
}