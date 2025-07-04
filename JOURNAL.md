---
title: "Slack Pager"
author: "@dld"
description: "Arduino-powered pager that syncs with Slack!"
created_at: "2025-07-04"
---

> I have been working on this for 2 hours.

### July 4th, 2025

3:21 PM: So this project is essentially just a pager that syncs with Slack. My idea is that it'll be basically some sort of WiFi/Bluetooth microcontroller, probably an ESP32, and it'll have a display, and when a message is sent in a specific channel in Slack (maybe DMs if I can get the software side of it set up like that), it'll vibrate or make a noise, then it will display the message sender, and then the message itself. It'll most likely also have a "quick response" menu, with quick messages and reactions to confirm that it was received. In an ideal world, what I'd do would be to set it up over Bluetooth with a mobile app, so that I don't have to be in a place with WiFi to use it, and so that I don't have to reupload the code every time I go to a new place, but I've got an iPhone, and I've got no experience with app development. What I think the setup will actually be is a Slack app hosted on Nest hooked up to Adafruit IO (included with the GitHub Student Developer Pack!), which communicates with the pager when there's a new message. It'll also likely have 3 buttons, up, down, and select. It's been 20 minutes of work so far, I'm gonna do more research.

3:45 PM: I'd like for the main controller to be an Adafruit Feather because I've worked with them before, and they have easily attachable (sometimes even built in) displays. There were some nice looking OLED FeatherWings that Adafruit makes, but unfortunately they aren't in stock at my local Micro Center, and I'm kinda impatient. Additionally, I don't think they would have worked very well design-wise. I still am gonna go with an [Adafruit HUZZAH ESP8266](https://www.microcenter.com/product/460313/adafruit-industries-feather-huzzah-with-esp8266-wifi) as the main board (I've worked with it before and it works great), and I'll use [this 1.3" 128x64 OLED](https://www.microcenter.com/product/643965/inland-iic-spi-13-128x64-oled-v20-graphic-display-module-for-arduino-uno-r3). I'll also use [this buzzer](https://www.microcenter.com/product/677929/leo-sales-ltd-piezo-buzzer-23x10mm-3-24v-(5-pack)) (sorry, it's a 5 pack, but that's all I could reasonably find), and I'll have 3 push buttons on a breadboard (both of which I have already). I also will need a battery, but they don't have any in stock at Micro Center that would work well, so I'll have to order [this one from Adafruit](https://www.adafruit.com/product/1578). The battery isn't 100% needed until I am done with it, so it's fine if that comes later. I don't think that I'll be able to make a case or software without having the parts already. Because of this, I'm gonna go ahead and pay for it out of pocket and get reimbursed later. It's around 5:00 PM, I've been working for an hour and 40 minutes.

5:50 PM: Ok so, after a bit of research it turns out, after shipping, it'd actually be cheaper to buy a bigger battery that they do have in stock at Micro Center than to buy one from Adafruit, specifically [this one](https://www.microcenter.com/product/636273/adafruit-industries-lithium-ion-cylindrical-battery-37v-2200mah). It is a bit big, so I'm gonna make a rudimentary 3D model of like an outline of the case just to make sure that it'll fit into the form factor. I'm gonna go to Micro Center tomorrow.

6:10 PM: Wasn't able to do much with that right now. Just gonna have to wait for the parts from Micro Center. Can't do much more work today.
