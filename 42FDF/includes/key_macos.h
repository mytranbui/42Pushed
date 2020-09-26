/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_macos.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:11:48 by mbui              #+#    #+#             */
/*   Updated: 2020/01/14 11:33:03 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_MACOS_H
# define KEY_MACOS_H

# define KEYPRESS           2
# define KEYRELEASE         3
# define MOUSEPRESS         4
# define MOUSERELEASE       5
# define MOTIONNOTIFY		6
# define DESTROYNOTIFY		17

# define KEYPRESSMASK       (1L<<0)
# define KEYRELEASEMASK     (1L<<1)
# define BUTTONPRESSMASK    (1L<<2)

# define MOUSE_RIGHT        1
# define MOUSE_LEFT         2
# define MOUSE_MIDDLE       3
# define MOUSE_SCROLLDOWN   4
# define MOUSE_SCROLLUP     5

# define K_ESC              53
# define K_F1 		    	122
# define K_F2				120
# define K_F3				99
# define K_F4				118
# define K_F5				96
# define K_F6				97
# define K_F7				98
# define K_F8				100
# define K_F9				101
# define K_F10		    	109
# define K_F11		    	103
# define K_F12		    	111
# define K_F13		    	105
# define K_F14		    	107
# define K_F15		    	113
# define K_F16		    	106
# define K_F17		    	64
# define K_F18		    	79
# define K_F19	     		80
# define K_TILDE			50
# define K_1				18
# define K_2				19
# define K_3				20
# define K_4				21
# define K_5				23
# define K_6				22
# define K_7				26
# define K_8				28
# define K_9				25
# define K_0				29
# define K_MINUS			27
# define K_EQUAL			24
# define K_BACKSPACE		51
# define K_TAB		    	48
# define K_Q				12
# define K_W				13
# define K_E				14
# define K_R				15
# define K_T				17
# define K_Y				16
# define K_U				32
# define K_I				34
# define K_O				31
# define K_P				35
# define K_OPEN_BRACKET 	33
# define K_OPEN_BRACE		33
# define K_CLOSE_BRACKET	30
# define K_CLOSE_BRACE  	30
# define K_BACKSLASH		42
# define K_PIPE		       	42
# define K_CAPSLOCK	    	272
# define K_A				0
# define K_S				1
# define K_D				2
# define K_F				3
# define K_G				5
# define K_H				4
# define K_J				38
# define K_K				40
# define K_L				37
# define K_COLON			41
# define K_SEMI_COLON		41
# define K_SIMPLE_QUOTE	    39
# define K_DOUBLE_QUOTES	39
# define K_ENTER			36
# define K_SHIFT_LEFT		257
# define K_Z				6
# define K_X				7
# define K_C				8
# define K_V				9
# define K_B				11
# define K_N				45
# define K_M				46
# define K_LESS_THAN		43
# define K_COMMA			43
# define K_GREATER_THAN	    47
# define K_DOT              47
# define K_SLASH			44
# define K_QUESTION_MARK    44
# define K_SHIFT_RIGHT      258
# define K_CTRL_LEFT		256
# define K_COMMAND_LEFT     259
# define K_OPTION_LEFT      261
# define K_ALT              261
# define K_SPACE            49
# define K_COMMAND_RIGHT	260
# define K_ALT_GR			262
# define K_FN				279
# define K_CTRL_RIGHT		269
# define K_LEFT             123
# define K_DOWN             125
# define K_RIGHT			124
# define K_UP				126
# define K_DEL              117
# define K_HOME             115
# define K_END              119
# define K_PAGE_UP          116
# define K_PAGE_DOWN        121
# define K_CLEAR			71
# define K_PAD_1			83
# define K_PAD_2			84
# define K_PAD_3			85
# define K_PAD_4			86
# define K_PAD_5			87
# define K_PAD_6			88
# define K_PAD_7			89
# define K_PAD_8			91
# define K_PAD_9			92
# define K_PAD_0			82
# define K_PAD_EQUAL		81
# define K_PAD_DIVIDE		75
# define K_PAD_MULTIPLY     67
# define K_PAD_SUB		    78
# define K_PAD_ADD		    69
# define K_PAD_ENTER		76
# define K_PAD_DOT	     	65

#endif
