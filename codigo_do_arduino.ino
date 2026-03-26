// Variaveis dos pinos

#define PinoLED1    5  //LED vermelho mais a esquerda
#define PinoLED2    18
#define PinoLED3    19
#define PinoLED4    4  // LED verde 
#define PinoButtD   22 // BOTAO A direita
#define PinoButtS   21 // A esquerda
#define PinoButtV   23 // o vermelho
#define SECRETO     0  //Boot
#define Buzzer      15 //SOM

// Variaveis do jogo
int vidas = 3;
String resposta_da_pessoa = "";
int Letra_Numero = 0;
char Letra_char = 'A';
boolean Enviar = false;
int pontuacao = 0; 
int fase = 1;


void setup(){ 
  Serial.begin(115200);
  pinMode(PinoLED1, OUTPUT);
  pinMode(PinoLED2, OUTPUT);
  pinMode(PinoLED3, OUTPUT);
  pinMode(PinoLED4, OUTPUT);
  pinMode(PinoButtD, INPUT_PULLUP);
  pinMode(PinoButtS, INPUT_PULLUP);
  pinMode(PinoButtV, INPUT_PULLUP);
  pinMode(SECRETO, INPUT_PULLUP);
  pinMode(Buzzer, OUTPUT);
  AleatorizarNumero();
  digitalWrite(PinoLED1,HIGH);
  digitalWrite(PinoLED2,HIGH);
  digitalWrite(PinoLED3,HIGH);

  
}



// fuçoes para o jogo
void ColocarPonto(){
	if (resposta_da_pessoa.length() == 4){
      resposta_da_pessoa = resposta_da_pessoa + ".";
  }
}

void PerderVida(){
  if(vidas == 3){
  vidas -= 1;
  digitalWrite(PinoLED3, LOW);
  }

  else if(vidas == 2){
  vidas -= 1;
  digitalWrite(PinoLED2,LOW);
  }
  else if (vidas == 1){
  vidas -= 1;
  digitalWrite(PinoLED1,LOW);
  fase = 3;
  }

}

void FazerFrase(){
  delay(200);
  if (digitalRead(PinoButtV) == LOW){
    Enviar = true; 
  }
  else if (digitalRead(SECRETO) == LOW){ // CASO O JOGADOR ERRAR ELE APAGA A RESPOSTA DADA ATE AGORA 
    ResetResposta();

  
  }

  else if (digitalRead(PinoButtD) == LOW){
    resposta_da_pessoa = resposta_da_pessoa + "1";
	  ColocarPonto();
  delay(300);
  Serial.println("A letra foi: ");
  Serial.println(Letra_char);
  Serial.println(resposta_da_pessoa);
  }
  else if (digitalRead(PinoButtS) == LOW){
    resposta_da_pessoa = resposta_da_pessoa + "0";
	ColocarPonto();
 
  delay(300);
  Serial.println("A letra foi: ");
  Serial.println(Letra_char);
  Serial.println(resposta_da_pessoa);
  }
  
}

void ResetResposta(){
  if (resposta_da_pessoa == "0101.0010" ){
    Musica_Mario();
    vidas = 3;
  } else{
  tone(Buzzer, 500, 50); // Nota média-aguda super rápida
  delay(50);             // Espera ela terminar
  tone(Buzzer, 300, 50); // Nota média-grave super rápida
  } 
  resposta_da_pessoa = "";
  Serial.println("A sua Resposta anterior foi apagada");
}
void AleatorizarNumero(){
  Letra_Numero = random(65,91);
  Letra_char = (char)Letra_Numero;
  Enviar = false;
  resposta_da_pessoa = "";
  Serial.println("A letra foi: ");
  Serial.println(Letra_char);
}

void VerVericidade(){
  String resposta = resposta_da_pessoa;
  resposta.replace(".","");
  int Vericidade = strtol(resposta.c_str(),NULL,2);
  
  if (Letra_Numero != Vericidade){
    Serial.println("Errou");
    tone(Buzzer, 200, 200);
    PerderVida();
    AleatorizarNumero();
    digitalWrite(PinoLED4,LOW);


  } else {
    Serial.println("Acertou");
    digitalWrite(PinoLED4,HIGH);
    tone(Buzzer, 3000, 200);
    AleatorizarNumero();
    
    pontuacao += 1;
  }
  delay(300);
}

void Musica_Mario(){
  tone(Buzzer, 659, 150); delay(200); // Mi
  tone(Buzzer, 659, 150); delay(200); // Mi
  delay(100);                             
  tone(Buzzer, 659, 150); delay(200); // Mi
  delay(100);                             
  tone(Buzzer, 523, 150); delay(200); // Dó
  tone(Buzzer, 659, 150); delay(200); // Mi
  delay(100);                             
  tone(Buzzer, 784, 150); delay(400); // Sol (Agudo)
  delay(100);                             
  tone(Buzzer, 392, 150); delay(400); // Sol (Grave)
  delay(100);

  tone(Buzzer, 523, 150); delay(300); // Dó
  tone(Buzzer, 392, 150); delay(300); // Sol grave
  tone(Buzzer, 330, 150); delay(300); // Mi grave
  delay(100);
  tone(Buzzer, 440, 150); delay(200); // Lá
  tone(Buzzer, 494, 150); delay(200); // Si
  tone(Buzzer, 466, 150); delay(200); // Si bemol
  tone(Buzzer, 440, 150); delay(200); // Lá
  delay(100);
  tone(Buzzer, 392, 150); delay(200); // Sol grave
  tone(Buzzer, 659, 150); delay(200); // Mi
  tone(Buzzer, 784, 150); delay(200); // Sol
  tone(Buzzer, 880, 150); delay(300); // Lá (Mais agudo!)
  tone(Buzzer, 698, 150); delay(200); // Fá
  tone(Buzzer, 784, 150); delay(200); // Sol
  delay(100);
  tone(Buzzer, 659, 150); delay(200); // Mi
  delay(100);
  tone(Buzzer, 523, 150); delay(200); // Dó
  tone(Buzzer, 587, 150); delay(200); // Ré
  tone(Buzzer, 494, 150); delay(400); // Si
}
void Musica_Inicio(){
	delay(200);
	tone(Buzzer, 600, 150); 
	delay(150);                  
  
	tone(Buzzer, 800, 150); 
	delay(150);                  

    tone(Buzzer, 1200, 300);
    delay(300);	
}

void Musica_Morte(){
	tone(Buzzer, 300, 200);  
    delay(200);                 
  
    tone(Buzzer, 250, 200);  
    delay(200);                  
  
    tone(Buzzer, 200, 200);  
    delay(200);
  
    tone(Buzzer, 150, 600);  
    delay(600);
}

void INICIO(){
    Serial.println("BORA JOGAR O JOGO DO BINARIO NO ESP32 APERTE OS DOIS BOTOES BRANCOS PARA COMEÇAR");
	while (digitalRead(PinoButtS) != LOW || digitalRead(PinoButtD) != LOW ){
    Serial.print("");
	
	}
	Musica_Inicio();
}

void JOGO(){
    FazerFrase();

    if (Enviar == true){
    VerVericidade();
    }

}
void FIM(){
	Musica_Morte();
	Serial.println("VOÇÊ MORREU, A SUA PONTUAÇÃO FOI");
    Serial.println(pontuacao);
    Serial.println("1. TENTAR NOVAMENTE");
	delay(200);
    while (digitalRead(PinoButtD) != LOW){
    delay(10);
    }
    fase = 1;
    vidas = 3;
	resposta_da_pessoa = "";
    pontuacao = 0;
    digitalWrite(PinoLED1,HIGH);
    digitalWrite(PinoLED2,HIGH);
    digitalWrite(PinoLED3,HIGH);    
}

void loop(){
  if (fase == 1){
	INICIO();
    Serial.println("A letra foi: ");
    Serial.println(Letra_char);
    fase = 2;
  }

  else if (fase == 2){
  JOGO();
  } 
  else if (fase == 3){
	FIM();
    }
  }
