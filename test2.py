import selenium
from selenium import webdriver
driver = webdriver.Firefox()

driver.get('https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1')
driver.quit()