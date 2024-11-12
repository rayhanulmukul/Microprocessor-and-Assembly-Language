/*
#define RCC_BASE 0x40001000
#define GPIO_BASE 0x40011000
#define TIM2_BASE 0x40000000

#define RCC_APB2ENR (*(volatile unsigned int*)(RCC_BASE + 0x18))
#define GPIOC_CRH (*(volatile unsigned int*)(GPIO_BASE + 0x04))
#define GPIOC_ODR (*(volatile unsigned int*)(GPIO_BASE + 0x0C))
	
#define RCC_APB1ENR (*(volatile unsigned int*)(RCC_BASE + 0x1C))
#define TIM2_PSC (*(volatile unsigned int*)(TIM2_BASE + 0x28))
#define TIM2_ARR (*(volatile unsigned int*)(TIM2_BASE + 0x2C))
#define TIM2_CR1 (*(volatile unsigned int*)(TIM2_BASE + 0x00))
#define TIM2_SR (*(volatile unsigned int*)(TIM2_BASE + 0x10))

void delay(int ms){
	TIM2_PSC = 36000 - 1;
	TIM2_ARR = 2 * ms - 1;
	TIM2_SR &= ~(1 << 0);
	TIM2_CR1 |= (1 << 0);
	while(!(TIM2_SR & (1 << 0)));
	
	TIM2_CR1 &= ~(1 << 0);
}
int main(){
	RCC_APB2ENR |= (1 << 4);
	RCC_APB1ENR |= (1 << 0); 
	GPIOC_CRH &= ~(15 << 20);
	GPIOC_CRH |= (2 << 20);
	
	while(1){
		GPIOC_ODR |= (1 << 13);
		//for(int i = 0; i <= 100000; i++);
		delay(1000);
		
		GPIOC_ODR &= ~(1 << 13);
		//for(int i = 0; i <= 100000; i++);
		delay(1000);
	}
}
*/




#define RCC_BASE 0x40021000
#define GPIOC_BASE 0x40011000
#define TIM3_BASE 0x40000400

#define RCC_CFGR (*(volatile unsigned int *) (RCC_BASE + 0x04))
#define RCC_APB2ENR (*(volatile unsigned int *) (RCC_BASE + 0x18))
	
#define GPIOC_CRH (*(volatile unsigned int *) (GPIOC_BASE + 0x04))
#define GPIOC_ODR (*(volatile unsigned int *) (GPIOC_BASE + 0x0C))

#define RCC_APB1ENR (*(volatile unsigned int *) (RCC_BASE + 0x1C))
#define TIM3_PSC (*(volatile unsigned int *) (TIM3_BASE + 0x28))
#define TIM3_ARR (*(volatile unsigned int *) (TIM3_BASE + 0x2C))
#define TIM3_CR1 (*(volatile unsigned int *) (TIM3_BASE + 0x00))
#define TIM3_SR (*(volatile unsigned int *) (TIM3_BASE + 0x10))		

void delay(int ms){
	TIM3_PSC = 8000 - 1;
	TIM3_ARR = 555ms - 1;
	TIM3_SR &= ~(1 << 0);
	TIM3_CR1 |= (1 << 0);
	while(!(TIM3_SR & (1 << 0)));
	TIM3_CR1 &= ~(1 << 0);
}
int main(void){
	RCC_CFGR &= ~(3 << 0); // HSI 8 MHz
	while((RCC_CFGR & (3 << 2)) != 0);
	
	RCC_APB2ENR |= (1 << 4);
	RCC_APB1ENR |= (1 << 1);
	GPIOC_CRH &= ~(15 << 20);
	GPIOC_CRH |= (1 << 21);
	
	while(1){
		GPIOC_ODR |= (1 << 13);
		//for(int i = 0; i < 100000; i++);
		delay(500);
		
		GPIOC_ODR &= ~(1 << 13);
		//for(int i = 0; i < 100000; i++);
		delay(1300);
	}
	
}



















