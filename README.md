<img src="https://content.arduino.cc/website/Arduino_logo_teal.svg" height="100" align="right" />

# Arduino_MultiWiFi

[![License](https://img.shields.io/github/license/arduino-libraries/Arduino_MultiWiFi)](https://support.arduino.cc/hc/en-us/articles/360018434279-I-have-used-Arduino-for-my-project-do-I-need-to-release-my-source-code-)

This Arduino library provides a wrapper around the WiFi library to allow you to configure multiple networks (SSID/passphrase combinations) within your sketch, and connect to the first one in the list that is available and accessible.

This functionality is already available in the ESP32 core, but this library provides a platform-independent implementation that works with any core and with the most popular WiFi libraries used in the Arduino ecosystem (WiFi, WiFiNINA, WiFi101, ESP32-WiFi etc.). While a formal interface definition for WiFi classes does not exist, this library relies on those methods that became de-facto standards across all the implementations.

> See the [library home page](https://www.arduino.cc/reference/en/libraries/arduino_multiwifi/) and the [examples](examples/) for more information about this library and its usage.

## Usage

```arduino
#include <WiFiNINA.h>
#include <Arduino_MultiWiFi.h>

void setup() {
    MultiWiFi multi;
    multi.add("myssid", "mypassphrase");
    multi.add("myssid_2", "mypassphrase_2");

    if (multi.run() == WL_CONNECTED) {
        Serial.print("Successfully connected to network: ");
        Serial.println(WiFi.SSID());
    } else {
        Serial.println("Failed to connect to a WiFi network");
    }
}
```

## 🔎 Resources

* [How to install a library](https://www.arduino.cc/en/guide/libraries)
* [Help Center](https://support.arduino.cc/)
* [Forum](https://forum.arduino.cc)

## 🐛 Bugs & Issues

If you want to report an issue with this library, you can submit it to the [issue tracker](issues) of this repository. Remember to include as much detail as you can about your hardware set-up, code and steps for reproducing the issue. Make sure you're using an original Arduino board.

## 👨‍💻 Development

There are many ways to contribute:

* Improve documentation and examples
* Fix a bug
* Test open Pull Requests
* Implement a new feature
* Discuss potential ways to improve this library

You can submit your patches directly to this repository as Pull Requests. Please provide a detailed description of the problem you're trying to solve and make sure you test on real hardware.
