# ESP32 Email Project

This project demonstrates how to use the ESP32 microcontroller to send an email using the [ESP32_MailClient](https://github.com/mobizt/ESP32-Mail-Client) library. The code connects to a WiFi network, sets up SMTP credentials, and sends an HTML email from the ESP32 to a specified recipient.

## Requirements
- To setup [SMTP](https://www.gmass.co/blog/gmail-smtp/)
- ESP32 board
- Arduino IDE or a similar IDE with ESP32 support
- [ESP32_MailClient library](https://github.com/mobizt/ESP32-Mail-Client)
- A Gmail account with app-specific password

## Usage

1. Clone this repository:

    ```bash
    git clone https://github.com/your-username/esp32-email-project.git
    ```

2. Open the project in your Arduino IDE.

3. Configure the WiFi and email settings in the `esp32_email.ino` file.

4. Upload the code to your ESP32 board.

## Configuration

In the `esp32_email.ino` file, configure the following settings:

- **WiFi credentials**:

    ```cpp
    const char* ssid = "your-ssid";
    const char* password = "your-password";
    ```

- **Email sender and recipient**:

    ```cpp
    #define emailSenderAccount "your-email@gmail.com"
    #define emailSenderPassword "your-app-specific-password"
    #define emailRecipient "recipient-email@gmail.com"
    ```

## Code Explanation

- Connects to WiFi network and sets up SMTP server and login credentials.
- Defines the email sender, priority, subject, and message content.
- Adds an email recipient.
- Sends an email using `MailClient.sendMail(smtpData)`.
- `sendCallback` function handles the email sending status.

## License

This project is open-source. See the [LICENSE](LICENSE) file for more information.
