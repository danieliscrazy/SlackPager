# SlackPager

This project is a pager powered by an Adafruit Feather HUZZAH ESP8266. It interfaces with Slack so that when you send a message in #pager in the Hack Club Slack, it notifies you by playing a little ringtone and then displaying the message and sender. It also has a quick response menu to send a few prewritten responses to messages you receive.

As of right now, everything is working, however it's not in its final built state, as I can't fit everything into a case without a PCB, and I can't get the measurements to make said case either until I get the PCB. It should be coming very soon, and I will definitely be able to submit it as built before the build deadline, but I don't think I can get the case designed before the submission deadline of July 31st.

## Gallery

I don't have any pictures of the whole working setup unfortunately, and I can't get them right now as I'm away from home. Here are the pictures I put in my journal though!

![image](https://github.com/user-attachments/assets/8cdc94c0-e6ab-40c0-aab1-b9c5dcf8b012)
> The demo code running on the OLED

![image](https://github.com/user-attachments/assets/f6f52bb1-a387-4152-8fe7-187d5f20b233)
> Example of the quick responses!

![image](https://github.com/user-attachments/assets/26f8783e-3838-4581-b23d-59ada369f5de)
> My PCB! 



## BOM

(Note: I've already purchased everything. As of writing this, I have everything except for the PCB, and it's working.)

| Item | Use | Source | Price | Total Price |
| ---- | --- | ------ | ----- | ----------- |
| Adafruit Feather HUZZAH ESP8266 | Main microcontroller| Micro Center (in person) | $18.45 |   |
| Inland 1.3" OLED Display | To display things | Micro Center (in person) | $8.70 |   |
| Adafruit Li-ion Battery (3.7V, 2200mAh) | Battery, a bit overkill but actually cheaper than buying a smaller one online | Micro Center (in person) | $16.32 |   |
| PCB | Can't fit it into the case without one | JLCPCB | $4.49 |   |
| Piezo buzzer | Buzz buzz! | Already owned | $0.00 |   |
| Buttons | Click click! | Already owned | $0.00 |   |
| Resistors | ...I can't think of an onomatopoeia for this one | Already owned | $0.00 |   |
|   |   |   |   | $47.96 |

