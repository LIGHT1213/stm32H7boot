#include "w25qxx.h"
#include "qspi.h"
////////////////////////////////////////////////////////////////////////////////
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32H7������
//W25QXX QPIģʽ��������
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2018/6/14
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved
////////////////////////////////////////////////////////////////////////////////
/*----------------------------------------------------------------------------*/
//˿ӡ25Q64JVSIQ���ο��ٷ��ĵ�W25Q64JV_DTR
//1 Sector = 4kB, 1 Block = 16 Sectors, 128 Blocks = 2048 Sectors = 8MB

//ע�⣺W25Q256֧��4�ֽڵ�ַģʽ
//W25X_SectorErase��W25X_FastReadData��W25X_PageProgram 3���������Ϊ32λ��ַģʽ

u16 W25QXX_TYPE = W25Q64; //Ĭ����W25Q64
u8 W25QXX_QPI_MODE = 0; //QSPIģʽ��־:0,SPIģʽ;1,QPIģʽ.
u8 W25QXX_BUFFER[4096];
/*----------------------------------------------------------------------------*/
//��ʼ��SPI FLASH
void W25QXX_Init(void)
{
	u8 temp;

	QSPI_Init(); //��ʼ��QSPI
	W25QXX_Qspi_Disable(); //�Ƚ���SPIģʽ
	W25QXX_Reset(); //��λ
	W25QXX_Qspi_Enable(); //ʹ��QSPIģʽ
	W25QXX_TYPE = W25QXX_ReadID(); //��ȡFLASH ID
	if ((W25QXX_TYPE & 0xEF10) == 0xEF10)
	{
		if (W25QXX_TYPE == W25Q256) //SPI FLASHΪW25Q256
		{
			temp = W25QXX_ReadSR(3); //��ȡ״̬�Ĵ���3���жϵ�ַģʽ
			if((temp & 0X01) == 0) //�������4�ֽڵ�ַģʽ,�����4�ֽڵ�ַģʽ
			{
				W25QXX_Write_Enable(); //дʹ��
				//QPI,ʹ��4�ֽڵ�ַָ��,��ַΪ0,������_8λ��ַ_�޵�ַ_4�ߴ���ָ��,�޿�����,0���ֽ�����
				QSPI_Send_CMD(W25X_Enable4ByteAddr, 0, (0<<6)|(0<<4)|(0<<2)|(3<<0), 0);
			}
		}
		W25QXX_Write_Enable(); //дʹ��
		//QPI,���ö�����ָ��,��ַΪ0,4�ߴ�����_8λ��ַ_�޵�ַ_4�ߴ���ָ��,�޿�����,1���ֽ�����
		QSPI_Send_CMD(W25X_SetReadParam, 0, (3<<6)|(0<<4)|(0<<2)|(3<<0), 0);
		temp = 3<<4; //����P4&P5=11,8��dummy clocks,104MHz
		QSPI_Transmit(&temp, 1); //����1���ֽ�
    }
}

//W25QXX����QSPIģʽ
void W25QXX_Qspi_Enable(void)
{
	u8 stareg2;
	stareg2 = W25QXX_ReadSR(2); //�ȶ���״̬�Ĵ���2��ԭʼֵ
	if((stareg2 & 0X02) == 0) //QEλδʹ��
	{
		W25QXX_Write_Enable(); //дʹ��
		stareg2 |= 1<<1; //ʹ��QEλ
		W25QXX_Write_SR(2, stareg2); //д״̬�Ĵ���2
	}
	//дcommandָ��,��ַΪ0,������_8λ��ַ_�޵�ַ_���ߴ���ָ��,�޿�����,0���ֽ�����
	QSPI_Send_CMD(W25X_EnterQPIMode, 0, (0<<6)|(0<<4)|(0<<2)|(1<<0), 0);
	W25QXX_QPI_MODE = 1; //���QSPIģʽ
}

//W25QXX�˳�QSPIģʽ
void W25QXX_Qspi_Disable(void)
{
	//дcommandָ��,��ַΪ0,������_8λ��ַ_�޵�ַ_4�ߴ���ָ��,�޿�����,0���ֽ�����
	QSPI_Send_CMD(W25X_ExitQPIMode, 0, (0<<6)|(0<<4)|(0<<2)|(3<<0), 0);
	W25QXX_QPI_MODE = 0; //���SPIģʽ
}

//��ȡW25QXX��״̬�Ĵ�����W25QXXһ����3��״̬�Ĵ���
//״̬�Ĵ���1��
//BIT7  6   5   4   3   2   1   0
//SPR   RV  TB BP2 BP1 BP0 WEL BUSY
//SPR:Ĭ��0,״̬�Ĵ�������λ,���WPʹ��
//TB,BP2,BP1,BP0:FLASH����д��������
//WEL:дʹ������
//BUSY:æ���λ(1,æ;0,����)
//Ĭ��:0x00
//״̬�Ĵ���2��
//BIT7  6   5   4   3   2   1   0
//SUS   CMP LB3 LB2 LB1 (R) QE  SRP1
//״̬�Ĵ���3��
//BIT7      6    5    4   3   2   1   0
//HOLD/RST  DRV1 DRV0 (R) (R) WPS ADP ADS
//regno:״̬�Ĵ����ţ���:1~3
//����ֵ:״̬�Ĵ���ֵ
u8 W25QXX_ReadSR(u8 regno)
{
	u8 byte = 0, command = 0;
    switch(regno)
    {
        case 1:
            command = W25X_ReadStatusReg1; //��״̬�Ĵ���1ָ��
            break;
        case 2:
            command = W25X_ReadStatusReg2; //��״̬�Ĵ���2ָ��
            break;
        case 3:
            command = W25X_ReadStatusReg3; //��״̬�Ĵ���3ָ��
            break;
        default:
            command = W25X_ReadStatusReg1;
            break;
    }
	if (W25QXX_QPI_MODE)
		//QPI,дcommandָ��,��ַΪ0,4�ߴ�����_8λ��ַ_�޵�ַ_4�ߴ���ָ��,�޿�����,1���ֽ�����
		QSPI_Send_CMD(command, 0, (3<<6)|(0<<4)|(0<<2)|(3<<0), 0);
	else
		//SPI,дcommandָ��,��ַΪ0,���ߴ�����_8λ��ַ_�޵�ַ_���ߴ���ָ��,�޿�����,1���ֽ�����
		QSPI_Send_CMD(command, 0, (1<<6)|(0<<4)|(0<<2)|(1<<0), 0);
	QSPI_Receive(&byte, 1);
	return byte;
}

//дW25QXX״̬�Ĵ���
void W25QXX_Write_SR(u8 regno, u8 sr)
{
    u8 command=0;
    switch(regno)
    {
        case 1:
            command = W25X_WriteStatusReg1; //д״̬�Ĵ���1ָ��
            break;
        case 2:
            command = W25X_WriteStatusReg2; //д״̬�Ĵ���2ָ��
            break;
        case 3:
            command = W25X_WriteStatusReg3; //д״̬�Ĵ���3ָ��
            break;
        default:
            command = W25X_WriteStatusReg1;
            break;
    }
	if (W25QXX_QPI_MODE)
		//QPI,дcommandָ��,��ַΪ0,4�ߴ�����_8λ��ַ_�޵�ַ_4�ߴ���ָ��,�޿�����,1���ֽ�����
		QSPI_Send_CMD(command, 0, (3<<6)|(0<<4)|(0<<2)|(3<<0), 0);
	else
		//SPI,дcommandָ��,��ַΪ0,���ߴ�����_8λ��ַ_�޵�ַ_���ߴ���ָ��,�޿�����,1���ֽ�����
		QSPI_Send_CMD(command, 0, (1<<6)|(0<<4)|(0<<2)|(1<<0), 0);
	QSPI_Transmit(&sr,1);
}

//W25QXXдʹ��
//��S1�Ĵ�����WEL��λ
void W25QXX_Write_Enable(void)
{
	if(W25QXX_QPI_MODE)
		//QPI,дʹ��ָ��,��ַΪ0,������_8λ��ַ_�޵�ַ_4�ߴ���ָ��,�޿�����,0���ֽ�����
		QSPI_Send_CMD(W25X_WriteEnable, 0, (0<<6)|(0<<4)|(0<<2)|(3<<0), 0);
	else
		//SPI,дʹ��ָ��,��ַΪ0,������_8λ��ַ_�޵�ַ_���ߴ���ָ��,�޿�����,0���ֽ�����
		QSPI_Send_CMD(W25X_WriteEnable, 0, (0<<6)|(0<<4)|(0<<2)|(1<<0), 0);
}

//W25QXXд��ֹ
//��WEL����
void W25QXX_Write_Disable(void)
{
	if (W25QXX_QPI_MODE)
		//QPI,д��ָֹ��,��ַΪ0,������_8λ��ַ_�޵�ַ_4�ߴ���ָ��,�޿�����,0���ֽ�����
		QSPI_Send_CMD(W25X_WriteDisable, 0, (0<<6)|(0<<4)|(0<<2)|(3<<0), 0);

	else
		//SPI,д��ָֹ��,��ַΪ0,������_8λ��ַ_�޵�ַ_���ߴ���ָ��,�޿�����,0���ֽ�����
		QSPI_Send_CMD(W25X_WriteDisable, 0, (0<<6)|(0<<4)|(0<<2)|(1<<0), 0);
}

//����ֵ����:
//0XEF13,��ʾоƬ�ͺ�ΪW25Q80
//0XEF14,��ʾоƬ�ͺ�ΪW25Q16
//0XEF15,��ʾоƬ�ͺ�ΪW25Q32
//0XEF16,��ʾоƬ�ͺ�ΪW25Q64
//0XEF17,��ʾоƬ�ͺ�ΪW25Q128
//0XEF18,��ʾоƬ�ͺ�ΪW25Q256
u16 W25QXX_ReadID(void)
{
	u8 temp[2];
	u16 deviceid;
	if (W25QXX_QPI_MODE)
		//QPI,��id,��ַΪ0,4�ߴ�������_24λ��ַ_4�ߴ����ַ_4�ߴ���ָ��,�޿�����,2���ֽ�����
		QSPI_Send_CMD(W25X_ManufactDeviceID, 0, (3<<6)|(2<<4)|(3<<2)|(3<<0), 0);

	else
		//SPI,��id,��ַΪ0,���ߴ�������_24λ��ַ_���ߴ����ַ_���ߴ���ָ��,�޿�����,2���ֽ�����
		QSPI_Send_CMD(W25X_ManufactDeviceID, 0, (1<<6)|(2<<4)|(1<<2)|(1<<0), 0);
	QSPI_Receive(temp, 2);
	deviceid = (temp[0] << 8) | temp[1];
	return deviceid;
}

//��ȡSPI FLASH,��֧��QPIģʽ
//��ָ����ַ��ʼ��ȡָ�����ȵ�����
//pBuffer:���ݴ洢��
//ReadAddr:��ʼ��ȡ�ĵ�ַ(���32bit)
//NumByteToRead:Ҫ��ȡ���ֽ���(���65535)
void W25QXX_Read(u8* pBuffer, u32 ReadAddr, u16 NumByteToRead)
{
	//QPI,���ٶ�����,��ַΪReadAddr,4�ߴ�������_24λ��ַ_4�ߴ����ַ_4�ߴ���ָ��,8������,NumByteToRead������
	QSPI_Send_CMD(W25X_FastReadData, ReadAddr, (3<<6)|(2<<4)|(3<<2)|(3<<0), 8);
	QSPI_Receive(pBuffer, NumByteToRead);
}

//SPI��һҳ(0~65535)��д������256���ֽڵ�����
//��ָ����ַ��ʼд�����256�ֽڵ�����
//pBuffer:���ݴ洢��
//WriteAddr:��ʼд��ĵ�ַ(���32bit)
//NumByteToWrite:Ҫд����ֽ���(���256),������Ӧ�ó�����ҳ��ʣ���ֽ���!!!
void W25QXX_Write_Page(u8* pBuffer, u32 WriteAddr, u16 NumByteToWrite)
{
	W25QXX_Write_Enable(); //дʹ��
	//QPI,ҳдָ��,��ַΪWriteAddr,4�ߴ�������_24λ��ַ_4�ߴ����ַ_4�ߴ���ָ��,�޿�����,NumByteToWrite������
	QSPI_Send_CMD(W25X_PageProgram, WriteAddr, (3<<6)|(2<<4)|(3<<2)|(3<<0), 0);
	QSPI_Transmit(pBuffer, NumByteToWrite);
	W25QXX_Wait_Busy(); //�ȴ�д�����
}

//�޼���дSPI FLASH
//����ȷ����д�ĵ�ַ��Χ�ڵ�����ȫ��Ϊ0XFF,�����ڷ�0XFF��д������ݽ�ʧ��!
//�����Զ���ҳ����
//��ָ����ַ��ʼд��ָ�����ȵ�����,����Ҫȷ����ַ��Խ��!
//pBuffer:���ݴ洢��
//WriteAddr:��ʼд��ĵ�ַ(���32bit)
//NumByteToWrite:Ҫд����ֽ���(���65535)
//CHECK OK
void W25QXX_Write_NoCheck(u8* pBuffer, u32 WriteAddr, u16 NumByteToWrite)
{
	u16 pageremain;
	pageremain = 256 - WriteAddr % 256; //��ҳʣ����ֽ���
	if (NumByteToWrite <= pageremain)
	{
		pageremain = NumByteToWrite; //������256���ֽ�
	}
	while(1)
	{
		W25QXX_Write_Page(pBuffer, WriteAddr, pageremain);
		if (NumByteToWrite == pageremain)
		{
			break; //д�������
		}
	 	else //NumByteToWrite>pageremain
		{
			pBuffer += pageremain;
			WriteAddr += pageremain;

			NumByteToWrite -= pageremain; //��ȥ�Ѿ�д���˵��ֽ���
			if (NumByteToWrite > 256)
				pageremain = 256; //һ�ο���д��256���ֽ�
			else
				pageremain = NumByteToWrite; //����256���ֽ���
		}
	}
}

//дSPI FLASH
//��ָ����ַ��ʼд��ָ�����ȵ�����
//�ú�������������!
//pBuffer:���ݴ洢��
//WriteAddr:��ʼд��ĵ�ַ(���32bit)
//NumByteToWrite:Ҫд����ֽ���(���65535)
void W25QXX_Write(u8* pBuffer, u32 WriteAddr, u16 NumByteToWrite)
{
	u32 secpos;
	u16 secoff;
	u16 secremain;
 	u16 i;
	u8* W25QXX_BUF;

	W25QXX_BUF = W25QXX_BUFFER;
 	secpos = WriteAddr / 4096; //������ַ
	secoff = WriteAddr % 4096; //�������ڵ�ƫ��
	secremain = 4096 - secoff; //����ʣ��ռ��С

 	if (NumByteToWrite <= secremain) secremain = NumByteToWrite; //������4096���ֽ�
	while(1)
	{
		W25QXX_Read(W25QXX_BUF, secpos * 4096, 4096); //������������������
		for (i = 0;i < secremain; i++) //У������
		{
			if (W25QXX_BUF[secoff+i] != 0XFF) break; //��Ҫ����
		}
		if (i < secremain) //��Ҫ����
		{
			W25QXX_Erase_Sector(secpos); //�����������
			for (i = 0; i < secremain; i++) //����
			{
				W25QXX_BUF[i + secoff] = pBuffer[i];
			}
			W25QXX_Write_NoCheck(W25QXX_BUF, secpos * 4096, 4096); //д����������
		}
		else
		{
			W25QXX_Write_NoCheck(pBuffer, WriteAddr, secremain); //д�Ѿ������˵�,ֱ��д������ʣ������.
		}
		if (NumByteToWrite == secremain)
		{
			break; //д�������
		}
		else//д��δ����
		{
			secpos++; //������ַ��1
			secoff = 0; //ƫ��λ��Ϊ0

			pBuffer += secremain;  //ָ��ƫ��
			WriteAddr += secremain;//д��ַƫ��
			NumByteToWrite -= secremain; //�ֽ����ݼ�
			if (NumByteToWrite > 4096)
				secremain = 4096; //��һ����������д����
			else
				secremain = NumByteToWrite; //��һ����������д����
		}
	}
}

//��������оƬ
//�ȴ�ʱ�䳬��...
void W25QXX_Erase_Chip(void)
{
	W25QXX_Write_Enable(); //SET WEL
	W25QXX_Wait_Busy();
	//QPI,дȫƬ����ָ��,��ַΪ0,������_8λ��ַ_�޵�ַ_4�ߴ���ָ��,�޿�����,0���ֽ�����
	QSPI_Send_CMD(W25X_ChipErase, 0, (0<<6)|(0<<4)|(0<<2)|(3<<0), 0);
	W25QXX_Wait_Busy(); //�ȴ�оƬ��������
}

//����һ������
//Dst_Addr:������ַ ����ʵ����������
//����һ������������ʱ��:150ms
void W25QXX_Erase_Sector(u32 Dst_Addr)
{
	W25QXX_Write_Enable(); //SET WEL
	W25QXX_Wait_Busy();
	//QPI,д��������ָ��,��ַΪ0,������_24λ��ַ_4�ߴ����ַ_4�ߴ���ָ��,�޿�����,0���ֽ�����
	QSPI_Send_CMD(W25X_SectorErase, Dst_Addr, (0<<6)|(2<<4)|(3<<2)|(3<<0), 0);
	W25QXX_Wait_Busy(); //�ȴ��������
}

//�ȴ�����
void W25QXX_Wait_Busy(void)
{
	while((W25QXX_ReadSR(1) & 0x01) == 0x01); //�ȴ�BUSYλ���
}

//��λ
void W25QXX_Reset(void)
{
	W25QXX_Wait_Busy();
	
	if (W25QXX_QPI_MODE)
	{
		//QPI,��λʹ��ָ��,��ַΪ0,������_8λ��ַ_�޵�ַ_4�ߴ���ָ��,�޿�����,0���ֽ�����
		QSPI_Send_CMD(W25X_EnableReset, 0, (0<<6)|(0<<4)|(0<<2)|(3<<0), 0);
		//QPI,��λ�豸ָ��,��ַΪ0,������_8λ��ַ_�޵�ַ_4�ߴ���ָ��,�޿�����,0���ֽ�����
		QSPI_Send_CMD(W25X_ResetDevice, 0, (0<<6)|(0<<4)|(0<<2)|(3<<0), 0);
	}
	else
	{
		//SPI,��λʹ��ָ��,��ַΪ0,������_8λ��ַ_�޵�ַ_���ߴ���ָ��,�޿�����,0���ֽ�����
		QSPI_Send_CMD(W25X_EnableReset, 0, (0<<6)|(0<<4)|(0<<2)|(1<<0), 0);
		//SPI,��λ�豸ָ��,��ַΪ0,������_8λ��ַ_�޵�ַ_���ߴ���ָ��,�޿�����,0���ֽ�����
		QSPI_Send_CMD(W25X_ResetDevice, 0, (0<<6)|(0<<4)|(0<<2)|(1<<0), 0);
	}
}
