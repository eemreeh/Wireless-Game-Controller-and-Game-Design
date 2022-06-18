import serial                                      # add Serial library for serial communication
import pyautogui                                   # add pyautogui library for programmatically controlling the mouse and keyboard.
import time

Arduino_Serial = serial.Serial(port='COM3', baudrate=9600, timeout=.1)      # Initialize serial and Create Serial port object called 
time.sleep(2)

incoming_data =  "b'111110100\\r\\n'"
while 1:

   #Arduino_Serial.flushInput()asawwasdwads
   #Arduino_Serial.reset_input_buffer()
   #Arduino_Serial.read_all() 
   incoming_data_old = incoming_data
   temp_data = str(Arduino_Serial.readline())
   
   if temp_data[0:2] == "b'" and temp_data[11:16] == "\\r\\n'" and temp_data != incoming_data:
      incoming_data = temp_data
   
   
   
      
#   if len(temp_data) ==16:     
#      incoming_data = temp_data
   
   if (incoming_data == incoming_data_old):
      continue
   
   print(incoming_data)                            #  print the incoming Serial data
#   Arduino_Serial.reset_input_buffer()                       #  print the incoming Serial data

   but1 = incoming_data[2] 
   but2 = incoming_data[3] 
   but3 = incoming_data[4] 
   but4 = incoming_data[5] 
   but_joy = incoming_data[6]  
   joystick = incoming_data[7:11]
   
   but1_key = 'left'
   but2_key = 'up'
   but3_key = 'down'
   but4_key = 'right'
   but_joy_key = 'r'
   joy_up = 'w'
   joy_down = 's'
   joy_left = 'a'
   joy_right = 'd'
   
   if (but1 == '0'): pyautogui.press(but1_key)
   if (but2 == '0'): pyautogui.press(but2_key)
   if (but3 == '0'): pyautogui.press(but3_key)
   if (but4 == '0'): pyautogui.press(but4_key)
   if (but_joy == '0'): pyautogui.press(but_joy_key) 
   
   if (joystick == "0001"): pyautogui.press(joy_up)
   if (joystick == "0011"): pyautogui.press(joy_left)
   if (joystick == "0101"): pyautogui.press(joy_right)
   if (joystick == "0111"): pyautogui.press(joy_down)
   
   
#   incoming_data =  "b'000000000\\r\\n'"