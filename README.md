# Dancing Queen: An Audio Visualization Sculpture via Frequency-Driven Motor Actuation

Demo Video: https://www.youtube.com/watch?v=8ptn5w8GsTI

### Code for system that connects Fast Fourier Transformation to Arduino Adafruit servo motor driver connecting 22 motors to spin at different rates according to their relative frequency amplitude values. This creates a realtime sound visualizer!

![](https://github.com/jennsun/stc_final_sound_visualizer/blob/master/dancingqueen.gif)

**Instructions To Run:**
* Clone this repository
* Create a virtual environment (recommended)
`pip install -r requirements.txt`
* Use the code from the file `arduino/final-5-3.ino` and load it into the Arduino IDE
* Connect laptop to the Arduino
* In Arduino IDE: Set Tools->Board->Arduino Uno and Tools->Port->[port connected to Arduino] 
* Upload the Arduino code
* Use the same port name as [port connected to Arduino] to fill in the line
arduino = serial.Serial('/dev/cu.usbmodem1301', 19200)

Where 'usbmodem1301' is an example PORT but this will change depending on your system used.
* Run `python FFT_to_arduino.py` to perform the live audio input, Fast-Fourier Transformations into relative rotation values that are sent to the Arduino via a serial communication at a baud rate of 19200. 

**Description:**

Our project, Dancing Queen: An Audio Visualization Sculpture via Frequency-Driven Motor Actuation, explores transformations between sound, structure, movement, and visuals. It aims to transform sound into a visual and movement-based experience using engineering. The final sculpture is the result of mapping various frequencies in the human range of hearing to a set of Arduino motors that will move blocks according to their relative levels. 

**Questions Addressed:** How do humans visualize sound? What properties make up our understanding of sound? How can we transform the properties of sound into a visual form via engineering? In the process of asking and addressing these questions, we were inspired by digital representations of sound waves and previous projects in the field of cymatics (the study of sound and vibration made visible) to build an audio visualization sculpture using the equipment we learned how to use in this course. The vision was to create a sculpture that would dynamically move according to live audio input. 

**Artistic Considerations and Challenges:** We sought to translate the intangible nature of sound waves into a tangible, dynamic, and aesthetically pleasing form. We learned that conventional digital sound wave visualizations are created by applying Fast Fourier Transformation (FFT), a mathematical technique that breaks down a sound wave into its frequency components. By analyzing the amplitude of each frequency component, we can create a visual representation of the sound wave, with different heights representing the varying intensities of the frequencies that make up the sound. 
We envisioned building individual components that mapped to a certain frequency in an FFT and then scaling this idea by placing motors next to each other to form a larger sculpture. We chose laser cutting as the best method to create our blocks, using 1/16 inch pieces of wood as our primary material. We also wanted to enhance the visual experience of our project, and therefore decided to utilize glow-in-the-dark paint to create a design that would further emphasize the fluidity and motion of the sound wave. 

One of our first challenges was creating servo helicopters that were longer than the default ones that come with the Arduino box. We also only needed the helicopters to be one sided; therefore, we laser-cut custom ones. We additionally connected the helicopters to the wooden pieces by cutting a slit in the end of the helicopters to click the two parts together. Designing a helicopter that would fit snug around the servo motor took a lot of trial and error: Eventually, we had to recut all 30 helicopters after we ordered new motors because the existing helicopters did not fit. 
We additionally struggled to determine the best way to place the pieces on the servo, as we did not have pistons to push the pieces but rather had to rely on the servo motors to essentially swing/lift them up. Moreover, we were not able to just attach the servos side-by-side as they are unable to sit flush next to each other. After talking to the teaching team, we were able to come up with a solution to measure the servos’ dimensions and create a zigzag patterned tool that would allow us to attach the servos in our desired way, as well as allow for the pieces to hang and rise/drop vertically. 

**Engineering Considerations and Challenges:** The engineering aspects of our project had to work hand in hand with the artistic vision, but we faced numerous challenges in adapting and learning new skills to work within feasible engineering constraints to get our sculpture functioning. 
One of the primary challenges we encountered was ensuring seamless communication between the various components of the system. Although the individual parts, such as the Python script performing Fast Fourier Transformations (FFT) and the Arduino code controlling the motor rotations, worked independently, integrating them posed many challenges. To solve this, we established a reliable serial communication between the audio analysis and Arduino movement.  Iterating with hardware inconsistencies was another challenge, especially since we were constrained to testing the motors only in the StudioLab. The Arduino motors had inherent limitations, such as the inability to lift blocks that were too heavy or when the laser-cut motor did not fit perfectly. Additionally, slight variations in the sizes of individual motors required meticulous adjustments and multiple rounds of printing.

Scaling up from our minimum viable product, which spun individual motors, presented its own set of difficulties. Each Arduino board could only accommodate about 6 servos, limiting the scope of our installation. After consulting with Liam and Brendan, we decided to use two Adafruit boards and solder them together, ultimately being able to control 22 Arduino motors from this setup.  Transitioning from the Arduino programming learned in class to the Adafruit boards required adapting to a new library. There was no straightforward approach of instructing motors to spin to a specific angle, and the Adafruit servo driver relied on PWM (Pulse Width Modulation) pulse timing with tick values, which required complex calculations. Scaling demanded learning new programming languages and libraries. 
Once we established consistent serial communication between the FFT audio transformations and the Arduino motor movement, we spent lots of time testing the sensitivities of the motors and experimenting with various audios, such as different genres of music and nature sounds, and how they could cause different movements in the sculpture. 

**Transformations:** Dancing Queen embodies transformations between all modules of our course: visuals, sound, structure, and movement. At its core, the installation transforms sound, an intangible medium, into a tangible, visual, and kinetic experience. By applying FFT to live audio input, we deconstruct complex sound waves and correspondingly rotate the Arduino motors to make the wooden pieces come to life, creating a mesmerizing wave-like motion that visually represents the sound. By using glow-in-the-dark blocks, we allow the sculpture to be experienced in a novel way by isolating the sound wave from the space and focusing on its visual representation. 

**New Skills Learned:** We built on top of skills learned in class, including laser cutting, soldering (connecting the various electronic components of the Adafruit servo driver boards), and engineering (coding our system with new libraries and programming languages/concepts).
Beyond the technical skills, this project also fostered our ability to collaborate effectively in a multidisciplinary team. Coming from different majors (COS, History, SPIA) with different challenges and visions, our project not only transformed sound into a visual and kinetic experience but also transformed us as individuals, expanding our capabilities to work at the intersection of art, technology, and engineering.
