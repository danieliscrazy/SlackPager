---
title: "Slack Pager"
author: "@dld"
description: "Arduino-powered pager that syncs with Slack!"
created_at: "2025-07-04"
---

> I have been working on this for 18 hours and 30 minutes.

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

### July 7th, 2025

12:20 PM: I'm getting back to work on the case. Damn it, I don't know what to do. The main issue is the buttons. I have two push buttons on a protoboard, which I'll eventually need to cut to size. I've got no clue where they need to go, and I'll also have to put in pressable button shell things on top of them. I think I'd be able to do this if it was an already existing 2 button module, but just the fact that it needs to be placed, soldered, and cut first is making it really hard for me to do anything. I'm almost at the point where I just want to try to modify it further and just make it 1 button, because I already have a module for a single button, but I think that would be overcomplicating it. Or maybe oversimplifying it? No clue. Getting quite frustrated.

### July 9th, 2025

10:20 AM: I lost all of my Arduino files. Then I found them again. Once again reminded of the glory of Git. Gonna remove the secrets from the files and upload them. Not counting this time in the total. 

11:15 AM: Now realizing I need a PCB, and that's fine because Undercity will have a PCB mill! Made a basic PCB, that should also allow me to have an on/off switch, and to have voltage reading (I'd test that now, but I can't find my resistors). This likely concludes my work on this project until after Undercity because of this.

![image](https://github.com/user-attachments/assets/26f8783e-3838-4581-b23d-59ada369f5de)
> My PCB! 

### July 28th, 2025

9:00 AM: Been a while, hasn't it? Finally received my PCBs (the Undercity PCB mill wasn't adequate, had to wait until yesterday to get my PCB from JLC), but I'm still on a trip, so no soldering for me. Working on CAD for it now. I have all the parts except for the display (which, thank god, I already measured), so I can use a caliper and measure out the whole thing. Time to get to work!

10:15 AM: Took a bit of a break. Still working now. Not much done yet, currently trying to model the PCB and device itself, but struggling to get the exact measurements. Trying to use Onshape just for this part, but the site hasn't been loading, at least until... right as I was typing this.

11:00 AM: Onshape didn't work for what I need it to. Back to TinkerCAD it is! I got the battery holder design mostly down, but that's very simple. I've gotten most of the board modeled as a reference, everything should be accurate except for the buttons, as I forgot to bring them with me, and my caliper's giving me 8mm apart while my gerber file says 12, so I'm just guesstimating for now. All that matters is that I actually _have_ the case, and it'd in theory work, whether or not it works exactly can be fixed before the build deadline. Have to go do stuff right now, time is 11:45 for my own reference.

<img width="650" height="275" alt="Screen Shot 2025-07-28 at 11 09 47 AM" src="https://github.com/user-attachments/assets/549ecc76-083c-44a3-bb86-6ee486ca4aa9" />

> The battery holder

<img width="935" height="543" alt="Screen Shot 2025-07-28 at 11 43 51 AM" src="https://github.com/user-attachments/assets/17f206ff-fa9c-4559-a3df-a3702d24a250" />

>The back and front side of the PCB, in glorious low poly.

12:00 PM: Bit unsure where to start, so I'm building a general frame for the PCB for now. 

<img width="476" height="574" alt="Screen Shot 2025-07-28 at 12 31 50 PM" src="https://github.com/user-attachments/assets/8f54e552-74da-4b45-a398-aaa147a76a57" />

> The frame for the board. The hole is for the piezo buzzer, and I just put nothing where the ESP8266 will go, and a hole at the bottom for the battery cable to go through.

12:30 PM: Trying to put the frame and the battery holder together as one bottom piece now. Haven't made the outer wall yet, but need to leave for a bit.

<img width="857" height="790" alt="Screen Shot 2025-07-28 at 12 49 25 PM" src="https://github.com/user-attachments/assets/0e10c38b-76f7-4410-97ff-9361aa8f3987" />

> The piece as one. Note that I left one side open- that's on purpose for the USB cable so I can upload code and recharge it.

4:00 PM: Made the bottom half of the case completely (I think)! Made it rounded, so instead of a box, it'll be a... rounded box! I am not very creative. Might have to be, because the battery is taller than the PCB and other electronics, and I need the buttons and screen to be very close to the case. This might be where I stop for today.

<img width="738" height="544" alt="Screen Shot 2025-07-28 at 4 23 28 PM" src="https://github.com/user-attachments/assets/dd7a663c-a21a-44f1-b441-0e19f8791dca" />

> The bottom case!

### July 30th, 2025

11:00 AM: Getting to work on the top case. Main issue I'm facing now is I need to curve the case down from the battery. I made this very bad diagram to show you what I'm talking about.

<img width="440" height="262" alt="Screen Shot 2025-07-30 at 11 31 44 AM" src="https://github.com/user-attachments/assets/7add4111-c75e-43de-b703-88f7c1fc5038" />

I need to do that. Issue I'm seeing now is, TinkerCAD (being TinkerCAD) doesn't have a curve like that. I'm thinking I'll have to do some trickery to do that.

12:00 PM: Working on the stuff other than that first. Got the cutout for the display done. Other thing I'm concerned about is the buttons. I'm likely just going to make caps that snap onto the buttons, but I can't get dimensions of my exact buttons right now, and online results are extremely varied. I'm gonna make the caps without the holes to interface the buttons for now, and I'll measure them tomorrow, when I get back home.

<img width="533" height="570" alt="Screen Shot 2025-07-30 at 11 52 19 AM" src="https://github.com/user-attachments/assets/76b35a0f-3c2d-448d-bd47-3fc5de9e2024" />

> Where I'm at right now.

12:30 PM: Buttons were a lot easier than I thought. Made them, put holes into the case, and also it's looking like that I won't need to have a curve for the battery! The case is already thick enough! With that, I think I've finished my case! Wait, no, I still need to figure out how to connect the two pieces of the case together. Also gonna see if I can add like a design or something to the top case, because it's kinda just a big empty space. Although I was planning to print with no supports, that side down, so that probably wouldn't work. Maybe I'll just put some stickers on it afterwards.

1:00 PM: I think I am finally done! The only aspects that are not done in this project (minus the build itself) is battery voltage detection (optional but I put places for resistors on the PCB so I can make it work) and putting in the holes for the buttons, both of which I'll do after I get back home. Gonna export the files and upload them to the repo, and then modify the README.

<img width="533" height="619" alt="Screen Shot 2025-07-30 at 12 51 23 PM" src="https://github.com/user-attachments/assets/8e512df0-ab96-49b3-b521-3cd0e1ec1679" />

> A top down view of the whole thing.

<img width="755" height="353" alt="Screen Shot 2025-07-30 at 12 53 10 PM" src="https://github.com/user-attachments/assets/f3725242-b9e7-40f6-a647-93d9e3102da6" />

> All of the parts (including the stand in for the electronics)!
