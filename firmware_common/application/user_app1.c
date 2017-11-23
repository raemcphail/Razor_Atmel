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
extern u8 G_au8DebugScanfBuffer[];
extern u8 G_u8DebugScanfCharCount;

/***********************************************************************************************************************
Global variable definitions with scope limited to this local application.
Variable names shall start with "UserApp1_" and be declared as static.
***********************************************************************************************************************/
static fnCode_type UserApp1_StateMachine;            /* The state machine function pointer */
//static u32 u32UserApp1_Counter =0;
//static bool bUserApp1_CounterOn =TRUE;
//static u32 UserApp1_u32Timeout; 
                     /* Timeout counter used across states */
static u8 UserApp_au8UserInputBuffer[U16_USER_INPUT_BUFFER_SIZE];

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
  
    u8 au8String[] = "A string to print that returns cursor to start of next line.\n\r";
    u8 au8String2[] = "Here's a number ";
    u8 au8String3[] = "<The 'cursor' was here after the number.";
    u32 u32Number = 1234567;
    
    DebugPrintf(au8String);
    DebugPrintf(au8String2);
    DebugPrintNumber(u32Number);
    DebugPrintf(au8String3);
    DebugLineFeed();
    DebugPrintf(au8String3);
    DebugLineFeed();
    
    for(u16 i = 0; i < U16_USER_INPUT_BUFFER_SIZE; i++)
    {
      UserApp_au8UserInputBuffer[i] = 0;
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
  static u8 u8NumCharsMessage[] = "\n\rCharacters in buffer: ";
  static u8 au8BufferMessage[] = "\n\rBuffer contents: \n\r";
  static u8 au8EmptyMessage[] = "\n\rThe buffer is empty\n\r";
  
  u8 u8CharCount;  
  //The name part of the assignment
  static u8 au8NameCountMessage[] = "\n\rNumber of times my name was printed: ";
  static u8 au8MyName[] = "rae";
  static u32 u32NameCount = 0;
  
  
  if(WasButtonPressed(BUTTON0))
    {
      ButtonAcknowledge(BUTTON0);
      
      DebugPrintf(u8NumCharsMessage);
      DebugPrintNumber(G_u8DebugScanfCharCount);
      DebugLineFeed();
    }
    
    if(WasButtonPressed(BUTTON1))
    {
      ButtonAcknowledge(BUTTON1);
      
      u8CharCount = DebugScanf(UserApp_au8UserInputBuffer);
     
      if(u8CharCount>0)
      {
      UserApp_au8UserInputBuffer[u8CharCount] = '\0';
      DebugPrintf(au8BufferMessage);
      DebugPrintf(UserApp_au8UserInputBuffer);
      
      }
      else
      {
        DebugPrintf(au8EmptyMessage);
      }
     
   }
  
  //The name part of the assignment
 if(WasButtonPressed(BUTTON2))
 {
   ButtonAcknowledge(BUTTON2);
   u8 u8BufferSize=DebugScanf(UserApp_au8UserInputBuffer);
   for(u8 i=0; i<u8BufferSize;i++)
   {
     u8 j;
     for(j=0; j<3;j++)
     {
      if(UserApp_au8UserInputBuffer[j+i]!= au8MyName[j])
      {
        break;
      }
      
     }
      if(j==3)
      {
        u32NameCount++;
      }
     
     
   }
  
   DebugPrintf(au8NameCountMessage);
   DebugPrintNumber(u32NameCount);
   DebugLineFeed();
 
 }
  
 

  
    
   
} /* end UserApp1SM_Idle() */
    

/*-------------------------------------------------------------------------------------------------------------------*/
/* Handle an error */
static void UserApp1SM_Error(void)          
{
  
} /* end UserApp1SM_Error() */



/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------*/


