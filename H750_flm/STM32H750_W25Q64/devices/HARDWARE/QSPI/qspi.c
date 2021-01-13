#include "qspi.h"
////////////////////////////////////////////////////////////////////////////////
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32H7������
//QSPI ��������
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2018/6/14
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved
////////////////////////////////////////////////////////////////////////////////

/*----------------------------------------------------------------------------*/
//���Ӳ�����߲�ͬ����Ҫ�� QSPI_Init ������
/*----------------------------------------------------------------------------*/
//�ȴ�״̬��־
//flag:��Ҫ�ȴ��ı�־λ
//sta:��Ҫ�ȴ���״̬
//wtime:�ȴ�ʱ��
//����ֵ:0,�ȴ��ɹ�.
//	     1,�ȴ�ʧ��.
u8 QSPI_Wait_Flag(u32 flag, u8 sta, u32 wtime)
{
	u8 flagsta = 0;
	while(wtime)
	{
		flagsta = (QUADSPI->SR & flag) ? 1 : 0;
		if (flagsta == sta) break;
		wtime--;
	}
	if (wtime)
		return 0;
	else
		return 1;
}

//��ʼ��QSPI�ӿ�
//����ֵ:0,�ɹ�;
//       1,ʧ��;
u8 QSPI_Init(void)
{
	u32 tempreg=0;

	RCC->AHB4ENR|=1<<0; //??GPIOA??
	RCC->AHB4ENR|=1<<1; //??GPIOB??
	RCC->AHB4ENR|=1<<2;	//??GPIOC??
	RCC->AHB4ENR|=1<<3; //QSPI????
	RCC->AHB4ENR|=1<<4;	//??GPIOE??
	RCC->AHB3ENR|=1<<14; //QSPI????

	//PB2 QUADSPI1_CLK
	GPIO_Set(GPIOB,1<<2,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_SPEED_HIGH,GPIO_PUPD_PU);
	//PB6 QUADSPI1_BK1_NCS
	GPIO_Set(GPIOB,1<<6,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_SPEED_HIGH,GPIO_PUPD_PU);
	//PC9,PC10 QUADSPI1_BK1_IO0, IO1, 
	//GPIO_Set(GPIOC,1<<9,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_SPEED_HIGH,GPIO_PUPD_PU);
	//GPIO_Set(GPIOC,1<<10,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_SPEED_HIGH,GPIO_PUPD_PU);
	GPIO_Set(GPIOD,1<<11,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_SPEED_HIGH,GPIO_PUPD_PU);
	GPIO_Set(GPIOD,1<<12,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_SPEED_HIGH,GPIO_PUPD_PU);
	//IO3
	GPIO_Set(GPIOD,1<<13,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_SPEED_HIGH,GPIO_PUPD_PU);
	//PE2 QUADSPI1_BK1_IO2
	GPIO_Set(GPIOE, 1<<2,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_SPEED_HIGH,GPIO_PUPD_PU);

	GPIO_AF_Set(GPIOB,2,9); //PB2,AF9
 	GPIO_AF_Set(GPIOB,6,10); //PB6,AF10
 	GPIO_AF_Set(GPIOD,11,9); //PC9,AF9
 	GPIO_AF_Set(GPIOD,12,9); //PC10,AF9
 	GPIO_AF_Set(GPIOD,13,9); //PD13,AF9
 	GPIO_AF_Set(GPIOE,2,9); //PE2,AF9

	RCC->AHB3RSTR|=1<<14; //��λQSPI
	RCC->AHB3RSTR&=~(1<<14); //ֹͣ��λQSPI
	if(QSPI_Wait_Flag(1<<5,0,0XFFFF)==0)//�ȴ�BUSY����
	{
		//QSPIʱ��Ĭ������rcc_hclk3(��RCC_D1CCIPR��QSPISEL[1:0]ѡ��)
		tempreg=(2-1)<<24;		//����QSPIʱ��ΪAHBʱ�ӵ�1/2,��200M/2=100Mhz,10ns
		tempreg|=(4-1)<<8;		//����FIFO��ֵΪ4���ֽ�(���Ϊ31,��ʾ32���ֽ�)
		tempreg|=0<<7;			//ѡ��FLASH1
		tempreg|=0<<6;			//��ֹ˫����ģʽ
		tempreg|=1<<4;			//������λ�������(DDRģʽ��,��������Ϊ0)
		QUADSPI->CR=tempreg;	//����CR�Ĵ���
		tempreg=(23-1)<<16;		//����FLASH��СΪ2^23=8MB
		tempreg|=(5-1)<<8;		//Ƭѡ�ߵ�ƽʱ��Ϊ5��ʱ��(10*5=50ns),���ֲ������tSHSL����
		tempreg|=1<<0;			//Mode3,����ʱCLKΪ�ߵ�ƽ
		QUADSPI->DCR=tempreg;	//����DCR�Ĵ���
		QUADSPI->CR|=1<<0;		//ʹ��QSPI
	}else return 1;
	return 0;
}

//QSPI��������
//cmd:Ҫ���͵�ָ��
//addr:���͵���Ŀ�ĵ�ַ
//mode:ģʽ,��ϸλ��������:
//	mode[1:0]:ָ��ģʽ;00,��ָ��;01,���ߴ���ָ��;10,˫�ߴ���ָ��;11,���ߴ���ָ��.
//	mode[3:2]:��ַģʽ;00,�޵�ַ;01,���ߴ����ַ;10,˫�ߴ����ַ;11,���ߴ����ַ.
//	mode[5:4]:��ַ����;00,8λ��ַ;01,16λ��ַ;10,24λ��ַ;11,32λ��ַ.
//	mode[7:6]:����ģʽ;00,������;01,���ߴ�������;10,˫�ߴ�������;11,���ߴ�������.
//dmcycle:��ָ��������
void QSPI_Send_CMD(u8 cmd,u32 addr,u8 mode,u8 dmcycle)
{
	u32 tempreg=0;
	u8 status;
	if(QSPI_Wait_Flag(1<<5,0,0XFFFF)==0)	//�ȴ�BUSY����
	{
		tempreg=0<<31;						//��ֹDDRģʽ
		tempreg|=0<<28;						//ÿ�ζ�����ָ��
		tempreg|=0<<26;						//���дģʽ
		tempreg|=((u32)mode>>6)<<24;		//��������ģʽ
		tempreg|=(u32)dmcycle<<18;			//���ÿ�ָ��������
		tempreg|=((u32)(mode>>4)&0X03)<<12;	//���õ�ַ����
		tempreg|=((u32)(mode>>2)&0X03)<<10;	//���õ�ַģʽ
		tempreg|=((u32)(mode>>0)&0X03)<<8;	//����ָ��ģʽ
		tempreg|=cmd;						//����ָ��
		QUADSPI->CCR=tempreg;				//����CCR�Ĵ���
		if(mode&0X0C)						//��ָ��+��ַҪ����
		{
			QUADSPI->AR=addr;				//���õ�ַ�Ĵ���
		}
		if((mode&0XC0)==0)					//�����ݴ���,�ȴ�ָ������
		{
			status=QSPI_Wait_Flag(1<<1,1,0XFFFF);//�ȴ�TCF,���������
			if(status==0)
			{
				QUADSPI->FCR|=1<<1;			//���TCF��־λ
			}
		}
	}
}

//QSPI����ָ�����ȵ�����
//buf:�������ݻ������׵�ַ
//datalen:Ҫ��������ݳ���
//����ֵ:0,����
//    ����,�������
u8 QSPI_Receive(u8* buf,u32 datalen)
{
	u32 tempreg=QUADSPI->CCR;
	u32 addrreg=QUADSPI->AR;
	u8 status;
	vu32 *data_reg=&QUADSPI->DR;
	QUADSPI->DLR=datalen-1;					//�������ݴ��䳤��
	tempreg&=~(3<<26);						//���FMODEԭ��������
	tempreg|=1<<26;							//����FMODEΪ��Ӷ�ȡģʽ
	QUADSPI->FCR|=1<<1;						//���TCF��־λ
	QUADSPI->CCR=tempreg;					//��дCCR�Ĵ���
	QUADSPI->AR=addrreg;					//��дAR�Ĵ���,��������
	while(datalen)
	{
		status=QSPI_Wait_Flag(3<<1,1,0XFFFF);//�ȵ�FTF��TCF,�����յ�������
		if(status==0)						//�ȴ��ɹ�
		{
			*buf++=*(vu8 *)data_reg;
			datalen--;
		}else break;
	}
	if(status==0)
	{
		QUADSPI->CR|=1<<2;							//��ֹ����
		status=QSPI_Wait_Flag(1<<1,1,0XFFFF);		//�ȴ�TCF,�����ݴ������
		if(status==0)
		{
			QUADSPI->FCR|=1<<1;						//���TCF��־λ
			status=QSPI_Wait_Flag(1<<5,0,0XFFFF);	//�ȴ�BUSYλ����
		}
	}
	return status;
}

//QSPI����ָ�����ȵ�����
//buf:�������ݻ������׵�ַ
//datalen:Ҫ��������ݳ���
//����ֵ:0,����
//    ����,�������
u8 QSPI_Transmit(u8* buf,u32 datalen)
{
	u32 tempreg=QUADSPI->CCR;
	u32 addrreg=QUADSPI->AR;
	u8 status;
	vu32 *data_reg=&QUADSPI->DR;
	QUADSPI->DLR=datalen-1;					//�������ݴ��䳤��
	tempreg&=~(3<<26);						//���FMODEԭ��������
	tempreg|=0<<26;							//����FMODEΪ���д��ģʽ
	QUADSPI->FCR|=1<<1;						//���TCF��־λ
	QUADSPI->CCR=tempreg;					//��дCCR�Ĵ���
	while(datalen)
	{
		status=QSPI_Wait_Flag(1<<2,1,0XFFFF);//�ȵ�FTF
		if(status!=0)						//�ȴ��ɹ�
		{
			break;
		}
		*(vu8 *)data_reg=*buf++;
		datalen--;
	}
	if(status==0)
	{
		QUADSPI->CR|=1<<2;							//��ֹ����
		status=QSPI_Wait_Flag(1<<1,1,0XFFFF);		//�ȴ�TCF,�����ݴ������
		if(status==0)
		{
			QUADSPI->FCR|=1<<1;						//���TCF��־λ
			status=QSPI_Wait_Flag(1<<5,0,0XFFFF);	//�ȴ�BUSYλ����
		}
	}
	return status;
}
