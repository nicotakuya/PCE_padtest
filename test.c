/* Pad test for PC Engine */
/* by takuya matsubara*/
#include "huc.h"
#incbin(bg_pattern,"bg_pattern.bin");
#incbin(bg_palette,"bg_palette.bin");
#incbin(bg_bat    ,"bg_bat.bin");

main()
{
	int x,y,i;
	char button,state;

	disp_on();
	cls();

	load_background(bg_pattern, bg_palette, bg_bat, 32, 28);

	set_font_color(15, 0);
	set_font_pal(1);
	load_default_font();

	put_string("BTN I :", 5,3);
	put_string("BTN II:", 5,5);
	put_string("SELECT:", 5,7);
	put_string("RUN   :", 5,9);
	put_string("UP    :", 5,11);
	put_string("RIGHT :", 5,13);
	put_string("DOWN  :", 5,15);
	put_string("LEFT  :", 5,17);

	while(1){
		button = joy(0);
		for(i=0; i<8; i++){
			state = button & 1;
			x = 15;
			y = (i*2)+3;
			put_hex(state, 1, x,y);
			button >>= 1;
		}
		vsync();
	}
}

