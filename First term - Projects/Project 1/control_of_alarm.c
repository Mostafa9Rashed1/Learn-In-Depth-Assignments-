
#include "control_of_alarm.h"
#include "driver.h"
#define TIME_ALARM	40000

void High_pressure_detected()
{
	Set_Alarm_actuator(0);
	Delay(TIME_ALARM);
	Set_Alarm_actuator(1);
	Delay(TIME_ALARM);

}
