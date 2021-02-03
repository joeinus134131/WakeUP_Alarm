/* 
 *  kodingan ini dibuat dan dikembangkan dari penggabungan dan penambahan fungsi tmbahan baru dari penulis
 *  Alarm Bangun Tidur
 *  Develop by : CorpseLily(Made agus andi gunawan)
 *  IDNmakerspace Algorithm Factory
 */
 
#include <Wire.h>
#include <Time.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
#include <RTClib.h>

RTC_DS1307 rtc;

const int RelayPin = 7;
char namaHari[7][12] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};

void setup()
{
  Serial.begin(9600);
  pinMode(RelayPin,OUTPUT);  
  
  if (! rtc.begin()) 
  {
    Serial.println("RTC TIDAK TERBACA");
    while (1);
  }

  if (! rtc.isrunning()) 
  {
    Serial.println("RTC Tidak Berjalan");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));    
  }
}

void loop() 
{
 DateTime now = rtc.now();
    Serial.print(namaHari[now.dayOfTheWeek()]);  
    Serial.print(',');    
    Serial.print(now.day(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.year(), DEC);
    Serial.print(" ");   
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
   
    delay(1000);

    if (now.hour() == 4 && now.minute() == 0)   //bangun pagi
    { 
      digitalWrite(RelayPin, HIGH);
      Serial.print("Bangunnn...");
      delay(10);
    }
    else if (now.hour() == 4 && now.minute() == 10)
    {   
      digitalWrite(RelayPin, LOW);
    }
    delay(1000);  
}
  
