

 #include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>





int RECV_PIN = 11;   // 11 pin VS1838 IN pini

IRrecv irrecv(RECV_PIN); // Alıcı Tanımlandı

decode_results results; // alıcıya gelen sinyalin 
                        // dijital karşılığı
void setup()
{
  Serial.begin(9600); // Ekrana yazmak için
                      // Seri haberleşme başlatıldı
  irrecv.enableIRIn(); // IR haberleşme başlatıldı.
  pinMode(2,OUTPUT);   // 2. ve 3. pindeki Led ayarlandı



}
void loop() {
  if (irrecv.decode(&results)) { // sinyal algılanırsa
   Serial.println(results.value, HEX); // ekrana hex karşılığını yaz
   
        if(results.value==0xFFA25D) // CH- ise 1. Led yansın
             digitalWrite(2,LOW); 
       
          else if(results.value==0xFF629D)  // CH ise 2. Led yansın, 
              digitalWrite(2,HIGH);
  
       
    irrecv.resume();             // Yeni bir değer yeniden veri alınacak
  }
  delay(100);                  // Gelen sinyaller arasında karışıklık olmaması
                              // icin 100ms bekleniyor
}

