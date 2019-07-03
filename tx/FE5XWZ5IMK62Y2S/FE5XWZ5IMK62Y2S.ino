/*********TACHLOG powered********
*********www.troncart.com*******
**electronics components online**
***********LASER Communication**************
*************************
*/ 

int ledArray [29][6] = 
  {
  {'a', 0, 0, 0, 0, 1}, //a
  {'b', 1, 1, 1, 0, 0}, //b
  {'c', 0, 0, 0, 1, 1}, //c
  {'d', 0, 0, 1, 0, 0}, //d
  {'e', 0, 0, 1, 0, 1}, //e
  {'f', 0, 0, 1, 1, 0}, //f
  {'g', 0, 0, 1, 1, 1}, //g
  {'h', 0, 1, 0, 0, 0}, //h
  {'i', 0, 1, 0, 0, 1}, //i
  {'j', 0, 1, 0, 1, 0}, //j
  {'k', 0, 1, 0, 1, 1}, //k
  {'l', 0, 1, 1, 0, 0}, //l
  {'m', 0, 1, 1, 0, 1}, //m
  {'n', 0, 1, 1, 1, 0}, //n
  {'o', 0, 1, 1, 1, 1}, //o
  {'p', 1, 0, 0, 0, 0}, //p
  {'q', 1, 0, 0, 0, 1}, //q
  {'r', 1, 0, 0, 1, 0}, //r
  {'s', 1, 0, 0, 1, 1}, //s
  {'t', 1, 0, 1, 0, 0}, //t
  {'u', 1, 0, 1, 0, 1}, //u
  {'v', 1, 0, 1, 1, 0}, //v
  {'w', 1, 0, 1, 1, 1}, //w
  {'x', 1, 1, 0, 0, 0}, //x
  {'y', 1, 1, 0, 0, 1}, //y
  {'z', 1, 1, 0, 1, 0}, //z
  {' ', 1, 1, 0, 1, 1}, //space
  {'.', 1, 1, 1, 1, 1,},//dot
  {'/', 0, 0, 0, 1, 0,},//New line
  };
  double ledRate = 50;
  int lightUp[6]= {0,0,0,0,0,0};
  void setup()
  {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  }

  void loop() 
  {
  while(Serial.available()==0){}
  String message = Serial.readString();
  Serial.print("Transmitting now:");
  Serial.println();
  int messageSize=message.length()-1;
  char messageBreakdown[100];
  for (int i=0;i<=messageSize;i++)
    {
      messageBreakdown[i]=message[i];
      Serial.print(messageBreakdown[i]);      
      for(int j=0;j <= 29; j++)
       {  
        if (messageBreakdown[i] == ledArray[j][0])
          {
          for(int k = 1;k<6;k++)
           {
            lightUp[k]= ledArray[j][k];
            if (k == 5)
            {
                if(lightUp[1] == 1)
                {
                digitalWrite(8, HIGH);
                }
                else
                {
                digitalWrite(8, LOW);
                }
                if(lightUp[2] == 1)
                {
                digitalWrite(9, HIGH);
                }
                else
                {
                digitalWrite(9, LOW);
                }
                if(lightUp[3] == 1)
                {
                digitalWrite(10, HIGH);
                }
                else
                {
                digitalWrite(10, LOW);
                }
                if(lightUp[4] == 1)
                {
                digitalWrite(11, HIGH);
                }
                else
                {
                digitalWrite(11, LOW);
                }
                if(lightUp[5] == 1)
                {
                digitalWrite(12, HIGH);
                }
                else
                {
                digitalWrite(12, LOW);
                }
                delay(50);
              }  
           }
            break; 
         } 
       }  
          digitalWrite(8, LOW);
          digitalWrite(9, LOW);
          digitalWrite(10, LOW);
          digitalWrite(11, LOW);
          digitalWrite(12, LOW);
          delay(50);    
    }
  }
