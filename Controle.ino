  #include <IRremote.h>  //including infrared remote header file     
int RECV_PIN = 7; // the pin where you connect the output pin of IR sensor     


IRrecv irrecv(RECV_PIN);     
decode_results results;     


#define led1 11
#define led2 12
#define led3 13
#define buzzerPin 10



boolean cl1 = LOW;
boolean cl2 = LOW;
boolean cl3 = LOW;



void alarm() {
  for(int i=0;i<200;i++) {
    digitalWrite(buzzerPin,LOW);
    delay(0.9);//wait for 1ms
    digitalWrite(buzzerPin,HIGH);
    delay(0.9);//wait for 1ms
  }
}
  
void setup()     
{     

  pinMode(buzzerPin, OUTPUT);   
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);     
irrecv.enableIRIn();  
  

}    
void loop(){     
if (irrecv.decode(&results))// Returns 0 if no data ready, 1 if data ready.     
{ 
//4294967295


  Serial.println(" ");        
 Serial.println(results.value, HEX); //prints the value a a button press  

    switch(results.value){
      case 0xFFE817:
        cl1 = !cl1;
        digitalWrite(led1, cl1);
        alarm();
        delay(500);
        break;
      case 0xFFC03F:
        cl2 = !cl2;
        digitalWrite(led2, cl2);
        alarm();
        delay(500);
        break;
      case 0xFF40BF:
        cl3 = !cl3;
        digitalWrite(led3, cl3);
        alarm();
        delay(500);
        break;
      default:
        Serial.println("botao nao cadastrado");
        alarm();
        delay(500);
        alarm();
        delay(500);
    }

         
  
 irrecv.resume(); // Restart the ISR state machine and Receive the next value     


}     


}
