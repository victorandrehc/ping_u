int led = 13;  // led to use for output (13 is built-in)

int dit_delay = 500;           // length of a dit in ms
int dah_delay = dit_delay * 3; // length of a dah in ms

// dit() and dat() already include dit_delay
int letter_delay = dah_delay - dit_delay;

// letters already include letter delay
int word_delay   = dit_delay * 7 - letter_delay;

void dit() {
    Serial.print(".");

    // send a dit
    digitalWrite(led, HIGH);
    delay(dit_delay);

    digitalWrite(led, LOW);
    delay(dit_delay);
}

void dah() {
    Serial.print("-");

    // send a dah
    digitalWrite(led, HIGH);
    delay(dah_delay);

    digitalWrite(led, LOW);
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
  dit(); dit(); dit();
  pause_letter();
}

void morse_O() {
  dah(); dah(); dah();
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
        dah(); dah(); dah(); dah(); dah();
    }
    if (n == 1) {
        dit(); dah(); dah(); dah(); dah();
    }
    if (n == 2) {
        dit(); dit(); dah(); dah(); dah();
    }
    if (n == 3) {
        dit(); dit(); dit(); dah(); dah();
    }
    if (n == 4) {
        dit(); dit(); dit(); dit(); dah();
    }
    if (n == 5) {
        dit(); dit(); dit(); dit(); dit();
    }
    if (n == 6) {
        dah(); dit(); dit(); dit(); dit();
    }
    if (n == 7) {
        dah(); dah(); dit(); dit(); dit();
    }
    if (n == 8) {
        dah(); dah(); dah(); dit(); dit();
    }
    if (n == 9) {
        dah(); dah(); dah(); dah(); dit();
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
  pinMode(led, OUTPUT);

  // Use serial port as output
  Serial.begin(9600);
}

void morse_letter(char c) {
  Serial.print("morse_letter(");
  Serial.print(c);
  Serial.println(")...");
  switch (c) {
    case 'a':{dit();dah();break;}
    case 'b':{dah();dit();dit();dit();break;}
    case 'c':{dah();dit();dah();dit();break;}
    case 'd':{dah();dit();dit();break;}
    case 'e':{dit();break;}
    case 'f':{dit();dit();dah();dit();break;}
    case 'g':{dah();dah();dit();break;}
    case 'h':{dit();dit();dit();dit();break;}
    case 'i':{dit();dit();break;}
    case 'j':{dit();dah();dah();dah();break;}
    case 'k':{dah();dit();dah();break;}
    case 'l':{dit();dah();dit();dit();break;}
    case 'm':{dah();dah();break;}
    case 'n':{dah();dit();break;}
    case 'o':{dah();dah();dah();break;}
    case 'p':{dit();dah();dah();dit();break;}
    case 'q':{dah();dah();dit();dah();break;}
    case 'r':{dit();dah();dit();break;}
    case 's':{dit();dit();dit();break;}
    case 't':{dah();break;}
    case 'u':{dit();dit();dah();break;}
    case 'v':{dit();dit();dit();dah();break;}
    case 'w':{dit();dah();dah();break;}
    case 'x':{dah();dit();dit();dah();break;}
    case 'y':{dah();dit();dah();dah();break;}
    case 'z':{dah();dah();dit();dit();break;}
  }
  pause_letter();
  Serial.print("morse_letter(");
  Serial.print(c);
  Serial.println(")...done");
}

void morse_word(String s){
  Serial.print("morse_word(");
  Serial.print(s);
  Serial.println(")...");
  for (int i = 0; i < s.length(); i++) {
    morse_letter(s[i]);
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
  morse_word("saarland");
  morse_word("university");
}

