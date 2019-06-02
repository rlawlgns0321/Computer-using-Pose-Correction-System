#include <Adafruit_VL53L0X.h>
 
Adafruit_VL53L0X lox = Adafruit_VL53L0X();
//Adafruit_VL53L0X lox2 = Adafruit_VL53L0X();
 
void setup()
{
Serial.begin(115200);
 
// wait until serial port opens for native USB devices
while (! Serial)
{
delay(1);
}
 
Serial.println("Adafruit VL53L0X test");
if (!lox.begin())/* || !lox2.begin())*/
{
Serial.println(F("Failed to boot VL53L0X"));
while(1);
}
// power
Serial.println(F("VL53L0X API Simple Ranging example\n\n"));
}
 
void loop()
{
VL53L0X_RangingMeasurementData_t measure;
//VL53L0X_RangingMeasurementData_t measure2;
 
Serial.print("Reading a measurement... ");
lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!
//lox2.rangingTest(&measure2, false);
 
if (measure.RangeStatus != 4)
{ // phase failures have incorrect data
Serial.print("Distance 1(mm): "); Serial.println(measure.RangeMilliMeter);
//Serial.print("Distance 2(mm): "); Serial.println(measure2.RangeMilliMeter);
}
else
{
Serial.println(" out of range ");
}
 
delay(1000);
}
