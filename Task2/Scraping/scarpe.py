from urllib2 import urlopen 
from bs4 import BeautifulSoup

htmlParser = "lxml"
url='https://www.youtube.com/playlist?list=PLm5ipifE5Hn5WyXlGVmspI7zlV5o8dZIy'
print("m")
html=urlopen(url)
response=html.read()
soup=BeautifulSoup(response, htmlParser)
links = soup.find_all('a', attrs={'class':'pl-video-title-link'})
print("m")
for a in links:
    print(a.get("href"))