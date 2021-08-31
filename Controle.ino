  #include <IRremote.h>  //including infrared remote header file     
int RECV_PIN = 7; // the pin where you connect the output pin of IR sensor     


IRrecv irrecv(RECV_PIN);     
decode_results results;     


#define led1 10
#define led2 11
#define led3 12


boolean cl1 = LOW;
boolean cl2 = LOW;
boolean cl3 = LOW;


void setup()     
{     
Serial.begin(9600);     
irrecv.enableIRIn();     
  pinMode(led1, INPUT);
  pinMode(led2, INPUT);
  pinMode(led3, INPUT);


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
        delay(500);
        break;
      case 0xFFC03F:
        cl2 = !cl2;
        digitalWrite(led2, cl2);
        delay(500);
        break;
      case 0xFF40BF:
        cl3 = !cl3;
        digitalWrite(led3, cl3);
        delay(500);
        break;
      default:
        Serial.println("botao nao cadastrado");
      
        
        
    }

         
  
 irrecv.resume(); // Restart the ISR state machine and Receive the next value     


}     
}
