// HASAN CEYHAN 20010011091
// Renklerin parlaklığı aşağıdaki denklemlerdeki gibi olacaktır. 
// LDR üzerine gelen ışığın açısına göre renkler yanıp sönecektir. 
// Bu açıyı hesaplamak için sin() fonksiyonu kullanılmıştır. 

// Aşağıdaki "PI" terimi LDR’yi dairesel bir eleman olarak kabul edip 
// dairesel alana düşen ışının hesaplanması için kullanılmıştır. 

// kırmızı = sin(x)
// yesil = sin(x + PI/3)
// mavi = sin(x + 2PI/3)

float RGB[3];     // RGB adında, içinde 3 adet eleman tutan değişken tanımlandı. 
int LDRpin = 0;   // LDR’nin bağlı olduğu analog-0 pini tanımlandı.
int LDRdeger;     // LDR’nin algıladığı ışık yoğunluğu tanımlandı. 
int ledKirmizi = 11; // Kırmızı led dijital 11 pininde. 
int ledYesil = 10;   // Yeşil led dijital 10 pininde. 
int ledMavi = 9;     // Mavi led dijital 9 pininde. 

void setup(){
  Serial.begin(9600);
  pinMode(ledKirmizi, OUTPUT);  // Kırmızı led çıkış elemanı 
  pinMode(ledYesil, OUTPUT);    // Yeşil led çıkış elemanı
  pinMode(ledMavi, OUTPUT);     // Mavi led çıkış elemanı 
  
  // İlk başta hiçbir led yanmayacak.
  digitalWrite(ledKirmizi, LOW); 
  digitalWrite(ledYesil, LOW); 
  digitalWrite(ledMavi, LOW); 
}

void loop(){
  // x ile tanımlanan açı yarım daire PI’ye kadar çok küçük oranda artacak. 
  for (float x=0; x<PI; x=x+0.00001){
    // abs() fonksiyonu, eksi sonuç çıkmamasını, mutlak değer çıkmasını sağlıyor.

    RGB[0] = 255*abs(sin(x*(180/PI))); 
    // Artma işlemi sırasında kırmızı led’in parlaklığı hesaplanıyor. 

    RGB[1] = 255*abs(sin((x+PI/3)*(180/PI))); 
    // Artma işlemi sırasında yeşil led’in parlaklığı hesaplanıyor. 

    RGB[2] = 255*abs(sin((x+(2*PI)/3)*(180/PI))); 
    // Artma işlemi sırasında mavi led’in parlaklığı hesaplanıyor. 
    
    LDRdeger=analogRead(LDRpin); 
    // LDR’ye düşen ışık kaydediliyor. 
    
    if(LDRdeger>200){ 
      // LDR’ye düşen ışık miktarı bizim belirlediğimiz
      // 600 değerinden büyükse işte o zaman
      // yapılan hesaplamaya göre led’ler yakılıyor.
      analogWrite(ledKirmizi, RGB[0]); 
      analogWrite(ledYesil, RGB[1]); 
      analogWrite(ledMavi, RGB[2]); 
    }
    else{
      // Parlaklık düşükse başlangıçta hepsi sönük bırakılıyor. 
      digitalWrite(ledKirmizi, LOW); 
      digitalWrite(ledYesil, LOW); 
      digitalWrite(ledMavi, LOW); 
    }

    // Led’ler arasında çok küçük bir zaman gecikmesi yaparak
    // renklerin daha net gözükmesini sağlayan
    // rastgele değerlerin eşik olarak belirlendiği for döngüsü kuruldu.
    for(int i=0; i<3; i++){
      if(RGB[i]<1){
        delay(100);
      }

      if(RGB[i]<5){
        delay(50);
      }

      if(RGB[i]<10){
        delay(10);
      }

      if(RGB[i]<100){
        delay(5);
      }
    }
    delay(1); 
  }
 }