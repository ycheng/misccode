#%%

import requests
from bs4 import BeautifulSoup
import pandas as pd

url = "http://www.boxofficemojo.com/yearly/"

response = requests.get(url)
response.encoding = "utf-8" # options in python 3 ?

# print(response.text)

def line(str=""):
    print("==" * 10, str)

soup = BeautifulSoup(response.text, "lxml")

tables = list(soup.find_all('table'))
table = tables[2]

trs = table.find_all("tr")
head = trs.pop(0)
headar = [i.text for i in head]
# print(headar)
rows = [list(d.stripped_strings) for d in trs]
# print(rows)

df = pd.DataFrame(rows, columns=headar)
print(df)

df.to_csv("/tmp/game.csv", index=False)