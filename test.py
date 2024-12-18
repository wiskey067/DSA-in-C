import pyautogui
import time

count = 0
while count <= 100:
    pyautogui.typewrite("elina tu randi hai   " + str(count))
    pyautogui.press("enter")
    count += 1
    time.sleep(3)
    
    