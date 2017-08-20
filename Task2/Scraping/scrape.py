import urllib2
from bs4 import BeautifulSoup
def internet_on():
    try:
        urllib2.urlopen('http://www.google.com', timeout=1)
        return True
    except urllib2.URLError as err: 
        return False
if internet_on()==False:
	print("NO internet access!")
	exit()
htmlParser = "lxml"
url='https://www.youtube.com/playlist?list=PLm5ipifE5Hn5WyXlGVmspI7zlV5o8dZIy'
html=urllib2.urlopen(url)
print("Link to all videos:-")
response=html.read()
soup=BeautifulSoup(response, htmlParser)
links = soup.find_all('a', attrs={'class':'pl-video-title-link'})
for a in links:
    print("www.youtube.com"+a.get("href"))