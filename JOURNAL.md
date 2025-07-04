---
title: "Slack Pager"
author: "@dld"
description: "Arduino-powered pager that syncs with Slack!"
created_at: "2025-07-04"
---

### July 4th, 2025

3:21 PM: So this project is essentially just a pager that syncs with Slack. My idea is that it'll be basically some sort of WiFi/Bluetooth microcontroller, probably an ESP32, and it'll have a display, and when a message is sent in a specific channel in Slack (maybe DMs if I can get the software side of it set up like that), it'll vibrate or make a noise, then it will display the message sender, and then the message itself. It'll most likely also have a "quick response" menu, with quick messages and reactions to confirm that it was received. In an ideal world, what I'd do would be to set it up over Bluetooth with a mobile app, so that I don't have to be in a place with WiFi to use it, and so that I don't have to reupload the code every time I go to a new place, but I've got an iPhone, and I've got no experience with app development. What I think the setup will actually be is a Slack app hosted on Nest hooked up to Adafruit IO (included with the GitHub Student Developer Pack!), which communicates with the pager when there's a new message. It'll also likely have 3 buttons, up, down, and select. It's been 20 minutes of work so far, I'm gonna do more research.
