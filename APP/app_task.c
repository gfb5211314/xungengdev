#include "app_task.h"
#include "stdio.h"
#include  "as608.h"
#include  "main.h"
#include "usart.h"
#include "as608_app.h"
#include "rc522_app.h"
#include "SX127X_Driver.h"


extern uint16_t ValidN;//模块内有效指纹个数
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
	//LORA 初始化配置
//  app_lora_config_init();

printf("AS608指纹识别模块测试程序");	    			    	 		    	 
	printf("与AS608模块握手....");	
	while(PS_HandShake(&AS608Addr))//与AS608模块握手
	{
		HAL_Delay(400);
		
		printf("未检测到模块!!!");
		HAL_Delay(800);
		
		printf("尝试连接模块...");		  
	}
	
	printf("通讯成功!!!");

	ensure=PS_ValidTempleteNum(&ValidN);//读库指纹个数
	if(ensure!=0x00)
	{
		ShowErrMessage(ensure);//显示确认码错误信息	
	}
	else
	{
	printf("读库指纹个数=%d",ValidN);
	}
	ensure=PS_ReadSysPara(&AS608Para);  //读参数 
	if(ensure==0x00)
	{
	
		printf("库容量:%d     对比等级: %d    波特率:  %d    aadr:  %d    PS_size:  %d",AS608Para.PS_max-ValidN,AS608Para.PS_level,AS608Para.PS_N,AS608Para.PS_addr,AS608Para.PS_size);
	
	}
	else
		ShowErrMessage(ensure);
	
}
//系统任务
void app_task_run()
{
	     static uint8_t run_app_state=0;
//			  if(PS_Sta)	 //检测PS_Sta状态，如果有手指按下
//		{
//			printf("有手指按下\r\n");
//				press_FR();//刷指纹			
//		}		
//		  rc522_find_card(card_test);
	  //测试
		/*正常业务运转    
		 *卡片刷卡开始录指纹*/
     /*新民警：通过后台分配卡号给民警，第一次刷卡，要录入指纹，每台机子问下卡号*/
		switch(run_app_state)
		{
			
			case 0 :          if( rc522_find_card(card_test)==1)
			{
				      Line_1A_WT588S(1);//打卡成功
		            HAL_Delay(2000);
					printf("获取卡号成功");
		   		run_app_state=1;
			}
				break;
			case 1 :     
            Add_FR(1); 
			
			      Line_1A_WT588S(13);//开始工作
		            HAL_Delay(2000);
			
				run_app_state=2;
           
			break;    
				case 2 :   
							  if(PS_Sta)	 //检测PS_Sta状态，如果有手指按下
		    {
			printf("有手指按下\r\n");
				press_FR();//刷指纹			
		   }
				  if( rc522_find_card(card_test)==1)
			{
				      Line_1A_WT588S(1);//打卡成功
		            HAL_Delay(2000);
					printf("获取卡号成功");
		   
			}
          break;			 
		}
}

// 
