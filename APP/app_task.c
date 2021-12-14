#include "app_task.h"
#include "stdio.h"
#include  "as608.h"
#include  "main.h"
#include "usart.h"
#include "as608_app.h"
#include "rc522_app.h"
#include "SX127X_Driver.h"


extern uint16_t ValidN;//ģ������Чָ�Ƹ���
extern SysPara AS608Para;//
	uint8_t  ensure=0;
	
uint8_t 	 card_test[6];
//int fputc(int ch, FILE *f)
//{
//  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xffff);
//  return ch;
//}
extern uint32_t AS608Addr ;

void device()
{
//	open_pwr_zhiwen();
		 ETH_DMA_START();
   test_rc522_init();
	//LORA ��ʼ������
//  app_lora_config_init();

printf("AS608ָ��ʶ��ģ����Գ���");	    			    	 		    	 
	printf("��AS608ģ������....");	
	while(PS_HandShake(&AS608Addr))//��AS608ģ������
	{
		HAL_Delay(400);
		
		printf("δ��⵽ģ��!!!");
		HAL_Delay(800);
		
		printf("��������ģ��...");		  
	}
	
	printf("ͨѶ�ɹ�!!!");

	ensure=PS_ValidTempleteNum(&ValidN);//����ָ�Ƹ���
	if(ensure!=0x00)
	{
		ShowErrMessage(ensure);//��ʾȷ���������Ϣ	
	}
	else
	{
	printf("����ָ�Ƹ���=%d",ValidN);
	}
	ensure=PS_ReadSysPara(&AS608Para);  //������ 
	if(ensure==0x00)
	{
	
		printf("������:%d     �Աȵȼ�: %d    ������:  %d    aadr:  %d    PS_size:  %d",AS608Para.PS_max-ValidN,AS608Para.PS_level,AS608Para.PS_N,AS608Para.PS_addr,AS608Para.PS_size);
	
	}
	else
		ShowErrMessage(ensure);
	
}
//ϵͳ����
void app_task_run()
{
	     static uint8_t run_app_state=0;
//			  if(PS_Sta)	 //���PS_Sta״̬���������ָ����
//		{
//			printf("����ָ����\r\n");
//				press_FR();//ˢָ��			
//		}		
//		  rc522_find_card(card_test);
	  //����
		/*����ҵ����ת    
		 *��Ƭˢ����ʼ¼ָ��*/
     /*���񾯣�ͨ����̨���俨�Ÿ��񾯣���һ��ˢ����Ҫ¼��ָ�ƣ�ÿ̨�������¿���*/
		switch(run_app_state)
		{
			
			case 0 :          if( rc522_find_card(card_test)==1)
			{
				      Line_1A_WT588S(1);//�򿨳ɹ�
		            HAL_Delay(2000);
					printf("��ȡ���ųɹ�");
		   		run_app_state=1;
			}
				break;
			case 1 :     
            Add_FR(1); 
			
			      Line_1A_WT588S(13);//��ʼ����
		            HAL_Delay(2000);
			
				run_app_state=2;
           
			break;    
				case 2 :   
							  if(PS_Sta)	 //���PS_Sta״̬���������ָ����
		    {
			printf("����ָ����\r\n");
				press_FR();//ˢָ��			
		   }
				  if( rc522_find_card(card_test)==1)
			{
				      Line_1A_WT588S(1);//�򿨳ɹ�
		            HAL_Delay(2000);
					printf("��ȡ���ųɹ�");
		   
			}
          break;			 
		}
}

// 
