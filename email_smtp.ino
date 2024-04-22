#include "ESP32_MailClient.h"
#include <WiFi.h>

const char* ssid = "Iqoo 9 pro";
const char* password = "nishadhhussain";

#define emailSenderAccount "nishm200012@gmail.com"
#define emailSenderPassword "xxpr rmhi zwry uwkb"
#define emailRecipient "annalakshmisuriyanarayan@gmail.com"
#define smtpServer "smtp.gmail.com"
#define smtpServerPort 465
#define emailSubject "ESP32 Testing Email"

SMTPData smtpData;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); 
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("WiFi connected");

  smtpData.setLogin(smtpServer, smtpServerPort, emailSenderAccount, emailSenderPassword);
  smtpData.setSender("ESP32 Sender", emailSenderAccount);
  smtpData.setPriority("High");
  smtpData.setSubject(emailSubject);
  //smtpData.setMessage("Hi from Nishadh", false);
  smtpData.setMessage("<p style=\"text-align: center;\"><span style=\"color: #ff0000;\">Hi from Nishadh</span></p>", true);
  smtpData.addRecipient(emailRecipient);

  if(!MailClient.sendMail(smtpData)){
    Serial.println("error" + MailClient.smtpErrorReason()) ;

    smtpData.empty();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}

void sendCallback(SendStatus message){
  Serial.println(message.info());

  if(message.success())
  {
    Serial.print("++");
  }
}
