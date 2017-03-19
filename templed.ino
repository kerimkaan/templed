// templed
// Calculate and show the room temperature with DHT11 temperature sensor and LEDs on Arduino.
// Hava sıcaklığına göre led yakma projesi. IF komutları içinde belirtilen Celcius derecesine göre mavi-kırmızı led yakar.
// github.com/kerimkaan


int mavi = 2;         // 2rd digital pin for blue led / Mavi LED 2. digital pinine bağlı
int kirmizi = 8;      // 8th digital pin for red led / Kırmızı LED 8. digital pinine bağlı
float temp;           // Defining temperature variable / Sıcaklık değişkeni
int tempPin = 0;      // A1 analog pin for temperature sensor / Sıcaklık sensör output'u A1 analog pinine bağlı

void setup() {
 Serial.begin(9600);         // Beginning for serial port / Seri port iletişimi için başlatıcı
 pinMode(mavi, OUTPUT);      // Output for blue led / Mavi LED için output
 pinMode(kirmizi, OUTPUT);   // Output for red led / Kırmızı LED için output

}

void loop() {

  temp = (5.0 * analogRead(tempPin) * 100.0) / 1024;   // Converting data to celsius / Analog pinden gelen veriyi celsius ölçeğine dönüştürme
  temp = (temp) / 9.31;                                // Converting from data to celsius / Celsius ölçeğine dönüştürme
  Serial.print("Sicaklik / Temperature = ");           // for serial port / Seri port için
  Serial.print(temp);                                  // Serial port output / Seri port data outputu
  Serial.print("*C");
  Serial.println();
  delay(1000);                                         // Delaying for coming data on pin / Pinden gelen veri için bekleme süresi
  
  if (temp > 21.19)                // IF conditions red led for desired temperature / Eğer okunan sıcaklık belirtilen değerin üstündeyse kırmızı led yanar.
  {
    digitalWrite(kirmizi, HIGH);   // sets the LED on
    delay(1000);                   // waits for a second
    digitalWrite(kirmizi, LOW);    // sets the LED off
    delay(1000);                   // waits for a second
  
  }
  
  if (temp <= 21.19)               // IF conditions blue led for desired temperature / Eğer okunan sıcaklık belirtilen değere küçük eşitse mavi led yanar.
  {
    digitalWrite(mavi,HIGH);       // sets the LED on
    delay(1000);                   // waits for a second
    digitalWrite(mavi,LOW);        // sets the LED off
    delay(1000);                   // waits for a second
    
  }
  
 

}
