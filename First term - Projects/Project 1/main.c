

#include "driver.h"
#include "control_of_alarm.h"

int main (){
	GPIO_INITIALIZATION();
	uint32_t	Presure_value;
	uint32_t Threshold_value = 20;
	while (1)
	{
		Presure_value = getPressureVal();
		if (Presure_value > Threshold_value)
		{
			High_pressure_detected();
		}
		Delay(20000);
		
	}

}
