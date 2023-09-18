# Embedded-Systems-Advanced-Calculator

This is an advanced calculator project developed for embedded systems using the Tiva C Series TM4C123G microcontroller (tm4c123gh6pm). The project features three main modes: Calculator, Timer, and Stopwatch. Additionally, it utilizes a keypad for numeric inputs and push buttons to switch between modes.

## Features
- Three operational modes:
  1. **Calculator Mode**: Allows users to perform basic arithmetic calculations with two numbers and various operators (+, -, /, *, =). Inputs are obtained through a keypad, and the LCD displays the numbers, operator, and the result.

  2. **Timer Mode**: Enables users to set a countdown timer using the keypad. The timer starts when the 'D' button is pressed and triggers a buzzer when it reaches zero. The LCD displays the timer in the format "MM:SS."

  3. **Stopwatch Mode**: Provides a stopwatch functionality with start, pause, and reset buttons. The stopwatch increments and displays the time in "MM:SS" format on the LCD.

- User-friendly interface with LCD display for input and output.
- Keypad for numeric input.
- Push button(s) for mode selection and control.

## Getting Started
1. **Hardware Setup**: Connect the TM4C123G microcontroller to the required components, including the LCD, keypad, and push button(s). Ensure proper wiring and connections are established.

2. **Software Setup**: Clone this GitHub repository and open the project in your preferred embedded development environment, such as Code Composer Studio or Keil MDK.

3. **Compile and Flash**: Compile the project and flash the firmware onto the TM4C123G microcontroller.

4. **Usage**: Power up the microcontroller, and you will be presented with the "Welcome Team 4" message on the LCD. Use the push button(s) to switch between the three modes:

   - Calculator Mode: Perform arithmetic calculations.
   - Timer Mode: Set and start countdown timers.
   - Stopwatch Mode: Use the stopwatch for timing purposes.

## Operation Instructions
- **Calculator Mode**:
  - Enter two numbers using the keypad.
  - Select an operator (+, -, /, *, =) using the keypad buttons (A, B, C, D, *).
  - The LCD will display the numbers, operator, and the result.

- **Timer Mode**:
  - Initially, "00:00" is displayed on the LCD.
  - Enter minutes and seconds using the keypad.
  - Press the 'D' button to start the countdown timer.
  - When the timer reaches zero, a buzzer will be triggered.

- **Stopwatch Mode**:
  - Initially, "00:00" is displayed on the LCD.
  - Use the buttons to start, pause, and reset the stopwatch.

## Additional Notes
- Feel free to add more push buttons or expand the functionality as needed.
- Ensure proper wiring and power supply for the components.
- Modify the code as necessary to adapt to your specific hardware configuration.
