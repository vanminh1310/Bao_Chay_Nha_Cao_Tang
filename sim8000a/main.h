#include "ESP32_MailClient.h"
#define emailSenderAccount    "aesp5286@gmail.com"    
#define emailSenderPassword   "123456@@"
#define emailRecipient        "taminh39@gmail.com"
#define smtpServer            "smtp.gmail.com"
#define smtpServerPort        465
#define emailSubject          "ESP32"
SMTPData smtpData;

void sendmail(String email){
  smtpData.setLogin(smtpServer, smtpServerPort, emailSenderAccount, emailSenderPassword);
  smtpData.setSender("ESP32", emailSenderAccount);
  smtpData.setPriority("High");
  smtpData.setSubject(emailSubject);
  smtpData.setMessage(email, true);
  smtpData.addRecipient(emailRecipient);

  if (!MailClient.sendMail(smtpData))
    Serial.println("Error sending Email, " + MailClient.smtpErrorReason());

  //Clear all data from Email object to free memory
  smtpData.empty();
  delay(5000);
  
  }
 
