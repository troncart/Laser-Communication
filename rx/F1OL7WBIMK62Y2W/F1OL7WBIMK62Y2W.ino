/*********TACHLOG powered********
*********www.troncart.com*******
**electronics components online**
***********LASER Communication*************
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
  double cycleRate = 50;
  int sensorInput[6]= {0,0,0,0,0,0};
  int sensorPins[6] = {0,1,2,3,4,5}; 
  int threshold[6] = {200,200,200,200,200,200};
  void setup()
  { 
  Serial.begin(9600);
  }
  
  void loop()
  {
  for(int i=1;i<6;i++)
  {
    if (analogRead(sensorPins[i]) > threshold[i])
     {
     sensorInput[i] = 1;
     }
     else
     {
     sensorInput[i] = 0;
     }
  }
    for(int i=0;i<29;i++)
      {
        for(int j=1;j<6;j++)
          {
            if (ledArray[i][j] == sensorInput[j])
              {
                if(j == 5)
                  {
                    if(ledArray[i][0]=='/')
                      {
                      Serial.println("");
                      }
                    else
                      {
                      Serial.print(char(ledArray[i][0]));
                      }
                      break;
                  }
              } 
            else
             {
             break;
             }
          }
      }
  delay(cycleRate);
  delay(5);
  }
