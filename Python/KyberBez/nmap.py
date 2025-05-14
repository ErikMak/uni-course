import os
from colorama import Fore, Back, Style
import time


start_time=time.time()
os.system('sudo nmap -sT 10.0.2.10')

# Время работы
print(Fore.BLUE+"Scan of ports Ended in:"+Style.RESET_ALL, Fore.GREEN+str(round(time.time()-start_time))+Style.RESET_ALL, "s")