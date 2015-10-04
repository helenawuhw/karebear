/*

Voice Recognition Shield Example

This example shows an application on 1Sheeld's voice recognition shield.

By using this example, you can play, pause and stop your smartphone's 
music using voice commands.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_VOICE_RECOGNIZER_SHIELD
#define INCLUDE_MIC_SHIELD
#define INCLUDE_TEXT_TO_SPEECH_SHIELD
#define INCLUDE_MUSIC_PLAYER_SHIELD
/* Include 1Sheeld library. */
#include <OneSheeld.h>

int red = 12;
int green = 13;

/* A command which will be compared. */
const char hellobear[]="hello care bear";
const char mommylove[]="tell mommy i love her";
const char goodbyebear[]="goodbye care bear";
const char daddylove[]="tell daddy i love him";
const char birthday[]="it's my birthday";


void setup()
{
  Serial.begin(115200);
  /* Start Communication. */
  OneSheeld.begin();
  VoiceRecognition.start();
  /* Error Commands handiling. */
  VoiceRecognition.setOnError(error);

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop () 
{

  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  /* Check if new command received. */
  /* Check if the voice command is the desired one. */
  if(VoiceRecognition.isNewCommandReceived())
  {
    if(!strcmp(hellobear,VoiceRecognition.getLastCommand()))
    {
      digitalWrite(red, LOW);
      digitalWrite(green, HIGH);
      TextToSpeech.say("Hello, I am Listening");
      Serial.println("Listening...");
      delay(2000);
      VoiceRecognition.start();
      delay(2000);
    }
    else if(!strcmp(mommylove,VoiceRecognition.getLastCommand()))
    {
        digitalWrite(red, LOW);
        digitalWrite(green, HIGH);
        delay(2000);
        TextToSpeech.say("Telling mommy you love her");
        Serial.println("mom received love");
        delay(2000);
        VoiceRecognition.start();
        delay(2000);
    }
    else if(!strcmp(daddylove,VoiceRecognition.getLastCommand()))
    {
        digitalWrite(red, LOW);
        digitalWrite(green, HIGH);
        delay(2000);
        TextToSpeech.say("Telling daddy you love him");
        Serial.println("dad received love");
        delay(2000);
        VoiceRecognition.start();
        delay(2000);
    }
    else if(!strcmp(birthday,VoiceRecognition.getLastCommand()))
    {
        digitalWrite(red, LOW);
        digitalWrite(green, HIGH);
        delay(2000);
        TextToSpeech.say("Happy birthday!");
        Serial.println("happy birthday");
        delay(2000);
        MusicPlayer.play();
        delay(10000);
        VoiceRecognition.start();
        delay(2000);
    }
    else if(!strcmp(goodbyebear,VoiceRecognition.getLastCommand()))
    {
      digitalWrite(red, LOW);
      digitalWrite(green, HIGH);
      TextToSpeech.say("Goodbye");
      Serial.println("goodbye");
      delay(2000);

    }
    else{
      TextToSpeech.say("I'm sorry, can you say that again?");
      delay(2000);
      VoiceRecognition.start();
      delay(2000);
    }

  }

}

/* Error checking function. */
void error(byte errorData)
{
  /* Switch on error and print it on the terminal. */
  switch(errorData)
  {
    case AUDIO_ERROR: Serial.println("Audio error");break;
    case SPEECH_TIMEOUT_ERROR: Serial.println("Speech timeout");break;
    case RECOGNIZER_BUSY_ERROR: Serial.println("Busy");break;
  }
}
