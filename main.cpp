#include "mbed.h"

SPI spi2(PC_3, PC_2, PD_3);
DigitalOut CS_OUT(PC_13, 1);
DigitalOut CS1(PG_7, 1);

int main()
{

	thread_sleep_for(1000);
	spi2.frequency(10000000);
	
	
	
	printf(" \033[32m Testing SPI2 peripheral for mbed-os PR \033[0m\n\r");
	

	char setup_data[3];
	char recieve_buffer[3];
	setup_data[0] = 0x40;
	setup_data[1] = 0x0A;
	setup_data[2] = 0x2A;
	
	CS1.write(0);
	spi2.write(setup_data, 3, nullptr, 0);
	CS1.write(1);
	wait_us(1000);


	char read_porta[3];
	read_porta[0] = 0x41;
	read_porta[1] = 0x12;
	read_porta[2] = 0xFF;
	
	

		CS1.write(0); //mbed::DigitalOut
		spi2.write(read_porta, 3, recieve_buffer, 3); //mbed::SPI
		CS1.write(1); //mbed::DigitalOut
//	wait_us(100);
		printf("SPI 2 DATA READ 0x%X 0x%X 0x%X\n\r", recieve_buffer[0], recieve_buffer[1], recieve_buffer[2]);
		while(recieve_buffer[2] != 0x01)
		{
			CS1.write(0);
			spi2.write(setup_data, 3, nullptr, 0);
			CS1.write(1);
			wait_us(100); //100 uS waits between data packets make it easier to trigger segmented memory on an oscilloscope. 
			CS1.write(0); //mbed::DigitalOut
			spi2.write(read_porta, 3, recieve_buffer, 3); //mbed::SPI
			CS1.write(1); //mbed::DigitalOut
			printf("SPI 2 DATA READ again 0x%X 0x%X 0x%X\n\r", recieve_buffer[0], recieve_buffer[1], recieve_buffer[2]);
			wait_us(100);
			CS1.write(0); //mbed::DigitalOut
			spi2.write(read_porta, 3, recieve_buffer, 3); //mbed::SPI
			CS1.write(1); //mbed::DigitalOut
			printf("SPI 2 DATA READ again 0x%X 0x%X 0x%X\n\r", recieve_buffer[0], recieve_buffer[1], recieve_buffer[2]);
			wait_us(100);
		}
		thread_sleep_for(100);
//	}
	return 0;
}
