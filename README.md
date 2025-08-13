# SlackPager

This project is a pager powered by an Adafruit Feather HUZZAH ESP8266. It interfaces with Slack so that when you send a message in #pager in the Hack Club Slack, it notifies you by playing a little ringtone and then displaying the message and sender. It also has a quick response menu to send a few prewritten responses to messages you receive. I got the idea because Slack had been really glitchy on my phone recently, and it wasn't always sending me notifications, so I thought "What if I made a device that was just for Slack notifications?" My hope in the future is to expand it to not just #pager, but everywhere I'd typically receive a notification as well. This project was made for and funded by Hack Club's Highway program.

![image](https://github.com/user-attachments/assets/57cb1c0d-89a4-4504-8976-696d0749a92d)

All code has been tested and is working (battery voltage tracking functionality needs to be added still, but it's not essential). All that's needed is to solder parts to the PCB and to print out the case.

(Note for Highway reviewers: I use TinkerCAD, which _cannot_ export .STEP files, only .STL files. In the future, I'll learn and use Onshape, but I don't have much choice right now. Sorry!)
## Gallery

![image](https://github.com/user-attachments/assets/8e512df0-ab96-49b3-b521-3cd0e1ec1679)
> Closest thing I can get to a render.

![image](https://github.com/user-attachments/assets/f3725242-b9e7-40f6-a647-93d9e3102da6)
> All of the parts (including the stand in for the electronics).

![image](https://github.com/user-attachments/assets/4cd99d04-fb56-4e7f-9e23-b178c2decad3)
> My PCB! 

![image](https://github.com/user-attachments/assets/78e99f1f-ae72-49a1-aad9-a0e0f041cc12)
> My schematic! 

![image](https://github.com/user-attachments/assets/8cdc94c0-e6ab-40c0-aab1-b9c5dcf8b012)
> The demo code running on the OLED

![image](https://github.com/user-attachments/assets/f6f52bb1-a387-4152-8fe7-187d5f20b233)
> Example of the quick responses!


[Demo](https://youtu.be/zU5LHW891Wc)

## BOM

(Note: I've already purchased everything. As of writing this, I have everything, and it's all been tested and working save for the PCB, which will be tested soon.)

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

