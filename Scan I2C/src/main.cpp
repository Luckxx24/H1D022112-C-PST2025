#include <Arduino.h>
#include <Wire.h>

int SDA_pin = D3; //deklarasi variabel pin untuk pin sda 
int SCL_pin = D2; //deklarasi variabel pin untuk pin scl

// put function declarations here:


void setup() {
  // put your setup code here, to run once:
  Wire.begin(SDA_pin,SCL_pin); //menginisialisais pin sda dan scl
  Serial.begin(9600);   //memulai sebanyak 96 detik
}

void loop() {
  // put your main code here, to run repeatedly:
  byte error,address;   
  int nDevices;

  Serial.print("scanning....");   // memprint scanning
  nDevices = 0;

  for(address = 1;address < 127; address++){   //melooping sampai menemukan  alamat lcd dari addres 1-127
    Wire.beginTransmission(address);
    error=Wire.endTransmission();

    if(error == 0){  // jika kode mengembalikan angak 0 maka tidak error yang mana berarrti sukses dan akan membaca almata yang sesuai
      Serial.print("I2C TERBACA PADA ALAMAT 0X");
      if(address<16){
        Serial.print("0");
      }
      Serial.print(address,HEX);
      Serial.print(".....");

      nDevices++;
    }else if(error == 4){   //jika kode error mengembalikan angak 4 maka akan mengeprint Ada error yang tidak diketahui di alamat
     Serial.print("Ada error yang tidak diketahui di alamat ");
     if(address<16){
      Serial.print("0");
     }
     Serial.print(address,HEX);
    }
  }

  if(nDevices == 0){  //jika ndevices mengembalikan angka 0 berarti led nya gak terdeteksi 
    Serial.print("tidak ada alamat i2c yang terdeteksi");

  }else{
    Serial.print("selesai");
  }

  delay(1000);
}

// put function definitions here:
