from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import re

driver = webdriver.Chrome()

driver.get("https://www.google.com")
assert "Google" in driver.title
elem = driver.find_element_by_name("q")
elem.clear()
elem.send_keys("bing")
elem.send_keys(Keys.RETURN)
src = driver.page_source
text_found = re.search(r'a', src)
assert text_found != None
driver.close()
