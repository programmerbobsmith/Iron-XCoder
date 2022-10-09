
# Iron XCoder Library   

***

#### About   


Iron XCoder is a macOS Monterey themed library for the TI-84 Plus CE, CE–T, and CE Python editions. It includes a many graphical and utility functions that are aimed at making shell/OS creations a lot easier.

#### License Information   

This library is free for all TI-84 Plus CE developers. If you use any part of this library (in whole or in part) either through copying any portion of the toolchain or using these functions, you must credit the author and creator (Jonathan Khayat 'Bob Smith') in your README AND in your program. You must also provide the following link and text ONLY in the readme: "Check out Bob Smith's Profile: https://tinyurl.com/ProgrammerBobSmith". Copying any portion of this toolchain includes copying and editing, regardless of how different the editing renders the function.

#### History

- **version 15.1** (newest release)
	- **build date:** TBD
	- **[Edit]** Implement code optimizations for faster functions
	- **[Added]** Routines to display C and ASM program sprites
	- **[Added]** Routine to calculate legs/hypotenuse of a right triangle
	- **[Added]** Routine to solve any triangle

- **version 15.0** (first fully supported release)
	- **build date:** August 20, 2022 4;07 PM CT
	- **[Edit]** Changed the library version to match Apple XCoder version numbering.
	- **[Added]** A new OS function category was added.
	- **[Added]** var_Sto function.   

- **version 1.2** (old builds)
	- **build date:** August 13, 2022 8:00 PM CT
	- **[FIX]** Problem with gfx_PrintDouble printing negative numbers is fixed
	- **[FIX]** Added math functions category
	- **[FIX]** Added a factorial function

- **version 1.0** (first release and old builds)
	- **build date:** August 10, 2022 4:29 PM CT
	- Completed the Iron XCoder library


## API Documentation

***

#### Input/Output (IO) Functions

1. `void gfx_PrintDouble(double value, uint8_t number_of_decimal_places, uint8_t text_color)`
> User input routine for printing a double 
	- Parameters:
		- `value`: value to be displayed
		- `number_of_decimal_places`: number of decimal places to be displayed (rounding is supported)
		- `text_color`: desired color of the printed number

	- Returns:
		- Does not return any value.

	- :warning: **Warning:** This function displays the number at the current gfx cursor position. If this position has not been set or updated recently, then use gfx_SetText(x,y) to ensure that this function prints as desired.

2. `int gfx_GetInteger(uint8_t x, uint8_t y, uint8_t text_color, uint8_t background_color)`
> User input routine for getting an integer.
	- Parameters:
		- `x`: x location on the screen to display the stream of numbers
		- `y`: y location on the screen to display the stream of numbers
		- `text_color`: color of the stream of numbers	
		- `background_color`: color of the background

	- Supported Hotkeys:
		- `[Enter]`: Ends the input process and returns the number.
		- `[Del]`: Deletes the last character.
		- `[Clear]`: Exits the program.
	
	- Returns:
		- Returns the integer typed.

	- :warning: **Warning:** This function supports positive and negative integers and deleting of text, but does not support ANY mathematical operations.


3. `double gfx_GetDouble(uint8_t x, int y, uint8_t text_color, uint8_t background_color)`
> User input routine for getting a double.
	- Parameters:
		- `x`: x location on the screen to display the stream of numbers
		- `y`: y location on the screen to display the stream of numbers
		- `text_color`: color of the stream of numbers
		- `background_color`: color of the background

	- Supported Hotkeys:
		- `[Enter]`: Ends the input process and returns the number.
		- `[Del]`: Deletes the last character.
		- `[Clear]`: Exits the program.

	- Returns:
		- Returns the decimal number (double) typed.

	– :warning: **Warning:** This function supports positive and negative decimal numbers and deleting of text, but does not support ANY mathematical operations.

4.	`int gfx_Slider(uint8_t start_x, uint8_t start_y, uint8_t step, uint8_t slider_color, uint8_t background_color, uint8_t max_entries)`
	- Parameters:
		- `start_x`: This is the x location of the first text in a list. The function performs any necessary shifting of the slider.
		- `start_y`: This is the y location of the first text in a list. The function performs any necessary shifting of the slider.
		- `step`: This is the distance in separation between text items in a list.
		- `slider_color`: color of the slider to display
		- `background_color`: background color
		- `max_entries`: This is the number of items in the list.

	- Supported Hotkeys:
		- `[Enter]`: Ends the input process and returns the number.
		- `[Del]`: Deletes the last character.
		- `[Clear]`: Exits the program.

	- Returns:
		- Returns an integer of the slider's position in the list. The first list item is 1 and the last is max_entries.

	- :warning: **Warning:** This function performs any necessary shifting of the slider from the text in the list.

***

#### PROGRAM FUNCTIONS:
		
1. `void disp_TIProg(uint8_t x, uint8_t y, uint8_t color)`
> Displays a list of all the TI-Basic Programs on the calculator
	- Parameters:
		- `x`: start x-position for displaying programs
		- `y`: start y-position for displaying programs
		- `color`: desired color for the programs' text
				
	- Returns:
		- Should not return anything.

2. `void disp_CProg(uint8_t x, uint8_t y, uint8_t color)`
> Displays a list of all the C/ASM programs on the calculator
	- Parameters:
		- `x`: start x-position for displaying programs
		- `y`: start y-position for displaying programs
		- `color`: desired color for the programs' text
				
	- Returns:
		- Should not return anything.

3. `void disp_ASMProg_Sprite(const char *prog_name, uint8_t x_loc, uint8_t y_loc)`
> Displays any C/ASM sprite from any desired program
	- Parameters:
		- `prog_name`: name of C program to get sprite from
		- `x_loc`: start x position for drawing the sprite
		- `y_loc`: start y position for drawing the sprite
	- Returns:
		- Should not return anything.
	- :warning: **Warning:** This function only draws C program 16x16 icons. ASM program icons and irregular shaped icons are not yet supported.

4. `void run_TIProg(uint8_t x, uint8_t y, uint8_t slider_x, uint8_t slider_y, uint8_t slider_color, uint8_t background_color, uint8_t text_color, uint8_t error_mode)`
> Runs the desired TI-basic program
	- Parameters:
		- `x`: start x-position for displaying programs
		- `y`: start y-position for displaying programs
		- `slider_x`: start x-position for the slider selector
		- `slider_y`:	start y-position for the slider selector
		- `slider_color`: desired color for the program selector
		- `background_color`: background color
		- `text_color`: desired color for the programs' text
		- `error_mode`: '1' if you want errors to be displayed to user, any other number if you don't.
				
	- Returns:
		- Should not return anything.
				
	- :warning: **Warning:** This function performs program callbacks. After running any program, callbacks will return to your main() function.

5. `void run_CProg(uint8_t x, uint8_t y, uint8_t slider_x, uint8_t slider_y, uint8_t slider_color, uint8_t background_color, uint8_t text_color, uint8_t error_mode)`
> Runs the desired C or ASM program
	- Parameters:
		- `x`: start x-position for displaying programs
		- `y`: start y-position for displaying programs
		- `slider_x`: start x-position for the slider selector
		- `slider_y`: start y-position for the slider selector
		- `slider_color`: desired color for the program selector
		- `background_color`: background color
		- `text_color`: desired color for the programs' text
		- `error_mode`: '1' if you want errors to be displayed to user, any other number if you don't.
				
	- Returns:
		- Should not return anything.
				
	- :warning: **Warning:** This function performs program callbacks. After running any program, callbacks will return to your main() function.

***

#### NOTIFICATION FUNCTIONS:

1. `void error_banner(const char *header, const char *text, uint8_t x_loc, uint8_t y_loc, uint8_t width, uint8_t height, uint8_t background_color)`
> Displays a error notification
	- Parameters:
		- `header`: Header text to display
		- `text`: Error text to display
		- `x_loc`: x-position of the notification
		- `y_loc`: y-position of the notification
		- `width`: width of the notification banner
		- `height`: height of the notification banner
		- `background_color`: background color

	- Returns:
		- Should not return anything.

	- :warning: **Warning:** This function displays the notification, pauses all program inputs for 2 seconds, and then removes the notification.

***

#### Math Functions:

> Defines:
>> `triangle_t`
>>> struct triangle
>>>{
>>>>double side_1;
>>>>double side_2;
>>>>double side_3;
>>>>double angle_1;
>>>>double angle_2;
>>>>double angle_3;
>>>>double perimeter;
>>>>double area;
>>>}

1. `unsigned long long int fact(unsigned int num)`
> Calculates the factorial of a number.
	- Parameters:
		- `num`: number to calculate the factorial of

	- Returns:
		– Returns the factorial.

	- :warning: **Warning:** If `1` is returned, this most likely indicates that the number you used for `num` exceeds C99 calculating power.

2. `double pythag(double leg_1, double leg_2, double hyp)`
> Calculates the missing side of a right triangle. Put `NULL` for the variable you want solved for.
	- Parameters:
		- `leg_1`: one leg of the right triangle
		- `leg_2`: second leg of the right triangle
		- `hyp`: hypotenuse of the right triangle

	- Returns:
		- The calculated value for the variable you put `NULL` for.

3. `void solve_triangle(triangle_t triangle, uint8_t mode)`
> Solves any triangle

	- Parameters:
		- `triangle`: pass a triangle_t to this function.
		- `mode`:
			- `1`: Given Side–Angle–Side
				- Populate: side_2, side_3, and angle_1.
			- `2`: Given Side–Side—Side
				- Populate: all sides.
			- `3`: Given Angle–Side–Angle
				- Populate: side_3, angle_1, and angle_2.
			- `4`: Given Angle–Angle–Side
				- Populate: side_1, angle_1, and angle_2.
	- Returns:
		- All values are stored in `triangle`.

	- :warning: **Warning:** Incorrect population of the struct will cause incorrect values and/or missing values.

***

#### Operating System Functions:

1. `void var_Sto(const char *var, float num_sto)`
> Stores a floating point number into any OS Variable.
	- Parameters:
		- var: variable to store number in
			- :tip: **Tip:** Include the <ti/vars.h> file in the header section and use the following defines: OS_VAR_$ where $ is any character from A-Z.
		- num_sto: number to store in variable
	- Returns:
		- Should not return anything.

***
##### Copyright October 2022. All Rights Reserved. May not be reproduced or distributed without permission.
