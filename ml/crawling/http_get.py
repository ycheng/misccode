#%%

import requests

url = "http://research.sinica.edu.tw/"

response = requests.get(url)
response.encoding = "utf-8" # options in python 3 ?

print(response.text)
