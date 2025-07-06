---
title: "Slack Pager"
author: "@dld"
description: "Arduino-powered pager that syncs with Slack!"
created_at: "2025-07-04"
---

> I have been working on this for 11 hours and 50 minutes.

> Also feel I should note, the times here are just the time I started typing/working. If an entry says it was at 3:45, it was actually the time between 3:45 and the next journal entry. I know it's a bit of a confusing system, but it works!

### July 4th, 2025

3:21 PM: So this project is essentially just a pager that syncs with Slack. My idea is that it'll be basically some sort of WiFi/Bluetooth microcontroller, probably an ESP32, and it'll have a display, and when a message is sent in a specific channel in Slack (maybe DMs if I can get the software side of it set up like that), it'll vibrate or make a noise, then it will display the message sender, and then the message itself. It'll most likely also have a "quick response" menu, with quick messages and reactions to confirm that it was received. In an ideal world, what I'd do would be to set it up over Bluetooth with a mobile app, so that I don't have to be in a place with WiFi to use it, and so that I don't have to reupload the code every time I go to a new place, but I've got an iPhone, and I've got no experience with app development. What I think the setup will actually be is a Slack app hosted on Nest hooked up to Adafruit IO (included with the GitHub Student Developer Pack!), which communicates with the pager when there's a new message. It'll also likely have 3 buttons, up, down, and select. It's been 20 minutes of work so far, I'm gonna do more research.

3:45 PM: I'd like for the main controller to be an Adafruit Feather because I've worked with them before, and they have easily attachable (sometimes even built in) displays. There were some nice looking OLED FeatherWings that Adafruit makes, but unfortunately they aren't in stock at my local Micro Center, and I'm kinda impatient. Additionally, I don't think they would have worked very well design-wise. I still am gonna go with an [Adafruit HUZZAH ESP8266](https://www.microcenter.com/product/460313/adafruit-industries-feather-huzzah-with-esp8266-wifi) as the main board (I've worked with it before and it works great), and I'll use [this 1.3" 128x64 OLED](https://www.microcenter.com/product/643965/inland-iic-spi-13-128x64-oled-v20-graphic-display-module-for-arduino-uno-r3). I'll also use [this buzzer](https://www.microcenter.com/product/677929/leo-sales-ltd-piezo-buzzer-23x10mm-3-24v-(5-pack)) (sorry, it's a 5 pack, but that's all I could reasonably find), and I'll have 3 push buttons on a breadboard (both of which I have already). I also will need a battery, but they don't have any in stock at Micro Center that would work well, so I'll have to order [this one from Adafruit](https://www.adafruit.com/product/1578). The battery isn't 100% needed until I am done with it, so it's fine if that comes later. I don't think that I'll be able to make a case or software without having the parts already. Because of this, I'm gonna go ahead and pay for it out of pocket and get reimbursed later. It's around 5:00 PM, I've been working for an hour and 40 minutes.

5:50 PM: Ok so, after a bit of research it turns out, after shipping, it'd actually be cheaper to buy a bigger battery that they do have in stock at Micro Center than to buy one from Adafruit, specifically [this one](https://www.microcenter.com/product/636273/adafruit-industries-lithium-ion-cylindrical-battery-37v-2200mah). It is a bit big, so I'm gonna make a rudimentary 3D model of like an outline of the case just to make sure that it'll fit into the form factor. I'm gonna go to Micro Center tomorrow.

6:10 PM: Wasn't able to do much with that right now. Just gonna have to wait for the parts from Micro Center. Can't do much more work today.

### July 5th, 2025

2:30 PM: Got the parts from Micro Center. Ended up buying [this small speaker](https://www.microcenter.com/product/612829/adafruit-industries-mini-metal-speaker-w-wires-8-ohm-05w) instead of a piezo buzzer, and bought this [1x4 keypad](https://www.microcenter.com/product/613569/adafruit-industries-membrane-1x4-keypad-extras) that I may or may not use (I'll pay for it myself if I don't use it) due to the fact that I have exactly 3 push buttons, and they're a bit fragile. I am seeing a potential issue now, because I didn't realize that the ESP8266 board has only 9 GPIO pins (I also believe there's some weird functionality with like 3 of them, not entirely sure), and I'd be using exactly 9 pins (that is, if I used 3 buttons instead of 4. If I end up using the keypad, might need to cut it or mod it in some way). I'm gonna work on testing out the display and wiring now. Also before I commit this journal log, I should note that I just realized I can't actually use that speaker! It'll fry the ESP8266. I might have a piezo somewhere around here, but it's definitely less than ideal.

2:45 PM: I say 2:45 PM just so I can keep track of my time. As of writing, it's actually closer to 3:25. After a bit of debugging and a bit of ChatGPTing, I found out that the display is _not_ an SSD1306, but an SH1106. Also found out it's blue for some reason. Anyways, I got that part working! Now I think I'm gonna work on code and getting it to receive Slack messages and display them.

![image](https://github.com/user-attachments/assets/8cdc94c0-e6ab-40c0-aab1-b9c5dcf8b012)
> The working demo code!

3:25 PM: I'm trying really hard to not vibe code this, however tempting. I'm trying to code the Slack bot side of things first, I would just use webhooks but I think in order to actually verify the things I need to verify, I need to code a bot. It's now roughly 4:15. You know when I said I was gonna try really hard not to vibe code this, literally 3 sentences ago? I gave up. I had ChatGPT make me a basic thing that when a message is sent in #pager in the slack, it sends a notification to the console. It works I guess! I've also gotten Adafruit IO hooked up to a webhook, and it sends words! Now I need to code the Arduino end of things.

![image](https://github.com/user-attachments/assets/489f4946-f0e0-4ed0-baed-301f7ae764c6)
> The demo code receiving a message

![image](https://github.com/user-attachments/assets/bff1cb36-6065-4d98-80c1-59d1ceae60ea)
> Webhook works! Don't ask why the PFP is a tie. I won't tell you.

4:30 PM: I'm just making this commit so that I can keep track of time. My time system is literally just, when I'm done with one journal entry, I start a new one, and I take the time from then to when I commit and add it to the time at the top of the page.

5:20 PM: Okay, I've got some semblance of functionality working. When the bot gets a message, it'll make two webhook requests, one to the "sender" feed, and one to the "message" feed. It'll send the message first, then immediately after, the sender. When it receives the sender (and this here is the currently implemented functionality), it'll blink the sender a couple times, then display the message. Currently trying to wire up a piezo to it but... I can't find any breadboards. All my breadboards are missing. I have like 10. Where the hell did they go?? I only have one ground pin, so I definitely need one. Where the hell are they???

6:20 PM: Okay, piezo hooked up, one button hooked up that triggers a message in #pager. Basically what I need to add to the arduino side to make it done software-wise is add a menu for responses, add battery voltage tracking, figure out an on off switch, and kinda just polish it more. I still need to do most of the Slack code. This is where I'm ending it tonight.

### July 6th, 2025

11:30 AM: AAAA, we're getting so close to Undercity!! I'm so damn excited!! Anyways, I'm gonna start working on the Slack code. Also I forgot to say in the last journal entry, I am proud to say that I did _not_ vibecode the Arduino code. Everything there so far is directly from templates or my brain. Can't say the same about the Slack bot code, I was hoping to not vibecode that as much as I could, but it's not looking too promising. 

12:00 PM: Yeah I used AI. Not proud of it, but my Slack code is working now! When I send a message in the channel, it sends it to the pager! Now I'm gonna start working on figuring out a menu here, probably need to make a seperate code file for figuring that out. Also, please excuse me for my lack of pictures, it's a bit of a mess in my room and at this point anything I did would have to be a video, which complicates things further. I'll have a lot more once I start working on the case.

12:15 PM: I have spent way too long debugging something, and I just realized that it was because 2 pins were taken on the ESP8266 by I2C/SPI stuff. I was able to free up one pin, but not another, and I just realized... I don't _need_ three buttons. I can have 1 arrow button to cycle through the menu, and one to select. With that debugged, hopefully I'll be able to figure this out soon. Also just spent a solid 10 minutes trying to figure out why the piezo wasn't working, and my dumb ass forgot to change the pin in the part that plays the tone. Anyways, it's been like 2 hours since I started this journal entry, I got a working menu! Need to hook it up to the main code so it can actually... do stuff. Gonna do that now.

2:15 PM: The Arduino gods hate me. One of the buttons refuses to work, no matter what pin I do. I know it's something code related, but what it is, that's a mystery. Taking a break.

3:30 PM: After what literally feels like an eternity, I got the button fixed. For some damn reason, pins 4, 5, 12, and 15 refused to work as an input. Pin 0 worked for some reason. Doesn't matter why as long as it works. Anyways, IT WORKS NOW!!!! It can receive messages and it can send back 6 different quick response messages. This means the code is basically complete! It might be missing a bit of polish, but everything that needs to work, works. It also turns out that my board is the only Feather board to not have onboard power voltage sensing. I can potentially get that set up, but I'm not gonna focus on that right now. Gonna take a break for a bit and then I'll work on 3D modeling.

![image](https://github.com/user-attachments/assets/f6f52bb1-a387-4152-8fe7-187d5f20b233)
> Example of the quick responses!

4:45 PM: Starting on 3D modeling. Bit harder here, because it's a lot more stuff to wire, and I have to do it in such a small space. Dear god, I didn't even think about wiring until now. I might have to get a custom length wiring thing to fit it all in here. I'm realizing, as I'm trying to work on this, this is extremely out of my league. I have no clue how to do most of this stuff. I've never made something so compact before. I'm gonna make a wiring diagram and come back to this.

5:05 PM: Been trying to figure out what to do. Definitely need custom length wires. I give up on the case for today. Hopefully tomorrow I'll be able to do a better job.
