#include <SoftwareSerial.h>

// Arduino Uno R3 için
// Yazılımsal Seri Port'un RX ve TX pini
int RX = 2; 
int TX = 3; 

// HC-06 modülünü tanımlayalım
SoftwareSerial bluetoothSerial(RX, TX);

void setup() {
  // Seri haberleşme başlatılır
  Serial.begin(9600);
  // HC-06 için haberleşme başlatılır
  bluetoothSerial.begin(9600);

  // Başlangıç mesajı
  Serial.println("\n HC-06 Bluetooth modulu baglantisi kuruldu.");
}
void loop() {  
  
  // Bilgisayardan HC-06'ya veri gönder
  if (Serial.available()) {
    char incomingByte = Serial.read();
    bluetoothSerial.write(incomingByte);
  }  
  
  // HC-06'dan bilgisayara veri gönder
  if (bluetoothSerial.available()) {
    char incomingByte = bluetoothSerial.read();
    Serial.write(incomingByte);
  }
}
