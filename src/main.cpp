#include <Arduino.h>

#include <stdio.h>
#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>

#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#include "PrayerTimes.h"

#include <DMDESP.h>
#include <fonts/DejaVuSans9.h>
#include <fonts/DejaVuSansBold9.h>
#include <fonts/ElektronMart5x6.h>
#include <fonts/ElektronMart6x8.h>
#include <fonts/ElektronMart6x12.h>
#include <fonts/ElektronMart6x16.h>
#include <fonts/ElektronMartArabic3x6.h>
#include <fonts/ElektronMartArabic5x6.h>
#include <fonts/ElektronMartArabic6x16.h>
#include <fonts/EMKotak5x7.h>
#include <fonts/EMSans5x6.h>
#include <fonts/EMSans6x8.h>
#include <fonts/EMSans6x16.h>
#include <fonts/EMSans8x16.h>
#include <fonts/EMSansSP8x16.h>
#include <fonts/Mono5x7.h>
#include <fonts/TimesNewRoman10.h>
#include <fonts/TimesNewRoman16.h>
#include <fonts/BernardMTCondensed10.h>
#include <fonts/BernardMTCondensed16.h>
#include <fonts/BodoniMTBlack16.h>
#include <fonts/BauhausMdBT16.h>
#include <fonts/SystemFont5x7.h>
#include <fonts/Font6x7.h>
#include <fonts/Droid_Sans_12.h>
#include <fonts/Droid_Sans_16.h>
#include <fonts/Tahoma11x12.h>
#include <fonts/Arial14.h>
#include <fonts/Corsiva_12.h>
#include <fonts/TimesNewRoman12.h>
#include <fonts/Distro12.h>






#define Font1 DejaVuSans9
#define Font5 ElektronMart6x12 // dipakai
#define Font6 ElektronMart6x16 // dipakai
#define Font23 SystemFont5x7 // dipakai
#define Font24 Font6x7 // dipakai
#define Font30 TimesNewRoman12 //dipakai

const char *ssid     = "lutfi";
const char *password = "innovate";

#define DISPLAYS_WIDE 4 // Kolom Panel
#define DISPLAYS_HIGH 1 // Baris Panel
DMDESP Disp(DISPLAYS_WIDE, DISPLAYS_HIGH);  // Jumlah Panel P10 yang digunakan (KOLOM,BARIS)

typedef struct waktuSholat{
  int menit;
  int jam;
}wSholat_t;

typedef struct namaSholat{
  wSholat_t subuh;
  wSholat_t terbit;
  wSholat_t dzuhur;
  wSholat_t ashar;
  wSholat_t terbenam;
  wSholat_t maghrib;
  wSholat_t isya;
}nSholat_t;

tmElements_t tm;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 7*3600);
nSholat_t w;

const char *monthName[12] = {
  "JAN", "FEB", "MAR", "APR", "MEI", "JUN",
  "JUL", "AGS", "SEP", "OKT", "NOV", "DES"
};


double times[sizeof(TimeName)/sizeof(char*)];

void p(char *fmt, ... ){
        char tmp[128]; // resulting string limited to 128 chars
        va_list args;
        va_start (args, fmt );
        vsnprintf(tmp, 128, fmt, args);
        va_end (args);
        Serial.print(tmp);
}

unsigned long previousMillis = 0;
const long interval = 1000;


unsigned long previousMillis2 = 0;
const long interval2 = 5*60000;

unsigned long previousMillis3 = 0;
const long interval3 = 500;

//PATI
float lat = -6.5358719;
float lng = 110.9699272;
int timeoffset = 7;
int sudut_Fajr = 18;
int sudut_Isha = 17;

// Variabel
byte Jam;
byte Men;
byte Det;
uint8_t last_minute = 99;
uint8_t display_num = 7;
uint8_t display_sub =0;
uint8_t display_count = 0;

//mode display
int display_mode = 0;
bool detik = true;
bool idul_fitri = false;

static char *teks1[] = {"RAPATKAN DAN LURUSKAN SHOF SAAT SHOLAT BERJAMAAH"};
static char *teks2[] = {"MATIKAN HP SAAT DI DALAM MASJID"};
static char *teks3[] = {"MASJID BAITUL MA'MUR DUKUH PLANDAN, RT 01 / RW 06, DESA NGABLAK"};
static char *text4[] = {"SELAMAT HARI RAYA IDUL FITRI"};

char jam[9];
char subuh[6];
char terbit[6];
char dhuhur[6];
char asar[6];
char magrib[6];
char isa[6];


void setRTC_withNTP(){

  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.begin();
  while(!timeClient.update()){
    timeClient.forceUpdate();
  }
    
  unsigned long epochTime = timeClient.getEpochTime();
  setTime(epochTime);
  
  RTC.set(now());
}

void print2digits(int number) {
  if (number >= 0 && number < 10) {
    Serial.write('0');
  }
  Serial.print(number);
}

void display_time_serial(){
    print2digits(tm.Hour);
    Serial.write(':');
    print2digits(tm.Minute);
    Serial.print(", Date (D/M/Y) = ");
    Serial.print(tm.Day);
    Serial.write('/');
    Serial.print(tm.Month);
    Serial.write('/');
    Serial.print(tmYearToCalendar(tm.Year));
    Serial.println();
}

void get_time_RTC(){
  if (RTC.read(tm)) {
    Serial.print("Ok, Time");
  } else {
    if (RTC.chipPresent()) {
      Serial.println("The DS1307 is stopped.  Please run the SetTime");
      Serial.println("example to initialize the time and begin running.");
      // setRTC_withNTP();
      Serial.println();
    } else {
      Serial.println("DS1307 read error!  Please check the circuitry.");
      Serial.println();
    }
    delay(9000);
  }
}


void get_prayer_time(){
  Serial.println("get prayer time");
  set_calc_method(MWL);
  set_asr_method(Shafii);
  set_high_lats_adjust_method(AngleBased);
  set_fajr_angle(sudut_Fajr);
  set_isha_angle(sudut_Isha);
  get_prayer_times(tmYearToCalendar(tm.Year), tm.Month, tm.Day, lat, lng, timeoffset, times);
  

  for (int i=0;i<sizeof(times)/sizeof(double);i++){
    char tmp[10];
    int hours, minutes;
    get_float_time_parts(times[i], hours, minutes);
    // p("%d \t %10s %s \t %02d:%02d \n\r",i ,TimeName[i], dtostrf(times[i],2,2,tmp), hours, minutes);
    if(i == 0){
      w.subuh.jam = hours;
      w.subuh.menit = minutes;
    }
    else if(i == 1){
      w.terbit.jam = hours;
      w.terbit.menit = minutes; 
    }
    else if(i == 2){
      w.dzuhur.jam = hours;
      w.dzuhur.menit = minutes;
    }
    else if(i == 3){
      w.ashar.jam = hours;
      w.ashar.menit = minutes;
    }
    else if(i == 4){
      w.terbenam.jam = hours;
      w.terbenam.menit = minutes;
    }
    else if(i == 5){
      w.maghrib.jam = hours;
      w.maghrib.menit = minutes;
    }
    else if(i == 6){
      w.isya.jam = hours;
      w.isya.menit = minutes;
    }
  }
}

void print_prayer_tine(){
  p("subuh    : %02d:%02d\n\r", w.subuh.jam, w.subuh.menit);
  p("terbit   : %02d:%02d\n\r", w.terbit.jam, w.terbit.menit);
  p("dzuhur   : %02d:%02d\n\r", w.dzuhur.jam, w.dzuhur.menit);
  p("ashar    : %02d:%02d\n\r", w.ashar.jam, w.ashar.menit);
  p("terbenam : %02d:%02d\n\r", w.terbenam.jam, w.terbenam.menit);
  p("magrib   : %02d:%02d\n\r", w.maghrib.jam, w.maghrib.menit);
  p("isya     : %02d:%02d\n\r", w.isya.jam, w.isya.menit);
}

void clear_display(){
  Disp.clear();
}

void TeksJalan1(int y, uint8_t kecepatan) {

  static uint32_t pM;
  static uint32_t x;
  int width = Disp.width();
  Disp.setFont(Font24);
  
  int fullScroll = Disp.textWidth(teks1[0]) + width;
  if((millis() - pM) > kecepatan) { 
    pM = millis();
    if (x < (fullScroll)) {
      ++x;
    } else {
      x = 0;
      display_num = 2;
      display_sub = 1;
      Disp.clear();
      return;
    }
    int a = width - x;
    Disp.drawText(a, y, teks1[0]);
  }  
}

void TeksJalan2(int y, uint8_t kecepatan) {

  static uint32_t pM;
  static uint32_t x;
  int width = Disp.width();
  Disp.setFont(Font24);
  int fullScroll = Disp.textWidth(teks2[0]) + width;
  if((millis() - pM) > kecepatan) { 
    pM = millis();
    if (x < (fullScroll)) {
      ++x;
    } else {
      x = 0;
      if(idul_fitri){
        display_num = 6;

      }
      else{
        display_num = 7;
        
      }
      Disp.clear();
      return;
    }
    int a = width - x;
    Disp.drawText(a, y, teks2[0]);
  }  
}

void TeksJalan3(int y, uint8_t kecepatan){
  static uint32_t pM;
  static uint32_t x;
  int width = Disp.width();
  Disp.setFont(Font30);
  int fullScroll = Disp.textWidth(teks3[0]) + width;
  if((millis() - pM) > kecepatan) { 
    pM = millis();
    if (x < (fullScroll)) {
      ++x;
    } else {
      x = 0;
      display_num = 4;
      display_sub = 1;
      Disp.clear();
      return;
    }
    int a = width - x;
    Disp.drawText(a, y, teks3[0]);
  }  
}

void TeksJalan4(int y, uint8_t kecepatan){
  static uint32_t pM;
  static uint32_t x;
  int width = Disp.width();
  Disp.setFont(Font30);
  int fullScroll = Disp.textWidth(text4[0]) + width;
  if((millis() - pM) > kecepatan) { 
    pM = millis();
    if (x < (fullScroll)) {
      ++x;
    } else {
      x = 0;
      display_num = 7;
      display_sub = 1;
      Disp.clear();
      return;
    }
    int a = width - x;
    Disp.drawText(a, y, text4[0]);
  }  
}


void text_sholat1(){
  static uint32_t pM;
  static int32_t x ;
  static int32_t stop;
  if((millis() - pM) > 60) { 
    pM = millis();
    if (x < (16)) {
      ++x;
    } else {
      stop++;

      if(stop > 100){
        stop  = 0;
        x = 0;
        display_sub = 2;
        Disp.clear();
        return;
      } 
      
    }
   
    // int a =  - x;
    Disp.drawText(45, x-7,  subuh);
    Disp.drawText(45, x-15, "     ");
    Disp.drawText(45, x-15, "SUBUH");
    Disp.drawText(45, x-22, "     ");

    Disp.drawText(87, x-7,  terbit);
    Disp.drawText(87, x-15, "      ");
    Disp.drawText(84, x-15, "TERBIT");
    Disp.drawText(84, x-22, "      ");

    // Disp.drawText(32, x-14, "SUBUH");
  }  
}

void text_sholat2(){
  static uint32_t pM;
  static int32_t x ;
  static int32_t stop;
  if((millis() - pM) > 60) { 
    pM = millis();
    if (x < (16)) {
      ++x;
    } else {
      stop++;

      if(stop > 100){
        stop  = 0;
        x = 0;
        display_sub = 3;
        Disp.clear();
        return;
      } 
      
    }
   

    // int a =  - x;
    Disp.drawText(45, x-7,  dhuhur);
    Disp.drawText(45, x-15, "     ");
    Disp.drawText(42, x-15, "DZUHUR");
    Disp.drawText(42, x-22, "      ");

    Disp.drawText(87, x-7,  asar);
    Disp.drawText(87, x-15, "     ");
    Disp.drawText(87, x-15, "AZHAR");
    Disp.drawText(87, x-22, "     ");

    // Disp.drawText(32, x-14, "SUBUH");
  }  
}

void text_sholat3(){
  static uint32_t pM;
  static int32_t x ;
  static int32_t stop;
  if((millis() - pM) > 60) { 
    pM = millis();
    if (x < (16)) {
      ++x;
    } else {
      stop++;

      if(stop > 100){
        stop  = 0;
        x = 0;
        display_sub = 0;
        Disp.clear();
        display_num++;
        return;
      } 
      
    }
   

    // int a =  - x;
    Disp.drawText(45, x-7,  magrib);
    Disp.drawText(45, x-15, "     ");
    Disp.drawText(39, x-15, "MAGHRIB");
    Disp.drawText(39, x-22, "       ");

    Disp.drawText(87, x-7,  isa);
    Disp.drawText(87, x-14, "     ");
    Disp.drawText(90, x-15, "ISYA");
    Disp.drawText(87, x-22, "       ");

    // Disp.drawText(32, x-14, "SUBUH");
  }  
}



void display(){

  if(display_num == 0){ //buat selama 10 detik
    // DISPLAY 0 
    Disp.setFont(Font24);
    Disp.drawText(59,1,"MASJID");
    Disp.drawText(37,9,"BAITUL MA'MUR");
  }

  else if(display_num == 1){
    // DISPLAY 1
    Disp.setFont(Font24); //23
    char date[9];
    sprintf(date,"%d-%s-%d", tm.Day, monthName[tm.Month-1], tmYearToCalendar(tm.Year));
    Disp.drawText(43,1,date);//48
    TeksJalan1(9, 90); //info 1
  }

  else if(display_num == 2){
    // DISPLAY 2
    Disp.setFont(Font23);
    if(display_sub == 1){
      Disp.drawLine(35, 2, 35, 13);
      Disp.drawLine(36, 2, 43, 2);
      Disp.drawLine(36, 13, 43, 13);

      Disp.drawLine(75, 2, 82, 2);
      Disp.drawLine(75, 13, 85, 13);

      Disp.drawLine(124, 2, 124, 13);
      Disp.drawLine(120, 2, 123, 2);
      Disp.drawLine(117, 13, 123, 13);

      text_sholat1();
    }
    else if(display_sub == 2){
      Disp.drawLine(35, 2, 35, 13);
      Disp.drawLine(36, 2, 40, 2);
      Disp.drawLine(36, 13, 43, 13);

      Disp.drawLine(78, 2, 85, 2);
      Disp.drawLine(75, 13, 85, 13);

      Disp.drawLine(124, 2, 124, 13);
      Disp.drawLine(117, 2, 123, 2);
      Disp.drawLine(117, 13, 123, 13);

      text_sholat2();
    }
    else if(display_sub == 3){
      Disp.drawLine(35, 2, 35, 13);
      Disp.drawLine(36, 2, 37, 2);
      Disp.drawLine(36, 13, 43, 13);

      Disp.drawLine(81, 2, 89, 2);
      Disp.drawLine(75, 13, 85, 13);

      Disp.drawLine(124, 2, 124, 13);
      Disp.drawLine(114, 2, 123, 2);
      Disp.drawLine(117, 13, 123, 13);
      text_sholat3();
    }
  }

  else if(display_num == 3){
    // DISPLAY 3
    Disp.drawLine(32, 1, 128, 1);
    Disp.drawLine(32, 13, 128, 13);
    Disp.drawLine(32, 14, 128, 14);

    TeksJalan3(2, 90);
  }

  else if(display_num == 4){
  // DISPLAY 4
    Disp.setFont(Font23);
    if(display_sub == 1){
      Disp.drawLine(35, 2, 35, 13);
      Disp.drawLine(36, 2, 43, 2);
      Disp.drawLine(36, 13, 43, 13);

      Disp.drawLine(75, 2, 82, 2);
      Disp.drawLine(75, 13, 85, 13);

      Disp.drawLine(124, 2, 124, 13);
      Disp.drawLine(120, 2, 123, 2);
      Disp.drawLine(117, 13, 123, 13);

      text_sholat1();
    }
    else if(display_sub == 2){
      Disp.drawLine(35, 2, 35, 13);
      Disp.drawLine(36, 2, 40, 2);
      Disp.drawLine(36, 13, 43, 13);

      Disp.drawLine(78, 2, 85, 2);
      Disp.drawLine(75, 13, 85, 13);

      Disp.drawLine(124, 2, 124, 13);
      Disp.drawLine(117, 2, 123, 2);
      Disp.drawLine(117, 13, 123, 13);

      text_sholat2();
    }
    else if(display_sub == 3){
      Disp.drawLine(35, 2, 35, 13);
      Disp.drawLine(36, 2, 37, 2);
      Disp.drawLine(36, 13, 43, 13);

      Disp.drawLine(81, 2, 89, 2);
      Disp.drawLine(75, 13, 85, 13);

      Disp.drawLine(124, 2, 124, 13);
      Disp.drawLine(114, 2, 123, 2);
      Disp.drawLine(117, 13, 123, 13);
      text_sholat3();
    }
  }

  else if(display_num == 5){
    // DISPLAY 5
    Disp.setFont(Font24); //23
    char date[9];
    sprintf(date,"%d-%s-%d", tm.Day, monthName[tm.Month-1], tmYearToCalendar(tm.Year));
    Disp.drawText(43,1,date);//48

    TeksJalan2(9, 90); //info 1

  }

  else if(display_num == 6){
    Disp.drawLine(32, 1, 128, 1);
    Disp.drawLine(32, 13, 128, 13);
    Disp.drawLine(32, 14, 128, 14);

    TeksJalan4(2, 90);
    
  }
 

  // fix display 

  Disp.setFont(Font6);
  Disp.drawText(0,0," ");
  Disp.drawText(1,0,jam);
  

  if(detik){
    
    Disp.setFont(Font5);
    Disp.drawText(15,2,":");
    // Serial.println("detik true");
  }
  else{
    Disp.setFont(Font5);
    Disp.drawText(15,2,"");
    // Serial.println("detik false");
  }
  
  Disp.loop();

}



void setup() {

  Serial.begin(9600);

  //display
  Disp.start(); // Jalankan library DMDESP
  Disp.setBrightness(1); // Tingkat kecerahan
  Disp.setFont(Font1); // Huruf default
  // delay(1000);

  // setRTC_withNTP(); //aktifkan jika ingin melakukan kalibrasi waktu
  get_prayer_time();
}


void loop() {
  
  unsigned long currentMillis = millis();
  display();
  

  // // 1 detk
  if(currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;

    get_time_RTC();

    if((tmYearToCalendar(tm.Year) == 2024 && tm.Month == 4 && tm.Day > 7) && (tmYearToCalendar(tm.Year) == 2024 && tm.Month == 4 && tm.Day < 18)){
      idul_fitri = true;
      // Serial.println("idul fitri true");

    }
    else{
     
      idul_fitri = false;
      // Serial.println("idul fitri false");
    }

    if(display_num == 0) {
      display_count++;
      if(display_count == 10) {
        display_count = 0;
        display_num = 1;
        Disp.clear();
      }
    }   

    if(display_num == 7){
      get_prayer_time();
      sprintf(subuh, "%02d:%02d", w.subuh.jam,    w.subuh.menit);
      sprintf(terbit,"%02d:%02d", w.terbit.jam, w.terbit.menit);
      sprintf(dhuhur,"%02d:%02d", w.dzuhur.jam,   w.dzuhur.menit);
      sprintf(asar,  "%02d:%02d", w.ashar.jam,    w.ashar.menit);
      sprintf(magrib,"%02d:%02d", w.maghrib.jam,  w.maghrib.menit);
      sprintf(isa,   "%02d:%02d", w.isya.jam,     w.isya.menit);
      display_num = 0;

    }
  }

  //tiap awal menit
  if(last_minute != tm.Minute){
    display_time_serial();
    sprintf(jam,"%02d   %02d", tm.Hour, tm.Minute);
    last_minute = tm.Minute;
  }

  if(currentMillis - previousMillis3 >= interval3){
    previousMillis3 = currentMillis;
    if(detik) detik = false;
    else detik = true;
  }
}


