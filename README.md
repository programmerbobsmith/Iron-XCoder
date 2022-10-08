
# Iron XCoder Library   

***

#### About   


Iron XCoder is a macOS Monterey themed toolchain for the TI-84 Plus CE, CE–T, and CE Python editions. It includes a many graphical and utility functions that are aimed at making shell/OS creations a lot easier.

#### License Information   

This toolchain is free for all TI-84 Plus CE and TI-84 Plus C Silver Edition Developers. If you use any part of this toolchain (in whole or in part) either through copying any portion of the toolchain or using these functions, you must credit the author and creator (Jonathan Khayat 'Bob Smith') in your readme.txt AND in your program. You must also provide the following link and text ONLY in the readme: "Check out Bob Smith's Profile: https://tinyurl.com/ProgrammerBobSmith". Copying any portion of this toolchain includes copying and editing, regardless of how different the editing renders the function.

#### History

- **version 15.0** (newest fully supported release)
	- **build date:** August 20, 2022 4;07 PM CT
	- **[Edit]** Changed the library version to match Apple XCoder version numbering.
	- **[Added]** A new OS function category was added.
	- **[Added]** var_Sto function.   

– **version 1.2** (old builds)
- **build date:** August 13, 2022 8:00 PM CT
- **[FIX]** Problem with gfx_PrintDouble printing negative numbers is fixed
- **[FIX]** Added math functions category
- **[FIX]** Added a factorial function

- **version 1.0** (first release and old builds)
	- **build date:** August 10, 2022 4:29 PM CT
	- Completed the Iron XCoder toolchain


## API Documentation

***

#### Input/Output (IO) Functions

`void gfx_PrintDouble(double value, unsigned int number_of_decimal_places, unsigned int text_color)`

- Parameters:

	- value: value to be displayed

	- number_of_decimal_places: number of decimal places to be displayed (rounding is supported)

	- text_color: desired color of the printed number

- Returns:

	- Does not return any value.

@ Note: This function displays the number at the current gfx cursor position. If this position has not been set or updated recently, then use gfx_SetText(x,y) to 							ensure that this function prints as desired.

`int gfx_GetInteger(unsigned int x, unsigned int y, unsigned int text_color, unsigned int background_color)`

- Parameters:

	- x: x location on the screen to display the stream of numbers

	- y: y location on the screen to display the stream of numbers

	- text_color: color of the stream of numbers

	- background_color: color of the background
				
- Returns:

	- Returns the integer typed.

@ Note: This function supports positive and negative integers and deleting of text, but does not support ANY mathematical operations.

>> - This function supports the following Hotkeys:
>>> - [Enter]: Ends the input process and returns the number.
>>> - [Del]: Deletes the last character.
>>> - [Clear]: Exits the program.

		3)	double gfx_GetDouble(unsigned int x, unsigned int y, unsigned int text_color, unsigned int background_color)
				- Parameters:
					- x: x location on the screen to display the stream of numbers
					- y: y location on the screen to display the stream of numbers
					- text_color: color of the stream of numbers
					- background_color: color of the background

				- Returns:
					- Returns the decimal number (double) typed.

				– Note: This function supports positive and negative decimal numbers and deleting of text, but does not support ANY mathematical operations.
						- This function supports the following Hotkeys:
							- [Enter]: Ends the input process and returns the number.
							- [Del]: Deletes the last character.
							- [Clear]: Exits the program.

		4)	int gfx_Slider(unsigned int start_x, unsigned int start_y, unsigned int step, unsigned int slider_color, unsigned int background_color, unsigned int max_entries)
				- Parameters:
					- start_x: This is the x location of the first text in a list. The function performs any necessary shifting of the slider.
					- start_y: This is the y location of the first text in a list. The function performs any necessary shifting of the slider.
					- step: This is the distance in separation between text items in a list.
					- slider_color: color of the slider to display
					- background_color: background color
					- max_entries: This is the number of items in the list.

				- Returns:
					- Returns an integer of the slider's position in the list. The first list item is 1 and the last is max_entries.

				- Note: This function performs any necessary shifting of the slider from the text in the list.
						- This function supports the following Hotkeys:
							- [Enter]: Ends the input process and returns the number.
							- [Del]: Deletes the last character.
							- [Clear]: Exits the program.

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

PROGRAM FUNCTIONS:
		
		1) void disp_TIProg(unsigned int x, unsigned int y, unsigned int program_text_color)
				- Parameters:
					- x: start x-position for displaying programs
					- y: start y-position for displaying programs
					- program_text_color: desired color for the programs' text
				
				- Returns:
					- Should not return anything.

		2) void disp_CProg(unsigned int x, unsigned int y, unsigned int program_text_color)
				- Parameters:
					- x: start x-position for displaying programs
					- y: start y-position for displaying programs
					- program_text_color: desired color for the programs' text
				
				- Returns:
					- Should not return anything.

		3) void disp_CProg_Sprite(

		4) void run_TIProg(unsigned int x, unsigned int y, unsigned int slider_x, unsigned int slider_y, unsigned int slider_color, unsigned int background_color, unsigned int program_text_color, unsigned int error_mode)
				- Parameters:
					- x: start x-position for displaying programs
					- y: start y-position for displaying programs
					- slider_x: start x-position for the slider selector
					- slider_y:	start y-position for the slider selector
					- slider_color: desired color for the program selector
					- background_color: background color
					- program_text_color: desired color for the programs' text
					- error_mode: '1' if you want errors to be displayed to user, any other number if you don't.
				
				- Returns:
					- Should not return anything.
				
				- Note: This function performs program callbacks. After running any program, callbacks will return to your main() function.

		5) void run_CProg(unsigned int x, unsigned int y, unsigned int slider_x, unsigned int slider_y, unsigned int slider_color, unsigned int background_color, unsigned int program_text_color, unsigned int error_mode)
				- Parameters:
					- x: start x-position for displaying programs
					- y: start y-position for displaying programs
					- slider_x: start x-position for the slider selector
					- slider_y:	start y-position for the slider selector
					- slider_color: desired color for the program selector
					- background_color: background color
					- program_text_color: desired color for the programs' text
					- error_mode: '1' if you want errors to be displayed to user, any other number if you don't.
				
				- Returns:
					- Should not return anything.
				
				- Note: This function performs program callbacks. After running any program, callbacks will return to your main() function.

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

NOTIFICATION FUNCTIONS:

		1) void error_banner(const char *header, const char *text, unsigned int location_x, unsigned int location_y, unsigned int width, unsigned int height, unsigned int background_color)
				- Parameters:
					- header: Header text to display
					- text: Error text to display
					- location_x: x-position of the notification
					- location_y: y-position of the notification
					- width: width of the notification banner
					- height: height of the notification banner
					- background_color: background color

				- Returns:
					- Should not return anything.

				- Note: This function displays the notification, pauses all program inputs for 2 seconds, and then removes the notification.

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

MATH FUNCTIONS:
		1) unsigned long long int fact(unsigned int num)
				- Parameters:
					- num: number to calculate the factorial of

				- Returns:
					– Returns the factorial. If [1] is returned, this most likely indicates that the number you used for [num] exceeds C99 calculating power.

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

OPERATING SYSTEM FUNCTIONS:
		1) void var_Sto(const char *var, float num_sto)
				- Parameters:
					- var: variable to store number in
						NOTE: Include the <ti/vars.h> file in the header section and use the following defines: OS_VAR_$ where $ is any character from A-Z.
					- num_sto: number to store in variable
				- Returns:
					- Should not return anything.

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
											Copyright August 2022. All Rights Reserved. May not be reproduced or distributed without permission.
