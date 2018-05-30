#%%

import requests
from bs4 import BeautifulSoup

url = "http://research.sinica.edu.tw/"

response = requests.get(url)
response.encoding = "utf-8" # options in python 3 ?

# print(response.text)

soup = BeautifulSoup(response.text, "lxml")

r = soup.find_all('div', {"class": "branding"})
print(r)

print("===>", soup.p)
print(soup.p)
print(soup.p['style']) # this works
print("===>", "soup.find_all")
for p in soup.find_all("p"):
    print(p.text)
    print(p.img)
    print("==== type")
    print(type(p))
    if ('style' in p.attrs):
        print(p.attrs['style'])


