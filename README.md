# Making a sound mixer powered by Arduino Nano
Welcome to this repository where i share my experience making a DIY sound mixing table powered by an Arduino Nano, please refer to omriharel's repo for a better description at ![Deej repo](https://github.com/omriharel/deej/blob/master/community.md)

In this repo i'll share some picture of the result, the schematics and the program to make your own, i'll also give you some advices onto the difficulties i've encountred while making mine.

# Pictures:
![Box Used](https://github.com/misterimo/deej/blob/main/Pictures/box%20used.jpg) I used a calliper box (that i opened the bottom of it) for this build

![Side view](https://github.com/misterimo/deej/blob/main/Pictures/side%20view.jpg) To elevate the box a little bit for the cable, i used small leg chair pads

![Top view](https://github.com/misterimo/deej/blob/main/Pictures/top%20view.jpg) I took the knobs and potentiometers from an old broken stereo, the combination of chrome painted plastic and wood looks cool...

![guts](https://github.com/misterimo/deej/blob/main/Pictures/guts.jpg) ... What doesn't look cool is the guts of the box, i'm still a beginner when it comes to soldering and learned a lot from this build.

# Schematics and tips:
Speaking of soldering i found it easier to work with rigid cables (you can get them from ethernet cables), also to make it easier for you always put some solder on both the ends before trying to solder them.

Measure your wires before commiting to the cut if you don't want to end up with guts like mine, always plane your routes and do your researches before beginning.

Measure the resistance of the potentiometers/slider to determine where you're going to put the + and - in each one of them, in my case i looked for the pins where i have the smallest value while having the knob/slider at the physical low volume position.

Finally when things become hard and you run out of patience, switch to something else and come back when you feel like it, you don't want to overreact while holding the soldering iron...

![Schematic](https://raw.githubusercontent.com/misterimo/deej/main/schematics%20v2.jpg?token=AR5P3NNWJIV7XT7YMHFCVIS7Y2BI6) This is the schematics that works with my code, for the ones with OCD forgive my non organised Inputs/Outputs, it was difficult for me to fix it once everything was inside the box.


# Code:
Check the ![Deejimo.ino](https://github.com/misterimo/deej/blob/main/Deejimo.ino) file to get the code i used, i left some comments to explain the "weird" lines
