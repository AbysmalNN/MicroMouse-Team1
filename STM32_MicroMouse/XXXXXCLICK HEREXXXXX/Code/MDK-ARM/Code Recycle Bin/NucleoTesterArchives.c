
/*
void GPIO_Tester(void) {
		GPIO LED1 = initIO(PA9,OUTPUT);
		GPIO LED2 = initIO(PA10,OUTPUT);
		digitalWrite(LED1, HIGH);
		digitalWrite(LED2, HIGH);
}

void SysClock_Tester() {
		SysTime_Init();
		GPIO LED1 = initIO(PA9,OUTPUT);
		GPIO LED2 = initIO(PA10,OUTPUT);
		while(1) {
				digitalWrite(LED1, HIGH);
				delay(100);
				digitalWrite(LED1, LOW);
				delay(100);
				digitalWrite(LED2, HIGH);
				delay(100);
				digitalWrite(LED2, LOW);
				delay(100);
		}
}
void PWM_Tester(void) {
			SysTime_Init();
//ADVTIM Testing
			TIM pwm1 = initIO_TIM(TIMER1, PA8, Ch1);
			TIM pwm2 = initIO_TIM(TIMER1, PA9, Ch2);
//		TIM pwm1 = initIO_TIM(TIMER8, PC6, Ch1);
//	  TIM pwm2 = initIO_TIM(TIMER8, PC7, Ch2);
//NORTIM Testing	
//		TIM pwm1 = initIO_TIM(TIMER2, PA0, Ch1);
//	  TIM pwm2 = initIO_TIM(TIMER2, PA1, Ch2);
	
//		TIM pwm1 = initIO_TIM(TIMER3, PA6, Ch1);
//	  TIM pwm2 = initIO_TIM(TIMER3, PA7, Ch2);
	
//	  TIM pwm1 = initIO_TIM(TIMER4, PB6, Ch1);
//	  TIM pwm2 = initIO_TIM(TIMER4, PB7, Ch2);

//		TIM pwm1 = initIO_TIM(TIMER5, PA0, Ch1);
//	  TIM pwm2 = initIO_TIM(TIMER5, PA1, Ch2);

//    TIM pwm1 = initIO_TIM(TIMER9, PA2, Ch1);
//	  TIM pwm2 = initIO_TIM(TIMER9, PA3, Ch2);

//		No Use of TIMER10, 11 

//		TIM pwm1 = initIO_TIM(TIMER12, PB14, Ch1);
//	  TIM pwm2 = initIO_TIM(TIMER12, PB15, Ch2);

//		No Use of TIMER13, 14
		PWM_ON(pwm1.TIMERx,10000); //pwm frequency = 10khz
		while(1) {
			  setPWM(pwm1, 250);
				setPWM(pwm2, 750);
		}
}
void USART_Tester(void) {
	SysTime_Init();
	initUSART(USART2, PA2, PA3, 9600);
	printfForUx(USART2);
	scanfForUx(USART2);
	char str[100];
	while(1) {
		readLine(str);
		printf("%s\r\n",str);
	}
}
void SPI_Tester(void) {
		SysTime_Init();
		initUSART(USART1, PA9, PA10, 9600);
		printfForUx(USART1);
	  scanfForUx(USART1);
		printf("EL PSY CONGROO <<<<<>>>>> Ich Liebe dich~\r\n");
		SPI1_init();
		SPI2_init();
		
	for(int i = 0; i < 10; i++) {
		while(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET);
		SPI_I2S_SendData(SPI2, 10 - i);  //SPI2 -> SPI1
		while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET);
		SPI_I2S_SendData(SPI1, i); // SPI1 -> SPI2
		printf("SENT\r\n");
		while(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET) {
	//		printf("SPI2 status = Reset");
		}
					printf("SPI2 status != Reset");

		char b = SPI_I2S_ReceiveData(SPI2);
		while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET);
		char a = SPI_I2S_ReceiveData(SPI1);
		printf("SPI1 receives %d     SPI2 receives %d\r\n", a, b);
		
	}
}
*/
/*
void SPI_Tester2(void) {
	SysTime_Init();
	initUSART(USART2, PA2, PA3, 9600);
	printfForUx(USART2);
	scanfForUx(USART2);
	printf("\rFUCK\r\n");
				GPIO_InitTypeDef GPIO_InitStructure; 	
	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOC , ENABLE);
	RCC_APB1PeriphClockCmd (RCC_APB1Periph_SPI2, ENABLE);
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource10,GPIO_AF_SPI2);
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource2,GPIO_AF_SPI2);
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource3,GPIO_AF_SPI2);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
//	
//	GPIO_InitStructure.GPIO_Pin = FLASH_CS_PIN;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
//	GPIO_Init(FLASH_CS_GPIO_PORT, &GPIO_InitStructure);
// 	//SPI_FLASH_CS_HIGH(); 
	SPI_InitTypeDef  SPI_InitStructure;
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStructure.SPI_CRCPolynomial = 7;
	SPI_Init(SPI2, &SPI_InitStructure);
	SPI_Cmd(SPI2, ENABLE);
	int r;
	while(1) { 
			r = SPI_ReadByte(SPI2);
			printf("\r%c\r\n", r);
	}
}
void Gyro_Tester(void) {
	SysTime_Init();
	initUSART(USART2, PA2, PA3, 9600);
	printfForUx(USART2);
	scanfForUx(USART2);
	printf("\rThis is a Gyro Tester\r\n");
	//SPI setup			
	GPIO_InitTypeDef GPIO_InitStructure; 	
	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOC , ENABLE);
	RCC_APB1PeriphClockCmd (RCC_APB1Periph_SPI2, ENABLE);
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource10,GPIO_AF_SPI2);
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource2,GPIO_AF_SPI2);
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource3,GPIO_AF_SPI2);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
//
//	GPIO_InitStructure.GPIO_Pin = FLASH_CS_PIN;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
//	GPIO_Init(FLASH_CS_GPIO_PORT, &GPIO_InitStructure);
//	//SPI_FLASH_CS_HIGH(); 
	GPIO CS = initIO(PA4, OUTPUT);
	digitalWrite(CS, HIGH);
	
	SPI_InitTypeDef  SPI_InitStructure;
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStructure.SPI_CRCPolynomial = 7;
	SPI_Init(SPI2, &SPI_InitStructure);
	SPI_Cmd(SPI2, ENABLE);
	int r;
	//delay(1000);
					while(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET);
					SPI_I2S_SendData(SPI2, (uint8_t)(0x00));  //SPI2 -> SPI1
					while(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET);
					r = SPI_I2S_ReceiveData(SPI2);
	delay(1000);
	while(1) { 
			digitalWrite(CS, LOW);
			//r = SPI_SendByte((uint8_t)0x45, SPI2);
					while(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET);
					SPI_I2S_SendData(SPI2, (uint8_t)(0x70 | 0x80));  //SPI2 -> SPI1
					while(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET);
					r = SPI_I2S_ReceiveData(SPI2);
			digitalWrite(CS, HIGH);
			
			delay(100);
			//delay_us(1);
			printf("\r%x\r\n", r);
	}
}
TIM LpwmA, LpwmB, RpwmA, RpwmB;
void motor(double Lpwr, double Rpwr) {
		if(Lpwr > 0.00f) {
				if(Lpwr > 100.00f) Lpwr = 100.00f;
				Lpwr*=10.00f; 
				if(Lpwr!=0.00f) Lpwr-=1.00f;
				setPWM(LpwmA, (uint32_t)Lpwr);
				setPWM(LpwmB, 0);
		}
		else {
				if(Lpwr < -100.00f) Lpwr = -100.00f;
				Lpwr*=-10.00f; 
				if(Lpwr!=0.00f) Lpwr-=1.00f;
				setPWM(LpwmB, (uint32_t)Lpwr);
				setPWM(LpwmA, 0);
		}
		if(Rpwr > 0.00f) {
				if(Rpwr > 100.00f) Rpwr = 100.00f;
				Rpwr*=10.00f; 
				if(Rpwr!=0.00f) Rpwr-=1.00f;
				setPWM(RpwmA, (uint32_t)Rpwr);
				setPWM(RpwmB, 0);
		}
		else {
				if(Rpwr < -100.00f) Rpwr = -100.00f;
				Rpwr*=-10.00f; 
				if(Rpwr!=0.00f) Rpwr+=1.00f;
				setPWM(RpwmB, (uint32_t)Rpwr);
				setPWM(RpwmA, 0);
		}
}
void motorTester(void) {
		SysTime_Init();
		initUSART(USART2, PA2, PA3, 9600);
		printfForUx(USART2);
		scanfForUx(USART2);
		printf("\rThis is a Motor Tester\r\n");
		
		LpwmA = initIO_TIM(TIMER1, PA8, Ch1);
		LpwmB = initIO_TIM(TIMER1, PA9, Ch2);
		RpwmA = initIO_TIM(TIMER1, PA10, Ch3);
		RpwmB = initIO_TIM(TIMER1, PA11, Ch4);
		PWM_ON(TIMER1,10000);
//		double m=35.32;
		while(1) {
				for(double pwr = 0.00f; pwr <= 100.00f; pwr+=0.1) {
						motor(pwr, pwr);
						delay(3);
				}
				
				for(double pwr = 100.00f; pwr > 0.00f; pwr-=0.1) {
						motor(pwr, pwr);
						delay(3);
				}
				for(double pwr = 0.00f; pwr >= -100.00f; pwr-=0.1) {
						motor(pwr, pwr);
						delay(3);
				}
				for(double pwr = -100.00f; pwr <= 0.00f; pwr+=0.1) {
						motor(pwr, pwr);
						delay(3);
				}
				
				//scanf("%lf",&m); 
				//motor(-m,m);

		}
}

extern __IO uint16_t CCR1_Val;
extern __IO uint16_t CCR2_Val;
GPIO itcc1;
GPIO itcc2;
void TIM3_itTask_cc1(void);
void TIM3_itTask_cc2(void);
int cc1Flag = 0;
void TIM3_itTask_cc1(void) {
		if(cc1Flag == 0) {
			digitalWrite(itcc1, HIGH);
			cc1Flag = 1;
			CCR1_Val*=2;
		}
		else {
			digitalWrite(itcc1, LOW);
			cc1Flag = 0;
			CCR1_Val/=2;
		}
}
void TIM3_itTask_cc2(void) {		
		//digitalWrite(itcc2, HIGH);
		//digitalWrite(itcc1, LOW);
}
void TIM3_IT_tester() {
		SysTime_Init();
		initUSART(USART2, PA2, PA3, 9600);
		printfForUx(USART2);
		scanfForUx(USART2);
		
		itcc1 = initIO(PA5, OUTPUT);
		itcc2 = initIO(PA6, OUTPUT);
		CCR1_Val = usToCCR(1000);
		TIM3_initIT();
		while(1) {
				digitalWrite(itcc2, HIGH);
				delay(2);
				digitalWrite(itcc2, LOW);
				delay(2);
		}	
		while(1) printf("\rFuck\r\n");
}
extern volatile uint16_t Aval[16];
void ADCtester(void) {
		SysTime_Init();
		initUSART(USART2, PA2, PA3, 9600);
		printfForUx(USART2);
		scanfForUx(USART2);
		printf("\rThis is a ADC Tester\r\n");
		int ch;
		addADC(PA0, ADC_Channel_0);
		ch = addADC(PA1, ADC_Channel_1);
		addADC(PA4, ADC_Channel_4);
		addADC(PA5, ADC_Channel_5);
		addADC(PA6, ADC_Channel_6);
		addADC(PA7, ADC_Channel_7);
		addADC(PB0, ADC_Channel_8);
		addADC(PB1, ADC_Channel_9);
		addADC(PC0, ADC_Channel_10);
		addADC(PC1, ADC_Channel_11);
		initADC(ADC1);
		//
		while(1) {
				printf("\r");
				for(int i = 0; i < 16; i++) printf("%d ",Aval[i]);
				printf("\r\n");
		}
		//
		uint32_t a[100];
		while(1) {	
				printf("\r");
				ADC_Sampling(a, ch, 10);
				for(int i = 0; i < 10; i++) printf("%d ",a[i]);
				printf("\r\n");
		}
}
void Encoder_Tester(void) {
		SysTime_Init();
		initUSART(USART2, PA2, PA3, 9600);
		printfForUx(USART2);
		scanfForUx(USART2);
		printf("\rThis is a Encoder Tester\r\n");
		
		initEncoder();
		while(1) printf("\r%d %d\r\n", LEnc(), REnc() );
}

//IR Tester
GPIO EM;
uint8_t RE;
volatile uint16_t RE_Val;
void TIM3_itTask_cc1(void) {
		if(cc1Flag == 0) {
			digitalWrite(EM, HIGH);
			cc1Flag = 1;
		}
		else {
			RE_Val = analogRead(RE);
			digitalWrite(EM, LOW);
			cc1Flag = 0;
		}
}
void IR_Tester(void) {
		SysTime_Init();
		initUSART(USART2, PA2, PA3, 9600);
		printfForUx(USART2);
		scanfForUx(USART2);
		printf("\rThis is a Single IR Tester\r\n");
		
		EM = initIO(PA8, OUTPUT);
		CCR1_Val = usToCCR(10);
		TIM3_initIT();
		
		RE = addADC(PA1, ADC_Channel_1);
		initADC(ADC1);
		while(1) printf("\r%d\r\n", RE_Val);
}
*/
/*
typedef struct {
    double Pout, Iout, Dout;
    double Ep, Ei, Ed;
    double Kp, Ki, Kd;
    double integral, differential;
    double pExp;
    double pAct;
    uint64_t T;

} PID;

PID Angular;
void initAngular_PID(double Kp, double Ki, double Kd, double Exp, double Act) {
    Angular.Kp = Kp;
    Angular.Ki = Ki;
    Angular.Kd = Kd;
    Angular.pExp = Exp;
    Angular.pAct = Act;
    Angular.integral = 0.000f;
    Angular.Pout = Kp * (Exp - Act); 
    Angular.Iout = 0.000f; 
    Angular.Dout = 0.000f;
    Angular.T = micros();
}

double Angular_PID(double Exp, double Act) {
    double dT = (double)(micros() - Angular.T) / 1000000.000f;
    //-------Pout--------//
    Angular.Ep = Exp - Act;
    double Pout = Angular.Kp * Angular.Ep;

    if(dT > 0.01000f) {
        Angular.pExp = Exp;
        Angular.pAct = Act;
        Angular.T = micros();
        return Pout + Angular.Iout + Angular.Dout;
    }

    //-------Iout--------//
    if(Angular.pExp != Exp) Angular.integral = 0.000f;
    Angular.integral += (((Exp - Act) + (Angular.pExp - Angular.pAct)) / 2.0000000000f) * dT ;
    double Iout = Angular.Ki * Angular.integral;

    //-------Dout--------//
    double Dout;
    if(equal(Act, Angular.pAct, 0.000001)) Dout = 0.000f;
    else {
        Angular.differential = (Angular.pAct - Act) / (dT * 1000.000f);
        Dout = Angular.differential * Angular.Kd;
    }

    //----update-----//
    Angular.pExp = Exp;
    Angular.pAct = Act;
    Angular.T = micros();
    //----Tester-----//
    //PTester[Tindex] = Pout; ITester[Tindex] = Iout; DTester[Tindex] = Dout; Ttrac[Tindex] = Angular.T;
    //Tindex++;
    //----return-----//
    Angular.Pout = Pout; Angular.Iout = Iout; Angular.Dout = Dout;
    return (Pout + Iout + Dout);
}

double Angle(void) {
		return (double)(REnc() - LEnc()) * 90.00f / 30000.000f;
}
*/
