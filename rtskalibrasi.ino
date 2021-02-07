/*
 * kalibrasi untuk rtc d3231
 * by :  ajang rahmad
 * Develop by : made agus andi gunawan
 * 
 */
#include "DS3231_Simple.h"

DS3231_Simple Clock;

void setup() 
{
  Serial.begin(9600);
  Clock.begin();
}

void loop()
{ 
  DateTime waktu;
  waktu.Day    = 6;       //atur tanggal
  waktu.Month  = 2;      //atur bulan
  waktu.Year   = 21;      //atur tahun
  waktu.Hour   = 15;      //atur jam
  waktu.Minute = 42;      //atur menit
  waktu.Second = 0;      //atur detik
  Clock.write(waktu);
  
  Serial.print("Waktu telah di atur ke: ");
  Clock.printTo(Serial);
  Serial.println();
  
  Serial.print("Program berakhir (RESET untuk menjalakan lagi)");
  while(1);
}
