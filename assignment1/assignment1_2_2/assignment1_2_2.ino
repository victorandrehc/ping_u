int led1 = 12;  // led to use for output (13 is built-in)
int led2 =13;
int dit_delay = 500;           // length of a dit in ms
int dah_delay = dit_delay * 3; // length of a dah in ms

// dit() and dat() already include dit_delay
int letter_delay = dah_delay - dit_delay;

// letters already include letter delay
int word_delay   = dit_delay * 7 - letter_delay;

void dit(int a) {
    Serial.print(".");

    // send a dit
    digitalWrite(a, HIGH);
    delay(dit_delay);

    digitalWrite(a, LOW);
    delay(dit_delay);
}

void dah(int a) {
    Serial.print("-");

    // send a dah
    digitalWrite(a, HIGH);
    delay(dah_delay);

    digitalWrite(a, LOW);
    delay(dit_delay);
}

void pause_letter() {
   Serial.println("");
   delay(letter_delay);
}

void pause_word() {
   Serial.println("");
   delay(word_delay);
}

void morse_S() {
  dit(led1); dit(led1); dit(led1);
  pause_letter();
}

void morse_O() {
  dah(led1); dah(led1); dah(led1);
  pause_letter();
}

void morse_SOS() {
    morse_S(); morse_O(); morse_S();
    pause_word();
}

// send n in morse code
void morse_digit(int n) {
    Serial.print("morse_digit(");
    Serial.print(n);
    Serial.println(")...");

    if (n == 0) {
        dah(led1); dah(led1); dah(led1); dah(led1); dah(led1);
    }
    if (n == 1) {
        dit(led1); dah(led1); dah(led1); dah(led1); dah(led1);
    }
    if (n == 2) {
        dit(led1); dit(led1); dah(led1); dah(led1); dah(led1);
    }
    if (n == 3) {
        dit(led1); dit(led1); dit(led1); dah(led1); dah(led1);
    }
    if (n == 4) {
        dit(led1); dit(led1); dit(led1); dit(led1); dah(led1);
    }
    if (n == 5) {
        dit(led1); dit(led1); dit(led1); dit(led1); dit(led1);
    }
    if (n == 6) {
        dah(led1); dit(led1); dit(led1); dit(led1); dit(led1);
    }
    if (n == 7) {
        dah(led1); dah(led1); dit(led1); dit(led1); dit(led1);
    }
    if (n == 8) {
        dah(led1); dah(led1); dah(led1); dit(led1); dit(led1);
    }
    if (n == 9) {
        dah(led1); dah(led1); dah(led1); dah(led1); dit(led1);
    }
    pause_letter();

    Serial.print("morse_digit(");
    Serial.print(n);
    Serial.println(")...done");
}

void morse_number(int n) {
    Serial.print("morse_number(");
    Serial.print(n);
    Serial.println(")...");

    if (n >= 10) {
        morse_number(n / 10);
    }
    morse_digit(n % 10);

    Serial.print("morse_number(");
    Serial.print(n);
    Serial.println(")...done");
}

void setup() {
  // put your setup code here, to run once:

  // Configure LED as output
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  // Use serial port as output
  Serial.begin(9600);
}

void morse_letter(char c, int a) {
  Serial.print("morse_letter(");
  Serial.print(c);
  Serial.println(")...");
  switch (c) {
    case 'b':{dah(a);dit(a);dit(a);dit(a);break;}
    case 'a':{dit(a);dah(a);break;}
    case 'c':{dah(a);dit(a);dah(a);dit(a);break;}
    case 'd':{dah(a);dit(a);dit(a);break;}
    case 'e':{dit(a);break;}
    case 'f':{dit(a);dit(a);dah(a);dit(a);break;}
    case 'g':{dah(a);dah(a);dit(a);break;}
    case 'h':{dit(a);dit(a);dit(a);dit(a);break;}
    case 'i':{dit(a);dit(a);break;}
    case 'j':{dit(a);dah(a);dah(a);dah(a);break;}
    case 'k':{dah(a);dit(a);dah(a);break;}
    case 'l':{dit(a);dah(a);dit(a);dit(a);break;}
    case 'm':{dah(a);dah(a);break;}
    case 'n':{dah(a);dit(a);break;}
    case 'o':{dah(a);dah(a);dah(a);break;}
    case 'p':{dit(a);dah(a);dah(a);dit(a);break;}
    case 'q':{dah(a);dah(a);dit(a);dah(a);break;}
    case 'r':{dit(a);dah(a);dit(a);break;}
    case 's':{dit(a);dit(a);dit(a);break;}
    case 't':{dah(a);break;}
    case 'u':{dit(a);dit(a);dah(a);break;}
    case 'v':{dit(a);dit(a);dit(a);dah(a);break;}
    case 'w':{dit(a);dah(a);dah(a);break;}
    case 'x':{dah(a);dit(a);dit(a);dah(a);break;}
    case 'y':{dah(a);dit(a);dah(a);dah(a);break;}
    case 'z':{dah(a);dah(a);dit(a);dit(a);break;}
  }
  pause_letter();
  Serial.print("morse_letter(");
  Serial.print(c);
  Serial.println(")...done");
}

void morse_word(String s, int a){
  Serial.print("morse_word(");
  Serial.print(s);
  Serial.println(")...");
  for (int i = 0; i < s.length(); i++) {
    morse_letter(s[i],a);
  }
  pause_word();
  Serial.print("morse_word(");
  Serial.print(s);
  Serial.println(")...done");
}

void loop() {
  // put your main code here, to run repeatedly:
  morse_SOS();
  morse_number(5024);
  morse_word("saarland",led1);
  morse_word("university",led2);
}

