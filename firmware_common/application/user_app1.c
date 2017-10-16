/**********************************************************************************************************************
File: user_app1.c                                                                

----------------------------------------------------------------------------------------------------------------------
To start a new task using this user_app1 as a template:
 1. Copy both user_app1.c and user_app1.h to the Application directory
 2. Rename the files yournewtaskname.c and yournewtaskname.h
 3. Add yournewtaskname.c and yournewtaskname.h to the Application Include and Source groups in the IAR project
 4. Use ctrl-h (make sure "Match Case" is checked) to find and replace all instances of "user_app1" with "yournewtaskname"
 5. Use ctrl-h to find and replace all instances of "UserApp1" with "YourNewTaskName"
 6. Use ctrl-h to find and replace all instances of "USER_APP1" with "YOUR_NEW_TASK_NAME"
 7. Add a call to YourNewTaskNameInitialize() in the init section of main
 8. Add a call to YourNewTaskNameRunActiveState() in the Super Loop section of main
 9. Update yournewtaskname.h per the instructions at the top of yournewtaskname.h
10. Delete this text (between the dashed lines) and update the Description below to describe your task
----------------------------------------------------------------------------------------------------------------------

Description:
This is a user_app1.c file template 

------------------------------------------------------------------------------------------------------------------------
API:

Public functions:


Protected System functions:
void UserApp1Initialize(void)
Runs required initialzation for the task.  Should only be called once in main init section.

void UserApp1RunActiveState(void)
Runs current task state.  Should only be called once in main loop.


**********************************************************************************************************************/

#include "configuration.h"

/***********************************************************************************************************************
Global variable definitions with scope across entire project.
All Global variable names shall start with "G_UserApp1"
***********************************************************************************************************************/
/* New variables */
volatile u32 G_u32UserApp1Flags;                       /* Global state flags */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Existing variables (defined in other files -- should all contain the "extern" keyword) */
extern volatile u32 G_u32SystemFlags;                  /* From main.c */
extern volatile u32 G_u32ApplicationFlags;             /* From main.c */

extern volatile u32 G_u32SystemTime1ms;                /* From board-specific source file */
extern volatile u32 G_u32SystemTime1s;                 /* From board-specific source file */


/***********************************************************************************************************************
Global variable definitions with scope limited to this local application.
Variable names shall start with "UserApp1_" and be declared as static.
***********************************************************************************************************************/
static fnCode_type UserApp1_StateMachine;            /* The state machine function pointer */
//static u32 UserApp1_u32Timeout;                      /* Timeout counter used across states */


/**********************************************************************************************************************
Function Definitions
**********************************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Public functions                                                                                                   */
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Protected functions                                                                                                */
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Function: UserApp1Initialize

Description:
Initializes the State Machine and its variables.

Requires:
  -

Promises:
  - 
*/
void UserApp1Initialize(void)
{
  LedOff(CYAN);
  LedOff(GREEN); 
  LedOff(YELLOW); 
  LedOff(ORANGE);
  LedOff(BLUE);
  LedOff(PURPLE);
  LedOff(WHITE);
  LedOff(RED);
  
  //LedBlink(RED, LED_2HZ);
  //LedPWM(WHITE, LED_PWM_5);
  
  
  
  
  
  /* If good initialization, set state to Idle */
  if( 1 )
  {
    UserApp1_StateMachine = UserApp1SM_Idle;
  }
  else
  {
    /* The task isn't properly initialized, so shut it down and don't run */
    UserApp1_StateMachine = UserApp1SM_Error;
  }

} /* end UserApp1Initialize() */

  
/*----------------------------------------------------------------------------------------------------------------------
Function UserApp1RunActiveState()

Description:
Selects and runs one iteration of the current state in the state machine.
All state machines have a TOTAL of 1ms to execute, so on average n state machines
may take 1ms / n to execute.

Requires:
  - State machine function pointer points at current state

Promises:
  - Calls the function to pointed by the state machine function pointer
*/
void UserApp1RunActiveState(void)
{
  UserApp1_StateMachine();

} /* end UserApp1RunActiveState */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Private functions                                                                                                  */
/*--------------------------------------------------------------------------------------------------------------------*/


/**********************************************************************************************************************
State Machine Function Definitions
**********************************************************************************************************************/

/*-------------------------------------------------------------------------------------------------------------------*/
/* Wait for ??? */
static void UserApp1SM_Idle(void)
{
  static u16 u16BlinkCount = 0;
  static u8 u8Counter = 0;
  static u8 u8ColorIndex = 0;
  
  static bool bIncreasing = TRUE;
  static LedRateType eCurrentRate = LED_PWM_0;
  
 // u16BlinkCount++;
 
    
 //Now I'm making my own Led Design
  static u32 u32FadeCount = 0;
  
  
  static LedRateType eCurrentRateRed = LED_PWM_0;
  static LedRateType eCurrentRateOrange = LED_PWM_0;
  static LedRateType eCurrentRateYellow = LED_PWM_0;
  static LedRateType eCurrentRateGreen = LED_PWM_0;
  static LedRateType eCurrentRateCyan = LED_PWM_0;
  static LedRateType eCurrentRateBlue = LED_PWM_0;
  static LedRateType eCurrentRatePurple = LED_PWM_0;
  static LedRateType eCurrentRateWhite = LED_PWM_0;
  
  static bool bIncreasingRed = TRUE;
  static bool bIncreasingOrange = TRUE;
  static bool bIncreasingYellow = TRUE;
  static bool bIncreasingGreen = TRUE;
  static bool bIncreasingCyan = TRUE;
  static bool bIncreasingBlue = TRUE;
  static bool bIncreasingPurple = TRUE;
  static bool bIncreasingWhite = TRUE;
  
  
  static u32 u32r = 20;
  static u32 u32o = 40;
  static u32 u32y = 60;
  static u32 u32g = 80;
  static u32 u32c = 100;
  static u32 u32b = 120;
  static u32 u32p = 140;
  static u32 u32w = 160;
  
  u32FadeCount++;
  
  //Red
  if(u32FadeCount == u32r)
  {
    u32r+=20;
    
  LedPWM(RED, eCurrentRateRed);
  
  if(eCurrentRateRed==LED_PWM_100)
  {
    bIncreasingRed = FALSE;
  }
   if(eCurrentRateRed==LED_PWM_0)
  {
    bIncreasingRed = TRUE;
  }
  if(bIncreasingRed)
  {
    eCurrentRateRed++;
  }
  else
  {
    eCurrentRateRed--;
  }
    
  }
  
  //Orange
  if(u32FadeCount == u32o)
  {
    u32o+=40;
    
  LedPWM(ORANGE, eCurrentRateOrange);
  
  if(eCurrentRateOrange==LED_PWM_100)
  {
    bIncreasingOrange = FALSE;
  }
   if(eCurrentRateOrange==LED_PWM_0)
  {
    bIncreasingOrange = TRUE;
  }
  if(bIncreasingOrange)
  {
    eCurrentRateOrange++;
  }
  else
  {
    eCurrentRateOrange--;
  }
    
  }
  
  //Yellow
  if(u32FadeCount == u32y)
  {
    u32y+=60;
    
  LedPWM(YELLOW, eCurrentRateYellow);
  
  if(eCurrentRateYellow==LED_PWM_100)
  {
    bIncreasingYellow = FALSE;
  }
  if(eCurrentRateYellow==LED_PWM_0)
  {
    bIncreasingYellow = TRUE;
  }
  if(bIncreasingYellow)
  {
    eCurrentRateYellow++;
  }
  else
  {
    eCurrentRateYellow--;
  }
    
  }
  
  
  //Green
  if(u32FadeCount == u32g)
  {
    u32g+=80;
    
  LedPWM(GREEN, eCurrentRateGreen);
  
  if(eCurrentRateGreen==LED_PWM_100)
  {
    bIncreasingGreen = FALSE;
  }
  if(eCurrentRateGreen==LED_PWM_0)
  {
    bIncreasingGreen = TRUE;
  }
  if(bIncreasingGreen)
  {
    eCurrentRateGreen++;
  }
  else
  {
    eCurrentRateGreen--;
  }
  
  }
  
  //Cyan
  if(u32FadeCount == u32c)
  {
    u32c+=100;
    
  LedPWM(CYAN, eCurrentRateCyan);
  
  if(eCurrentRateCyan==LED_PWM_100)
  {
    bIncreasingCyan = FALSE;
  }
  if(eCurrentRateCyan==LED_PWM_0)
  {
    bIncreasingCyan = TRUE;
  }
  if(bIncreasingCyan)
  {
    eCurrentRateCyan++;
  }
  else
  {
    eCurrentRateCyan--;
  }
  
  }
  
  //Blue
  if(u32FadeCount == u32b)
  {
    u32b+=120;
    
  LedPWM(BLUE, eCurrentRateBlue);
  
  if(eCurrentRateBlue==LED_PWM_100)
  {
    bIncreasingBlue = FALSE;
  }
  if(eCurrentRateBlue==LED_PWM_0)
  {
    bIncreasingBlue = TRUE;
  }
  if(bIncreasingBlue)
  {
    eCurrentRateBlue++;
  }
  else
  {
    eCurrentRateBlue--;
  }
  
  }
  
  //Purple
  if(u32FadeCount == u32p)
  {
    u32p+=140;
    
  LedPWM(PURPLE, eCurrentRatePurple);
  
  if(eCurrentRatePurple==LED_PWM_100)
  {
    bIncreasingPurple = FALSE;
  }
  if(eCurrentRatePurple==LED_PWM_0)
  {
    bIncreasingPurple = TRUE;
  }
  if(bIncreasingPurple)
  {
    eCurrentRatePurple++;
  }
  else
  {
    eCurrentRatePurple--;
  }
  
  }
  
    //White
  if(u32FadeCount == u32w)
  {
    u32w+=160;
    
  LedPWM(WHITE, eCurrentRateWhite);
  
  if(eCurrentRateWhite==LED_PWM_100)
  {
    bIncreasingWhite = FALSE;
  }
  if(eCurrentRateWhite==LED_PWM_0)
  {
    bIncreasingWhite = TRUE;
  }
  if(bIncreasingWhite)
  {
    eCurrentRateWhite++;
  }
  else
  {
    eCurrentRateWhite--;
  }
  
  }
  
  
  /*if(u8FadeCount == 160)
  {
    u8FadeCount = 0;
  } */ 
   


  
  
  /*if(u8FadeCount==40)
  {
    u8FadeCount = 0;

  
  LedPWM(CYAN, eCurrentRate);
  
  if(eCurrentRate==LED_PWM_100)
  {
    bIncreasing = FALSE;
  }
   if(eCurrentRate==LED_PWM_0)
  {
    bIncreasing = TRUE;
  }
  if(bIncreasing)
  {
    eCurrentRate++;
  }
  else
  {
    eCurrentRate--;
  }
  
  }*/
  
  
 /* if(u16BlinkCount==500)
  {
    u16BlinkCount = 0;
    u8Counter++;
  
    if(u8Counter == 16)
    {
      u8Counter = 0; 
      u8ColorIndex++;
      if(u8ColorIndex == 7)
      {
        u8ColorIndex = 0;
      }
      switch(u8ColorIndex)
      {
        case 0:
          LedOn(LCD_RED);
          LedOn(LCD_BLUE);
          LedOn(LCD_GREEN);
          break;
          
        case 1:
          LedOn(LCD_RED);
          LedOn(LCD_BLUE);
          LedOff(LCD_GREEN);
          break;
          
         case 2:
          LedOff(LCD_RED);
          LedOn(LCD_BLUE);
          LedOff(LCD_GREEN);
          break;
          
         case 3:
          LedOff(LCD_RED);
          LedOn(LCD_BLUE);
          LedOn(LCD_GREEN);
          break;
          
         case 4:
          LedOff(LCD_RED);
          LedOff(LCD_BLUE);
          LedOn(LCD_GREEN);
          break;
          
         case 5:
          LedOn(LCD_RED);
          LedOff(LCD_BLUE);
          LedOn(LCD_GREEN);
          break;
          
         case 6:
          LedOn(LCD_RED);
          LedOff(LCD_BLUE);
          LedOff(LCD_GREEN);
          break;
          
         default:
          LedOff(LCD_RED);
          LedOff(LCD_BLUE);
          LedOff(LCD_GREEN);
          break;
      }
    }
  }
  
  if(u8Counter & 0x01)
  {
    LedOn(RED);
  }
  else
  {
    LedOff(RED);
  }
  
  if(u8Counter & 0x02)
  {
    LedOn(ORANGE);
  }
  else
  {
    LedOff(ORANGE);
  }
  
  if(u8Counter & 0x04)
  {
    LedOn(YELLOW);
  }
  else
  {
    LedOff(YELLOW);
  }
  
  if(u8Counter & 0x08)
  {
    LedOn(GREEN);
  }
  else
  {
    LedOff(GREEN);
  }
  
   if(u8Counter & 0x10)
  {
    LedOn(CYAN);
  }
  else
  {
    LedOff(CYAN);
  }
  
   if(u8Counter & 0x20)
  {
    LedOn(BLUE);
  }
  else
  {
    LedOff(BLUE);
  }
  
  if(u8Counter & 0x40)
  {
    LedOn(PURPLE);
  }
  else
  {
    LedOff(PURPLE);
  }
  
   if(u8Counter & 0x80)
  {
    LedOn(WHITE);
  }
  else
  {
    LedOff(WHITE);
  }*/
} /* end UserApp1SM_Idle() */
    

/*-------------------------------------------------------------------------------------------------------------------*/
/* Handle an error */
static void UserApp1SM_Error(void)          
{
  
} /* end UserApp1SM_Error() */



/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------*/
