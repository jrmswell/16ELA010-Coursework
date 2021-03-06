# Intro
The task was to write a program that will draw sine waves and output them as a full colour image in the .ppm file format

[Download the .exe](https://github.com/jrmswell/16ELA010-Coursework/releases)

# Help
This program is designed to generate a sine wave using the parameters you set and then save them to a .ppm compatible file

Let's review each menu option

## 1) Help and About
Shows the below information

## 2) Set the parameters
This brings you to the create screen, here you can specify the amplitude, frequency and colour of your sine wave

This program walks you through the process so there's no need to learn anything.

You can repeat this step as many times as you would like

## 3) Import parameters

This brings you to a screen that allows you to import a Plain-Text document (we recommend a .txt file due to them being commonplace)

Please write each variable on a new line. For example:

```c
2
50
255
0
0
```

Would produce a wave with a frequency of 2, amplitude of 50 pixels and a colour of red as seen below:

![Sine Wave](http://i.imgur.com/1wnCnOP.png)

## 4) Exports your parameters to a .PPM file then opens it

This program asks you where you would like to save. Please remember to include the file type however

We recommend saving as a .ppm file since the contents will be saved in the .ppm format

We have not restricted you to the .ppm extension however in case you plan to do something else with the file

After saving the program will end

You will need a compatible viewer, one viewer that we recommend is the free IrfanView which can be downloaded from [here](http://www.irfanview.com/)

## 5) Exits the program

Stops the program
